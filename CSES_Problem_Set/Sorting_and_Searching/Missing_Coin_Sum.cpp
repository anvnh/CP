#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int main()
{
    // https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &v : x)
        cin >> v;
    sort(x.begin(), x.end());
    ll res = 1;
    for (int i = 0; i < n && x[i] <= res; i++)
    {
        res += x[i];
    }
    cout << res;
}
