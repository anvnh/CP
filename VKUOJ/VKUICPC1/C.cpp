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
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) {
   ((std::cout << args << ' '), ...);
   std::cout << '\n';
}
#define ll long long
#define pb push_back
#define fi first
#define se second
#define forn(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _n; ++i)
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

const int N = 1e6 + 6;

vector<int> graph[N];
vector<bool> visited(N);

void DFS(int root)
{
    visited[root] = true;
    for(auto v : graph[root]) {
        if(!visited[v]) {
            visited[v] = true;
        }
    }
}

void solve()
{
    int n, k; get(n, k);
    for(int i = 1; i <= k; i++)
    {
        int a, b; get(a, b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    visited.assign(N, false);
    DFS(1);
    bool ok = true;
    for(int i = 1; i <= n; i++) if(!visited[i]) {ok = false; break;}
    if(ok) {
        cout << "-" << k - n + 1 << nl;
    }
    else {
        int conn = 0;
        visited.assign(N, false);
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i]) {
                conn++;
                DFS(i);
            }
        }
        cout << "+" << conn - 1 << nl;
    }
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
