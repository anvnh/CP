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
    vector<int> a(n);
    int m = 0;
    for(int&v : a) {
        cin >> v;
        m = max(m, v);
    }
    vector<ll> cnt(1e5 + 5, 0);
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    vector<ll> dp(1e5 + 5);
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i <= m; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout << dp[m] << endl;
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
