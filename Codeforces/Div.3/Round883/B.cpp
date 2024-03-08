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
	fastio;
	int t; cin>>t;
	while(t--)
	{
		char a[3][3];
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				cin>>a[i][j];
			}
		}
		string res = "DRAW";
		if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != '.' || a[1][1] == a[2][0] && a[1][1] == a[0][2] && a[1][1] != '.')
		{
			cout<<a[1][1]<<endl;
			continue;
		}
		for(int i=0; i<3; i++)
		{
			if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][1] != '.')
			{
				res = a[i][1];
				break;
			}
		}
		for(int j=0; j<3; j++)
		{
			if(a[0][j] == a[1][j] && a[1][j] == a[2][j] && a[1][j] != '.')
			{
				res =  a[1][j];
				break;
			}
		}
		cout<<res;
		cout<<endl;
	}
}