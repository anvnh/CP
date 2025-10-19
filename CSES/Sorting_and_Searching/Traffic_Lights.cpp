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
    int x, n; cin >> x >> n;
    set<int> lights_pos{0, x};
    multiset<int> dist{x};
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        auto it1 = lights_pos.upper_bound(p);
        auto it2 = it1;
        it2--;
        dist.erase(dist.find(*it1 - *it2));
        dist.insert(*it1 - p);
        dist.insert(p - *it2);

        lights_pos.insert(p);

        auto ans = dist.end();
        ans--;
        cout << *ans << " ";
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
