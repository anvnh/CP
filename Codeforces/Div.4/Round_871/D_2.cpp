//gah dang, imma pie12 【=◈︿◈=】
#include <bits/stdc++.h>
#define io freopen("main.inp","r",stdin); freopen("main.out","w",stdout);
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define hi signed main()
#define bye return 0;
// #define int long long
#define float long double
#define endl '\n'
using namespace std;

bool check(int n, int m){
    if(n == m) return true;
    if(n % 3 != 0) return false;
    return (check(2 * n / 3, m) || check(n / 3, m));
}
hi {
    fast
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << (check(n, m) ? "YES" : "NO") << endl; 
    }
    bye
}

