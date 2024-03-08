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
const ll MOD = (1e9) + 7;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int ntest = 1;
    while(ntest--)
    {
        int n,x; cin>>n>>x;
        map<int, int> mp;
        while(n--)
        {
            int t1; cin>>t1;
            ++mp[t1];
        }
        ll ans = 0;
        for(auto it : mp)
        {
            int a = it.first;
            int freq_a = it.second;
            int b = x - a;
            int freq_b = mp[b];
            if(a == b)
                ans += 1LL * freq_a * (freq_a - 1) / 2;
            else
                ans += 1LL * freq_a * freq_b;
            mp[b] = 0;
        }
        cout<<ans;
    }
    return 0;
}