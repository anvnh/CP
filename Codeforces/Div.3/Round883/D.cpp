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
#define double long double
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
	int t; cin>>t;
	while(t--)
	{
		ll n, d, h; cin >> n >> d >> h;
		vector<int> a(n);
		for(auto&v : a) cin >> v;	
		double ans = (double)n * (d * h)/2;
		for(int i=1; i<n; i++)
		{
			if(a[i] - (a[i - 1] + h) < 0)
			{
				double h_resi = 0;
				h_resi += abs(a[i] - a[i - 1] - h);
				double d_resi = (double)h_resi * d / h;
				ans -= (double)h_resi * d_resi / 2;
			}
		}
		cout<<fixed<<setprecision(6)<<(ans);
		cout<<endl;
	}
}