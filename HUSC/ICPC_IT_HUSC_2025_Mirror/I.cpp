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
        cout << element << " ";
    }
    cout << endl;
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
int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    int res = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int X = mid;
        vector<int> tmp = a;
        int times = 0;
        bool can = true;
        for (int i = 0; i < n && times < k; i++) {
            if (tmp[i] == 1) {
                int end = min(i + X - 1, n - 1);
                for (int j = i; j <= end; j++) {
                    tmp[j] = 0;
                }
                times++;
            }
        }
        bool off = true;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == 1) {
                off = false;
                break;
            }
        }
        if (off) {
            res = X;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
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
