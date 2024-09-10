/**
    Author: anvnh
    Created: 2024-08-12 16:06:21
**/

#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << "}\n";
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

void solve()
{
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a;
    REP(i, n) {
        int t; cin >> t;
        a.pb(make_pair(t, i + 1));
    }
    sort(all(a));
    for(int i = 0; i < n - 3; i++)
    {
        for(int j = i + 1; j < n - 2; j++)
        {
            int target = x - a[i].fi - a[j].fi;
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int sum = a[l].fi + a[r].fi;
                if (sum == target && l != i && l != j && r != i && r != j)
                {
                    cout << a[i].se << " " << a[j].se << " " << a[l].se << " " << a[r].se << nl;
                    return;
                }
                if (sum < target) l++;
                else r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

anvnh {
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
