/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops") 
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
#define forn(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _n; ++i)
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

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

int moveX[] = {-1, 1, 0, 0};
int moveY[] = {0, 0, -1, 1};

char island[105][105];
bool visited[105][105][1 << 15];
// bitset<1 << 15> visited[105][105];
int ind[105][105];

struct State {
    int x, y, mask, time;
    State(int x, int y, int mask, int time) : x(x), y(y), mask(mask), time(time) {
    }
};

inline bool valid(int x, int y, int r, int c) {
    return x >= 0 && x < r && y >= 0 && y < c && island[x][y] != '#';
}

inline int bfs(int r, int c, int n) {
    queue<State> q;
    q.emplace(0, 0, 0, 0);
    visited[0][0][0] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        if (curr.mask == (1 << n) - 1) return curr.time;
        for (int i = 0; i < 4; i++) {
            int mx = curr.x + moveX[i];
            int my = curr.y + moveY[i];
            if (valid(mx, my, r, c)) {
                int _mask = curr.mask;
                if (island[mx][my] == 'S') {
                    _mask |= (1 << ind[mx][my]);
                }
                if (!visited[mx][my][_mask]) {
                    visited[mx][my][_mask] = true;
                    q.emplace(mx, my, _mask, curr.time + 1);
                }
            }
        }
    }

    return -1;
}

void solve()
{
    int r, c, n; get(r, c, n);
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            get(island[i][j]);
            if (island[i][j] == 'S') {
                ind[i][j] = cnt++;
            }
        }
    }
    put(bfs(r, c, n));
}

anvnh {
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

