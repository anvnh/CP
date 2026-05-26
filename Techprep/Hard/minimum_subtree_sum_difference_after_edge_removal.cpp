class Solution {
  public:
    int minimumDifference(int n, vector<int> &vals,
                          vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long tot = 0;
        for (int i = 0; i < n; i++)
            tot += vals[i];

        vector<int> par(n, -1);
        vector<int> order;
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            order.push_back(node);
            for (int i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    par[i] = node;
                    st.push(i);
                }
            }
        }

        vector<long long> subtree(n, 0);
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int node = order[i];
            subtree[node] = vals[node];
            for (int i : adj[node]) {
                if (par[i] == node) {
                    subtree[node] += subtree[i];
                }
            }
        }
        long long res = LLONG_MAX;
        for (int i = 1; i < n; i++) {
            long long diff = abs(tot - 2 * subtree[i]);
            if (diff < res) {
                res = diff;
            }
        }
        return res;
    }
};
