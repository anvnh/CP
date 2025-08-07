/**
    Author: anvnh
    Created: 2024-08-19 16:34:16
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

int moveX[6] = {1, 1, 0, -1, -1, 0};
int moveY[6] = {1, 0, -1, -1, 0, 1};

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        vp.pb({a, b});
    }
    cout << "YES" << nl << n * 7 << nl;
    for(int i = 0; i < n; i++) 
    {
        cout << vp[i].fi << " " << vp[i].se << " " << 3 << nl;
        for(int j = 0; j < 6; j++)
        {
            // cout << vp[i].fi + moveX[i] << " " << vp[i].se + moveY[i] << " " << 1 << nl;
            cout << vp[i].fi + moveX[j] << " " << vp[i].se + moveY[j] << " " << 2 << nl;
        }
    }
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        solve();
    }
    return 0;
}
