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

ll binpow(ll a, ll b) {
    if(b == 0) return 1;
    ll res = binpow(a, b / 2);
    if(b % 2) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

void solve()
{
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    for(auto x : mp)
    {
        ans = (ans + binpow(2, x.se) - 1 + MOD) % MOD;
    }
    cout << ans << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
