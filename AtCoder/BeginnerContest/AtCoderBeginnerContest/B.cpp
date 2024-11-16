#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define ford(i, n) for (int i = (n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (a); i <= (b); ++i)
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
bool check(int a)
{
    int t = a%10;
    a /= 10;
    while(a)
    {
        if(a%10 != t) return false;
        a/=10;
    }
    return true;
}
void fac(int n)
{
}
int facc(int n)
{
    while(n / 10 != 0) n /= 10;
    return n;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int total = 0;
    for(int i=1; i<=n; i++)
    {
        if(check(i))
        {
            int rep = i;
            int cnt = 0;
            while(rep/10 != 0) rep /= 10;
            for(int j=1; j<=a[i];j++)
            {
                if(check(j))
                {
                    if(facc(j) == rep) cnt++;
                }
            }
            total += cnt;
        }
    }
    cout << total;
	return 0;
}