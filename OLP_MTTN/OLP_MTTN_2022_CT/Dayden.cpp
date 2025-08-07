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
int n, t, a, b;
int res = 0;
//
void init(void) {
    cin >> n >> t >> a >> b;
}
void backtrackSubtask1(int left)
{

}

bool checkSubtask1() {
    return n <= 6 && t <= 6;
}

void solveSubtask1() {
    
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

    if(checkSubtask1()) return solveSubtask1(), 0;

    debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
