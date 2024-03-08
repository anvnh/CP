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
    vector<int> a(n);
    for (int &v : a)
        cin >> v;
    sort(a.begin(), a.end());
    if (a.size() <= 2)
    {
        cout << 0;
    }
    else
    {
        int cnt = 0;
        int Max = *max_element(a.begin(), a.end());
        int Min = *min_element(a.begin(), a.end());
        for (int i = 1; i < (n - 1); i++)
        {
            if (a[i] < Max && a[i] > Min)
            {
                cnt++;
            }
        }
        cout << cnt;
    }
}