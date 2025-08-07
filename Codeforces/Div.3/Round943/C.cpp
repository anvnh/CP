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

const int maxN = 1e3;
const int inf = -1e9;

void solve()
{
    int n; cin >> n;
    vector<int> x; 
    vector<int> a(n, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int k; cin >> k;
        x.pb(k);
    }
    a[0] = 1000;
    for(int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + x[i - 1];
    }
    for(auto x : a) cout << x << " ";
    cout << endl;
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
