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

string s; 
int n, k;

void solve()
{
    cin >> n >> k >> s;
    
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == s[n - 1]) 
            cnt++;
        else break;
    }
    
    auto ok = [&] () {
        for(int i = 0; i < k; i++)
        {
            if(s[i] != s[0]) return false;
        }
        for(int i = 0; i + k < n; i++)
        {
            if(s[i] == s[i + k]) return false;
        }
        return true;
    };
    
    auto process = [&] (int p) {
        reverse(s.begin(), s.begin() + p);
        s = s.substr(p, sz(s) - p) + s.substr(0, p); 
        if(ok()) {
            return void(cout << p << endl);
        }
        cout << -1 << endl;
    };

    if(cnt == k)
    {
        int p = n;
        for(int i = n - 1 - k; i >= 0; i--)
        {
            if(s[i] == s[i + k]) 
            {
                p = i + 1;
                break;
            }
        }
        process(p);
    }
    else if(cnt > k)
    {
        return void(cout << -1 << endl);
        // return cout << -1 << endl, void();
    }
    else 
    {
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != s.back()) continue;
            int j = i;
            while(j <= n && s[i] == s[j + 1]) j++;
            if(j - i + 1 + cnt == k)
            {
                ok = true;
                process(j + 1);
                break;
            }
            else if(j - i + 1 - k + cnt == k){
                ok = true;
                process(i + k - cnt);
                break;
            }
            i = j;
        }
        if(!ok) return void(cout << -1 << endl);
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
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
