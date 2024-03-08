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
#define maxn 10000000
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
const ll MOD = (1e9) + 7;
bool prime[maxn + 1];
void sieve()
{
    for(int i = 0; i <= maxn; i++)
    {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(maxn); i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= maxn; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	fastio;
    sieve();
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n + 1);
    b[0] = 0;
    for(ll&v : a) cin >> v;
    for(ll i = 0; i < n; i++)
    {
        b[i + 1] = b[i] + a[i];
    }
    while(m--)
    {
        int u, v; cin >> u >> v;
        ll t = b[v] - b[u - 1];
        if(t >= 0)
        {
            cout << prime[t] << endl;
        }
        else cout << 0 << endl;
    }
	return 0;
}
