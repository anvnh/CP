#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

void solve()
{
    int n; cin >> n;
    vector<ll> h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<ll> dp(n + 1);
    dp[0] = 0;
    ll a = h[1];
    ll b = -h[1];
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], a - h[i]);
        dp[i] = max(dp[i], b + h[i]);
        dp[i] = max(dp[i], 1ll * 0);
        a = max(a, dp[i] + h[i + 1]);
        b = max(b, dp[i] - h[i + 1]);
    }
    cout << dp[n] << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
