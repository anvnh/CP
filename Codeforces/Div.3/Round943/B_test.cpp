#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char a[200005],b[200005];

void solve(){
    int k=0, j=1, i=1;
    while (i <= n && j <= m){
        if (a[i] == b[j]){
            k++; i++; j++;
        } else {
            j++;
        }
    }
    return cout << k << '\n', void();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin>>t;
    while (t>0){
    	cin>>n>>m;
    	for(int i=1; i<=n; i++){
    		cin>>a[i];
    	}
    	for(int i=1; i<=m; i++){
    		cin>>b[i];
    	}
    	solve();
    	t--;
    }
}
