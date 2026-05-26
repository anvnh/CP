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

void backtrack(int indx, string digits, string comb, vector<string> vs,
               vector<string> &res) {
    if (indx == (int)digits.size()) {
        res.push_back(comb);
        return;
    }

    string letters = vs[digits[indx] - '0'];
    for (char letter : letters) {
        backtrack(indx + 1, digits, comb + letter, vs, res);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> vs = {" ",   "#",   "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    backtrack(0, digits, "", vs, res);
    return res;
}

void solve() {
    string s;
    cin >> s;
    vector<string> a = letterCombinations(s);
    for (auto x : a)
        cout << x << " ";
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
