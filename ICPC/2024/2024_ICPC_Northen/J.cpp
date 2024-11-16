/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
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
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) {
   ((std::cout << args << ' '), ...);
   std::cout << '\n';
}
#define ll long long
#define pb push_back
#define fi first
#define se second
#define forn(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _n; ++i)
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
const ll MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

const double EPS = 1e-9;
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
};

struct Sensor {
    Point p;
    int r;
    Sensor(Point p, int r) : p(p), r(r) {}
};

// Tính khoảng cách từ điểm đến đoạn thẳng
double pointSegmentDist(Point p, Point a, Point b) {
    Point v = b - a;
    Point w = p - a;
    double c1 = w.x * v.x + w.y * v.y;
    if (c1 <= 0) return sqrt(pow(p.x - a.x, 2) + pow(p.y - a.y, 2));
    
    double c2 = v.x * v.x + v.y * v.y;
    if (c2 <= c1) return sqrt(pow(p.x - b.x, 2) + pow(p.y - b.y, 2));
    
    double b2 = c1 / c2;
    Point pb(a.x + b2 * v.x, a.y + b2 * v.y);
    return sqrt(pow(p.x - pb.x, 2) + pow(p.y - pb.y, 2));
}

// Kiểm tra xem đoạn thẳng có an toàn với cảm biến không
bool isSafe(Point start, Point end, const vector<Sensor>& activeSensors) {
    for (const Sensor& s : activeSensors) {
        if (pointSegmentDist(s.p, start, end) < s.r - EPS) {
            return false;
        }
    }
    return true;
}

// Kiểm tra xem có thể đi từ điểm start đến end với tập sensors không
bool canPass(Point start, Point end, const vector<Sensor>& sensors) {
    return isSafe(start, end, sensors);
}

int find(int L, int W, vector<Sensor>& sensors) {
    int n = sensors.size();
    int result = n;
    
    // Thử tất cả các tổ hợp cảm biến có thể bị phá hủy
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<Sensor> activeSensors;
        int destroyed = 0;
        
        // Tạo danh sách cảm biến còn hoạt động
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                activeSensors.pb(sensors[i]);
            } else {
                destroyed++;
            }
        }
        
        // Kiểm tra tất cả các điểm có thể đi từ (0,y1) đến (L,y2)
        bool possible = false;
        for (int y1 = 0; y1 <= W && !possible; y1++) {
            for (int y2 = 0; y2 <= W && !possible; y2++) {
                Point start(0, y1);
                Point end(L, y2);
                if (canPass(start, end, activeSensors)) {
                    possible = true;
                    result = min(result, destroyed);
                }
            }
        }
    }
    
    return result;
}

void solve()
{
    int L, W, N;
    cin >> L >> W >> N;
    
    vector<Sensor> sensors;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        sensors.pb(Sensor(Point(x, y), 100)); // R = 100 meters
    }
    
    cout << find(L, W, sensors) << endl;   
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    // ntest = 1;
    cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
