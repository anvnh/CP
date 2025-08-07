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

int maxn = 1000005;

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> data(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++)
        cin >> data[i].fi >> data[i].se;
    vector<int> res;
    int cnt = 0;
    int min_k = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(data[i].fi == 1)
        {
            if(mp[data[i].se] == 0) 
            {
                res.pb(0);
            }
            else {
                res.pb(1);
                cnt--;
                mp[data[i].se]--;
            }
        }
        if(data[i].fi == 2)
        {
            cnt++;
            min_k = max(min_k, cnt);
            mp[data[i].se]++;
        }
    }
    if(cnt == 0)
    {
        cout << min_k << endl;
        for(int i = sz(res) - 1; i >= 0; i--) cout << res[i] << " ";
    }
    else {
        cout << -1 << endl;
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
