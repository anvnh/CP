#include <bits/stdc++.h>
#include <string>
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

int n;

void init(void) {
    cin >> n;
}

bool checkSubtask1_2() {
    return n < 1e8;
}

bool checkSubtask1_2(int n){
    string t = to_string(n);
    map<int, int> mp;
    for(char c : t)
    {
        if(mp[(c - '0')] > 1) return false;
        mp[(c - '0')]++;
    }
    return true;
}

void solveSubtask1_2() {
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(i % 5 == 0 && checkSubtask1_2(i))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}

bool checkSubtask3()
{
    return n > 1e8;
}

void solveSubtask3()
{
    cout << 1 << endl;
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
    if(checkSubtask1_2()) return solveSubtask1_2(), 0;
    if(checkSubtask3()) return solveSubtask3(), 0;
    debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
