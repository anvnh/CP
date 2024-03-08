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
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	fastio;
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> vv(10);
    set<int> digits;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int indx = x/10;
        vv[indx].pb(x);
        digits.insert(indx);
    }
    for(vector<int>&x : vv) sort(all(x));
    print(digits);
    for(vector<int>&x : vv)
    {
        for(auto tmp : x) cout << tmp << " ";
        cout << endl;
    }

	return 0;
}
