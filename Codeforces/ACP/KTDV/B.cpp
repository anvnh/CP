#include <bits/stdc++.h>
#include <cmath>
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
const int N = 1e7 + 5;

vector<int> spf(N);

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++) spf[i] = i;
    for (int i = 4; i < N; i += 2) spf[i] = 2;
    for (int i = 3; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) 
                if (spf[j] == j) spf[j] = i;
        }
    }
}

ll factor(int x) {
    ll ans = 1;
    while (x > 1) {
        int primeFactor = spf[x];
        ans *= primeFactor;
        while (x % primeFactor == 0) {
            x /= primeFactor;
        }
    }
    return ans;
}

void solve()
{
    int L, R; cin >> L >> R;   
    sieve();
    
    vector<int> freq(N, 0); 

    for (int i = L; i <= R; i++) freq[factor(i)]++;

    ll res = 0;
    for (int f : freq) res += 1LL * f * (f - 1) / 2;
    cout << res << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("capsomayman.inp", "r", stdin);
    freopen("capsomayman.out", "w", stdout);
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
