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

bool check(string a, string b) {
      if (a.size() != b.size()) return false;
      int diff = 0;
      for (int i = 0; i < max(a.size(), b.size()); i++) {
            if (a[i] != b[i]) diff++;
      }
      if (diff <= 1) return true;
      return false;
}

void solve() {
      string s; cin >> s;
      map<int, string> mp;
      mp[1] = "one";
      mp[2] = "two";
      mp[3] = "three";
      mp[4] = "four";
      mp[5] = "five";
      mp[6] = "six";
      mp[7] = "seven";
      mp[8] = "eight";
      mp[9] = "nine";
      mp[10] = "ten";
      mp[11] = "eleven";
      mp[12] = "twelve";
      mp[13] = "thirteen";
      mp[14] = "fourteen";
      mp[15] = "fifteen";
      mp[16] = "sixteen";
      mp[17] = "seventeen";
      mp[18] = "eighteen";
      mp[19] = "nineteen";
      mp[20] = "twenty";

      if (s.size() <= 2) {
            int k = stoi(s);
            return cout << mp[k], void();
      } else {
            for (int i = 1; i <= 20; i++) {
                  string k = mp[i];
                  if (check(k, s)) {
                        return cout << i, void();
                  }
            }
      }
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
