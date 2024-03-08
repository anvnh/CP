#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isPrime(ll a)
{
	if (a == 1)
		return 0;
	for (int i = 2; i <= round(sqrt(a)); ++i)
		if (a % i == 0)
			return 0;
	return 1;
}
#define MOD 2004010501
#define MAX_N 100005
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &v : a)
		cin >> v;
	vector<int> mark(n, 1);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			mark[i] -= 2;
		}
	}
	for (auto x : mark)
		cout << x << " ";
	cout << endl;
	vector<int> suff(n + 1, 0);
}
