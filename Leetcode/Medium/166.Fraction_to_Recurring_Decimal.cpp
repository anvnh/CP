/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <string>
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

string fractionToDecimal(long numerator, long denominator) {
    if (numerator == 0)
        return "0";
    string ans = "";
    if (numerator > 0 ^ denominator > 0)
        ans += '-';
    long num = labs(numerator);
    long den = labs(denominator);

    long integer = num / den;
    long fraction = num % den;
    ans += to_string(integer);

    if (fraction == 0) {
        return ans;
    }
    ans += '.';

    unordered_map<long, long> ump;

    while (fraction) {
        if (ump.find(fraction) != ump.end()) {
            int pos = ump[fraction];
            ans.insert(pos, "(");
            ans += ")";
            break;
        } else {
            ump[fraction] = ans.length();
            fraction *= 10;
            integer = fraction / den;
            fraction = fraction % den;
            ans += to_string(integer);
        }
    }

    return ans;
}

void solve()
{
    int a, b; cin >> a >> b;
    cout << fractionToDecimal(a, b);
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
