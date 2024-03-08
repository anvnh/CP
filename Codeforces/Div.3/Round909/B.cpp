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
int main()
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
        vector<int> a(n);
        for(int&v : a) cin >> v;
        ll res = *max_element(all(a)) - *min_element(all(a));
        if(isPrime(n))
        {
            cout << res << endl;
            continue;
        }
        vector<ll> cnt(n + 1, 0);
        for(int i=0; i<n; i++)
        {
            cnt[i + 1] = cnt[i] + a[i];
        }
        vector<int> div;
        for(int i=2; i <= sqrt(n); i++)
        {
            if(n%i == 0) 
            {
                div.pb(i);
            }
            if(n/i > sqrt(n) && round(n/i)*i == n) div.pb(n/i);
        }
        for(auto x : div)
        {
            vector<ll> temp;
            for(int i=0; i<n; i+=x)
            {
                temp.pb(cnt[i + x] - cnt[i]);
            }
            ll res_t = *max_element(all(temp)) - *min_element(all(temp));
            res = max(res, res_t);
        }
        cout << res << endl;
    }
    return 0;
}
