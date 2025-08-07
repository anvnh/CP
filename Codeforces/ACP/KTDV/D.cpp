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

int n;

void Generate(string a, map<string, bool>& mp)
{
    vector<string> vi;
    vi.pb(a);
    mp[a] = true;
    for(int num = 1; num <= 2; num++)
    {
        vector<string> new_;
        for(auto s : vi)
        {
            for(int i = 0; i < n; i++)
                for(int j = i; j < n; j++)
                {
                    string tmp = "";
                    for(int k = 0; k < i; k++) tmp += s[k];
                    for(int k = j; k >= i; k--) tmp += s[k];
                    for(int k = j + 1; k < n; k++) tmp += s[k];
                    if(!mp[tmp])
                    {
                        new_.pb(tmp);
                        mp[tmp] = true;
                    }
                }
        }
        vi = new_;
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;
    n = sz(a);
    map<string, bool> mp_a, mp_b;
    if(a == b) return cout << "Similar" << endl, void();
    Generate(a, mp_a);
    Generate(b, mp_b);

    for(auto x : mp_a)
    {
        if(mp_b[x.fi]) return cout << "Similar" << endl, void();
    }
    cout << "Different" << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    // ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
