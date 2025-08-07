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
#define maxn 10000000
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
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	fastio;
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n, k; cin >> n >> k;
        set<int> st;
        for(int i = 0; i < n; i++) 
        {
            int x; cin >> x;
            st.insert(x);
        }
        // print(st); 
        bool check = false;
        // auto it = next(st.begin(), 2);
        for(auto x : st)
        {
            int trg = k - x;
            if(st.count(trg))
            {
                if((trg&1 && !(x&1)) || (!(trg&1) && ((x&1))))
                {
                    check = true;
                    break;
                }
            }
        }
        (check) ? cout << 1 : cout << 0;
    }
	return 0;
}
