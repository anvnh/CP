#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 2004010501
#define maxn 200005
#define INF 10000007
vector<vector<ll>> adj(maxn);
vector<bool> visited(maxn, false);
vector<int> dist(maxn);
void BFS(int root)
{
    visited[root] = true;
    dist[root] = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto v : adj[node])
        {
            if (visited[v] == true)
                continue;
            dist[v] = dist[node] + 1;
            q.push(v);
            visited[v] = true;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS(1);
    if (!visited[n])
    {
        cout << "IMPOSSIBLE";
        return;
    }
}