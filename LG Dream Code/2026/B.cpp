/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
#define fastio                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
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
const ll N = 50001;

ll fact[N];

void init() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
    }
}

void solve() {
    init();
    int n, m; cin >> n >> m;
    vector<ll> A(n);
    for(auto&v : A) cin >> v;
    vector<ll> diff(n + 2, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        diff[r + 1] -= 1;
        // for(auto x : diff) cout << x << " ";
        // cout << nl;
    }
    // for(auto x : diff) cout << x << " "; cout << nl;

    vector<ll> w(n);
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        w[i - 1] = cur;
        // for(auto x : w) cout << x << " ";
        // cout << nl;
    }
    sort(all(w), greater<ll>());
    sort(all(A), greater<ll>());
    // for(auto x : w) cout << x << " "; cout << nl;
    ll S = 0;
    for(int i = 0; i < n; i++) S += w[i] * A[i];
    cout << S << " ";
    map<int, int> mp;
    for(auto x : w) mp[x]++;
    ll res = 1;
    for(auto x : mp) {
        // cout << x.fi << " " << x.se << nl;
        res = (res % MOD * fact[x.se] % MOD) % MOD;
    }
    cout << res << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    ntest = 1;
    cin >> ntest;
    while (ntest--) {
        // clock_t z = clock();
        solve();
        // debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
