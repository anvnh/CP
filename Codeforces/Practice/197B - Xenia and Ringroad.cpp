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


void solve()
{
    int n, m; 
    cin >> n >> m;
    vector<ll> a(m);
    for(auto&v : a) cin >> v;
    ll curr = 1;
    ll cnt = 0;
    for(int i = 0; i < m; i ++)
    {
        if(a[i] >= curr) {
            cnt += a[i] - curr;
        }
        else {
            cnt += n - curr + a[i];
        }
        curr = a[i];
    }
    cout << cnt << endl;
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
