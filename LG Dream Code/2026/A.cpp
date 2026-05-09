/**
    Author: anvnh
    RyeNyn
    **/

#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
ios_base::sync_with_stdio(0);                                                \
cin.tie(0);                                                                  \
cout.tie(0);
#define anvnh signed main(void)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define _for(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f

// string score(const string &s) {
//     bool colored[26] = {};
//     string res;
//     for (char ch : s) {
//         int l = ch - 'A';
//         colored[l] = true;
//         int score = 0;
//         int r = pos_r[l], c = pos_c[l];

//         bool row_done = true;
//         for (int x : rows[r]) {
//             if (!colored[x]) {
//                 row_done = false;
//                 break;
//             }
//         }
//         if (row_done)
//             score++;

//         bool col_done = true;
//         for (int x : cols[c]) {
//             if (!colored[x]) {
//                 col_done = false;
//                 break;
//             }
//         }
//         if (col_done)
//             score++;

//         if (in_main[l]) {
//             bool done = true;
//             for (int x : main_diag) {
//                 if (!colored[x]) {
//                     done = false;
//                     break;
//                 }
//             }
//             if (done)
//                 score++;
//         }

//         if (in_anti[l]) {
//             bool done = true;
//             for (int x : anti_diag) {
//                 if (!colored[x]) {
//                     done = false;
//                     break;
//                 }
//             }
//             if (done)
//                 score++;
//         }

//         res += ('0' + score);
//     }
//     return res;
// }

void solve() {
    string s; cin >> s;
    string grid[3];
    cin >> grid[0] >> grid[1] >> grid[2];

    int pos_r[26], pos_c[26];
    vector<int> rows[3], cols[3];
    vector<int> main_diag, anti_diag;
    bool in_main[26], in_anti[26];

    for (int r = 0; r < 3; r++)
        rows[r].clear();
    for (int c = 0; c < 3; c++)
        rows[c].clear();

    main_diag.clear();
    anti_diag.clear();

    fill(all(in_main), false);
    fill(all(in_anti), false);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int l = grid[i][j] - 'A';
            // cout << l << nl;
            pos_r[l] = i;
            pos_c[l] = j;
            rows[i].pb(l);
            cols[j].pb(l);
            if (i == j) {
                main_diag.pb(l);
                in_main[l] = true;
            }
            if (i + j == 2) {
                anti_diag.pb(l);
                in_anti[l] = true;
            }
        }
    }

    auto score = [&](const string &s) -> string {
        bool colored[26] = {};
        string res;
        for (char ch : s) {
            int l = ch - 'A';
            colored[l] = true;
            int score = 0;
            int r = pos_r[l], c = pos_c[l];

            bool row_done = true;
            for (int x : rows[r]) {
                if (!colored[x]) {
                    row_done = false;
                    break;
                }
            }
            if (row_done)
                score++;

            bool col_done = true;
            for (int x : cols[c]) {
                if (!colored[x]) {
                    col_done = false;
                    break;
                }
            }
            if (col_done)
                score++;

            if (in_main[l]) {
                bool done = true;
                for (int x : main_diag) {
                    if (!colored[x]) {
                        done = false;
                        break;
                    }
                }
                if (done)
                    score++;
            }

            if (in_anti[l]) {
                bool done = true;
                for (int x : anti_diag) {
                    if (!colored[x]) {
                        done = false;
                        break;
                    }
                }
                if (done)
                    score++;
            }

            res += ('0' + score);
        }
        return res;
    };

    string target = score(s);

    string letters = s;
    sort(all(letters));

    string best;
    do {
        if (score(letters) == target) {
            best = letters;
            break;
        }
    } while (next_permutation(letters.begin(), letters.end()));

    cout << target << " " << best << nl;
}

anvnh {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    fastio int ntest;
    // ntest = 1;
    cin >> ntest;
    while (ntest--) {
        // clock_t z = clock();
        solve();
        // debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
