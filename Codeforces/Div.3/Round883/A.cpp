#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define MAX_N 100005
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		vector<pair<int, int>> vp;
		for(int i=0; i<n; i++)
		{
			int a, b; cin>>a>>b;
			vp.push_back({a, b});
		}
		sort(all(vp));
		int res = 0;
		for(auto x : vp)
		{
			if(x.ff > x.ss) res++;
		}
		cout<<res<<endl;
	}
}