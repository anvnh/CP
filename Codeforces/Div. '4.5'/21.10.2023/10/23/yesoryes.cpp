#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 2004010501
#define maxn 200005
#define INF 10000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (auto &i : s)
        {
            if (i <= 'Z' && i >= 'A')
            {
                i += 32;
            }
        }
        if (s == "yes")
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}