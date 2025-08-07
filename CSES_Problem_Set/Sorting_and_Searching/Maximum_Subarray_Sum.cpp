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
// Kadane's Algorithm
ll lscs(vector<int> &a)
{
    ll max = INT_MIN, curr = 0;
    for (int i = 0; i < a.size(); i++)
    {
        curr += a[i];
        if (max < curr)
            max = curr;
        if (curr < 0)
            curr = 0;
    }
    return max;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cout << lscs(a);
}
