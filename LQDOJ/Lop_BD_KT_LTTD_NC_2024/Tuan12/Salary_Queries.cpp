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

const int N = 1e5 + 10;

int n, Q;
int bit[N], a[N];
vector<int> values;

void update(int x, int val)
{
    for(; x <= n; x += (x & -x)) bit[x] += val;
}

int query(int x)
{
    int res = 0;
    for(; x > 0; x -= (x & -x)) res += bit[x];
    return res;
}


void solve()
{
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }

    sort(all(values));
    values.erase(unique(all(values)), values.end());
    
    for(int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(values), a[i]) - values.begin() + 1;
        update(a[i], 1);
    }

    while(Q--)
    {
        char c;
        int l; int r;
        cin >> c >> l >> r;
        if(c == '!')
        {
            update(a[l], -1);
            a[l] = lower_bound(all(values), r) - values.begin() + 1;
            update(a[l], 1);
        }
        else {
            cout << query(r) - query(l - 1) << endl;
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

