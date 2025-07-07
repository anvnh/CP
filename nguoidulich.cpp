/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#define ll long long
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
// #define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

struct State {
    int node;
    int visited;
    double cost;
    double estimate;
    bool operator<(const State& other) const {
        return estimate > other.estimate;
    }
};

int n;
vector<vector<double>> dist;
vector<double> minEdge;

double heuristic(int visited) {
    double h = 0;
    for (int i = 0; i < n; ++i) {
        if ((visited & (1 << i)) == 0) {
            h += minEdge[i];
        }
    }
    return h;
}

double tsp() {
    priority_queue<State> pq;
    vector<vector<double>> cost(n, vector<double>(1 << n, 1e15));
    pq.push({0, 1, 0, heuristic(1)});
    cost[0][1] = 0;

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        if (cur.visited == (1 << n) - 1) {
            // Đã thăm hết, cộng chi phí quay về điểm xuất phát
            return cur.cost + dist[cur.node][0];
        }
        if (cur.cost > cost[cur.node][cur.visited]) continue;

        for (int nxt = 0; nxt < n; ++nxt) {
            if ((cur.visited & (1 << nxt)) == 0) {
                double newCost = cur.cost + dist[cur.node][nxt];
                int newVisited = cur.visited | (1 << nxt);
                if (newCost < cost[nxt][newVisited]) {
                    cost[nxt][newVisited] = newCost;
                    double f = newCost + heuristic(newVisited);
                    pq.push({nxt, newVisited, newCost, f});
                }
            }
        }
    }
    return -1;
}

void solve()
{
    cin >> n;
    dist.assign(n, vector<double>(n));
    minEdge.assign(n, 1e15);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] < minEdge[i]) {
                minEdge[i] = dist[i][j];
            }
        }
    }
    return cout << fixed << setprecision(2) << tsp() << nl, void();
}

anvnh {
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
