#include <bits/stdc++.h>
using namespace std;
int upper_bound_custom(const vector<long long> &a, long long x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), cur(n);
    vector<int> skip(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cur[i] = a[i];
    }

    while (true) {
        vector<long long> b = cur;
        sort(b.begin(), b.end());

        vector<int> check(n, 0);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            long long x = cur[i];
            long long y = x + k;
            int u1 = b.size() - upper_bound_custom(b, x);
            int u2 = b.size() - upper_bound_custom(b, y);
            if (u1 == u2) {
                check[i] = 1;
            } else {
                skip[i]++;
                ok = false;
            }
        }
        if (ok) break;
        for (int i = 0; i < n; ++i) {
            if (check[i]) {
                cur[i] += k;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << skip[i] << ' ';
    }
    cout << '\n';
    return 0;
}
