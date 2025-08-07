#include <bits/stdc++.h>
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

vector<int> moveX = {1, 0, -1, 0};
vector<int> moveY = {0, 1, 0, -1};

void solve()
{
    int n, q; cin >> n >> q;
    deque<pair<int, int>> pos;
    for(int i = 1; i <= n; i++) pos.pb({i, 0});
    while(q--)
    {
        int type; cin >> type;
        if(type == 1)
        {
            char query; cin >> query;
            pair<int, int> front = pos[0];
            if(query == 'U')
            {
                pos.push_front({front.fi, front.se + 1});
            }
            if(query == 'D')
            {
                pos.push_front({front.fi, front.se - 1});
            }
            if(query == 'L')
            {
                pos.push_front({front.fi - 1, front.se});
            }
            if(query == 'R')
            {
                pos.push_front({front.fi + 1, front.se});
            }
            pos.pop_back();
        }
        else
        {
            int idx; cin >> idx;
            idx--;
            cout << pos[idx].fi << " " << pos[idx].se << endl;
        }
    }
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
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
