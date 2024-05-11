#include <algorithm>
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
const int inf = -1e9 + 7;

void solve()
{
    int n, k, q; cin >> n >> k >> q;
    deque<int > a(k), b(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    a.push_front(0);
    b.push_front(0);

    // vector<double> veloc;
    // vector<double> cal_pre(n + 1);
    // for(int i = 1; i <= k; i++)
    // {
        // int s= a[i] - a[i - 1];
        // int t = b[i] - b[i - 1];
        // cout << s << " " << t << endl;
        // cout << s / t << endl;
        // veloc.pb((double)s / t); // time for travel x unit per min
    // }
    // set<int> st;
    // for(int i = 1; i <= k; i++) st.insert(b[i]);
    // for(auto&x : veloc) {
    //     x = (double) 1 / x;
    // }
    // for(auto x : veloc) cout << x << " ";


    /*                                                                  // prefix (not working)
    int j = 1;
    int l = 0;
    double val = veloc[l];
    for(int i = 1; i <= n; i++)
    {
        cal_pre[i] = val;
        if(i == a[j])
        {
            j++;
            l++;
            val = veloc[l];
        }
    }
    // for(int i = 1; i <= n; i++) cout << cal_pre[i] << endl; 
    vector<double> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + cal_pre[i];
    }
    // for(auto x : prefix) cout << x << endl;
    */

    while(q--)
    {
        int query; cin >> query;
        if(query == n) {
            cout << b[k] << " ";
            continue;
        }
        int l = 0, r = k;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] <= query) {l = mid + 1; ans = mid;}
            else r = mid - 1;
        }
        // cout << b[ans] + (query - b[ans - 1]) * 1ll * (1 / (a[ans] - a[ans - 1]) / (b[ans] - b[ans - 1])) << endl;
        cout << b[ans] + (query - a[ans]) * 1ll * (b[ans + 1] - b[ans]) / (a[ans + 1] - a[ans]) << " ";
        // cout << b[ans - 1] << endl;
    }
    cout << endl;
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
