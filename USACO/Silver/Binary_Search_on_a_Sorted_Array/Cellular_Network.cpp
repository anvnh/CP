// https://codeforces.com/contest/702/problem/C
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
#define INF 0x3f3f3f3f

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    vector<int> b(m);
    for(int&v : b) cin >> v;

    int res = 0;

    for(int i = 0; i < n; i++) {
        int right = lower_bound(all(b), a[i]) - b.begin();
        int left = right - 1;
        int mi = INT_MAX;
        if(left >= 0) {
            assert(a[i] >= b[left]);
            mi = min(mi, a[i] - b[left]);
        }
        if(right < m) {
            assert(a[i] <= b[right]);
            mi = min(mi, b[right] - a[i]);
        }
        res = max(res, mi);
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
