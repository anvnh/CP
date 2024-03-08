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
        string s; cin >> s;
        int Max = 0; 
        int cnt = 0;
        int res = 0;
        char c = '.';
        for(int i = 0; i < n; i++)
        {
            if(s[i] == c)
            {
                cnt++;
                res++;
            }
            else
            {
                Max = max(Max, cnt);
                cnt = 0;
            }
        }
        Max = max(Max, cnt);
        (Max >= 3) ? cout << 2 << endl : cout << res << endl;
    }
    return 0;
}