/**
    Author: anvnh
    Created: 2024-08-13 11:57:03
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << "}\n";
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

struct ranges {
    int l, r, ind;
    bool operator<(const ranges& other) const
    {
        if (l == other.l)
            return r > other.r;
        return l < other.l;
    }
};


void solve()
{
    int n; cin >> n;
    vector<ranges> vp(n);
    vector<int> ans1(n);
    vector<int> ans2(n);
    REP(i, n)
    {
        cin >> vp[i].l >> vp[i].r;
        vp[i].ind = i;
    }
    sort(all(vp));
    // REP(i, n)
    // {
    //     cout << vp[i].l << " " << vp[i].r << " " << vp[i].ind << nl;
    // }

    // contains
    int minEnd = 2e9;
    for(int i = n - 1; i >= 0; i--)
    {
        // cout << vp[i].fi.fi << " " << vp[i].fi.se << " " << vp[i].se << " | " << minEnd << nl;
        if(vp[i].r >= minEnd){
            ans1[vp[i].ind] = 1;
        }

        minEnd = min(minEnd, vp[i].r);
    }

    // contained
    int maxEnd = -2e9;
    for(int i = 0; i < n; i++)
    {
        if(vp[i].r <= maxEnd)
        {
            ans2[vp[i].ind] = 1;
        }
        maxEnd = max(maxEnd, vp[i].r);
    }

    REP(i, n) cout << ans1[i] << " ";
    cout << nl;

    REP(i, n) cout << ans2[i] << " ";
    cout << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
