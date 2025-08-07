/**
    Author: anvnh
    RyeNyn
**/

#include <algorithm>
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

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

struct SegmentTree {
    vector<int> tree;

    void init(int n) {
        int sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(2 * sz, 0);
    }

    void update(int pos, int val, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = max(tree[x], val);
            return;
        }
        int mid = (lx + rx) >> 1;
        if(pos < mid) {
            update(pos, val, 2 * x + 1, lx, mid);
        } else {
            update(pos, val, 2 * x + 2, mid, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    int query(int x, int l, int r, int lx, int rx) {
        if(lx >= r || rx <= l) return 0; // out range
        if(lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) >> 1;
        int lMax = query(2 * x + 1, l, r, lx, mid);
        int rMax = query(2 * x + 2, l, r, mid, rx);
        return max(lMax, rMax);
    }
};

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int&v : a) cin >> v;

    vector<ll> vals;
    for(int i = 0; i < n; i++) {
        vals.pb(a[i]);
        vals.pb(a[i] - k);
        vals.pb(a[i] + k);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    int N = sz(vals);
    SegmentTree tree;
    tree.init(N);

    int res = 1;

    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        int pos = (int)(lower_bound(all(vals), a[i]) - vals.begin());

        int lMax = 0;
        ll lVal = a[i] - k;
        int lPos = (int)(lower_bound(all(vals), lVal) - vals.begin());
        if(lPos >= 0) {
            lMax = tree.query(0, 0, lPos + 1, 0, N);
        }

        int rMax = 0;
        ll rVal = a[i] + k;
        int rPos = (int)(lower_bound(all(vals), rVal) - vals.begin());
        if(rPos < N) {
            rMax = tree.query(0, rPos, N, 0, N);
        }

        dp[i] = 1 + max(lMax, rMax);
        res = max(res, dp[i]);

        tree.update(pos, dp[i], 0, 0, N);
    }

    cout << res << nl;
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
