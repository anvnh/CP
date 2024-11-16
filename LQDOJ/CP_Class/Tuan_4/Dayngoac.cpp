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
        freopen((s + ".INP").c_str(), "r", stdin);
        freopen((s + ".OUT").c_str(), "w", stdout);
    #endif
}

void solve()
{
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        stack<char> st;
        bool ok = true;
        for (int i = 0; i < sz(s); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if (st.empty()){
                    ok = false;
                    break;
                }
                if (s[i] == ')' && st.top() == '('){
                    st.pop();
                } else if (s[i] == ']' && st.top() == '['){
                    st.pop();
                } else if (s[i] == '}' && st.top() == '{'){
                    st.pop();
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && st.empty()){
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
}

anvnh {
    freopen("PARENTHESES.INP", "r", stdin);
    freopen("PARENTHESES.OUT", "w", stdout);
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
