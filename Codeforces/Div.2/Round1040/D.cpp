/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

const int INF = 1e9;

struct fenwick {
    vector<int> bit;
    int n;
    fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int& v : p) cin >> v;
    vector<int> a(n);
    vector<pair<int, int>> choice(n);
    for (int i = 0; i < n; ++i) {
        choice[i] = {p[i], 2 * n - p[i]};
    }
    for (int pos = 0; pos < n; ++pos) {
        int opt1 = choice[pos].fi;
        int opt2 = choice[pos].se;
        int inv1 = 0, inv2 = 0;
        for (int i = 0; i < pos; ++i) {
            if (a[i] > opt1) inv1++;
            if (a[i] > opt2) inv2++;
        }
        for (int i = pos + 1; i < n; ++i) {
            int _min = min(choice[i].fi, choice[i].se);
            int _max = max(choice[i].fi, choice[i].se);
            if (opt1 > _max) inv1++;
            else if (opt1 > _min) inv1++;
            if (opt2 > _max) inv2++;
            else if (opt2 > _min) inv2++;
        }
        a[pos] = (inv1 <= inv2) ? opt1 : opt2;
    }
    fenwick ft(2 * n);
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        res += ft.query(a[i] - 1);
        ft.update(a[i], 1);
    }
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
