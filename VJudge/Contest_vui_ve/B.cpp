/**
    Author: anvnh
    Created: 2024-08-23 18:34:50
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
    std::cout << "}\n";
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
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

int moveX[4] = {0, 0, -1, 1};
int moveY[4] = {-1, 1, 0, 0};

void solve()
{
    int h, w, n; cin >> h >> w >> n;
    string t; cin >> t;
    vector<string> vs;
    for(int i = 0; i < h; i++)
    {
        string s; cin >> s;
        vs.pb(s);
    }
    int res = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(vs[i][j] == '.') {
                int cnt_w = 0;
                int X = i, Y = j;
                for(char c : t) {
                    if(c == 'L') {
                        if(vs[X][Y - 1] == '#') break;
                        Y--;
                        cnt_w++;
                    }
                    if(c == 'R') {
                        if(vs[X][Y + 1] == '#') break;
                        Y++;
                        cnt_w++;
                    }
                    if(c == 'U') {
                        if(vs[X - 1][Y] == '#') break;
                        cnt_w++;
                        X--;
                    }
                    if(c == 'D') {
                        if(vs[X + 1][Y] == '#') break;
                        cnt_w++;
                        X++;
                    }
                }
                if(cnt_w == n) res++; 
            }
        }
    }
    return cout << res << nl, void();
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
