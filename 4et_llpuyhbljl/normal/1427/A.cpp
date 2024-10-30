#pragma comment(linker, "/STACK:9759095000")
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
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    //file_inc();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto& x : a)cin >> x;
        int s1 = 0, s2 = 0;
        for (auto x : a) {
            if (x > 0)s1 += x;
            else s2 += x;
        }
        if (abs(s1) > abs(s2)) {
            cout << "YES\n";
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
            for (auto x : a)cout << x << " ";
            cout << endl;
            continue;
        }
        if (abs(s2) > abs(s1)) {
            cout << "YES\n";
            sort(a.begin(), a.end());
            //reverse(a.begin(), a.end());
            for (auto x : a)cout << x << " ";
            cout << endl;
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}