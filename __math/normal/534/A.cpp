#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int *x) { int k, m = 0; *x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { *x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; *x = (*x) * 10 + k - '0'; }if (m)(*x) = -(*x); }
void reader(ll *x) { int k, m = 0; *x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { *x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; *x = (*x) * 10 + k - '0'; }if (m)(*x) = -(*x); }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T *x, S *y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T *x, S *y, U *z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

int main() {
	int n; cin >> n;
	vector<int> v;
	if (n == 1) {
		v.push_back(1);
	} else if (n == 2) {
		v.push_back(1);
	} else if (n == 3) {
		v.push_back(1);
		v.push_back(3);
	} else if (n == 4) {
		v.push_back(2);
		v.push_back(4);
		v.push_back(1);
		v.push_back(3);
	}
	if (n >= 5) {
		FOR(i, n) {
			int x = 2 * i + 1;
			if (x > n) break;
			v.push_back(x);
		}
		FOR(i, n) {
			int x = 2 * i + 2;
			if (x > n) break;
			v.push_back(x);
		}
	}
	cout << sz(v) << endl;
	FOR(i, sz(v)) printf("%d ",v[i]);
	cout << endl;
}