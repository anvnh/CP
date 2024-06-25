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

int _find(vector<int>& root, int x) {
    return (root[x] == x ? x : root[x] = _find(root, root[x]));
}

void _union(vector<int>& root, vector<int>& size, int a, int b) {
    int rootA = _find(root, a);
    int rootB = _find(root, b);
    if (rootA != rootB) {
        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }
        root[rootB] = rootA;
        size[rootA] += size[rootB];
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> root(101), size(101, 1);
    iota(all(root), 0);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        _union(root, size, a, b);
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (root[i] == i) {
            ans = max(ans, size[i]);
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
