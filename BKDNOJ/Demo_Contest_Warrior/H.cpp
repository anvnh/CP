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
    string s; cin >> s;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(s.length() + 1, s.length() + 1);
    dp[0] = 0;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < n; j++) {
            if (a[j].length() <= i && s.substr(i - a[j].length(), a[j].length()) == a[j]) {
                dp[i] = min(dp[i], dp[i - a[j].length()] + 1);
            }
        }
    }

    cout << dp[s.length()] << endl;
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
