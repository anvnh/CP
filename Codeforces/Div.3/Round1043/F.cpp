/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f

struct Node { 
    ll Ty; 
    int y; 
};

void solve()
{
    int n; string a, b;
    cin >> n >> a >> b;

    vector<ll> A1(n + 1, 0), B1(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        A1[i] = A1[i - 1] + (a[i - 1]=='1');
        B1[i] = B1[i - 1] + (b[i - 1]=='1');
    }

    vector<Node> nodes(n);
    for (int i = 1; i <= n; i++) nodes[i - 1] = { (ll)i - 2LL * B1[i], i };

    sort(nodes.begin(), nodes.end(), [](const Node& L, const Node& R){
        if (L.Ty != R.Ty) return L.Ty < R.Ty;
        return L.y < R.y;
    });

    vector<ll> prefCnt(n + 1, 0), prefB(n + 1, 0), prefY(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefCnt[i] = i;
        prefB[i] = prefB[i - 1] + B1[nodes[i - 1].y];
        prefY[i] = prefY[i - 1] + nodes[i - 1].y;
    }
    const ll totCnt = prefCnt[n];
    const ll totB = prefB[n];
    const ll totY = prefY[n];

    ll res = 0;

    for (int x = 1; x <= n; ++x) {
        ll u = A1[x];
        ll t = 2LL * u - x;

        int pos = int(lower_bound(nodes.begin(), nodes.end(), Node{t, -1},
                                  [](const Node& L, const Node& R){
                                  if (L.Ty != R.Ty) return L.Ty < R.Ty;
                                  return L.y < R.y;
                                  }) - nodes.begin());
        ll cnt0 = pos;
        ll cnt1 = totCnt - pos;
        ll sumB0 = prefB[pos];
        ll sumY0 = prefY[pos];
        ll sumB1 = totB - sumB0;
        ll part1 = cnt1 * u + sumB1;
        ll part0 = cnt0 * (x - u) + (sumY0 - sumB0);
        res += part0 + part1;
    }

    cout << res << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
