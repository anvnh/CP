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

int Fact(int n)
{
    if (n == 0)
        return 1;
    return n * Fact(n - 1);
}

int Fib(int n)
{
    if (n <= 1)
        return n;
    return Fib(n - 1) + Fib(n - 2);
}

void Move(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << A << " to rod " << C << endl;
        return;
    }
    Move(n - 1, A, C, B);
    cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
    Move(n - 1, B, A, C);
}

void InFib(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;
}

int FactFor(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int FibFor(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    fastio

    return 0;
}
