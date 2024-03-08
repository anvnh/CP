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
    string a, b; cin >> a >> b;
    map<char, int> cnt_odd, cnt_even;
    for(int i = 1; i <= sz(a); i++)
    {
        if(i&1)
        {
            cnt_odd[a[i - 1]]++;
        }
        else cnt_even[a[i - 1]]++;
    }
    for(int i = 1; i <= sz(b); i++)
    {
        if(i&1)
        {
            cnt_odd[b[i - 1]]--;
        }
        else cnt_even[b[i - 1]]--;
    }
    for(auto x: cnt_odd)
    {
        if(x.se != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for(auto x : cnt_even)
    {
        if(x.se != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        // clock_t z = clock();
        solve();
        // debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
