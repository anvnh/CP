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
    vector<int> c(3), m(3);
    for(int i = 0; i <  3; i++)
    {
        cin >> c[i] >> m[i];
    }
    for(int i = 0; i < 100; i++)
    {
        int buck1 = i % 3;
        int buck2 = (i + 1) % 3;
        int amount = min(m[buck1], c[buck2] - m[buck2]);
        m[buck1] -= amount;
        m[buck2] += amount;
    }
    cout << m[0] << endl << m[1] << endl << m[2] << endl;

}   

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
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
