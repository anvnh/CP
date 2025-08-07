#include <bits/stdc++.h>
#include <numeric>
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
    vector<int> k(n);
    for(int&v : k) cin >> v;
    vector<int> ans(n);
    int tot_gcd = 1;
    for(int i = 1; i < 20; i++)
    {
        tot_gcd = (tot_gcd * i) / __gcd(tot_gcd, i);
    }
    for(int i = 0; i < n; i++)
    {
        ans[i] = tot_gcd / k[i];
    }
    if(accumulate(all(ans), 0LL) < tot_gcd)
    {
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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
