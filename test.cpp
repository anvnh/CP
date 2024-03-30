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

const int LIM = 2e6 + 16;
int dem[LIM + 5];
bool pr[LIM + 5];

void solve() {
    int n;
    cin >> n;
    int64_t rev = 0;
    for(int i = 1; i <= n; i++) {
        int Left = dem[i + n] - dem[i];
        int Right = n - Left;
        if (i == 1)
          --Left;
        else
          --Right;
        rev += 1ll * Left * Right;
    }
    cout << 1ll * n * (n - 1) * (n - 2) / 6 - rev / 2 << '\n';
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    //erathos
    pr[0] = pr[1] = 1;
    for (int i = 2; i <= sqrt(LIM); i++)
    {
        if (!pr[i])
        {
            for (int j = i * i; j <= LIM; j += i)
                pr[j] = 1;
        }
    }
    for(int i = 1; i <= LIM; i++)
    {
        dem[i] += dem[i - 1] + (pr[i] == 0);
    }
    while (tt--) {
        solve();
    }
}
