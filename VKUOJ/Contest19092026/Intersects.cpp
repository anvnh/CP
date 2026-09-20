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

struct P {
    ll x, y;
};

ll cross(P a, P b, P c) {
    ll tmp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (tmp < 0) ? -1 : (tmp > 0) ? 1 : 0;
}

bool on(P a, P b, P c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool check(P a, P b, P c, P d) {
    ll s1 = cross(a, b, c);
    ll s2 = cross(a, b, d);
    ll s3 = cross(c, d, a);
    ll s4 = cross(c, d, b);
    if((s1 * s2 < 0 && s3 * s4 < 0) ||
        (s1 == 0 && on(a, b, c)) ||
        (s2 == 0 && on(a, b, d)) ||
        (s3 == 0 && on(c, d, a)) ||
        (s4 == 0 && on(c, d, b))
    ) return true;
    return false;
}

void solve() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    P a = {x1, y1}, b = {x2, y2}, c = {x3, y3}, d = {x4, y4};
    return cout << (check(a, b, c, d) ? "YES" : "NO") << nl, void();
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
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
