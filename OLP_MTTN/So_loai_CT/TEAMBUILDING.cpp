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
int k, n;
string s; 
int res = 0;
vector<int> dp(5005, 0);
//
void init(void) {
    cin >> n >> k >> s;
}

void backtrackSubtask1(int left) {
    if (left == n + 1) {
        res++;
        return;
    }
    int diff = 0;
    for (int right = left; right <= n; right++) {
        diff += (s[right] == '1') - (s[right] == '0');
        if (abs(diff) <= k) {
            backtrackSubtask1(right + 1);
        }
    }
}

bool checkSubtask1() {
    return n <= 20;
}

void solveSubtask1(void) {
    s = " " + s;
    backtrackSubtask1(1);
    cout << res;
}

bool checkSubtask2() {
    return n <= 500;
}

void addSubtask2(int &x, int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
}

void solveSubtask2()
{
    dp[0] = 1;
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            int diff = 0;
            for(int k = j; k <= i; k++)
            {
                diff += (s[k] == '1') - (s[k] == '0');
            }
            if(abs(diff) <= k)
            {
                addSubtask2(dp[i], dp[j - 1]);
            }
        }
    }
    cout << dp[n] << endl;
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    init();

    if(checkSubtask1()) return solveSubtask1(), 0;
    if(checkSubtask2()) return solveSubtask2(), 0;

    return 0;
}
