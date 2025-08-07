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
    vector<string> equals1 = {"AB", "BC", "CD", "DE", "EA"};
    vector<string> equals2 = {"AD", "AC", "BE", "BD", "CE", "CA"};
    for(string&s : equals1) sort(all(s));
    for(string&s : equals2) sort(all(s));
    // for(auto x : equals1) cout << x << " ";
    // cout << endl;
    // for(auto x : equals2) cout << x << " ";
    // cout << endl;
    string s; cin >> s;
    string t; cin >> t;
    sort(all(s));
    sort(all(t));
    if(s == t)
    {
        cout << "Yes" << endl;
        return;
    }
    for(auto x : equals1)
    {
        if(s == x)
        {
            for(auto y : equals1)
            {
                if(t == y)
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    for(auto x : equals2)
    {
        if(s == x)
        {
            for(auto y : equals2)
            {
                if(t == y)
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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
