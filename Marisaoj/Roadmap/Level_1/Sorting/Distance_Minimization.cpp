/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <pthread.h>
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

struct Point{
    ll x, y;
};

bool comp(Point& a, Point& b) {
    return a.x < b.x;
}

void solve()
{
    ll n; get(n);
    vector<Point> points;
    for(auto i = 0; i < n; i++) {
        Point p; get(p.x, p.y);
        points.pb(p);
    }
    sort(all(points), comp);
    ll med = (n&1 ? (n >> 1) : (n >> 1) - 1);
    ll a = points[med].x, b = points[med].y;
    ll res = 0;
    for(auto [x, y] : points) {
        res += (abs(a - x) + abs(b - y));
    }
    put(res);
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
