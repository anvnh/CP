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
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(2));
	for(int i=1; i<=m; i++)
	{
		int u, v; cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	int q; cin >> q;
	while(q--)
	{
		int cnt = 0;
		int s, t; cin >> s >> t;
		for(auto i : a[s])
		{
			for(auto j : a[t])
			{
				if(i == j && i != 0 && j != 0) cnt++;
			}
		}
		cout << cnt; 
		cout << endl;
	}
}