#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    #endif
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n, x, y; cin >> n >> x >> y;
        vector<int> a(n);
        for(int&v : a) cin >> v;
        map<pair<int, int>, int> mp;
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            res += mp[{(x - a[i] % x) % x, a[i] % y}];
            mp[{a[i] % x, a[i] % y}]++;
        }
        cout << res << endl;
    }
    return 0;
}
