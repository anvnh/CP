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

const int maxn = 1e3 + 5;


void solve()
{
    int n, m; cin >> n >> m;   
    vector<vector<int>> graph(maxn);
    vector<pair<int, int>> vp;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
    {
        vp.pb({i, sz(graph[i])});
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << vp[i].fi << " " << vp[i].se << endl;
    // }
    // cout << "_______________________________" << endl;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(vp[i].se == 1) cnt++;
    }
    int x = n - 1 - cnt;
    int y = cnt / x;
    cout << x << " " << y << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    // ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
