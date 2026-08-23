/**
    Author: anvnh
    RyeNyn
**/
#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
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
const ll MOD = 1e9 + 7;

ll N;

ll norm(ll x)
{
    x %= MOD;
    if (x < 0)
        x += MOD;
    return x;
}
ll madd(ll a, ll b) { return norm(a + b); }
ll msub(ll a, ll b) { return norm(a - b); }
ll mmul(ll a, ll b) { return norm(norm(a) * norm(b) % MOD); }

ll modpow(ll b, ll e, ll m)
{
    ll r = 1;
    b %= m;
    if (b < 0)
        b += m;
    while (e > 0)
    {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

ll INV2, INV6;

ll floorDiv(ll a, ll b)
{
    ll q = a / b;
    if ((a % b != 0) && ((a < 0) != (b < 0)))
        q--;
    return q;
}
ll ceilDiv(ll a, ll b) { return -floorDiv(-a, b); }

ll sumK(ll n)
{
    if (n <= 0)
        return 0;
    ll n1 = norm(n), n2 = norm(n + 1);
    return mmul(mmul(n1, n2), INV2);
}
ll sumK2(ll n)
{
    if (n <= 0)
        return 0;
    ll n1 = norm(n), n2 = norm(n + 1), n3 = norm(2 * n + 1);
    return mmul(mmul(mmul(n1, n2), n3), INV6);
}
ll sumK3(ll n)
{
    ll s = sumK(n);
    return mmul(s, s);
}

ll S1(ll a, ll b)
{
    if (a > b)
        return 0;
    return msub(sumK(b), sumK(a - 1));
}
ll S2(ll a, ll b)
{
    if (a > b)
        return 0;
    return msub(sumK2(b), sumK2(a - 1));
}
ll S3(ll a, ll b)
{
    if (a > b)
        return 0;
    return msub(sumK3(b), sumK3(a - 1));
}

// domainType 1 => edge_lo(k)=1-k, edge_hi(k)=k
// domainType 2 => edge_lo(k)=-k,  edge_hi(k)=k-1
ll edgeSum(ll kmin, ll kmax, ll A, ll B_, ll C, ll sign, int domainType, ll flo, ll fhi)
{
    if (kmin > kmax)
        return 0;
    ll kb_lo, kb_hi;
    ll eL0, eL1, eH0, eH1;
    if (domainType == 1)
    {
        kb_lo = 1 - flo;
        kb_hi = fhi;
        eL0 = 1;
        eL1 = -1;
        eH0 = 0;
        eH1 = 1;
    }
    else
    {
        kb_lo = -flo;
        kb_hi = fhi + 1;
        eL0 = 0;
        eL1 = -1;
        eH0 = -1;
        eH1 = 1;
    }

    vector<ll> pts;
    pts.pb(kmin);
    pts.pb(kmax + 1);
    auto addbp = [&](ll v)
    {
        if (v >= kmin && v <= kmax)
            pts.pb(v);
        if (v + 1 >= kmin && v + 1 <= kmax)
            pts.pb(v + 1);
    };
    addbp(kb_lo);
    addbp(kb_hi);
    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());

    ll total = 0;
    for (size_t i = 0; i + 1 < pts.size(); i++)
    {
        ll a = pts[i], b = pts[i + 1] - 1;
        if (a < kmin)
            a = kmin;
        if (b > kmax)
            b = kmax;
        if (a > b)
            continue;
        ll L0, L1, H0, H1;
        if (a <= kb_lo)
        {
            L0 = eL0;
            L1 = eL1;
        }
        else
        {
            L0 = flo;
            L1 = 0;
        }
        if (a <= kb_hi)
        {
            H0 = eH0;
            H1 = eH1;
        }
        else
        {
            H0 = fhi;
            H1 = 0;
        }
        ll C0 = H0 - L0 + 1, C1 = H1 - L1;
        ll a2 = a, b2 = b;
        if (C1 == 0)
        {
            if (C0 < 1)
                continue;
        }
        else
        {
            ll lowk = ceilDiv(1 - C0, C1);
            if (lowk > a2)
                a2 = lowk;
        }
        if (a2 > b2)
            continue;
        ll M0 = L0 + H0, M1 = L1 + H1;
        ll A_m = norm(A), B_m = norm(B_), C_m = norm(C), C0_m = norm(C0), C1_m = norm(C1);
        ll M0_m = norm(M0), M1_m = norm(M1);
        ll signInv2 = (sign == 1) ? INV2 : norm(MOD - INV2);
        ll c3 = mmul(A_m, C1_m);
        ll c2 = madd(madd(mmul(A_m, C0_m), mmul(B_m, C1_m)), mmul(signInv2, mmul(M1_m, C1_m)));
        ll c1 = madd(madd(mmul(B_m, C0_m), mmul(C_m, C1_m)), mmul(signInv2, madd(mmul(M0_m, C1_m), mmul(M1_m, C0_m))));
        ll c0 = madd(mmul(C_m, C0_m), mmul(signInv2, mmul(M0_m, C0_m)));

        ll s3 = S3(a2, b2), s2 = S2(a2, b2), s1 = S1(a2, b2), cnt = norm(b2 - a2 + 1);
        ll seg = madd(madd(mmul(c3, s3), mmul(c2, s2)), madd(mmul(c1, s1), mmul(c0, cnt)));
        total = madd(total, seg);
    }
    return total;
}

void solve(int n)
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll ans = 0;
    if (x1 <= 0 && 0 <= x2 && y1 <= 0 && 0 <= y2)
        ans = madd(ans, 1);
    { // Right edge
        ll kmin = max(1LL, x1), kmax = min(x2, N);
        ans = madd(ans, edgeSum(kmin, kmax, 4, -3, 1, 1, 1, y1, y2));
    }
    { // Bottom edge
        ll kmin = max(1LL, -y2), kmax = min(-y1, N);
        ans = madd(ans, edgeSum(kmin, kmax, 4, 3, 1, 1, 1, x1, x2));
    }
    { // Top edge
        ll kmin = max(1LL, y1), kmax = min(y2, N);
        ans = madd(ans, edgeSum(kmin, kmax, 4, -1, 1, -1, 2, x1, x2));
    }
    { // Left edge
        ll kmin = max(1LL, -x2), kmax = min(-x1, N);
        ans = madd(ans, edgeSum(kmin, kmax, 4, 1, 1, -1, 2, y1, y2));
    }

    cout << ans << nl;
}
anvnh
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio int ntest;
    cin >> N;
    ntest = 1;
    cin >> ntest;
    INV2 = modpow(2, MOD - 2, MOD);
    INV6 = modpow(6, MOD - 2, MOD);
    while (ntest--)
    {
        clock_t z = clock();
        solve(N);
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}