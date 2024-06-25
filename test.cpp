/**
    Author: anvnh
    Created: 2024-06-12 22:29:04
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

void solve()
{
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < 2 * n - 1; i++)
    {
        int x; cin >> x;
        res ^= x;
    }
    cout << res << "\n";
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    solve();
    return 0;
}
