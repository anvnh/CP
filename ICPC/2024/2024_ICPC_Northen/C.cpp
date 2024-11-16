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
void put(T&&... args) {
   ((std::cout << args << ' '), ...);
   std::cout << '\n';
}
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


ll find(vector<vector<int>>&mt, int k) {
    int N = sz(mt);
    int M = sz(mt[0]);
    ll res = 0;
    
    vector<vector<ll>> rowSum(N, vector<ll>(M + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            rowSum[i][j] = rowSum[i][j-1] + mt[i][j-1];
        }
    }
    
    for(int j = 1; j <= M; j++) {
        for(int start = 0; start < j; start++) {
            vector<ll> colSum(N);
            for(int i = 0; i < N; i++) {
                colSum[i] = rowSum[i][j] - rowSum[i][start];
            }
            unordered_map<ll, ll> prefixMod;
            prefixMod[0] = 0;
            ll curr = 0;
            
            for(int i = 0; i < N; i++) {
                curr += colSum[i];
                ll mod = ((curr % k) + k) % k;
                if(prefixMod.count(mod)) {
                    res = max(res, curr - prefixMod[mod]);
                }
                if(!prefixMod.count(mod) || prefixMod[mod] > curr) {
                    prefixMod[mod] = curr;
                }
            }
        }
    }
    
    return res;
}
void solve()
{
    int n, m, k; get(n, m, k);   
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            get(a[i][j]);
        }
    }
    put(find(a, k));
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
