#include<bits/stdc++.h>

using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int a, b; cin >> a >> b;
        if(a&1 && b&1) 
        {
            cout << "NO" << endl;
        }
        else if(a % 2 == 0 && b % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if((a % 2 == 0 && b&1) || (a&1 && b % 2 == 0))
        {
            if(min(a, b) == 1)
            {
                if(max(a, b) > 2 && max(a, b) % 2 == 0)
                {
                    cout << "YES" << endl;
                }
                else cout << "NO" << endl;
            }
            else if(min(a, b) * 2 == max(a, b))
            {
                cout << "NO" << endl;
            }
            else cout << "YES" << endl;
        }
    }
    return 0;
}

