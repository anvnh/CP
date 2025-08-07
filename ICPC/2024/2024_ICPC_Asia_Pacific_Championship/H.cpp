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
    vector<pair<int, int>> a;
    int max_0 = 0, max_1 = 0;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        int cnt_0 = 0, cnt_1 = 0;
        for(int j = 0; j < sz(s); j++)
        {
            if(s[j] == '0') cnt_0++;
            else cnt_1++;
        }
        max_0 = max(max_0, cnt_0);
        max_1 = max(max_1, cnt_1);
        a.pb({cnt_0, cnt_1});
    }
    // sort(all(a));
    for(auto x : a) cout << x.fi << " " << x.se << endl;
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
