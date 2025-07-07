#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void dfs(int root, vector<vector<int>>& edge, vector<bool>& visited, vector<char>& nodes) {
    visited[root] = true;
    cout << nodes[root] << " ";

    for (int v : edge[root]) {
        if (!visited[v]) {
            dfs(v, edge, visited, nodes);
        }
    }
}

void bfs(int root, vector<vector<int>>& edge, vector<bool>& visited, vector<char>& nodes) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << nodes[u] << " ";
        for(int v : edge[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> edge(n + 1);
    vector<bool> visited(n + 1, false);
    vector<char> nodes(n + 1);
    map<char, int> node_map;

    int node_counter = 1;

    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;

        if (node_map.find(u) == node_map.end()) {
            node_map[u] = node_counter++;
        }
        if (node_map.find(v) == node_map.end()) {
            node_map[v] = node_counter++;
        }

        int u_index = node_map[u];
        int v_index = node_map[v];

        edge[u_index].push_back(v_index);
        edge[v_index].push_back(u_index);
    }

    for (auto& p : node_map) {
        nodes[p.second] = p.first;
    }

    dfs(1, edge, visited, nodes);

    fill(visited.begin(), visited.end(), false);
    cout << nl;

    bfs(1, edge, visited, nodes);
}

anvnh {
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
