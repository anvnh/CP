#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e5 + 5;
int dp[MAX_N];
int h[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>h[i];
    dp[1] = 0;
    for(int i=2; i<=n; i++)
    {
        dp[i] = 1e9;
        for(int j=i - 1; j>=max(1, i - k); j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout<<dp[n];
}
