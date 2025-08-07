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
    int x, y, m; cin >> x >> y >> m;   
    ll res = 0;
    ll cnt = 0;
    for(int i = 1; i <= (m / min(x, y)); i++)
    {
        int t1 = i * min(x, y);
        if((m - t1) / max(x, y) + i > cnt)
        {
            cnt = (m - t1) / max(x, y) + i;
            res = max(res, 1ll * t1 + (m - t1) / max(x, y) * max(x, y));
        }


    }
    cout << res << endl;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
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
