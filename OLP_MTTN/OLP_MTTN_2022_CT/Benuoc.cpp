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

//Variable here
int a, b; 
//
void init(void) {
    cin >> a >> b;
}

void solve()
{
    cout << fixed << setprecision(5);
    cout << 1 /( 1 / (double)a + 1 / double(b) ) << endl;  
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    init();
    clock_t z = clock();
    solve();
    debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
