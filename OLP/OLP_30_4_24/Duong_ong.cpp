#include <algorithm>
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
const int maxN = 1e5 + 7;

int n, m, comp = 0, k;
vector<bool> visited(maxN, false);
vector<int> graph[maxN];

void bfs(int root) 
{
    comp++;
    visited[root] = true;
    queue<int> q;
    q.push(root);
    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for(auto v : graph[u]) {
            if(!visited[v]) 
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}   

void solve()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]) bfs(i);
    }
    cout << comp << endl;
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
