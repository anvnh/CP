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
// const ll MOD = 1e9 + 7;
const int MOD = 10007;
using int128 = __int128;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

int128 gcd(int128 a, int128 b) {
    while (b != 0) {
        int128 t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int128 abs128(int128 x) {
    return x < 0 ? -x : x;
}

void rd(int128 &p, int128 &q) {
    if (q < 0) {
        p = -p;
        q = -q;
    }
    int128 g = gcd(abs128(p), q);
    p /= g;
    q /= g;
}

void add(int128 p1, int128 q1, int128 p2, int128 q2, int128 &p, int128 &q) {
    p = p1 * q2 + p2 * q1;
    q = q1 * q2;
    rd(p, q);
}

void sub(int128 p1, int128 q1, int128 p2, int128 q2, int128 &p, int128 &q) {
    p = p1 * q2 - p2 * q1;
    q = q1 * q2;
    rd(p, q);
}

void mul(int128 p1, int128 q1, int128 p2, int128 q2, int128 &p, int128 &q) {
    p = p1 * p2;
    q = q1 * q2;
    rd(p, q);
}

void div(int128 p1, int128 q1, int128 p2, int128 q2, int128 &p, int128 &q) {
    p = p1 * q2;
    q = q1 * p2;
    rd(p, q);
}

int mod128(int128 x) {
    int res = 0;
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        res = (res + (int)(x % MOD)) % MOD;
        x /= MOD;
    }
    return neg ? (MOD - res) % MOD : res;
}

int inv(int a, int mod = MOD) {
    int b = mod, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

void solve()
{
    int n, d, w, l; cin >> n >> d >> w >> l;
    vector<int> win(n + 1, 0);
    vector<int> lose(n + 1, 0);
    for(int i = 0; i < w; i++) {
        int x; cin >> x;
        win[x] = 1;
    }
    for(int i = 0; i < l; i++) {
        int x; cin >> x;
        lose[x] = 1;
    }

    vector<vector<int128>> p_mat(n, vector<int128>(n+1, 0));
    vector<vector<int128>> q_mat(n, vector<int128>(n+1, 1));

    for (int i = 0; i < n; i++) {
        int pos = i + 1;
        if (win[pos]) {
            p_mat[i][i] = 1; q_mat[i][i] = 1;
            p_mat[i][n] = 1; q_mat[i][n] = 1;
        } else if (lose[pos]) {
            p_mat[i][i] = 1; q_mat[i][i] = 1;
            p_mat[i][n] = 0; q_mat[i][n] = 1;
        } else {
            p_mat[i][i] = 1; q_mat[i][i] = 1;
            for (int step = 1; step <= d; step++) {
                int nxt = (pos - 1 + step) % n;
                int128 p_tmp, q_tmp;
                sub(p_mat[i][nxt], q_mat[i][nxt], 1, d, p_tmp, q_tmp);
                p_mat[i][nxt] = p_tmp;
                q_mat[i][nxt] = q_tmp;
            }
            p_mat[i][n] = 0; q_mat[i][n] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int pivot = i;
        long double max_val = 0;
        for (int r = i; r < n; r++) {
            long double val = (long double)p_mat[r][i] / (long double)q_mat[r][i];
            if (abs(val) > max_val) {
                max_val = abs(val);
                pivot = r;
            }
        }
        if (pivot != i) {
            swap(p_mat[i], p_mat[pivot]);
            swap(q_mat[i], q_mat[pivot]);
        }

        if (p_mat[i][i] == 0) {
            cout << 0 << nl;
            return;
        }

        int128 p_div = p_mat[i][i], q_div = q_mat[i][i];
        for (int c = i; c <= n; c++) {
            int128 p_new, q_new;
            div(p_mat[i][c], q_mat[i][c], p_div, q_div, p_new, q_new);
            p_mat[i][c] = p_new;
            q_mat[i][c] = q_new;
        }

        for (int c = i; c <= n; c++) {
            rd(p_mat[i][c], q_mat[i][c]);
        }

        for (int r = 0; r < n; r++) {
            if (r == i) continue;
            int128 p_mul = p_mat[r][i], q_mul = q_mat[r][i];
            for (int c = i; c <= n; c++) {
                int128 p_sub, q_sub, p_tmp, q_tmp;
                mul(p_mul, q_mul, p_mat[i][c], q_mat[i][c], p_tmp, q_tmp);
                sub(p_mat[r][c], q_mat[r][c], p_tmp, q_tmp, p_sub, q_sub);
                p_mat[r][c] = p_sub;
                q_mat[r][c] = q_sub;
            }
        }
    }

    int128 p_res = p_mat[0][n];
    int128 q_res = q_mat[0][n];

    int p_mod = mod128(p_res);
    int q_mod = mod128(q_res);
    int q_inv = inv(q_mod);

    cout << (1LL * p_mod * q_inv) % MOD << nl;
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
