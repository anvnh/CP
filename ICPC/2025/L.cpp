#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define pb push_back
#define faster                                                                 \
      ios_base::sync_with_stdio(0);                                            \
      cin.tie(0);
#define str string
#define pr pair
#define Lb lower_bound
#define Ub upper_bound
using vi = vector<int>;
#define fi first
#define se second
#define db double
#define ldb long double
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'
#define desc greater<int>()
#define foi(i, a, b) for (int i = a; i <= b; ++i)
#define fol(i, a, b) for (ll i = a; i <= b; ++i)
#define fo(i, a, b) for (int i = a; i >= b; --i)
#define each(x, a) for (auto &x : a)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define Danh_Hanma signed main()

#define file(name)                                                             \
      if (fopen(name ".inp", "r")) {                                           \
            freopen(name ".inp", "r", stdin);                                  \
            freopen(name ".out", "w", stdout);                                 \
      }

const int mod = 1e9 + 7;

ll solve(ll l, ll r) {
      auto div3 = [&](ll x) { return x / 3; };
      ll dem = div3(r) - div3(l - 1);
      if (l <= 3 && r >= 3)
            dem--;
      if (l <= 9 && r >= 9)
            dem--;
      return dem;
}

Danh_Hanma {
      int q;
      cin >> q;
      while (q--) {
            ll l, r;
            cin >> l >> r;
            cout << solve(l, r) << endl;
      }
      return 0;
}
