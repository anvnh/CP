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
	int ntest; cin >> ntest;
	while(ntest--)
	{
		int n, m; cin >> n >> m; 
		vector<int> a(n);
		for(int&v : a) cin >> v;
		vector<int> b(m);
		for(int&v : b) cin >> v;
		sort(rall(b));
		vector<int> res(n + m);
		merge(all(a), all(b), res.begin(), greater<int>());
		for(auto x : res) cout << x << " ";
		cout << endl;
	}
	return 0;
}