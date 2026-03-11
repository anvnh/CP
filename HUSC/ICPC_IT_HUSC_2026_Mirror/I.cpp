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

template <typename T>
void print(const T &t)
{
    for (const auto &element : t)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
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
#define ull unsigned long long
const ll MOD = 1e9 + 7;

void setIO(string s)
{
#ifdef ONLINE_JUDGE
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

void solve()
{
    int n;
    cin >> n;
    int zero_cnt = 0;
    int minus_one_cnt = 0;
    int one_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            one_cnt++;
        else if (x == -1)
            minus_one_cnt++;
        else
            zero_cnt++;
    }
    string todo;
    cin >> todo;
    string sta;
    cin >> sta;

    if (zero_cnt == 0)
    {
        if (minus_one_cnt % 2 == 1)
        {
            if (todo == "ADD")
            {
                if (sta == "MIN")
                    return cout << -1 << nl, void();
                if (sta == "MAX")
                    return cout << 1 << nl, void();
            }
            else
            {
                if (sta == "MIN")
                    return cout << -1 << nl, void();
                if (sta == "MAX")
                    return cout << 1 << nl, void();
            }
        }
        else
        {
            if (todo == "ADD")
            {
                if (sta == "MIN")
                    return cout << -1 << nl, void();
                if (sta == "MAX")
                    return cout << 1 << nl, void();
            }
            else
            {
                if (one_cnt == 0)
                {
                    if (sta == "MIN")
                        return cout << -1 << nl, void();
                    if (sta == "MAX")
                        return cout << -1 << nl, void();
                }
                else
                {
                    if (sta == "MIN")
                        return cout << -1 << nl, void();
                    if (sta == "MAX")
                        return cout << 1 << nl, void();
                }
            }
        }
    }
    else
    {
        if (todo == "ADD")
        {
            if (sta == "MIN")
                return cout << 0 << nl, void();
            if (sta == "MAX")
                return cout << 0 << nl, void();
        }
        else
        {
            if (sta == "MIN")
                if (minus_one_cnt > 0 && one_cnt > 0)
                    if (minus_one_cnt % 2 == 0)
                        return cout << 0 << nl, void();
                    else
                        return cout << -1 << nl, void();
            if (sta == "MAX")
                return cout << 0 << nl, void();
        }
    }
}

anvnh
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
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
