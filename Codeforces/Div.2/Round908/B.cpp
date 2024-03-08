#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define maxn 100005
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int ntest; cin >> ntest;
	while(ntest--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for(int&x : a) cin >> x;
		vector<int> b(n, 1);
		vector<vector<int>> index(105);
		for(int i = 0; i < n; i++)
			index[a[i]].push_back(i);
		int k = 2;
		for(auto x : index)
		{
			if(x.size() >= 2)
			{
				b[x[0]] = k;
				k++;
				if(k > 3) break;
			}
		}
		if(k <=  3) cout << "-1" << endl;
		else
		{
			for(int i = 0; i < n; i++) cout << b[i] << " ";
			cout << endl;
		}
	}
	return 0;
}