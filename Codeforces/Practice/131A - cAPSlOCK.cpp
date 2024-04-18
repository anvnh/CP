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
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	string s; cin >> s;
	bool check = true;
	if(s[0] <= 'z' && s[0] >= 'a')
	{
		for1(i, s.size() - 1)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				check = false;
				break;
			}
		}
		if(check) 
		{
			cout << char(s[0] - 32);
			for1(i, s.size() - 1)
			{
				cout << char(s[i] + 32);
			}
		}
		else cout << s;
	}
	else
	{
		bool check = true;
		for1(i, s.size() - 1)
		{
			if(s[i] <= 'z' && s[i] >= 'a')
			{
				check = false;
				break;
			}
		}
		if(check)
		{
			forn(i, s.size())
			{
				cout << char(s[i] + 32);
			}
		}
		else cout << s;
	}
	return 0;
}