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
    int N, R, Q;
    double P;
    cin >> N >> R >> Q >> P;

    vector<pair<int, int>> requests(R);
    for (int i = 0; i < R; ++i) {
        cin >> requests[i].fi >> requests[i].se;
    }

    sort(all(requests));

    multiset<int> ends;
    int notok = 0;
    int ok = 0;

    for (const auto[x, y] : requests) {
        while (!ends.empty() && *ends.begin() <= x) 
        {
            ends.erase(ends.begin());
        }
        if (ends.size() < Q) 
        {
            ends.insert(y);
            ok++;
        } 
        else 
        {
            notok++;
        }
    }

    double per = (double)notok / R * 100.0;
    cout << ok << "/" << R << ": ";
    cout << (per > P ? "Yes" : "No") << endl;
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
