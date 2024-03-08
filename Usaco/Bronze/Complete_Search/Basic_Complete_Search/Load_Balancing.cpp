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

void solve()
{
    int n, b; cin >> n >> b;
    vector<pair<int, int>> coors(n);
    set<int> f_x, f_y;
    for(auto &x : coors) {
        cin >> x.fi >> x.se;
        f_x.insert(x.fi + 1);
        f_y.insert(x.se + 1);
    }
    int res = INT_MAX;
    int diff = INT_MAX;
    for(auto x : f_x)
    {
        for(auto y : f_y)
        {
            int reg1 = 0;
            int reg2 = 0;
            int reg3 = 0;
            int reg4 = 0;

            for(int i = 0; i < n; i++)
            {
                if(coors[i].fi < x && coors[i].se < y) reg1++;
                if(coors[i].fi < x && coors[i].se > y) reg2++;
                if(coors[i].fi > x && coors[i].se > y) reg3++;
                if(coors[i].fi > x && coors[i].se < y) reg4++;
            }
            res = min(res, max({reg1, reg2, reg3, reg4}));
        }
    }
    cout << res << endl;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
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
