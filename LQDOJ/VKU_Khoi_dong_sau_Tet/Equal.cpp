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

ll sum_digits(int n)
{
    ll sum = 0;
    while(n > 10)
    {
        sum += n % 10;
        n /= 10;
    }
    sum += n;
    return sum;
}

void solve()
{
    string n; cin >> n;
    if(sz(n)&1)
    {
        int sum_l = 0, sum_r = 0;
        for(int i = 0; i < sz(n)/2; i++)
        {
            sum_l += n[i] - '0';
            sum_r += n[i + sz(n)/2 + 1] - '0';
        }
        string left = n.substr(0, sz(n)/2);
        string right = n.substr(sz(n)/2 + 1, sz(n)/2);
        string mid = n.substr(sz(n)/2, 1);
        
        if(stoll(left) < stoll(right))
        {
            mid = to_string(stoll(left + mid) + 1);
            string tmp1 = left;
            string tmp2 = left;
            sort(all(tmp1));
            sort(rall(tmp2));
            cout << mid << (stoll(tmp1) < stoll(tmp2) ? tmp1 : tmp2) << endl;
        }
        if(stoll(left) > stoll(right))
        {
            for(int i = 0; i <= stoll(string(sz(n) / 2, '9')); i++)
            {
                if(sum_digits(i) == sum_l)
                {
                    string tmp = to_string(i);
                    tmp = string(sz(n)/2 - sz(tmp), '0') + tmp;
                    if(stoll(tmp) > stoll(right))
                    {
                        cout << left + mid + tmp << endl;
                        break;
                    }
                }
            }
        }
        if(stoll(left) == stoll(right))
        {
            ll tmp = stoll(right) + 1;
            string tmp1 = to_string(tmp);
            sort(all(tmp1));
            if(sz(tmp1) > sz(right))
            {
                cout << to_string(tmp) + tmp1 << endl;
            }
        }
    }   
    else 
    {

        int sum_l = 0, sum_r = 0;
        for(int i = 0; i < sz(n)/2; i++)
        {
            sum_l += n[i] - '0';
            sum_r += n[i + sz(n)/2] - '0';
        }
        string left = n.substr(0, sz(n)/2);
        string right = n.substr(sz(n)/2, sz(n)/2);
        string res = n;
        for(int i = 0; i <= stoll(string(sz(n) / 2, '9')); i++)
        {
            if(sum_digits(i) == sum_l)
            {
                string tmp = to_string(i);
                tmp = string(sz(n)/2 - sz(tmp), '0') + tmp;
                // cout << tmp << endl;
                if(stoll(tmp) > stoll(right))
                {
                    res = left + tmp;
                    break;
                }
            }
        }
        if(stoll(left) == stoll(right))
        {
            ll tmp = stoll(right) + 1;
            string tmp1 = to_string(tmp);
            if(sz(tmp1) > sz(right))
            {
                tmp1 = tmp1.substr(0, sz(n) - sz(tmp1) + 1);
                sort(all(tmp1));
                cout << to_string(tmp) + tmp1 << endl;
                return;
            }
        }

        cout << res << endl;
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("EQUAL.INP", "r", stdin);
    freopen("EQUAL.OUT", "w", stdout);
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
