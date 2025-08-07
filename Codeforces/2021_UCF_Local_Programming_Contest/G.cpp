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

double time(double s, double v) {
    double a = 1.0;
    double b = -2.0 * v;
    double c = 2.0 * s;
    double delta = b*b - 4*a*c;
    double res = sqrt(delta);
    double t1 = (2.0 * v - res) / 2.0;
    double t2 = (2.0 * v + res) / 2.0;
    if (t1 >= 0 && t1 <= v) return t1;
    if (t2 >= 0 && t2 <= v) return t2;
    return 1e18;
}

bool can(vector<int>&boosts, int t, int L, int n, double v) {
    double vec = v;
    double tot_t = 0.0;
    for(int i = 1; i < n; i++) {
        double s = (double)(boosts[i] - boosts[i - 1]);
        double time_need = time(s, vec);
        tot_t += time_need;
        if(tot_t > t) return false;
        vec = vec - time_need + v;
    }

    double s = double(L - boosts[n - 1]);
    double time_need = time(s, vec);
    tot_t += time_need;
    return tot_t <= t;
}

void solve()
{
    int L, n, t; cin >> L >> n >> t;
    vector<int> boosts(n);
    for(int i = 0; i < n; i++) cin >> boosts[i];
    double l = 0.0, r = 1e9;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if(can(boosts, t, L, n, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(4) << r << nl;
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
