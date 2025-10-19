#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define maxn 100005
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
    int n; cin >> n;
    multiset<int> a;
    for(int i=0; i<n; i++)
    {
        int k; cin >> k;
        auto it = a.upper_bound(k);
        if(it == a.end())
        {
            a.insert(k);
        }
        else
        {
            a.erase(it);
            a.insert(k);
        }
    }
    cout << sz(a);
	return 0;
}
