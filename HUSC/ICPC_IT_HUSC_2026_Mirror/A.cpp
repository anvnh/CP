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
const ll MOD = 1e9 + 7;

void setIO(string s)
{
#ifdef ONLINE_JUDGE
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

int cal(int a, int b)
{
    if (a > b)
        return 3;
    if (a == b)
        return 1;
    return 0;
}

void solve()
{
    vector<int> a, b;
    string s1;
    getline(cin, s1);
    while (true)
    {
        int x;
        cin >> x;
        if (x != -1)
            a.push_back(x);
        else
            break;
    }
    cin.ignore();

    string s2;
    getline(cin, s2);
    while (true)
    {
        int x;
        cin >> x;
        if (x != -1)
            b.push_back(x);
        else
            break;
    }
    cin.ignore();
    // cout << s1 << " " << s2 << nl;
    // for (auto x : a)
    //     cout << x << " ";
    // cout << nl;
    // for (auto x : b)
    //     cout << x << " ";
    sort(rall(a));
    sort(rall(b));

    int a0 = a[0], a1 = a[1], a2 = a[2];
    int b0 = b[0], b1 = b[1], b2 = b[2];
    int res0 = cal(a2, b0) + cal(a0, b1) + cal(a1, b2);
    int res1 = cal(b0, a2) + cal(b1, a0) + cal(b2, a1);
    if (res0 > res1)
    {
        cout << s1;
    }
    else if (res0 < res1)
    {
        cout << s2;
    }
    else
    {
        cout << "Hoa";
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
