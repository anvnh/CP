#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> a(n);
    for(int&x : a)
    {
        cin>>x;
    }
    for(int x : a)
    {
        int count_smaller = 0;
        for(int y : a)
        {
            if(y < x)
            {
                ++count_smaller;
            }
        }
        if(count_smaller == 1)
        {
            cout<<x;
            return 0;
        }
    }
    assert(false);
}
