#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int binarySearch(int left, int right, vector<int> &a, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            left = mid + 1;
        if (a[mid] > target)
            right = mid - 1;
    }
    return -1;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.pb(make_pair(x, i + 1));
    }
    sort(a.begin(), a.end());
    int pos1 = -1, pos2 = -1;
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (a[left].first + a[right].first == x)
        {
            cout << a[left].second << " " << a[right].second;
            return 0;
        }
        if (a[left].first + a[right].first > x)
        {
            right--;
        }
        if (a[left].first + a[right].first < x)
        {
            left++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
