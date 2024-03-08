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
#define MAX_N 100005
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int ntest; cin>>ntest;
	while(ntest--)
	{
		int n, m; cin >> n >> m;
		string s; cin >> s;
		vector<vector<string>> a(m, vector<string>(3));
		for(int i=1; i<=m; i++)
		{
			cin >> a[i - 1][0] >> a[i - 1][1] >> a[i - 1][2];
		}
		
	}
	return 0;
}