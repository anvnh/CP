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
const int N = 2e5 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

vector<pair<int, int>> graph[N];
vector<bool> vis(N, false);
vector<ll> f(N, 0);

void dfs(int root) 
{
    stack<int> st;
    st.push(root);
    vis[root] = true;
    while (!st.empty())
    {
        int u = st.top(); st.pop();
        for(auto [v, w] : graph[u]){
            if(!vis[v]){
                vis[v] = true;
                f[v] = f[u] + w;
                st.push(v);
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;   
    FOR(i, 1, m)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].pb({v, w});
        graph[v].pb({u, -w});
    }
    FOR(i, 1, n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    FOR(i, 1, n) cout << f[i] << " ";
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
