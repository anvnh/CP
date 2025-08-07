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
const int maxn = 1010;

int n, m;
vector<vector<int>> a(maxn, vector<int>(maxn));
vector<vector<bool>> visited(maxn, vector<bool>(maxn, false));

int dfs(int row, int col)
{
    visited[row][col] = true;
    int curr = a[row][col]; 
    if(col != 0 && a[row][col - 1] != 0 && !visited[row][col - 1])
        curr += dfs(row, col - 1); 
    if(col != m - 1 && a[row][col + 1] != 0 && !visited[row][col + 1])
        curr += dfs(row, col + 1);
    if(row != 0 && a[row - 1][col] != 0 && !visited[row - 1][col])
        curr += dfs(row - 1, col); 
    if(row != n - 1 && a[row + 1][col] != 0 && !visited[row + 1][col])
        curr += dfs(row + 1, col);
    return curr;
}

void solve()
{
    cin >> n >> m;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            cin >> a[i][j];           
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != 0)
                res = max(res, dfs(i, j));
        }
    }
    cout << res << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    // ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
