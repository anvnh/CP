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
ll lscs(vector<int> &a)
{

    ll max = INT_MIN, curr = 0;
    for (int i = 0; i < a.size(); i++)
    {
        curr += a[i];
        if (max < curr)
            max = curr;
        if (curr < 0)
            curr = 0;
    }
    return max;
}
const ll MOD = (1e9) + 7;
ll sumv(vector<int>&a)
{
    ll sum = 0; 
    for(int i=0; i<sz(a); i++) sum += a[i];
    return sum;
}
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
        vector<vector<int>> ans(n);
        int x1; cin >> x1;
        int index = 0;
        ans[0].pb(x1);
        for(int i=1; i<n; i++)
        {
            int x; cin >> x;
            if(x&1 && !(ans[index].back()&1) || !(x&1) && ans[index].back()&1)
            {
                ans[index].pb(x);
            }
            else{
                index++;
                ans[index].pb(x);
            }
        }
        ll res = INT_MIN;
        for(auto x : ans)
        {
            res = max(res, lscs(x));
        }   
        cout << res << endl;
    }
    return 0;
}