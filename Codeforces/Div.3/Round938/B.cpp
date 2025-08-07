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
    int n, c, d; cin >> n >> c >> d;
    vector<int> a(n * n);
    for(int i = 0; i < n * n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    // for(auto x : a) cout << x << " ";
    // cout << endl;
    vector<int> b(n * n);
    b[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + d;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            b[i * n + j] = b[i * n + j - n] + c;
        }
    }
    sort(all(b));
    for(int i = 0; i < n * n; i++)
    {
        if(a[i] != b[i])
            return cout << "NO" << endl, void();
    }
    cout << "YES" << endl;
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
