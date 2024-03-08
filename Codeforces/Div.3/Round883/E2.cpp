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
set<ll> check;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	for(ll k = 2; k <= 1000000; ++k) 
	{
		ll value = 1 + k;
		ll p = k*k;
		for (int i = 3; i <= 63; ++i) 
		{
			value += p;
			if (value > 1e18) break;
			check.insert(value);
			if (p > (1e18) / k) break;
			p *= k;
		}
	}
	int ntest; cin >> ntest;
	while(ntest--)
	{
		ll n; cin>>n;
		if (n < 7)
		{
			cout<<"NO"<<endl;
			continue;
		}
	
		ll k = floor(sqrt(n - 1));
		if(k * (k + 1) == (n - 1) || (k - 1) * k == (n - 1))
			{
				cout<<"YES"<<endl;
				continue;
			}
	
		if (check.count(n)) cout << "YES" << endl;
		else cout<<"NO"<<endl;
	}
}