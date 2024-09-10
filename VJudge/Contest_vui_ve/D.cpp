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

struct edg {
    ll to;
    ll w;
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(ll&v : a) cin >> v;
    vector<vector<edg>> g(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vector<ll> dist(2e5 + 10, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[0] = a[0];
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        ll d = pq.top().fi;
        ll node = pq.top().se;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto edge : g[node]) {
            ll new_d = d + edge.w + a[edge.to];
            if (new_d < dist[edge.to]) {
                dist[edge.to] = new_d;
                pq.push({new_d, edge.to});
            }
        }
    }
    for(int i = 1; i < n; i++) cout << dist[i] << " ";
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
