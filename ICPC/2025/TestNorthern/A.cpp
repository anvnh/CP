//
// Created by vnhantyn on 10/25/25.
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

ll m;

struct Matrix {
      ll mat[2][2];
      Matrix() {
            mat[0][0] = 0; mat[0][1] = 0;
            mat[1][0] = 0; mat[1][1] = 0;
      }
};

Matrix multiply(Matrix A, Matrix B) {
      Matrix C;
      for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                  ll term1 = (A.mat[i][0] * B.mat[0][j]) % m;
                  ll term2 = (A.mat[i][1] * B.mat[1][j]) % m;
                  C.mat[i][j] = (term1 + term2 + m) % m;
            }
      }
      return C;
}

Matrix matrix_pow(Matrix A, ll p) {
      Matrix res;
      res.mat[0][0] = 1;
      res.mat[1][1] = 1;
      Matrix base = A;
      while (p > 0) {
            if (p % 2 == 1) {
                  res = multiply(res, base);
            }
            base = multiply(base, base);
            p /= 2;
      }
      return res;
}

void solve() {
      ll t;
      cin >> t >> m;
      Matrix M;
      M.mat[0][0] = 8 % m;
      M.mat[0][1] = (m - 5) % m;
      M.mat[1][0] = 1 % m;
      M.mat[1][1] = 0;
      Matrix M_res = matrix_pow(M, t);
      ll c = M_res.mat[1][0];
      ll d = M_res.mat[1][1];
      ll S_t = ( (c * 8) % m + (d * 2) % m ) % m;
      ll F = (S_t - 1 + m) % m;
      cout << F << nl;
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
            clock_t z = clock();
            solve();
            debug("Total Time: %.7f\n", static_cast<double>(clock() - z)/ CLOCKS_PER_SEC);
      }
      return 0;
}
