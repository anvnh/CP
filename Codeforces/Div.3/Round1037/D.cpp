/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <system_error>
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

struct st {
    int l, r, real;
};

void solve() {
    int n, k; cin >> n >> k;
    vector<st> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].real;
    }

    vector<st> inc, dec, nor;

    for(auto&v : a) {
        if(v.real > v.r) {
            inc.pb(v);
        } else if(v.real < v.l) {
            dec.pb(v);
        } else {
            nor.pb(v);
        }
    }

    sort(all(inc), [](const st&a, const st&b) {
        return a.r < b.r;
    });

    sort(all(dec), [](const st&a, const st&b) {
        return a.real > b.real;
    });

    int res = k;

    for(auto x : inc) {
        if(x.l <= res && res <= x.r) {
            res = x.real;
        }
    }

    vector<bool> vis(sz(nor), false);
    bool check = true;

    while(check) {
        check = false;
        int max_real = res;
        int max_idx = -1;

        for(int i = 0; i < sz(nor); i++) {
            if(!vis[i] && nor[i].l <= res && res <= nor[i].r && nor[i].real > max_real) {
                max_real = nor[i].real;
                max_idx = i;
                check = true;
            }
        }

        if(check) {
            vis[max_idx] = true;
            res = max_real;
        }
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
