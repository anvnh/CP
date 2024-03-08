#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // !ONLINE_JUDGE
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        set<int> s(a.begin(), a.end());
        a.assign(s.begin(), s.end());
        int pos = 0, res = INT_MIN;
        // for(auto x: a) cout << x << " ";
        cout << endl;
        for(int i = 0; i < a.size(); i++)
        {
            while(a[i] - a[pos] >= n)
                pos++;
            res = max(res, i - pos + 1);
        }
        cout << res << endl;
        // cout << "-------------------" << endl;
    }
}
