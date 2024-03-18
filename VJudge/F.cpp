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

vector<int> moveX = {1, 0, -1, 0};
vector<int> moveY = {0, 1, 0, -1};
vector<vector<int>> a(45, vector<int>(45, 0));

void solve()
{
    int n; cin >> n;
    int x = 0, y = 0;
    int move = 0;
    a[0][0] = 1;
    int cell_cnt = 1;
    while(cell_cnt < n * n)
    {
        int coor_x = x + moveX[move];
        int coor_y = y + moveY[move];
        if(coor_x >= 0 && coor_x < n && coor_y >= 0 && coor_y < n && a[coor_x][coor_y] == 0)
        {
            a[coor_x][coor_y] = cell_cnt + 1;
            x = coor_x;
            y = coor_y;
            cell_cnt++;
        }
        else
        {
            move++;
            if(move == 4)
            {
                move = 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i + 1 == (n + 1) >> 1 && j + 1 == (n + 1) >> 1)
            {
                cout << 'T' << " ";
            }
            else
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
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
