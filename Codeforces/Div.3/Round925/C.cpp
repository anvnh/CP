#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    int ntest; cin >> ntest;
    while(ntest--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int&v : a) cin >> v;
        if(a[0] == a[n - 1])
        {
            int cntL = 0;
            int cntR = 0;
            for(int i = 1; i < n; i++)
            {
                if(a[i] == a[0])
                {
                    cntL++;
                }
                else break;
            }
            for(int i = n - 2; i >= 0; i--)
            {
                if(a[i] == a[n - 1])
                {
                    cntR++;
                }
                else break;
            }
            // cout << n - abs(cntL - cntR) - 2 << endl;
            if(cntL == n - 1 || cntR == n - 1)
            {
                cout << 0 << endl;
                continue;
            }
            else 
            {
                cout << n - 2 - cntL - cntR << endl;
            }   
        }
        else {
            int cntL = 0;
            int cntR = 0;
            for(int i = 1; i < n; i++)
            {
                if(a[i] == a[0])
                {
                    cntL++;
                }
                else break;
            }
            for(int i = n - 2; i >= 0; i--)
            {
                if(a[i] == a[n - 1])
                {
                    cntR++;
                }
                else break;
            }
            cout << min(n - 1 - cntL, n - 1 - cntR) << endl;
        }
    }
}
