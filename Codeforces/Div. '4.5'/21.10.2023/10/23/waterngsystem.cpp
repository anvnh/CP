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
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> s(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        sum += s[i];
    }
    int first = s[0];
    sort(s.begin() + 1, s.end());
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((double)first * A / sum >= B)
        {
            break;
        }
        sum -= s[i];
        cnt++;
    }
    cout << cnt;
}
