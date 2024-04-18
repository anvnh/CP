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
    string s; cin >> s;
    ll res = 0;
    for(int i = 0; i < sz(s); i++)
    {
        int cnt_O = 0, cnt_L = 0, cnt_P = 0;
        for(int j = i; j < sz(s); j++)
        {
            if(s[j] == 'O') cnt_O++;
            if(s[j] == 'L') cnt_L++;
            if(s[j] == 'P') cnt_P++;
            // cout << cnt_O << " " << cnt_L << " " << cnt_P << endl;
            if(cnt_O >= 3 || cnt_L >= 3 || cnt_P >= 3){
                res += sz(s) - j;
                break;
            }
        }
    }
    cout << res << endl;
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
