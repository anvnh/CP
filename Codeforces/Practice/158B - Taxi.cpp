#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    int res = 0;
    res += mp[4];
    int tmp = min(mp[1], mp[3]);
    res += tmp, mp[1] -= tmp, mp[3] -= tmp;
    res += mp[3];
    res += mp[2]/2; mp[2] %= 2;
    res += mp[1] / 4;
    mp[1] %= 4;
    tmp = min(mp[1] / 2, mp[2]);
    res += tmp;
    mp[1] -= tmp * 2; mp[2] -= tmp; 
    (mp[1] > 0 || mp[2] > 0) ? res+= 1 : res += 0;
    cout << res << endl;
    return 0;
}
