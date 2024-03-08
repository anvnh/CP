#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define ford(i, n) for (int i = (n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (a); i <= (b); ++i)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
const ll MOD = (1e9) + 7;
signed main()
{
	fastio;
	int ntest; cin >> ntest;
	while(ntest--)
	{
		string s; cin >> s; 
		string ans = "";
		vector<int> low, high;
		vector<int> mk(sz(s), 1);
		for(int i = 0; i < sz(s); i++)
		{
			if(s[i] <= 'z' && s[i] >= 'a' && s[i] != 'b') {low.push_back(i); continue;}
			if(s[i] <= 'Z' && s[i] >= 'A' && s[i] != 'B') {high.push_back(i); continue;}
			if(s[i] == 'b')
			{
				if(!low.empty())
				{
					mk[low.back()]--;
					low.pop_back();
					continue;
				}
				else continue;
			}
			if(s[i] == 'B')
			{
				if(!high.empty())
				{
					mk[high.back()]--;
					high.pop_back();
					continue;
				}
				else continue;
			}
		}
		for(int i = 0; i < sz(s); i++)
		{
			if(mk[i] != 0 && s[i] != 'b' && s[i] != 'B') ans += s[i];
		}
		cout << ans << endl;
	}
	return 0;
}

