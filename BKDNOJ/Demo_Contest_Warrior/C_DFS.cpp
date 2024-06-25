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
const int N = 1e5 + 5;

vector<int> adj[N];
vector<bool> vis(N);

int cnt = 0;

void dfs(int root)
{
    cnt++;
    vis[root] = true;
    for(auto x : adj[root])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
}

void solve()
{
    int n; cin >> n;   
    for(int i = 0; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cnt = 0;
            dfs(i);
            res = max(res, cnt);
        }
    }
    cout << res << endl;
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
