#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
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
    ll n, S;
    cin >> n >> S;
    vector<pair<ll, ll>> choose;
    vector<pair<ll, ll>> b;
    for (int i = 0; i < n; i++)
    {
        int w, v, c;
        cin >> w >> v >> c;
        if (c == 1)
        {
            choose.push_back({v, w});
        }
        if (c == 0)
        {
            b.push_back({v, w});
        }
    }
    ll ans = 0;
    sort(choose.begin(), choose.end());
    sort(b.begin(), b.end());
    ll curr = 0;
    for (auto x : choose)
    {
        curr += x.se;
        ans += x.fi;
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        for (int j = choose.size() - 1; j >= 0; j--)
        {
            if (S >= (curr - b[i].se + choose[j].se))
            {
                ans = max(ans, ans - b[i].fi + choose[j].fi);
            }
        }
    }
    cout << ans;
}
