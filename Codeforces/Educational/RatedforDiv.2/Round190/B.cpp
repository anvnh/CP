/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
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

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> pre2(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre2[i + 1] = pre2[i] + (s[i] == '2' ? 1 : 0);
    for(auto x : pre2) cout << x << " ";
    cout << nl;

    vector<int> suf13(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
        suf13[i] = suf13[i + 1] + (s[i] == '1' || s[i] == '3' ? 1 : 0);
    for(auto x : suf13) cout << x << " ";
    cout << nl;

    int ma = 0;
    for (int k = 0; k <= n; k++)
        ma = max(ma , pre2[k] + suf13[k]);

    // cout << n - max_keep << "\n";
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
