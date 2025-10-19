#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define maxn 100005
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    vector<string> res;
    sort(s.begin(), s.end());
    res.pb(s);
    while (next_permutation(s.begin(), s.end()))
    {
        res.pb(s);
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << endl;
}
