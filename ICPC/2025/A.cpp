/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
      ios_base::sync_with_stdio(0);                                            \
      cin.tie(0);                                                              \
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

int _max(vector<int> tmp) {
      int m = INT_MIN;
      for (auto x : tmp)
            m = max(m, x);
      return m;
}

int _min(vector<int> tmp) {
      int m = INT_MAX;
      for (auto x : tmp)
            m = min(m, x);
      return m;
}

void solve() {
      int n, C, D;
      cin >> n >> C >> D;
      vector<int> a(n);
      for (int &v : a)
            cin >> v;
      vector<int> b(n);
      for (int &v : b)
            cin >> v;
      cout << _max(a) - _min(a) << "|" << C << nl;
      // cout << _max(b) - _min(b) << "|" << D << nl;
      cout << "----" << nl;

      // if(_max(a) - _min(a) )
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
            clock_t z = clock();
            solve();
            debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
      }
      return 0;
}
