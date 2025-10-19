//
// Created by vnhantyn on 10/19/25.
//
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

int manha(int x1, int y1, int x2, int y2) {
      return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
      int N; cin >> N;
      vector<pair<int, int>> vp;
      for (int i = 0; i < N; i++) {
            int x1, x2; cin >> x1 >> x2;
            vp.emplace_back(x1, x2);
      }
      sort(all(vp));
      int xA, yA; cin >> xA >> yA;
      int xB, yB; cin >> xB >> yB;
      for (auto x : vp) cout << x.fi << " " << x.se << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      fastio
      int ntest = 1;
      // cin >> ntest;
      while (ntest--) {
            solve();
      }
      return 0;
}
