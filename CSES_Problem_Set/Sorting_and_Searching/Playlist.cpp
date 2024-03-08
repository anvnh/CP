#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &v : a)
        cin >> v;
    map<int, int> mp;
    int i = 0, j = 0, curr_len = 0, ans = 0;
    while (i < n)
    {
        if (mp.find(a[i]) == mp.end() || mp[a[i]] == 0)
        {
            mp[a[i]]++;
            curr_len++;
            ans = max(curr_len, ans);
            i++;
        }
        else
        {
            curr_len--;
            mp[a[j]]--;
            j++;
        }
    }
    cout << ans;
}
