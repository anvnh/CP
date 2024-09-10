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
    vector<vector<char>> a(2 * n, vector<char>(2 * n, '.'));
    for(int i = 0; i < 2 * n; i+=4)
    {
        for(int j = 0; j < 2 * n; j += 4)
        {
            a[i][j] = '#';
            a[i][j + 1] = '#';
        }
    }
    for(int i = 1; i < 2 * n; i+=4)
    {
        for(int j = 0; j < 2 * n; j += 4)
        {
            a[i][j] = '#';
            a[i][j + 1] = '#';
        }
    }
    for(int i = 2; i < 2 * n; i+=4)
    {
        for(int j = 2; j < 2 * n; j += 4)
        {
            a[i][j] = '#';
            a[i][j + 1] = '#';
        }
    }
    for(int i = 3; i < 2 * n; i+=4)
    {
        for(int j = 2; j < 2 * n; j += 4)
        {
            a[i][j] = '#';
            a[i][j + 1] = '#';
        }
    }
    for(int i = 0; i < 2 * n; i++)
    {
        for(int j = 0; j < 2 * n; j ++)
        {
            cout << a[i][j];
        }
        cout << endl;
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
