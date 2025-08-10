/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <climits>
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

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    for(int i = 0; i < n - 2; i++) {
        int cnt1 = 0;
        int cnte = 0;
        int ma = INT_MIN;
        int mi = INT_MAX;
        for(int j = i; j < i + 3; j++) {
            if(a[j] == -1) cnt1++;
            else {
                ma = max(a[j], ma);
                mi = min(a[j], mi);
                cnte++;
            }
        }
        if(cnt1 == 0) {
            for(int j = 0; j <= ma; j++) {
                if(a[j] != a[i] && a[j] != a[i + 1] && a[j] != a[i + 2]) {
                    if(a[j] != ma - mi) return cout << "NO" << nl, void();
                }
            }
        } else if(cnt1 == 1) {
            if(a[i] != a[i + 1] && a[i + 1] != a[i + 3]) {
                return cout << "NO" << nl, void();
            }
        } else if(cnt1 == 2) {
        }
    }
    cout << "YES" << nl;
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
