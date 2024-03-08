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
int n, a, b, c;
int dp[4005];
#define MAX(a, b, c) max(a, max(b, c))
int f(int x)
{
    if (x == 0) return 0;
    if (x < 0 || (x > 0 && x < a && x < b && x < c)) return 0xACCE97ED;
    if (!dp[x]) dp[x] = MAX(f(x-a),f(x-b),f(x-c)) + 1;
    return dp[x];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int ntest = 1;
	while(ntest--)
	{
		cin >> n >> a >> b >> c; 
		cout << f(n);
	}
	return 0;
}