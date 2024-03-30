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

const int inf = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q;
int a[maxn];
int st[4 * maxn];

void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i, int val)
{
    if(l > i || r < i) return;
    if(l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return inf;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while(q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) update(1, 1, n, x, y);
        else cout << get(1, 1, n, x, y) << endl;
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
