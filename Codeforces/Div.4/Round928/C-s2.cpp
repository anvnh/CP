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
#define maxn 200005
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
vector<int> cal(maxn, 0);
ll one_digit(int n)
{
    if(n < 10) return n;
    ll sum = 0;
    while(n >= 10)
    {
        sum += n%10;
        n /= 10;
    }
    return sum + n;
}
void solve()
{
    for(int i = 1; i <= maxn; i++)
    {   
        cal[i] = cal[i-1] + one_digit(i);
    }
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        cout << cal[n] << endl;
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
