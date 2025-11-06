/**
 * Author: anvnh
 * RyeNyn
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

void solve() {
      ll n, m;
      cin >> n >> m;
      if (n & 1 || m & 1) {
            return cout << "IMPOSSIBLE" << nl, void();
      }
      // n eyes, m feet
      // 2 * x + 2 * y = n
      // x + y = n / 2
      // x = n / 2 - y

      // 4 * x + 2 * y = m
      // 4 * (n / 2 - y) + 2 * y = m
      // 2n - 4y + 2y = m
      // 2n - 2y = m
      // (2n - m) / 2 = y

      ll f = (m - n) / 2;
      ll c = (2 * n - m) / 2;
      // cout << f << " " << c << nl;
      if (f * 4 + c * 2 == m && f * 2 + c * 2 == n && f >= 0 && c >= 0) {
            cout << f << " " << c << nl;
      } else {
            cout << "IMPOSSIBLE" << nl;
      }
}

anvnh {
// #ifndef ONLINE_JUDGE
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
// #endif
      fastio
      int ntest = 1;
      // cin >> ntest;
      while (ntest--) {
            solve();
      }
      return 0;
}
