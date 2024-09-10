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

map<ll, ll> sol(int n)
{
    map<ll, ll> res;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ll cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            res[i] = cnt;
        }
    }
    if(n > 1) res[n] = 1;
    return res;
}

void solve()
{
    int a, b;
    while(cin >> a >> b){
        map<ll, ll> resa = sol(a);
        map<ll, ll> resb = sol(b);
        ll ans = 0;
        for(auto x : resa){
            if(resb.find(x.fi) == resb.end()) ans += x.se;
            else ans += abs(x.se - resb[x.fi]);
        }
        for(auto x : resb){
            if(resa.find(x.fi) == resa.end()) ans += x.se;
        }
        cout << ans << nl;
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
