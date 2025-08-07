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
    double x1, x2, v1, v2; cin >> x1 >> x2 >> v1 >> v2;
    cout << fixed << setprecision(4);
    if(x1 == x2)
    {
        cout << 0 << endl;
    }
    else{
        if(v1 * v2 < 0)
        {
            if(x1 < x2)
            {
                if(v1 < 0)
                {
                    cout << -1;
                }
                else {
                    cout << double(x2 - x1) / (v1 - v2);
                }
            }
            else {
                if(v2 < 0)
                {
                    cout << -1;
                }
                else {
                    cout << double(x1 - x2) / (v2 - v1);
                }
            }
        }
        if(v1 * v2 > 0)
        {
            if(v1 == v2)
            {
                cout << -1;
            }
            else if(v1 < 0 && v2 < 0)
            {
                if(x1 < x2)
                {
                    if(v1 < v2) 
                        cout << -1;
                    else 
                        cout << double(x2 - x1) / (v1 - v2);
                }
                else 
                {
                    if(v1 > v2) 
                        cout << -1;
                    else 
                        cout << double(x1 - x2) / (v2 - v1);
                }
            }
            else {
                if(x1 < x2)
                {
                    if(v1 < v2) 
                        cout << -1;
                    else 
                        cout << double(x2 - x1) / (v1 - v2);
                }
                else 
                {
                    if(v1 > v2) 
                        cout << -1;
                    else 
                        cout << double(x1 - x2) / (v2 - v1);
                }
            }
        }
        if(v1 * v2 == 0)
        {
            if(x1 < x2)
            {
                if(v1 == 0)
                {
                    if(v2 < 0) 
                        cout << double(x2 - x1) / v2;
                    else 
                        cout << -1;
                }
                if(v2 == 0)
                {
                    if(v1 < 0)
                        cout << -1;
                    else 
                        cout << double(x2 - x1) / v1;
                }
            }
            if(x1 > x2)
            {
                if(v1 == 0)
                {
                    if(v2 > 0) 
                        cout << double(x1 - x2) / v2;
                    else 
                        cout << -1;
                }
                if(v2 == 0)
                {
                    if(v1 > 0)
                        cout << -1;
                    else 
                        cout << double(x1 - x2) / v1;
                }
            }
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
