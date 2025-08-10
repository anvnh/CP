/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)
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

const int MOD = 1e9 + 7;

uint64_t mod_pow(uint64_t a, uint64_t e) {
    uint64_t r = 1;
    while (e) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}
uint64_t mod_inv(uint64_t a) { return mod_pow(a, MOD - 2); }

struct Fact {
    int L;
    vector<uint64_t> fac;
    Fact(int L_=2000000): L(L_), fac(L+1,1) {
        for (int i=1;i<=L;i++) fac[i] = (fac[i-1]* (uint64_t)i) % MOD;
    }
    uint64_t factorial(uint64_t n) const {
        if (n <= (uint64_t)L) return fac[(int)n];
        // Use Wilson complement if n is close to MOD-1
        uint64_t diff = (MOD - 1) - n; // number of terms in (n+1..MOD-1)
        // If diff is small, compute product (n+1..MOD-1) and invert
        if (diff <= (uint64_t)L) {
            uint64_t prod = 1;
            for (uint64_t x = n + 1; x <= MOD - 1; ++x)
                prod = (__int128)prod * x % MOD;
            // n! = (-1) * inv(prod) mod MOD
            uint64_t inv = mod_inv(prod);
            uint64_t ans = (MOD - 1) * inv % MOD; // (-1) mod MOD is MOD-1
            return ans;
        }
        if (n < MOD - 1 - n) {
            // naive up to n (rare if L chosen well)
            uint64_t ans = 1;
            for (uint64_t i = 1; i <= n; ++i) {
                ans = (__int128)ans * i % MOD;
                if (i > (uint64_t)L) {
                }
            }
            return ans;
        } else {
            uint64_t prod = 1;
            for (uint64_t x = n + 1; x <= MOD - 1; ++x)
                prod = (__int128)prod * x % MOD;
            uint64_t inv = mod_inv(prod);
            uint64_t ans = (MOD - 1) * inv % MOD;
            return ans;
        }
    }
};

Fact F(2000000);

void solve()
{
    int n; long long k;
    cin >> n >> k;
    vector<uint64_t> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(all(a));

    long long pref = 0;
    int j = -1;
    for (int i=0;i<n;i++){
        if (pref + (long long)a[i] >= k) { j = i; break; }
        pref += (long long)a[i];
    }
    uint64_t ans = 1;

    for (int i=0;i<j;i++){
        ans = (__int128)ans * F.factorial(a[i]) % MOD;
    }

    long long r = k - pref; // 1..a[j]
    if (r >= 1){
        ans = (__int128)ans * (a[j] % MOD) % MOD;
        if (r >= 2){
            ans = (__int128)ans * F.factorial((uint64_t)(r-1)) % MOD;
        }
    }
    cout << ans % MOD << "\n";
}

anvnh {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
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
