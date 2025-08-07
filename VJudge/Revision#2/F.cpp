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
    int n; cin >> n;
    string s; cin >> s;
	ll a = 0, b = 0, c = 0, d = 0, e = 0;
    for(int i = 0; i < sz(s); i++)
    {
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else if(s[i] == 'c') c++;
        else if(s[i] == 'd') d++;
        else e++;
    }
    // cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << min(a, min(b, min(c, min(d, e)))) << " " << max(a, max(b, max(c, max(d, e)))) << endl;
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
