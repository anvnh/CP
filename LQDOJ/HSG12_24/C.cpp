#include <bits/stdc++.h>
#include <deque>
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

const int maxn = 5e5 + 5;

int n, q;
vector<int> a(maxn);

void solve()
{
    // a.push_back(0);
    int k = 0;
    cin >> n >> q;
    ll sum = 0;
    ll curr_move = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    while(q--)
    {
        int type; cin >> type;
        if(type == 1)
        {
            // curr_move %= n;
            int i, x; cin >> i >> x;
            i = (i + curr_move) % n;
            sum -= a[i];
            a[i] = x;
            sum += a[i];
            for(int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl; 
            cout << sum << endl;
        }
        if(type == 2)
        {
            int k; cin >> k;
            curr_move += k;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("DODEP.INP", "r", stdin);
    freopen("DODEP.OUT", "w", stdout);
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
