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
        int n, q; cin >> n >> q;
        vector<int> c(n + 1);
        vector<int> mark(n + 1, 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        while(q--)
        {
            int a, b; cin >> a >> b;
            if(c[a] == c[b])
            {
                mark[a] = 0;
                cout << mark[b] << endl;
                continue;
            }             
            if(c[a] != c[b])
            {
                mark[b] += mark[a];
                mark[a] = 0; 
                cout << mark[b] << endl;
                continue;
            }
        }
    }
    return 0;
}