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
    int n, k; cin >> n >> k;
    vector<int> S(n);
    vector<int> T(n);
    for(int&v : S) cin >> v;
    for(int&v : T) cin >> v;
    vector<pair<int, int>> r1, r2;
    r1.reserve(n); r2.reserve(n);
    for (int i = 0; i < n; ++i) {
        int r = S[i] % k;
        int q = llabs(r - k);
        r1.emplace_back(min(r, q), max(r, q));
    }
    for (int i = 0; i < n; ++i) {
        int r = T[i] % k;
        int q = llabs(r - k);
        r2.emplace_back(min(r, q), max(r, q));
    }

    sort(all(r1));
    sort(all(r2));

    (r1 == r2) ? cout << "YES" << nl : cout << "NO" << nl;
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
