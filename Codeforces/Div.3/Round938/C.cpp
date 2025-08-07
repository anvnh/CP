#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, k; cin >> n >> k;
    deque<int> a(n);
    for (int &x : a) cin >> x;
    int cnt = 0;
    while(sz(a) > 1 && k) {

        int val = min(a.front(), a.back());
        (k < val * 2) 
            ? (a.front() -= (k >> 1) + (k&1), a.back() -= (k >> 1), k = 0)
        : (a.front() -= val, a.back() -= val, k -= val * 2);
        if(a.front() == 0) a.pop_front();
        if(a.back() == 0) a.pop_back();

    }
    cout << n - sz(a) + (sz(a) && a.front() <= k) << endl;
}

signed main()
{
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
