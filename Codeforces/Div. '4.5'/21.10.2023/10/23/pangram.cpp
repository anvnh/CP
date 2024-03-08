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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
        {
            s[i] += 32;
        }
    }
    int c[26]{};
    for (int i = 0; i < s.size(); i++)
    {
        c[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (c[i] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
}