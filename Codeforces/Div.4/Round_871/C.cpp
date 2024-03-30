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
    int n; cin >> n;
    vector<pair<int, string>> vp10;
    vector<pair<int, string>> vp01;
    vector<pair<int, string>> vp11;
    for(int i = 0; i < n; i++) 
    {
        int x; string y;
        cin >> x >> y;
        if(y[0] == '1' && y[1] == '0')
            vp10.pb({x, y});
        if(y[0] == '0' && y[1] == '1')
            vp01.pb({x, y});
        if(y[0] == '1' && y[1] == '1')
            vp11.pb({x, y});
    }
    sort(all(vp01));
    sort(all(vp10));
    sort(all(vp11));
    if(sz(vp11) == 0)
    {
        if(sz(vp01) != 0 && sz(vp10) != 0)
        {
            cout << vp01[0].fi + vp10[0].fi <<  endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    else 
    {
        if(sz(vp01) != 0 && sz(vp10) != 0)
        {
            cout << min(vp01[0].fi + vp10[0].fi, vp11[0].fi) << endl;
            return;
        }
        cout << vp11[0].fi << endl;
        return;
    }
}

signed main()
{
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
