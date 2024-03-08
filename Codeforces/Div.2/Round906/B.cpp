#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isPrime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
#define MOD 2004010501
#define MAX_N 100005
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        string t;
        cin >> t;
        if (s.size() == 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        bool check = true;
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                check = false;
                break;
            }
        }
        bool check1 = true;
        for (int i = 0; i + 1 < m; i++)
        {
            if (t[i] == t[i + 1])
            {
                check1 = false;
                break;
            }
        }
        if (check == false)
        {
            if (check1 == false)
            {
                cout << "No" << endl;
                continue;
            }
            else
            {
                bool check2 = true;
                for (int i = 0; i + 1 < n; i++)
                {
                    if (s[i] == s[i + 1])
                    {
                        if (s[i] == t[0] || s[i + 1] == t[m - 1])
                        {
                            check2 = false;
                            break;
                        }
                    }
                }
                if (check2)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}