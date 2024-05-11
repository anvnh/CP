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

struct Node{
    char data;
    Node* left;
    Node* right;
};
Node* root = NULL;
void Init() 
{
    Node* p = new Node();
    p -> data = 'A';
    root = p;
    p = new Node();
    p -> data = 'B';
    root -> left = p;
    p = new Node();
    p -> data = 'C';
    root -> right = p;
    p = new Node();
    p -> data = 'D';
    root -> left -> left = p;
    p = new Node();
    p -> data = 'E';
    root -> left -> right = p;
    p = new Node();
    p -> data = 'F';
    root -> right -> left = p;
    p = new Node();
    p -> data = 'G';
    root -> right -> right = p;
}

void PreOrder() {
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* p = st.top();
        st.pop();
        cout << p -> data << " ";
        if (p -> right != NULL) st.push(p -> right);
        if (p -> left != NULL) st.push(p -> left);
    }
}

void InOrder() {
    stack<Node*> st;
    Node* p = root;
    while (p != NULL || !st.empty()) {
        while (p != NULL) {
            st.push(p);
            p = p -> left;
        }
        p = st.top();
        st.pop();
        cout << p -> data << " ";
        p = p -> right;
    }
}

void PostOrder() {
    stack<Node*> st;
    Node* p = root;
    Node* last = NULL;
    while (p != NULL || !st.empty()) {
        while (p != NULL) {
            st.push(p);
            p = p -> left;
        }
        p = st.top();
        if (p -> right == NULL || p -> right == last) {
            cout << p -> data << " ";
            st.pop();
            last = p;
            p = NULL;
        } else {
            p = p -> right;
        }
    }
}

void BFS() 
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        cout << p -> data << " ";
        if (p -> left != NULL) q.push(p -> left);
        if (p -> right != NULL) q.push(p -> right);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    Init();
    PreOrder();
    cout << endl;
    InOrder();
    cout << endl;
    PostOrder();
    cout << endl;
    BFS();
    return 0;
}
