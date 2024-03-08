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
ll expo(ll x, ll y)
{
    ll res = 1;
    while(y > 0)
    {
        if(y&1) res = (res * x); 
        y >>= 1; 
        x *= x;
    }
    return res;
}
const ll MOD = (1e9) + 7;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int q; cin >> q;
    while(q--) {
        ll k; cin >> k;
        ll len = 1;
        ll p = 9;
        /*
        for(;;k -= p, len++, p = 9 * expo(10, len - 1) * len)
        {
            if(k - p <= 0) break;
        }
        */
        k--;
        ll ans = expo(10, len-1) + k / len;
        string s = to_string(ans);
        cout << s[k % len] << endl;
    }
    return 0;
}
