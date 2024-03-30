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
const int maxn = 1e5 + 10;

int sol(int k, int x)
{
    int res = 0;
    int speed_up = 0;
    int speed_down = 0;
    for(int curr_speed = 1;; curr_speed++)
    {
        speed_up += curr_speed;
        res++;
        if(speed_up + speed_down >= k) 
            return res;
        if(curr_speed >= x)
        {
            speed_down += curr_speed;
            res++;
            if(speed_up + speed_down >= k) 
                return res;
        }
    }
}

void solve()
{
    int k, n; cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cout << sol(k, x) << endl;
    }
    
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
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
