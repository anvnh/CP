#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    #endif
    int ntest; cin >> ntest;
    while(ntest--){
        int n; cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for(int&v : a) {
            cin >> v;
            sum += v;
        }
        sum /= n;
        bool check = true;
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > sum) res += (a[i] - sum);
            if(a[i] < sum)
            {
                res -= (sum - a[i]);
                if(res < 0) {check = false; break;}
            }
        }
        (check) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
