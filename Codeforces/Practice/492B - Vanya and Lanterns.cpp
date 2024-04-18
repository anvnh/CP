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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int n, l; cin >> n >> l;
	vector<int> a(n);
	for(int& v : a) cin >> v;
	sort(all(a));
	int max_dist = 0;
	for(int i=0; i + 1 < n; i++)
	{
		max_dist = max(max_dist, abs(a[i] - a[i + 1]));
	}
	double res = max((double)max_dist / 2, max((double)a[0] - 0, (double)(l - a[n - 1])));
	cout << fixed << setprecision(6) << res;
}