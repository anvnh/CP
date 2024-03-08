#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 2004010501
#define INF 10000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int hol[10]{};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            for (int i = 0; i < 10; i++)
            {
                if (hol[i] == 0)
                {
                    hol[i] = 1;
                    break;
                }
            }
        }
        if (s[i] == 'R')
        {
            for (int i = 9; i >= 0; i--)
            {
                if (hol[i] == 0)
                {
                    hol[i] = 1;
                    break;
                }
            }
        }
        if ((s[i] - '0') <= 9 && (s[i] - '0') >= 0)
        {
            int index = s[i] - '0';
            hol[index] = 0;
        }
    }
    for (auto x : hol)
        cout << x;
}