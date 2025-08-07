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

int fw[105][(int)5e5];
int k, n;

void build(int x) {
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j <= n) {
            fw[x][j] += 1;
            j += j & -j;
        }
    }
}

void update(int x, int i, int d) {
    while (i <= n) {
        fw[x][i] += d;
        i += i & -i;
    }
}

int sum(int x, int i) {
    int res = 0;
    while (i > 0) {
        res += fw[x][i];
        i -= i & -i;
    }
    return res;
}

int get(int x, int k) {
    int idx = 0;
    int bit = 1 << (32 - __builtin_clz(n));
    while (bit) {
        int t = idx + bit;
        if (t <= n && fw[x][t] < k) {
            k -= fw[x][t];
            idx = t;
        }
        bit >>= 1;
    }
    return idx + 1;
}

void solve()
{
    int m;
    cin >> k >> n;
    cin >> m;

    for (int i = 1; i <= k; ++i) build(i);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;

        int tmp = sum(x, n);
        int kq = 0;

        if (y > tmp) {
            kq = 0;
        } else {
            int idx = get(x, y);
            kq = (idx - 1) * k + x;
            update(x, idx, -1);
        }

        cout << kq << nl;
    }
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
