#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &v : a)
        cin >> v;
    sort(a.begin(), a.end());
    ll median = a[n / 2];
    ll cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(median - a[i]);
    }
    cout << cost;
}
