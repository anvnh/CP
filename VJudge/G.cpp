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
int maxn = 1000005;

vector<vector<int>> graph(maxn);
vector<bool> visited(maxn, false);
vector<int> deg(maxn, 0);
int cnt;

void dfs(int u)
{
    cnt++;
    visited[u] = true;
    for(int v : graph[u])
    {
        if(visited[v]) continue;
        else dfs(v);
    }
}

void solve()
{
    int n; cin >> n;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int u, v; cin >> u >> v;
        // u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    if(deg[1] == 1) {
        cout << 1;
        return;
    }
    else {
        for(int node : graph[1])
        {
            visited[1] = true;
            cnt = 0;
            dfs(node);
            // cout << cnt << endl;
            ans = max(ans, cnt);
        }
    }
    cout << n - ans << endl;
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
