#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define endl "\n"
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    a[0].first = a[0].second = 0;
    for (int i = 1; i <= n; ++i)
    {
        mp[a[i].second] = i;
    }
    int res = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].second < a[i - 1].second)
        {
            res++;
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        auto it1 = mp.find(x);
        auto it2 = mp.find(y);
        int i = it1->second;
        int j = it2->second;
        int Min = min(i, j);
        int Max = max(i, j);
        if (a[Min].second < a[Min - 1].second)
        {
            if (a[Max].second > a[Min - 1].second)
            {
                res--;
            }
        }
        else
        {
            if (a[Max].second < a[Min - 1].second)
            {
                res++;
            }
        }
        if (a[Max + 1].second < a[Max].second)
        {
            if (a[Max + 1].second > a[Min].second)
            {
                res--;
            }
        }
        else
        {
            if (a[Max + 1].second < a[Min].second)
            {
                res++;
            }
        }
        if (Max - Min == 1)
        {
            if (a[Max].second < a[Min].second)
            {
                if (a[Min].second > a[Max].second)
                {
                    res--;
                }
            }
            else
            {
                if (a[Min].second < a[Max].second)
                {
                    res++;
                }
            }
        }
        else
        {
            if (a[Max].second < a[Max - 1].second)
            {
                if (a[Min].second > a[Max - 1].second)
                {
                    res--;
                }
            }
            else
            {
                if (a[Min].second < a[Max - 1].second)
                {
                    res++;
                }
            }
            if (a[Min + 1].second < a[Min].second)
            {
                if (a[Min + 1].second > a[Max].second)
                {
                    res--;
                }
            }
            else
            {
                if (a[Min + 1].second < a[Max].second)
                {
                    res++;
                }
            }
        }
        swap(a[Min].second, a[Max].second);
        swap(it1->second, it2->second);
        cout << res << endl;
    }
}
