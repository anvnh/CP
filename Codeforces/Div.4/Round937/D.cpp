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

int cal(int x, vector<int>&a)
{
    for(int i = 0; i < sz(a); i++)
    {
        while(x % a[i] == 0) x /= a[i];
    }
    return (x == 1) ? 1 : 0;
}

void solve()
{
    int n; cin >> n;
    vector<int> preset = {11, 10, 111, 110, 101, 100, 1111, 1110, 1101, 1100, 1011, 1010, 1001, 1000};
    string s = to_string(n);
    bool isFullBinary = true;
    for(auto x : s)
    {
        if(x > '1')
        {
            isFullBinary = false;
            break;
        }
    }
    if(isFullBinary)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        cal(n, preset) ? cout << "YES" << endl : cout << "NO" << endl;
        return;
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
