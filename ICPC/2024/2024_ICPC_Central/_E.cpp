/**
    Author: anvnh
    RyeNyn
**/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)
template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
#define ll long long
#define pb push_back
#define fi first
#define se second
#define forn(i, a, b) for(int i = (a), *b = (b); i <= *b; ++i)
#define rep(i, a, b) for(int i = (a), *b = (b); i < *n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

int moveX[] = {-1, 1, 0, 0};
int moveY[] = {0, 0, -1, 1};

int dp[1 << 16][16];  
vector<vector<int>> d; 

vector<vector<int>> BFS(pair<int,int> st, vector<string>& grid, int r, int c) {
    vector<vector<int>> d(r, vector<int>(c, -1));
    queue<pair<int,int>> q;
    q.push(st);
    d[st.fi][st.se] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + moveX[i];
            int my = y + moveY[i];
            if(mx >= 0 && mx < r && my >= 0 && my < c && 
               grid[mx][my] != '#' && d[mx][my] == -1) {
                d[mx][my] = d[x][y] + 1;
                q.push({mx, my});
            }
        }
    }
    return d;
}

int dfs(int n, vector<vector<int>>& dist) {
    d = dist;  
    memset(dp, -1, sizeof(dp));
    function<int(int, int)> DFS = [&](int mask, int p) {
        if(mask == (1 << n) - 1) return 0;
        if(dp[mask][p] != -1) return dp[mask][p];
        int res = INF;
        for(int nxt = 0; nxt < n; nxt++) {
            if(!(mask & (1 << nxt)) && d[p][nxt] != -1) {
                res = min(res, d[p][nxt] + DFS(mask | (1 << nxt), nxt));
            }
        }
        return dp[mask][p] = res;
    };

    return DFS(1, 0);
}

void solve() {
    int r, c, n; get(r, c, n);
    vector<string> grid(r);
    for(int i = 0; i < r; i++) get(grid[i]);
    vector<pair<int,int>> vt;
    vt.pb({0, 0}); 
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 'S') {
                vt.pb({i, j});
            }
        }
    }
    vector<vector<int>> d(sz(vt), vector<int>(sz(vt), -1));
    for(int i = 0; i < sz(vt); i++) {
        auto p = BFS(vt[i], grid, r, c);
        for(int j = 0; j < sz(vt); j++) {
            if(i != j) {
                d[i][j] = p[vt[j].fi][vt[j].se];
            }
        }
    }
    (dfs(sz(vt), d) == INF ? put(-1) : put(dfs(sz(vt), d)));
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest = 1;
    // cin >> ntest;
    while (ntest--) {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
