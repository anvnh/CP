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
	int n, x; cin >> n >> x;
	vector<pair<int, int>> vp;
	for(int i=1; i<=n; i++)
	{
		int temp; cin >> temp;
		vp.push_back({temp, i});
	}
	sort(all(vp));
	for(int i=0; i<n; i++)
	{
		int l = 0, r = n - 1;
		while(l != r)
		{
			int target = x - vp[i].fi;
			if(l != i && r != i && vp[l].fi + vp[r].fi == target)
			{
				cout << vp[i].second << " " << vp[l].second << " " << vp[r].second << endl;
				return 0;
			}
			if(vp[l].fi + vp[r].fi < target) 
				l++;
			else 
				r--;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}