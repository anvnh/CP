#include <algorithm>
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

ll binpow(int a, int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    ll res = binpow(a, b / 2);
    if(b&1) return res % MOD * res % MOD * a % MOD;
    return res % MOD * res % MOD;
}

void solve()
{
    int n; cin >> n;
    ll max_col = INT_MIN, max_row = INT_MIN;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    char c = '#';
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        ll res = 0;
        for(int j = 0; j <= n; j++) {
            if(a[i][j] == c) {
                cnt++;
            } else {
                if(cnt != 0) {
                    res = (res % MOD + binpow(cnt, cnt) % MOD) % MOD;
                    cnt = 0;
                }
                else cnt = 0;
            }
        }
        // cout << endl;
        // cout << res << endl;
        max_col = max(max_col, res);
    }

    for(int j = 0; j < n; j++)
    {
        int cnt = 0;
        ll res = 0;
        for(int i = 0; i <= n; i++) {
            if(a[i][j] == c) {
                cnt++;
            } else {
                if(cnt != 0) {
                    res = (res % MOD + binpow(cnt, cnt) % MOD) % MOD;
                    cnt = 0;
                }
                else cnt = 0;
            }
        }
        max_row = max(max_row, res);
    }

    cout << max_col << " " << max_row << endl;
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
