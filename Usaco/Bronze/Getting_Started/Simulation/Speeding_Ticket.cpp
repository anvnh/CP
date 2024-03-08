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
    int n, m; cin >> n >> m;
    vector<int> segs(100, 0);
    int start = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        for(int j = start; j < start + a; j++)
        {
            segs[j] = b;
        }
        start += a;
    }
    int res = 0;
    start = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        // cout << a << " " << b << " " << start << endl;
        for(int j = start; j < start + a; j++)
        {
            // cout << segs[j] << " " << b << endl;
            res = max(res, b - segs[j]);
        }
        start += a;
    }
    cout << res << endl;
    
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
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
