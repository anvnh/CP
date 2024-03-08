#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

const int Max = 10000;

void Nhap(int A[], int n)
{
    for(int i = 0; i < n; i++) cin >> A[i];
}
void Xuat(int A[], int n)
{
    for(int i = 0; i < n; i++) cout << A[i] << " ";
}
int Tong(int A[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++) sum += A[i];
    return sum;
}
float TBCChan(int A[], int n)
{
    float avg = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(!(A[i]&1)) 
        {
            cnt++;
            avg += A[i];
        }
    }
    return (cnt == 0) ? 0 : avg / cnt;
}
int DemLe(int A[], int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i]&1) cnt++;
    }
    return cnt;
}
void inXY(int A[], int n, int x, int y)
{
    for(int i = 0; i < n; i++)
    {
        if(A[i] >= x && A[i] <= y) cout << A[i] << " ";
    }
}
int TimKiem(int x, int A[], int n)
{
    int res = -1;
    for(int i = 0; i < n; i++)
    {
        if(A[i] == x) 
        {
            res = A[i];
            break;
        }
    }
    return res;
}
void Chen(int x, int p, int A[], int *n)
{
    for(int i = *n; i > p; i--) A[i] = A[i - 1];
    A[p] = x;
    (*n)++;
}
void Xoa(int p, int A[], int *n)
{
    for(int i = p; i < *n - 1; i++) A[i] = A[i + 1];
    (*n)--;
}


signed main()
{
    int n = 5;
    int A[Max];
    Nhap(A, n);
    Xuat(A, n);
    cout << endl;
    cout << TBCChan(A, n);
    cout << endl;
    cout << DemLe(A, n);
    cout << endl;
    inXY(A, n, 2, 4);
    cout << endl;
    cout << TimKiem(3, A, n);
    Chen(3, 2, A, &n);
    cout << endl;
    Xuat(A, n);
    cout << endl;
    Xoa(2, A, &n);
    Xuat(A, n);
    return 0;
}
