/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
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
const ll MOD = 1e9 + 7;

int n, k;
vector<int> a, remapped;
vector<int> freq;
int L = 0, R = 0;
int curCost = 0;
void add(int idx) {
    int x = remapped[idx];
    freq[x]++;
    if (freq[x] == 1) curCost++;
}
void removeElement(int idx) {
    int x = remapped[idx];
    freq[x]--;
    if (freq[x] == 0) curCost--;
}
 
void adjust(int newL, int newR) {
    while (R < newR) { add(R); R++; }
    while (R > newR) { R--; removeElement(R); }
    while (L < newL) { removeElement(L); L++; }
    while (L > newL) { L--; add(L); }
}
 
int getCost(int l, int r) {
    adjust(l, r + 1);
    return curCost;
}
vector<int> dp_prev, dp_curr;
void compute(int left, int right, int optL, int optR) {
    if (left > right) return;
    int mid = (left + right) / 2;
    int bestVal = -1, bestIdx = -1;
    for (int j = optL; j <= min(mid - 1, optR); j++) {
        int costSegment = getCost(j, mid - 1); 
        int curVal = dp_prev[j] + costSegment;
        if (curVal > bestVal) {
            bestVal = curVal;
            bestIdx = j;
        }
    }
    dp_curr[mid] = bestVal;
    compute(left, mid - 1, optL, bestIdx);
    compute(mid + 1, right, bestIdx, optR);
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    remapped.resize(n);
    for (int i = 0; i < n; i++) {
        remapped[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    }
    int compSize = comp.size();
    freq.assign(compSize, 0);
    L = 0; R = 0; curCost = 0;
    dp_prev.assign(n + 1, 0);
    dp_curr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp_prev[i] = getCost(0, i - 1);
    }
    for (int group = 2; group <= k; group++) {
        compute(group, n, group - 1, n - 1);
        dp_prev = dp_curr;
    }
 
    cout << dp_prev[n] << nl;
}

anvnh {
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
