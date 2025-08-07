#include <bits/stdc++.h>
#include <tuple>
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

bool compare_trip(tuple<int, int, int> a, tuple<int, int, int> b){
    int a1 = get<0>(a);
    int a2 = get<1>(a);
    int a3 = get<2>(a);
    int b1 = get<0>(b);
    int b2 = get<1>(b);
    int b3 = get<2>(b);

    return (a1 != b1 && a2 == b2 && a3 == b3)
        || (a1 == b1 && a2 != b2 && a3 == b3)
        || (a1 == b1 && a2 == b2 && a3 != b3);
}   

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> b;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - 2; i ++)
    {
        vector<int> c = {a[i], a[i + 1], a[i + 2]};
        b.pb(c);
    }
    sort(all(b));
    vector<vector<int>> c = b;
    // for(auto x : b)
    // {
    //     cout << "[ ";
    //     for(auto y : x) cout << y << " ";
    //     cout << "]";
    //     cout << endl;
    // }
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
