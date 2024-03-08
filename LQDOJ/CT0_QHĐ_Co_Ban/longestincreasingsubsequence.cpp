#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int> a(n); for(int&v : a) cin>>v;
    vector<int> dp(n + 1, 1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
}