/**
    Author: anvnh
    Created: 2024-08-23 18:34:50
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
    std::cout << "}\n";
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

void solve()
{
    int n, x, y; cin >> n >> x >> y;
    vector<int> graph[n + 1];
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    // for(int i = 1; i < n; i++){
    //     cout << i << " : ";
    //     for(auto x : graph[i]) cout << x << " ";
    //     cout << nl;
    // }
    // direction from node x to y. Eg: 2 -> 1 -> 3 -> 4
    vector<int> path;
    vector<int> p(n + 1, 0);
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : graph[u])
        {
            if(p[v] == 0)
            {
                p[v] = u;
                q.push(v);
            }
        }
    }
    int cur = y;
    while(cur != x)
    {
        path.pb(cur);
        cur = p[cur];
    }
    path.pb(x); 
    reverse(all(path));
    for(auto x : path) cout << x << " ";
    cout << nl;
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
