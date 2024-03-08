#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

ll power(ll x, ll y, ll m)
{
    ll res = 1;
 
    x = x % m; 
 
    while (y > 0) {
       
        if (y & 1)
            res = (res * x) % m;
 
        y >>= 1; 
        x = (x * x) % m;
    }
    return res;
}

void solve()
{
    ll n, x, m; cin >> n >> x >> m;   
    cout << ((power(2, n, m) % m * x % m) % m + power(2, n, m) % m - 1) % m << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("FUNCT.INP", "r", stdin);
    freopen("FUNCT.OUT", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
