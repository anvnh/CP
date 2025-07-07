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

void solve()
{
    vector<int> a(5);
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    vector<int> perm = a;
    sort(perm.begin(), perm.end());

    do {
        int MP = perm[0];
        int W = perm[1];
        int D = perm[2];
        int L = perm[3];
        int Pts = perm[4];

        if (MP == W + D + L && Pts == 3 * W + D) {
            cout << MP << " " << W << " " << D << " " << L << " " << Pts << "\n";
            break;
        }
    } while (next_permutation(all(perm)));
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
