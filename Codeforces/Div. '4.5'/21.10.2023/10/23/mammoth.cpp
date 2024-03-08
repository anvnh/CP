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
    char a[288];
    int n;
    cin >> n;
    string s;
    cin >> s;
    int A = 0, C = 0, G = 0, T = 0, sum = n / 4;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            A++;
        if (s[i] == 'C')
            C++;
        if (s[i] == 'G')
            G++;
        if (s[i] == 'T')
            T++;
    }
    if (n % 4 != 0 || A > sum || C > sum || G > sum || T > sum)
    {
        cout << "===";
        return 0;
    }
    A = sum - A;
    C = sum - C;
    G = sum - G;
    T = sum - T;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (A)
            {
                cout << 'A';
                A--;
                continue;
            }
            if (C)
            {
                cout << 'C';
                C--;
                continue;
            }
            if (G)
            {
                cout << 'G';
                G--;
                continue;
            }
            if (T)
            {
                cout << 'T';
                T--;
                continue;
            }
        }
        else
        {
            cout << s[i];
        }
    }
}