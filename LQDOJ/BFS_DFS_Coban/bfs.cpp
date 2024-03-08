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
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    BFS(s);
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            res.push_back(make_pair(dist[i], i));
        }
    }
    sort(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x.second << " " << x.first << endl;
    }
}
