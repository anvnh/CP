/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
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

ll val(ll x, ll y)
{
    if (x == 0 && y == 0)
        return 1;

    ll k = max(abs(x), abs(y));

    if (x == k && y > -k)
        return (4 * k * k - 3 * k + 1 + y) % MOD;
    if (y == k && x < k)
        return (4 * k * k - k + 1 - x) % MOD;
    if (x == -k && y < k)
        return (4 * k * k + k + 1 - y) % MOD;
    if (y == -k && x > -k)
        return (4 * k * k + 3 * k + 1 + x) % MOD;

    return 0;
}

void solve(ll N)
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll sum = 0;
    for (ll x = x1; x <= x2; x++)
    {
        for (ll y = y1; y <= y2; y++)
        {
            sum += val(x, y);
            if (sum >= MOD)
                sum -= MOD;
        }
    }
    cout << sum << nl;
}

anvnh
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    ll N;
    cin >> N;
    ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve(N);
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
