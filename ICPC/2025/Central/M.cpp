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

ll mt1 = LLONG_MAX;
ll kq = LLONG_MAX;

pair<int, int> A;
pair<int, int> B;

int kc(pair<int, int> x1, pair<int, int> x2) {
      return abs(x1.fi - x2.fi) + abs(x1.se - x2.se);
}

int _min(ll a, ll b) {
      return min(a, b);
}

void tinh(vector<pair<int, int> > l, int k, pair<int, int> last, int sl, pair<int, int> z) {
      if (l.size()) {
            for (int i = 0; i < l.size(); i++) {
                  vector<pair<int, int>> tam = l;
                  pair<int, int> x = tam[i];
                  tam.erase(tam.begin() + i);
                  int kk = k + kc(x, last) * sl;
                  tinh(tam, kk, x, sl + 1, z);
            }
      } else {
            mt1 = _min(mt1, kc(z, last) * sl + k);
      }
}

void ran(vector<pair<int, int>> vt, vector<pair<int, int>> n1, vector<pair<int, int>> n2) {
      if (vt.size()) {
            vector<pair<int, int>> tt = vt;
            pair<int, int> xx = tt[tt.size() - 1];
            tt.pop_back();
            vector<pair<int, int>> nn1 = n1;
            nn1.push_back(xx);
            ran(tt, nn1, n2);
            vector<pair<int, int>> nn2 = n2;
            nn2.push_back(xx);
            ran(tt, n1, nn2);
      } else {
            mt1 == LLONG_MAX;
            tinh(n1, 0, A, 0, A);
            ll m1 = mt1;
            mt1 = LLONG_MAX;

            tinh(n2, 0, B, 0, B);
            ll m2 = mt1;
            kq = min(kq, m1 + m2);
            cout << m1 << " "<< m2 << nl;
      }
}

void solve() {
      int N;
      cin >> N;
      vector<pair<int, int> > vt;
      for (int i = 0; i < N; i++) {
            int x1, x2;
            cin >> x1 >> x2;
            vt.emplace_back(x1, x2);
      }
      cin >> A.fi >> A.se;
      cin >> B.fi >> B.se;
      ran(vt, vector<pair<int, int>>(), vector<pair<int, int>>());
      cout << kq << nl;
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
