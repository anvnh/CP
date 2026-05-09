/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define fastio                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
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

int prefix[3][1005][1005];
ll dp1[1005][1005];
ll dp2[1005][1005];

void solve() {
    int r, c; cin >> r >> c;
    int n; cin >> n;
    vector<string> grid(r);
    for(int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    string like; cin >> like;

    int fruit[n + 2];

    auto indx = [&](char c) {
        switch (c) {
            case 'S': return 0;
            case 'B': return 1;
            case 'R': return 2;
            default: return -1;
        }
    };

    auto query = [&](int f, int r1, int c1, int r2, int c2) {
        return prefix[f][r2][c2] - prefix[f][r1 - 1][c2] - prefix[f][r2][c1 - 1]
            + prefix[f][r1 -1 ][c1 - 1];
    };

    for(int f = 0; f < 3; f++) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                prefix[f][i][j] = 0;
            }
        }
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            int findex = indx(grid[i - 1][j - 1]);
            for (int f = 0; f < 3; f++) {
                prefix[f][i][j] = prefix[f][i - 1][j] + prefix[f][i][j - 1] - prefix[f][i - 1][j - 1]
                    + (findex == f ? 1 : 0);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        fruit[i] = indx(like[i - 1]);
        // fruit[1] = 0
        // fruit[2] = 1
        // fruit[3] = 2
    }

    for (int r1 = 1; r1 <= r; r1++){
        for (int c1 = 1; c1 <= c; c1++){
            bool k = query(fruit[n], r1, c1, r, c) > 0;
            dp1[r1][c1] = k ? 1 : 0;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int r1 = r; r1 >= 1; r1--) {
            for (int c1 = c; c1 >= 1; c1--) {
                ll val = 0;
                // hor cut
                for (int r2 = r1; r2 <= r - 1; r2++) {
                    if (query(fruit[i], r1, c1, r2, c) > 0) {
                        val = (val % MOD + dp1[r2+1][c1] % MOD) % MOD;
                    }
                }
                // ver cut
                for (int c2 = c1; c2 <= c - 1; c2++) {
                    if (query(fruit[i], r1, c1, r, c2) > 0) {
                        val = (val % MOD + dp1[r1][c2+1] % MOD) % MOD;
                    }
                }
                dp2[r1][c1] = val;
            }
        }

        for (int r1 = 1; r1 <= r; r1++) {
            for (int c1 = 1; c1 <= c; c1++){
                dp1[r1][c1] = dp2[r1][c1];
            }
        }
    }

    cout << dp1[1][1] << nl;
}


anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    ntest = 1;
    cin >> ntest;
    while (ntest--) {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
