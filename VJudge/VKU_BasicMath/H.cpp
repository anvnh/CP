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
    int x, y, z; cin >> x >> y >> z;
    if(x == y && y == z)
    {
        cout << "YES" << endl;
        cout << x << " " << x << " " << x << endl;
        return;
    }
    if(x == y && x > z)
    {
        cout << "YES" << endl;
        cout << x << " " << z << " " << z << endl;
        return;
    }
    if(x == z && x > y)
    {
        cout << "YES" << endl;
        cout << x << " " << y << " " << y << endl;
        return;
    }
    if(y == z && y > x)
    {
        cout << "YES" << endl;
        cout << y << " " << x << " " << x << endl;
        return;
    }
    cout << "NO" << endl;
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
