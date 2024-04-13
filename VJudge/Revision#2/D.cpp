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


void solve()
{
    int x, n; cin >> n >> x;   
    vector<ll> a(n);
    for(auto&v : a) cin >> v;
    vector<ll> pref(n + 1, 0);
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    // for(auto v : pref) cout << v << " ";
    // cout << endl;
    if(pref[n] < x) return cout << "-1" << endl, void();
    ll l = 0, r = 1e18;
    bool check = false;
    ll ans = 1e18;
    for(ll i = 1; i <= n ; i++){
        if(pref[i] - pref[l] >= x && l < i ){
            while(l < i && pref[i] - pref[l+1] >= x){
                l++;
            }
            if(l + 1 == i){
                check = true;
                break;
            }
            r = i - l;
            ans = min(ans, r);
        }
    }

    if(check) cout << "1" << endl;
    else{
        cout<<ans<<endl;
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
