/**
    Author: anvnh
    RyeNyn
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
#define INF 0x3f3f3f3f

struct Pair {
    int a, b, index;
    int len() {
        return b - a;
    }
};

struct Union {
    vector<int> par, rank;
    Union(int n): par(n), rank(n, 0) {
        iota(all(par), 0);
    }
    int find(int x) {
        if(par[x] != x) par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vector<Pair> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i].a >> s[i].b;
        s[i].index = i + 1;
    }

    sort(all(s), [](Pair& p1, Pair& p2) {
        return p1.len() > p2.len();
    });

    Union u(2 * n + 5);
    vector<int> sec;

    for (auto &p : s) {
        if (u.unite(p.a, p.b)) {
            sec.pb(p.index);
        }
    }
    
    cout << sz(sec) << nl;
    for(auto x : sec) cout << x << " ";
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
