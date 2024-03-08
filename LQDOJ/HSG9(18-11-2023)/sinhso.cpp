#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define ford(i, n) for (int i = (n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (a); i <= (b); ++i)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}
const ll MOD = (1e9) + 7;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        if(isPrime(n))
        {
            cout << -1 << endl;
            continue;
        }
        if(n < 10)
        {
            cout << 1 << n << endl;
            continue;
        }
        vector<int> divs;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0) divs.pb(i);
            if(n/i > sqrt(n) && round(n/i)*i == n) divs.pb(n/i);
        }
        sort(all(divs));
        vector<pair<int, int>> vp;
        for(int i=0; i<sz(divs)/2; i++)
        {
            if(divs[i] * divs[sz(divs) - (i + 1)] == n)
            {
                vp.pb({divs[i], divs[sz(divs) - (i + 1)]});
            }
        }
        sort(all(vp));
        //for(auto x : vp) cout << x.fi << " " << x.se << endl;
        cout << vp[0].fi << vp[0].se << endl;
        //print(divs);
    }
    return 0;
}