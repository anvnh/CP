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
	set<ll> check;
	for(int k=2; k<=1000; k++)
	{
		ll value = 1 + k;
		ll K = k * k;
		for(int i=1; i<=100; i++)
		{
			if(value > (1e6))
			{
				break;
			}
			value += K;
			check.insert(value);
			K *= k;
		}
	}
	int t; cin>>t;
	while(t--)
	{
		int n; cin >> n;
		if(check.count(n)) cout<<"YES";
		else cout<<"NO";
		cout << endl;
	}
	return 0;
}