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
const int MAX_N = 100; // Adjust this based on the maximum possible n

int tree[MAX_N + 1][MAX_N + 1][MAX_N + 1];
int n;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void update(int x, int y, int z, int val) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            for (int k = z; k <= n; k += k & -k) {
                tree[i][j][k] += val;
            }
        }
    }
}

int query(int x, int y, int z) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            for (int k = z; k > 0; k -= k & -k) {
                sum += tree[i][j][k];
            }
        }
    }
    return sum;
}

int range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2, y2, z2) - query(x1-1, y2, z2) - query(x2, y1-1, z2) - query(x2, y2, z1-1)
    + query(x1-1, y1-1, z2) + query(x1-1, y2, z1-1) + query(x2, y1-1, z1-1)
    - query(x1-1, y1-1, z1-1);
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                tree[i][j][k] = 0;

    for (int i = 0; i < m; ++i) {
        string q; get(q);
        if (q == "UPDATE") {
            int x, y, z, val; get(x, y, z, val);
            update(x, y, z, val - range_query(x, y, z, x, y, z));
        } else if (q == "QUERY") {
            int x1, y1, z1, x2, y2, z2; get(x1, y1, z1, x2, y2, z2);
            cout << (range_query(x1, y1, z1, x2, y2, z2)) << nl;
        }
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
