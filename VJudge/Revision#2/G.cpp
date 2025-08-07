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
    int n, k; cin >> n >> k;
    map<int, int> mp_1;
    map<int, int> mp_2;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp_1[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp_2[x]++;
    }
    int ans_0 = 0;
    int ans_1 = 0;

    for(auto x : mp_1)
    {
        if(mp_1[x.fi] > 0 && mp_1[k - x.fi] > 0)
        {
            ans_0 += (mp_1[x.fi] * mp_1[k - x.fi]);
            mp_1[x.fi] = 0;
            mp_1[k - x.fi] = 0;
        }
    }
    for(auto x : mp_2)
    {
        if(mp_2[x.fi] > 0 && mp_2[k - x.fi] > 0)
        {
            ans_1 += (mp_2[x.fi] * mp_2[k - x.fi]);
            mp_1[x.fi] = 0;
            mp_2[k - x.fi] = 0;
        }
    }
    if(ans_0 == ans_1)
    {
        cout << "Draw" << endl;
    }
    else if(ans_0 > ans_1)
    {
        cout << "Mahmoud" << endl;
    }
    else
    {
        cout << "Bashar" << endl;
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
