#include <bits/stdc++.h>
using namespace std; 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long 
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

void solve()
{
    int n; cin >> n;  
    vector<pair<pair<int, int>, int>> a(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    sort(all(a));
    int last_room = 0;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++)
    {
        if(pq.empty())
        {
            last_room++;
            pq.push({-a[i].fi.se, last_room});
            ans[a[i].se] = last_room;
        }
        else {
            pair<int, int> min = pq.top();
            if(-min.fi < a[i].fi.fi)
            {
                pq.pop();
                pq.push({-a[i].fi.se, min.se});
                ans[a[i].se] = min.se;
            }
            else {
                last_room++;
                pq.push({-a[i].fi.se, last_room});
                ans[a[i].se] = last_room;
            }
        }
    }
    cout << pq.size() << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}


signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
