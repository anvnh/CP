/**
    Author: anvnh
    RyeNyn
**/

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
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { 
    ((cout << args << " "), ...);
    cout << '\n';
}
#define ll long long
#define pb push_back
#define fi first
#define se second
#define forn(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _n; ++i)
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

const int MAX_N = 10005;
const int MAX_V = MAX_N + 5;

vector<int> graph[MAX_N];
int capacity[MAX_V][MAX_V];
int parent[MAX_V];
int n, nA, nB, nC;

bool bfs(int s, int t) {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(s);
    parent[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    
    return false;
}

int ford(int s, int t) {
    int max_flow = 0;
    
    while (bfs(s, t)) {
        int path_flow = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

void addEdge(int u, int v, int cap) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    capacity[u][v] = cap;
}

void solve() {
    cin >> n;
    cin >> nA >> nB >> nC;
    
    int s = 0, t = n + 4;
    for (int i = 0; i <= t; i++) {
        graph[i].clear();
    }
    memset(capacity, 0, sizeof(capacity));
    addEdge(s, n + 1, nA);
    addEdge(s, n + 2, nB);
    addEdge(s, n + 3, nC);
    
    for (int bd = 1; bd <= 3; bd++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int worker; get(worker);
            addEdge(n + bd, worker, 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        addEdge(i, t, 1);
    }
    
    put(ford(s, t));
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
