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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        a[l - 1]--;
        a[r]++;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        a[i] += a[i + 1];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int pos = lower_bound(a.begin() + 1, a.end(), x) - a.begin() - 1;
        cout << n - pos << endl;
    }
}