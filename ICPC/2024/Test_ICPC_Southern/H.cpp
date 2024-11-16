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
const int MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if (a == 0)
        return make_tuple(b, 0LL, 1LL);
    auto [gcd, x, y] = extended_gcd(b % a, a);
    return make_tuple(gcd, y - (b / a) * x, x);
}

ll mod_mul(ll a, ll b, ll m) {
    ll result = 0;
    a %= m;
    while (b > 0) {
        if (b & 1)
            result = (result + a) % m;
        a = (a * 2) % m;
        b >>= 1;
    }
    return result;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll cal(ll n, ll M) {
    ll A = n % M;
    ll B = (n + 1) % M;
    ll C = (2 * n + 1) % M;
    ll result = mod_mul(mod_mul(A, B, M), C, M);
    auto [gcd, x, _] = extended_gcd(6, M);
    if (gcd == 1) {
        ll inv_6 = (x % M + M) % M;
        result = mod_mul(result, inv_6, M);
    } else {
        result /= gcd;
        ll new_M = M / gcd;
        // if (result % (6 / gcd) != 0) {
        //     throw runtime_error("Không thể chia chính xác cho 6");
        // }
        result /= (6 / gcd);
        result %= new_M;
    }
    
    return result;
}

void solve()
{
    ll A, B, M; get(A, B, M);
    // (2B^3 + 3B^2 + B - 2A^3 + 3A^2 - A) / 6
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
