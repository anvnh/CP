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

pair<int, int> move(pair<int, int> pos, int d, int step, int n) {
    int x = pos.fi, y = pos.se;
    switch (d) {
        case 1: x = (x - step + n) % n; break; // North
        case 2: y = (y + step) % n; break;     // East
        case 3: x = (x + step) % n; break;     // South
        case 4: y = (y - step + n) % n; break; // West
    }
    return {x, y};
}

int rotate(int d, int r) {
    return ((d - 1 + r) % 4) + 1;
}

pair<int, int> teleport(int K, int N) {
    return {K / N, K % N};
}

void solve()
{
    int n, p, m; get(n, p, m);
    vector<tuple<int, int, int>> pacmen(p);
    for (auto& pacman : pacmen) {
        get(get<0>(pacman), get<1>(pacman), get<2>(pacman));
    }
    vector<pair<char, int>> coms(m);
    for (auto& cmd : coms) {
        get(cmd.fi, cmd.se);
    }
    for (const auto& cmd : coms) {
        char com = cmd.fi; int K = cmd.se;
        if (com == 'A') {
            for (auto& pacman : pacmen) {
                auto& [x, y, d] = pacman;
                tie(x, y) = move({x, y}, d, K, n);
            }
        } else if (com == 'R') {
            for (auto& pacman : pacmen) {
                auto& [x, y, d] = pacman;
                d = rotate(d, K);
            }
        } else if (com == 'Z') {
            auto new_pos = teleport(K, n);
            for (auto& pacman : pacmen) {
                auto& [x, y, d] = pacman;
                x = new_pos.fi;
                y = new_pos.se;
            }
        }
    }
    vector<pair<int, int>> f_pos;
    for (const auto& pac: pacmen) {
        f_pos.emplace_back(get<0>(pac), get<1>(pac));
    }
    for (const auto& pos : f_pos) {
        put(pos.fi, pos.se);
        cout << nl;
    }
}

anvnh {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
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
