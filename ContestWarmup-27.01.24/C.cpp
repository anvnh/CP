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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.pb(make_pair(x, i + 1));
    }
    sort(all(a));
    k *= 2;
    for(int i = 0, j = n - 1; i < j;)
    {
        if(a[i].fi + a[j].fi == k) 
        {
            cout << a[i].se << " " << a[j].se << endl;
            return 0;
        }
        if(a[i].fi + a[j].fi < k) i++;
        if(a[i].fi + a[j].fi > k) j--;
    }
    cout << 0;
	return 0;
}
