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
    int arr[n];
    cin >> n;
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        int t = 4;
        while (t--)
        {
            int x;
            cin >> x;
            arr[i] += x;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[0])
        {
            rank += 1;
        }
    }
    cout << rank;
}