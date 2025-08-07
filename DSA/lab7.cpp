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
    int songID;
    string name;
    int length;
    Node* next;
};

Node* head = NULL;

void addFirst(int id, string name, int len)
{
    Node* add = new Node();
    add -> songID = id;
    add -> name = name;
    add -> length = len;
    add -> next = head;
    head = add;
    // Node* temp = new Node();
    // temp -> songID = id;
    // temp -> name = name;
    // temp -> length = len;
    // temp -> next = head;
    // head = temp;
}

void traversal()
{
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> songID << " " << temp -> name << " " << temp -> length << endl;
        temp = temp -> next;
    }
    cout << endl;
}

Node* findNode(int id)
{
    Node* temp = head;
    while(temp -> songID != id) {
        temp = temp -> next;
    }
    return temp;
}

void addAfter(int id, string name, int len, Node* Q)
{
    Node* add = new Node();
    add -> songID = id;
    add -> name = name;
    add -> length = len;
    add -> next = Q -> next; 
    Q -> next = add;
}

void DeleteN(){

}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    addFirst(1, "ASD", 3);
    addFirst(2, "ABC", 3);
    addFirst(3, "oiw", 3);
    addFirst(4, "aowid", 3);
    addFirst(5, "OAIWJD", 3);
    addFirst(6, "LAWID", 3);
    traversal();
    addAfter(100, "AHHAHA", 999, findNode(4));
    addAfter(999, "NAIXI", 1231, findNode(2));
    traversal();
    return 0;
}
