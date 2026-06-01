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

void backtrack(int n, int open, int close, string s, vector<string>& res) {
    if((int)s.size() == n * 2) {
        res.push_back(s);
        return;
    }
    if(open == 0 || open < n) {
        backtrack(n, open + 1, close, s + '(', res);
    }
    if(close < n && close < open) {
        backtrack(n, open, close + 1, s + ')', res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(n, 0, 0, "", res);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<string> a = generateParenthesis(n);
    for(auto x : a) cout << x << " ";
    cout << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--) {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
