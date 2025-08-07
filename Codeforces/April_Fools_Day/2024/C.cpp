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
    if(n == 0) cout << 10;
    else if(n == 1) cout << 10;
    else if(n == 2) cout << 8;
    else if(n == 3) cout << 9;
    else if(n == 4) cout << 8;
    else if(n == 5) cout << 7;
    else if(n == 6) cout << 7;
    else if(n == 7) cout << 7;
    else if(n == 8) cout << 7;
    else if(n == 9) cout << 0;
    else if(n == 10) cout << 9;
    else if(n == 11) cout << 6;
    else if(n == 12) cout << 8;

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
