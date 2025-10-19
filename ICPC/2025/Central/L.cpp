//
// Created by vnhantyn on 10/19/25.
//
/**
 * Author: anvnh
 * RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
// #define INF 0x3f3f3f3f
const ll INF = 1e18;

void solve() {
      ll n, m, v;
      cin >> n >> m >> v;
      vector<vector<pair<ll ,ll>>> g(n+1);
      for (int i = 0; i < m; ++i) {
            ll u, v; ll w;
            cin >> u >> v >> w;
            // g[u].emplace_back(v,w);
            // g[v].emplace_back(u,w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
      }
      ll a, b;
      cin >> a >> b;

      for (int i = 1; i <= n; i++) {
            cout << i << ":";
            for (auto y : g[i]) cout << y.fi << " " << y.se << " ";
            cout << nl;
      }

      vector<ll> dist(n+1, INF);
      vector<ll> par(n+1, -1);
      priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
      dist[a] = 0;
      pq.push({0, a});

      while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            if (u == b) break;
            for (auto [v, w] : g[u]) {
                  if (dist[v] > d + w) {
                        dist[v] = d + w;
                        cout << g[v].size() << nl;
                        if (g[v].size() >= 3) {
                              dist[v] = dist[v] + (g[v].size() / 2 - 2) * v;
                        }
                        par[v] = u;
                        pq.emplace(dist[v], v);
                  }
            }
      }

      vector<int> path;
      for (int v = b; v != -1; v = par[v]) path.push_back(v);
      reverse(path.begin(), path.end());

      cout << fixed << setprecision(6);
      // cout << dist[b] << " " << v << nl;
      dist[b] = dist[b] - (g[b].size() - 2);
      cout << (static_cast<float>(dist[b]) / static_cast<float>(v)) << nl;
      for (size_t i = 0; i < path.size(); ++i) {
            if (i) cout << " ";
            cout << path[i];
      }
      cout << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      fastio
      int ntest = 1;
      // cin >> ntest;
      while (ntest--) {
            solve();
      }
      return 0;
}
