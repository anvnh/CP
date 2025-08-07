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
const int N = 1e5 + 10;

vector<int> graph[N];
vector<bool> vis(N, false);

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vector<bool> vis(N, false);
    vis[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x : graph[v])
        {
            if(!vis[x])
            {
                vis[x] = true;
                cout << x << " ";
                q.push(x);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true; 
    cout << u << " "; 

    for (int v : graph[u]) { 
        if (!vis[v]) {
            dfs(v);      
        }
    }
}

void solve()
{
    int n; cin >> n;
    for(int i = 0; i < 10; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    // Print the graph
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(int v : graph[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    // BFS
    bfs(1);
    cout << endl;
    // DFS
    dfs(1);

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
