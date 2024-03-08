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
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
int solve1(int n)
{
    if (n<10)
      return n*(n+1)/2;
    int d = log10(n);
    int a[d+1];
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1] * 10 + 45 * ceil(pow(10, i-1));
 
    int p = ceil(pow(10, d));
 
    int msd = n/p;
    return msd*a[d] + (msd*(msd-1)/2)*p +  
           msd*(1+n%p) + solve1(n%p);
}
void solve()
{
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        cout << solve1(n) << endl;
    }

}
const ll MOD = (1e9) + 7;
signed main()
{
    time_t start, end;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
    time(&start);
    solve();
    time(&end);
    double time_taken = double(end - start);
    cerr << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << endl;
	return 0;
}
