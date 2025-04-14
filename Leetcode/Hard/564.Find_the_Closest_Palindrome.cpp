/**
    Author: anvnh
    RyeNyn
**/

#include <algorithm>
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

long long halfToPalindrome(long long left, bool even) {
    long long res = left;
    if (!even) left = left / 10;
    while (left > 0) {
        res = res * 10 + left % 10;
        left /= 10;
    }
    return res;
}

void solve()
{
    string n; cin >> n;
    int N = n.size();
    if(N & 1) {
        N = (N >> 1);
    } else {
        N = (N >> 1) - 1;
    }

    vector<long long> comb;
    comb.push_back((long long)pow(10, n.size() - 1) - 1);
    comb.push_back((long long)pow(10, n.size()) + 1);
    string half1 = n.substr(0, N + 1);
    if(n.size()&1) {
        string half2 = half1.substr(0, half1.size() - 1);
        reverse(half2.begin(), half2.end());
        // cout << half1 + half2 << nl;
        comb.push_back(stol(half1 + half2));
        int tmp = stol(half1);
        tmp--;
        string tmp1 = to_string(tmp);
        string tmp2 = tmp1.substr(0, tmp1.size() - 1);
        reverse(tmp2.begin(), tmp2.end());
        // cout << tmp2 << nl;
        comb.push_back(stol(to_string(tmp) +  tmp2));
        tmp += 2;
        tmp1 = to_string(tmp);
        tmp2 = tmp1.substr(0, tmp1.size() - 1);
        reverse(tmp2.begin(), tmp2.end());
        comb.push_back(stol(to_string(tmp) +  tmp2));
    } else {
        string half2 = half1;
        reverse(half2.begin(), half2.end());
        comb.push_back(stol(half1 + half2));
        int tmp = stol(half1);
        tmp--;
        half2 = to_string(tmp);
        reverse(half2.begin(), half2.end());
        comb.push_back(stol(to_string(tmp) + half2));
        tmp += 2;
        half2 = to_string(tmp);
        reverse(half2.begin(), half2.end());
        comb.push_back(stol(to_string(tmp) + half2));
    }

    long long diff = LLONG_MAX, res = 0, n1 = stol(n);
    for(auto x : comb) {
        if(x == n1) continue;
        long long abs_val = abs(x - n1);
        // cout << x << " ";
        if(abs_val < diff) {
            res = x;
            diff = abs_val;
        } else if(abs_val == diff) {
            res = min(res, x);
        }
    }

    cout << to_string(res) << nl;
    // return to_string(res);
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
