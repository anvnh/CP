#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    #endif
    int ntest; cin >> ntest;
    while(ntest--){
        int n; cin >> n;
        vector<int> s(3);
        for(int a = 1; a <= 26; a++)
        {
            for(int b = 1; b <= 26; b++)
            {
                for(int c = 1; c <= 26; c++)
                {
                    if(a + b + c == n)
                    {
                        s[0] = a;
                        s[1] = b;
                        s[2] = c;
                        break;
                    }
                }
            }
        }
        sort(s.begin(), s.end());
        cout << char(s[0] + 96) << char(s[1] + 96) << char(s[2] + 96) << endl;
    }
    return 0;
}
