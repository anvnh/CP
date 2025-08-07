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
    for (const auto& tmp : t) { 
        std::cout << tmp << " ";
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

struct Tree {
    int n;
    vector<int> tree;
    Tree(int N): n(N), tree(4 * N, INT_MAX) {}
    void build(int node, int st, int end, const vector<int>& f) {
        if(st == end) {
            tree[node] = f[st];
        } else {
            int mid = (st + end) >> 1;
            build(2 * node, st, mid, f);
            build(2 * node + 1, mid + 1, end, f);
            tree[node] = min(tree[2*node], tree[2 * node + 1]);
        }
    }
    int query(int node, int st, int end, int L, int R) {
        if(R < st || end < L) return INT_MAX;
        if(L <= st && end <= R) return tree[node];
        int mid = (st + end) >> 1;
        return min(query(2 * node, st, mid, L, R), query(2 * node + 1, mid + 1, end, L, R));
    }
};

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vector<int> p(n + 1), a(m + 2);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= m; i++) cin >> a[i];

    vector<int> nextp(n + 1);
    for(int i = 1; i < n; i++) {
        nextp[p[i]] = p[i + 1];
    }
    nextp[p[n]] = p[1];

    int def = m + 1;

    vector<int> lastpos(n + 1, def), idx(m + 2, def);
    for(int i = m; i >= 1; --i) {
        int x = a[i];
        int y = nextp[x];
        idx[i] = lastpos[y];
        lastpos[x] = i;
    }

    idx[def] = def;

    int log = 0;
    while((1 << log) <= n) log++;

    vector<vector<int>> up(log, vector<int>(m + 2, def));
    for(int i = 1; i <= m; i++) {
        up[0][i] = idx[i];
    }

    up[0][def] = def;

    for(int k = 1; k < log; k++) {
        for(int i = 1; i <= m + 1; i++) {
            int mid = up[k - 1][i];
            up[k][i] = (mid > m ? def : up[k - 1][mid]);
        }
    }

    vector<int> f(m + 2, def);
    for(int i = 1; i <= m; i++) {
        int cur = i;
        int s = n - 1;
        for(int k = 0; k < log && cur <= m && s > 0; k++) {
            if(s & (1 << k)) {
                cur = up[k][cur];
                if(cur > m) break;
            }
        }
        f[i] = (cur > m ? def : cur);
    }

    Tree tree(m);
    tree.build(1, 1, m, f);

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(r - l + 1 < n) {
            cout << 0 << nl;
            continue;
        }
        int minf = tree.query(1, 1, m, l, r);
        cout << (minf <= r ? 1 : 0) << nl;
    }
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
