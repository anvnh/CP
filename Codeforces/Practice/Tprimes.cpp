#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
const ll MOD = (1e9) + 7;
bool isPrime(ll n)
{
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
void solve(ll n)
{
    ll i = sqrt(n);
    if(i * i == n && isPrime(i))
    {
        cout << "YES";
    }
    else cout << "NO";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int n; cin >> n;
    vector<ll> a(n);
    for(auto&v : a) cin >> v;
    for(int i = 0; i < n ; i++)
    {
        solve(a[i]);
        cout << endl;
    }
    return 0;
}
