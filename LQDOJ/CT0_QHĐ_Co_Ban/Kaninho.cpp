#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        vector<int> t(3);
        for(int&v : t) cin>>v;
        
    }
    cout<<dp[n];
}