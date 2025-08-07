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
const ll maxN = 1e5 + 5;

vector<set<int>> graph(maxN);
vector<bool> visited(maxN, false);

void dfs(int start, int end) {
    if(start > end) return cout << "NO" << endl, void();
    if(start == end) return cout << "YES" << endl, void();
    visited[start] = true;
    for(auto x : graph[start]) {
        if(!visited[x]) 
        {
            dfs(x, end);
        }
    }
}

void solve()
{
    int n, t; cin >> n >> t;
    for(int i = 1; i < n; i++){
        int cell; cin >> cell;
        // cout << i << " " << cell + i << endl;
        graph[i].insert(cell + i);
        graph[cell + i].insert(i);
    }
    // cout << m << endl;
    // for(int i = 1; i <= 10; i++)
    // {
    //     cout << i << " | ";
    //     for(auto x : graph[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // dfs(1, t) ? cout << "YES" << endl : cout << "NO" << endl;
    dfs(1, t);
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
