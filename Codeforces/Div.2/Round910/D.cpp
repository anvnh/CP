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
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        ll res = 0;
        ll max_a = INT_MIN;
        ll max_b = INT_MIN;
        ll min_abs = INT_MAX;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            max_a = max(max_a, a[i]);
        }
        for(int i=0; i<n; i++)
        {
            cin >>b[i];
            min_abs = min(abs(a[i] - b[i]), min_abs);
            max_b = max(max_b, b[i]);
        }
    }
    return 0;
}