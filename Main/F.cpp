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
		for(int&v : a) cin >> v;
		vector<ll> cnt(n + 1, 0);
		for(auto x : a)
		{
			if(x <= n) cnt[x]++;
		}
		vector<ll> res(n + 1, 0);
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j += i)
			{
				res[j] += cnt[i];
			}
		}
		cout << *max_element(all(res));
		cout << endl;
	}

}
        
