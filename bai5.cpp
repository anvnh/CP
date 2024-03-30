#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

const int maxn = 1e6 + 10;
vector<bool> prime(maxn, 0);
vector<int> cnt(maxn, 0);

void erathos() {
  prime[0] = prime[1] = true;
  for (int i = 2; i <= sqrt(maxn); i++) {
    if (!prime[i]) {
      for (int j = i * i; j <= maxn; j += i)
        prime[j] = true;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  erathos();
  for (int i = 1; i <= maxn; i++)
    cnt[i] = cnt[i - 1] + (prime[i] == 0);
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    int left = cnt[i + n] - cnt[i];
    int right = n - left;
    if (i == 1)
      --left;
    else
      --right;
    res += 1ll * left * right;
  }
  cout << 1ll * n * (n - 1) * (n - 2) / 6 - res / 2 << endl;
}

signed main() {
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
