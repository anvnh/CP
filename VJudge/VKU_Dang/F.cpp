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

const int maxN = 2e5 + 5;


void solve()
{
    int h, w, m;
    cin >> h >> w >> m;

    vector<bool> painted_row(h);
    vector<bool> painted_col(w);

    vector<tuple<int, int, int>> paint_ord;

    vector<ll> cnt(maxN, 0);

    int row = h, col = w;
    //Vi sao ll thi duoc con int thi khong nhi ??

    // cnt[0] = col * row;
    for(int i = 0; i < m; i++)
    {
        int t, a, x; cin >> t >> a >> x;
        a--;
        paint_ord.pb({t, a, x});
    }
    // for(auto [t, a, x] : paint_ord){
    //     cout << t << " " << a << " " << x << endl;
    // }
    for(int i = m - 1; i >= 0; i--)
    {
        auto [t, a, x] = paint_ord[i];
        // cout << t << " " << a << " " << x << endl;
        if(t == 1) {
            if(!painted_row[a]){
                row--;
                painted_row[a] = true;
                cnt[x] += col;
            }
        }
        else {
            if(!painted_col[a]){
                col--;
                painted_col[a] = true;
                cnt[x] += row;
            }
        }
    }
    cnt[0] += 1ll * col * row;
    ll tot = 0;
    for(auto x : cnt) if(x) tot++;
    cout << tot << endl;
    for(int i = 0; i < maxN; i++)
    {
        if(cnt[i] > 0)
        {
            cout << i << " " << cnt[i] << endl;
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
