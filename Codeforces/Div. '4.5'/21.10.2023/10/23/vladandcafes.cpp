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
    vector<int> a(n);
    for (int &v : a)
        cin >> v;
    int maxn = *max_element(a.begin(), a.end()) + 1;
    vector<int> res(maxn);
    for (int i = 0; i < n; i++)
    {
        res[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        res[a[i]]--;
        if (res[a[i]] == 0)
        {
            cout << a[i];
            break;
        }
    }
    return 0;
}