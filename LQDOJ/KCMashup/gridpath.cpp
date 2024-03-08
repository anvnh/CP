#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define ford(i, n) for (int i = (n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (a); i <= (b); ++i)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
const ll MOD = (1e9) + 7;
int a[1005][1005];
int dp[1005][1005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int n;
	cin >> n;
	dp[0][1] = 1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			char c; cin >> c;
			if(c == '.') a[i][j] = 1;
			else a[i][j] = -1;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i][j]) dp[i][j] = dp[i - 1][j]%MOD + dp[i][j - 1]%MOD;
			if(a[i][j] == -1) dp[i][j] = 0;
		}
	}
	cout << dp[n][n]%MOD;
	return 0;
}