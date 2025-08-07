#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

const int N = 1e5 + 10;
const int INF = 1e9 + 7;

int n, Q;
vector<int> a(N);

struct Node{
    int val, lazy;
} nodes[4 * N];

void build(int id, int l, int r)
{
    if(l == r) 
    {
        nodes[id].val = a[l];
        nodes[id].lazy = -1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);

}

void lazy_update(int id)
{
    ll t = nodes[id].lazy;
    if(nodes[id].lazy == -1) return;
    nodes[id * 2].lazy = t;
    nodes[id * 2].val = t;
    nodes[id * 2 + 1].lazy = t;
    nodes[id * 2 + 1].val = t;
    nodes[id].lazy = -1;
}

void update(int id, int l, int r, int u, int v, int val) 
{
    if(v < l || u > r) return;
    if(u <= l && r <= v) {
        nodes[id].val = val;
        nodes[id].lazy = val;
        return;
    }
    int mid = (l + r) >> 1;

    lazy_update(id); // Day gia tri lazy propagation xuong
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

ll get(int id, int l, int r, int u, int v)
{
    if(v < l || u > r) return -INF;
    if(u <= l && r <= v) return nodes[id].val;
    int mid = (l + r) >> 1;
    lazy_update(id);

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
    }
    // cout << n << " " << Q << endl;
    // for(int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << endl;
    // build(1, 1, n);
    while(Q--)
    {
        int q, l, r, w;
        cin >> q >> l >> r;
        if(q == 1) {
            cin >> w;
            update(1, 1, n, l, r, w);
        }
        else {
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}

signed main()
{
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

