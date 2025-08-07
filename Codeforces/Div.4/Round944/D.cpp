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
    vector<string> cut;
    int i = 0;
    while(i < sz(s))
    {
        int j = i;
        string t = "";
        while(s[j] == s[i] && j < sz(s)) {
            t += s[j];
            j++;
        }
        cut.pb(t);
        i = j;
    }
    // for(auto x : cut) cout << x << " ";
    int res = sz(cut);
    // cout << res << endl;
    bool c01 = false, c10 = false;
    char c = cut[0][0];
    int pos;
    for(int i = 1; i < sz(cut); i++) 
    {
        if(cut[i][0] != c) 
        {
            if(c == '1') c10 = true;
            else  c01 = true;
            res--;
            pos = i;
            break;
        }
    }
    if(sz(cut) - 2 > 0)
    {
        if(c10) c01 = true;
        else if(c01) c10 = true;
    }
    if(c10 && !c01) cout << res + 1 << endl;
    else cout << res << endl;
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
