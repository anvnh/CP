#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
using namespace std;
struct compare
{
    bool operator()(const pair<int, int> &a, const int &b)
    {
        return a.first < b;
    }
    bool operator()(const int &a, const pair<int, int> &b)
    {
        return a < b.first;
    }
};
int binarySearch(int a[], int l, int r, int x)
{
    while(l <= r)
    {
        int m = l + (r - l)/2;
        if(a[m] == x) return m;
        if(a[m] < x)
            l = m + 1;
        if(a[m] > x)
            r = m - 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++) {
        int a; cin>>a;
        vp.pb(make_pair(a, i));
	}
    sort(vp.begin(), vp.end());
	for (int i = 0; i < n; i++) 
    {
		int l, r;
		l = 0;
		r = n - 1;
		while (l != r) 
        {
			int target;
			target = x - vp[i].first;
			if (l != i && r != i && vp[l].first + vp[r].first == target)
            {
				cout << vp[i].second << " " << vp[l].second << " " << vp[r].second << endl;
				return 0;
			}
			if (vp[l].first + vp[r].first < target) 
				l++;
            else 
				r--;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
