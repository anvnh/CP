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
        int n, m; cin >> n >> m;
        map<int, int> mp;
        vector<int> a(n + 1, 0);
        int max_candidate = INT_MIN;
        int min_number = INT_MAX;
        for(int i = 1; i <= m; i++)
        {
            int x; cin >> x;
            mp[x]++;
            //for(auto x : mp) cout << x. fi <<  " " << x.se << endl;
            //cout << "_____________" << endl;
            if(mp[x] > max_candidate)
            {
                cout << x << endl;
                max_candidate = mp[x];
                min_number = x;
                continue;
            }
            if(mp[x] == max_candidate)
            {
                if(x < min_number)
                {
                    cout << x << endl;
                    min_number = x;
                }
                else
                {
                    cout << min_number << endl;
                }
                continue;
            }
            if(mp[x] < max_candidate)
            {
                cout << min_number << endl;
                continue;
            }
        }
    }
    return 0;
}