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

vector<char> stack;

void push(char c, vector<char>& stack) {
    stack.push_back(c);
}
void pop(vector<char>& stack) {
    stack.pop_back();
}
bool isEmpty(vector<char>& stack) {
    return stack.empty();
}

bool check(string s, vector<char>& stack)
{
    for(char c : s)
    {
        if(c == '(') push(c, stack);
        else if(c == ')')
        {
            if(isEmpty(stack)) return false;
            pop(stack);
        }
    }
    return true;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<char> stack;
    fastio
    string s; 
    getline(cin, s);
    check(s, stack) ? cout << "YES" : cout << "NO";
    return 0;
}
