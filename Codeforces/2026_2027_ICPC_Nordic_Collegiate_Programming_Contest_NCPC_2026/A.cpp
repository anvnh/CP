/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
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

bool check(int n, vector<int> &t, int d) {
    vector<bool> vis(n, false);
    int j = 0;
    rep(i, 0, n) {
        if (vis[i])
            continue;
        int t2 = t[i] + d;

        while (j < n && (t[j] < t2 || vis[j])) {
            j++;
        }
        if (j == n || t[j] != t2)
            return false;
        vis[j] = true;
        j++;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> res;
    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];
    rep(i, 0, n) {
        int d = t[i] - t[0];
        if (d <= 0 || (i > 1 && t[i] == t[i - 1]))
            continue;
        if (check(n, t, d)) {
            res.pb(d);
        }
    }
    cout << sz(res) << nl;
    for (auto x : res)
        cout << x << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    fastio int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--) {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
