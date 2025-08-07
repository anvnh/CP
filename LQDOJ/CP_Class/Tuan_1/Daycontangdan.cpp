/**
    Author: anvnh
    Created: 2024-08-23 18:34:50
**/

#include <algorithm>
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

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    vector<int> a1, a2;
    for(int i = 0; i < n; i++)
    {
        if(sz(a1) && sz(a2) && a1.back() >= a[i] && a2.back() >= a[i]) {
            if(a1.back() > a2.back()) a2.pb(a[i]);
            else a1.pb(a[i]);
            continue;
        }
        if(a1.empty() || a1.back() >= a[i]) {
            a1.pb(a[i]); continue;
        }
        if(a2.empty() || a2.back() >= a[i]) {
            a2.pb(a[i]); continue;
        }
        if(a1.back() > a2.back()) a2.pb(a[i]);
        else a1.pb(a[i]);
    }
    int res = 0;
    for(int i = 1; i < sz(a1); i++) if(a1[i] > a1[i - 1]) res++;
    for(int i = 1; i < sz(a2); i++) if(a2[i] > a2[i - 1]) res++;
    cout << res << nl;
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
