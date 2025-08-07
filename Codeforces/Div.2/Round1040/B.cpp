/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <cstdlib>
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
    int n, s; cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    for(int&v : a) {
        cin >> v;
        sum += v;
    }
    if(sum > s) {
        for(auto x : a) cout << x << " ";
    } else {
        int tmp = s - sum;

        if(tmp == 1) {
            int cnt0 = 0, cnt1 = 0, cnt2 = 0;
            for (int x : a) {
                if (x == 0) cnt0++;
                else if (x == 1) cnt1++;
                else if (x == 2) cnt2++;
            }
            for (int i = 0; i < cnt0; ++i) cout << "0 ";
            for (int i = 0; i < cnt2; ++i) cout << "2 ";
            for (int i = 0; i < cnt1; ++i) cout << "1 ";
        } else {
            cout << -1;
        }
    }
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
