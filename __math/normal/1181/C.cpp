#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

#ifdef _MSC_VER
template <typename ... Args>
void debugPrintf(const char *format, Args const & ... args) {
	fprintf(stderr, format, args ...);
	fflush(stderr);
}
#else
#define debugPrintf(...)
#endif
const int MOD = ten(9) + 7;

char s[1001][1001];
int sm[26][1001][1001];
int h[1001][1001];

int maxLen(int a, int b, int uh, int m) {
	auto& d = sm[s[a][b] - 'a'];
	auto& e = sm[s[a + uh][b] - 'a'];
	auto& f = sm[s[a + uh * 2][b] - 'a'];

	int l = 0, r = m - b + 1;
	while (r - l != 1) {
		int md = (l + r) / 2;
		int sm1 = d[a + uh][b + md] - d[a][b + md] - d[a + uh][b] + d[a][b];
		int sm2 = e[a + uh * 2][b + md] - e[a + uh][b + md] - e[a + uh * 2][b] + e[a + uh][b];
		int sm3 = f[a + uh * 3][b + md] - f[a + uh * 2][b + md] - f[a + uh * 3][b] + f[a + uh * 2][b];
		if (sm1 == sm2 && sm2 == sm3 && sm3 == uh * md) {
			l = md;
		} else {
			r = md;
		}
	}
	return l;
}

int main() {
	int n, m; reader(n, m);
	FOR(i, n) reader(s[i]);
	FOR(i, n) FOR(j, m) {
		sm[s[i][j] - 'a'][i + 1][j + 1] = 1;
	}
	FOR(x, 26) {
		auto d = sm[x];
		FOR(i, n) FOR(j, m) {
			d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
		}
	}
	FOR(j, m) {
		int x = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i][j] != s[i + 1][j]) {
				x = 0;
			}
			x++;
			h[i][j] = x;
		}
	}

	ll ans = 0;
	FOR(i, n) FOR(j, m) {
		int uh = h[i][j];
		if (i + uh * 3 > n) continue;
		if (h[i][j] != h[i + uh][j]) continue;
		if (h[i][j] > h[i + uh * 2][j]) continue;

		int l1 = maxLen(i, j, uh, m);
		ans += l1;
	}
	writerLn(ans);

	return 0;
}