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
    int res = 0;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        a.pb(make_pair(end, start));
    }
    sort(begin(a), end(a));
    int ans = 1;
    int curr = a[0].first;
    for (int i = 1; i < n; i++)
    {
        if (a[i].second >= curr)
        {
            curr = a[i].first;
            ans++;
        }
    }
    cout << ans;
}
