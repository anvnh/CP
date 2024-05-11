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
    int n, k, Pb, Ps;      
    cin >> n >> k >> Pb >> Ps;
    vector<int> p(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int b_curr = 0, s_curr = 0;
    b_curr += a[Pb];
    s_curr += a[Ps];
    k -= 1;
    while(k--)
    {
        if(k&1) // Bodya
        {
            if(a[Pb] < a[p[Pb]]) Pb = p[Pb];
            b_curr += a[Pb];
        }
        else  // Sasha
        {
            if(a[Ps] < a[p[Ps]]) Ps = p[Ps];
            s_curr += a[Ps];
        }
    }
    cout << b_curr << " " << s_curr << endl;
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
