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
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for(int v : a) {
            cnt += mid / v;
            if(cnt >= t) break;
        }
        if(cnt >= t) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
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
