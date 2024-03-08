#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> x[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        x[i].first = t;
        x[i].second = i + 1;
    }
    sort(x, x + n);
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i].second > x[i + 1].second)
        {
            ++res;
        }
    }
    cout << res;
}
