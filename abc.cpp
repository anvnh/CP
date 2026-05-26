#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);
#define anvnh signed main(void)

template <typename T> void print(const T &t) {
    for (const auto &element : t) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
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

void dfs(int root, int par, int tot, vector<vector<int>> edges,
         vector<int> vertex, int &res) {
    int sum = vertex[root];
    for (int i = 0; i < (int)edges[root].size(); i++) {
        int v = edges[root][i];
        if (v != par) {
            dfs(v, root, tot, edges, vertex, res);
            sum += vertex[v];
        }
    }

    vertex[root] = sum;
    if (root != 1 && abs(tot - 2 * sum) < res) {
        res = abs(tot - 2 * sum);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> vertex(n + 1);
    vector<vector<int>> edges(n + 1);
    int tot = 0;

    for (int i = 0; i < n; i++) {
        cin >> vertex[i + 1];
        tot += vertex[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ":";
    //     for (auto x : edges[i])
    //         cout << x << " ";
    //     cout << nl;
    // }
    int res = INT_MAX;
    dfs(1, -1, tot, edges, vertex, res);
    cout << res << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--) {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
