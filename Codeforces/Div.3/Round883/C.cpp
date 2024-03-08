#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
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
void fastio(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}
int main()
{
	fastio();
	int ntest; cin >> ntest;
	while(ntest--)
	{
		int n, m, h; cin >> n >> m >> h;
		vector<int> rudolf(m + 1);
		for(int i=1; i<=m; i++)
		{
			cin>>rudolf[i];
		}
		sort(all(rudolf));
		int curr_rank = 1;
		ll solved = 0, time = 0, penalty = 0;
		for(int i=1; i<=m; i++)
		{
			if(rudolf[i] + time <= h)
			{
				time += rudolf[i];
				penalty += time;
				solved++;
			}
		}
		n -= 1;
		while(n--)
		{
			vector<int> partis; 
			for(int i=1; i<=m; i++)
			{
				int x; cin>>x;
				partis.push_back(x);
			}
			sort(all(partis));
			ll solved_p = 0, time_p = 0, penalty_p = 0;
			for(int i=0; i<m; i++)
			{
				if(partis[i] + time_p <= h)
				{
					time_p += partis[i];
					penalty_p += time_p;
					solved_p++;
				}
			}
			if(solved_p > solved)
			{
				curr_rank++;
			}
			else
			{
				if(solved_p == solved)
				{
					if(penalty_p < penalty) curr_rank++;
				}
			}
		}
		cout<<curr_rank<<endl;
	}
}