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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

const ll MOD = (1e9) + 7;

void solve()
{
    int n; cin >> n;
    cout << n << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
    int ntest; cin >> ntest;
    while(ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.6f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
	return 0;
}


