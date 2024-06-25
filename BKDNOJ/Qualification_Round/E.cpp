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


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* build(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = build(root->left, value);
    } 
    else {
        root->right = build(root->right, value);
    }

    return root; 
}

Node* find(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return find(root->left, value);
    }
    return find(root->right, value);
}

Node* LCA(Node* root, int A, int B) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data == A || root->data == B) {
        return root;
    }
    Node* leftLCA = LCA(root->left, A, B);
    Node* rightLCA = LCA(root->right, A, B);
    if (leftLCA && rightLCA) {
        return root;
    }
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

void res(Node* root, int target, int& min_val, int& max_val) {
    if (root == nullptr) {
        return;
    }
    min_val = min(min_val, root->data);
    max_val = max(max_val, root->data);
    if (root->data == target) {
        return;
    }
    if (target < root->data) {
        res(root->left, target, min_val, max_val);
    } else {
        res(root->right, target, min_val, max_val);
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    int A, B; cin >> A >> B;

    Node* root = nullptr;
    for(int i = 0; i < n; i++) {
        root = build(root, a[i]);
    }

    Node* lca = LCA(root, A, B);
    int min_val = INT_MAX, max_val = INT_MIN;
    res(lca, A, min_val, max_val);
    res(lca, B, min_val, max_val);
    cout << min_val << " " << max_val << endl;

}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
