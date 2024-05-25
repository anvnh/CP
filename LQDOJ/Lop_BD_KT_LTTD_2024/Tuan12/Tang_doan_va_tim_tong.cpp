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

int n, Q;
vector<ll> a(N);

struct Node {
    ll sum, lazy;
} nodes[4 * N];

void build(int id, int l, int r)
{
    if (l == r) {
        nodes[id] = {a[l], 0};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    nodes[id].sum = nodes[id * 2].sum + nodes[id * 2 + 1].sum;
}

void lazy_update(int id, int l, int r)
{
    // ll t = nodes[id].lazy;
    // nodes[id * 2].lazy += t;
    // nodes[id * 2].sum += t;
    // nodes[id * 2 + 1].lazy += t;
    // nodes[id * 2 + 1].sum += t;
    // nodes[id].lazy = 0;

    int mid = (l + r) / 2;
    nodes[id * 2].sum += nodes[id].lazy * (mid - l + 1);
    nodes[id * 2].lazy += nodes[id].lazy;
    nodes[id * 2 + 1].sum += nodes[id].lazy * (r - mid);
    nodes[id * 2 + 1].lazy += nodes[id].lazy;
    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    if(v < l || u > r) return;
    if(u <= l && v >= r) {
        // nodes[id].lazy += sum;
        // nodes[id].sum += sum;
        nodes[id].sum += 1LL * val * (r - l + 1);
        nodes[id].lazy += val;
        return;
    }
    lazy_update(id, l, r);
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    nodes[id].sum = nodes[id * 2].sum + nodes[id * 2 + 1].sum;
}

ll get(int id, int l, int r, int u, int v) 
{
    if(v < l || u > r) return 0;
    if(l >= u && r <= v) return nodes[id].sum;
    lazy_update(id, l, r);
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve()
{
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(Q--)
    {
        int q, l, r, w;
        cin >> q >> l >> r;
        if(q == 1) {
            cin >> w;
            update(1, 1, n, l, r, w);
        } else {
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
