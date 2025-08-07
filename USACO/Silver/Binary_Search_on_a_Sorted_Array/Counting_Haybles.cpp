// https://usaco.org/index.php?page=viewproblem2&cpid=666
/**
    Author: anvnh
    RyeNyn
**/

#include <algorithm>
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

void setIO(string name = "") {
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    sort(all(a));

    auto bin = [&](int x) {
        int l = 0;
        int r = a.size();
        while(l < r) {
            int mid = (l + r) >> 1;
            if(a[mid] <= x) l = mid + 1;
            else r = mid;
        }
        return l;
    };

    while(q--) {
        int A, B; cin >> A >> B;
        cout << bin(B) - bin(A - 1) << nl;
    }
}

anvnh {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
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
