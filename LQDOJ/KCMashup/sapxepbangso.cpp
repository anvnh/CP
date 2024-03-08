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
ll Pow(ll a, ll b)
{
	return a*a + b*b;
}
ll binarySearch(ll i, ll left, ll right, ll target)
{
	while(left <= right)
	{
		ll mid = (left + right)/2;
		ll temp = Pow(i, mid);
		if(temp == target) return mid;
		if(temp < target) left = mid + 1;
		else right = mid - 1;
	}
	return right;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	ll n, m, k; cin >> n >> m >> k;
	ll l = 0, r = Pow(n, m);
	while(l <= r)
	{
		ll mid = (l + r)/2;
		ll j = max(m, n);
		ll cnt = 0;
		for(ll i=1; i<=min(m, n); i++)
		{
			j = binarySearch(i, 1, j, mid);
			cnt += j;
		}
		if(cnt < k) 
			l = mid + 1;
		else 
			r = mid - 1;
	}
	cout << l;
}