#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
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
ll lscs(vector<int> &a)
{
    ll max = INT_MIN, curr = 0;
    for (int i = 0; i < a.size(); i++)
    {
        curr += a[i];
        if (max < curr)
            max = curr;
        if (curr < 0)
            curr = 0;
    }
    return max;
}
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &v : a)
            cin >> v;
        vector<int> suff(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            suff[i + 1] = suff[i] + a[i];
        }
        int ans2 = lscs(a);
        sort(a.begin(), a.end(), greater<int>());
        int ans1 = 0;
        if (a[0] < 0)
        {
            cout << a[0] << " " << a[0] << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] > 0)
                {
                    ans1 += a[i];
                }
            }
            cout << ans1 << " " << ans2 << endl;
        }
    }
}
