#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
vector<ll> dp(1000007);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x; cin>>n>>x;
    vector<int> coin(n);
    for(int&v : coin) cin>>v;
    dp[0] = 1;
    for(int w=0; w<=x; w++)
    {
        for(int i=0; i<n; i++)
        {
            if(w - coin[i] >= 0)
            {
                dp[w] += dp[w - coin[i]];
                dp[w] %= mod;
            }
        }
    }
    cout<<dp[x];
}