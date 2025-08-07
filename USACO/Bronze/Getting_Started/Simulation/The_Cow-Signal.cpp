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
    int m, n, k; 
    cin >> m >> n >> k;
    vector<vector<string>> v;
    for(int i = 0; i < m; i++)
    {
        string s; cin >> s;
        string tmp = "";
        for(char c : s)
        {
            tmp += string(k, c);
        }
        for(int j = 0; j < k; j++)
        {
            v.push_back({tmp});
        }
    }
    for(auto x : v)
    {
        cout << x[0] << endl;
    }
}   

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
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
