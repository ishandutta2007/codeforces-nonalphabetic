#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#include<ctime>
#define double long double
#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 1e18;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300000, maxT = 2001;
long long solve(int f, int s) {
    long long tmp = f + s;
    if (tmp >= 0)return (tmp + 1) / 2;
    else return tmp / 2;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; ++i)cin >> a[i];
        int s = 0;
        for (int i = n - 1; i >= 1; --i) {
            a[i] -= a[i - 1];
            if (a[i] >= 0)s += a[i];
        }
        cout << solve(a[0], s) << "\n";
        int q;
        cin >> q;
        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            --r;
            if (l == 0) {
                a[0] += x;
            }
            else {
                if (a[l] > 0)s -= a[l];
                a[l] += x;
                if (a[l] > 0)s += a[l];
            }
            if (r + 1 != n) {
                if (a[r + 1] > 0)s -= a[r + 1];
                a[r + 1] -= x;
                if (a[r + 1] > 0)s += a[r + 1];
            }
            cout << solve(a[0], s) << "\n";
        }
    }
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/