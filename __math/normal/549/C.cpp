#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T CRT(T r1, T m1, T r2, T m2) { T a1, a2; extgcd(m1, m2, a1, a2); T ret = (m1*a1*r2 + m2*a2*r1) % (m1*m2); return ret < 0 ? ret + m1 * m2 : ret; }


int memo[100][100];

int _k;
int dfs(int a, int b, int k){
	if (memo[a][b] != -1) return memo[a][b];
	if (k == 0) {
		if (_k % 2 == 0)  return b % 2 == 1;
		else return b % 2 == 0;
	}
	int val = 0;
	if (a != 0) val = max(val, dfs(a - 1, b, k - 1) ^ 1);
	if (b != 0) val = max(val, dfs(a, b - 1, k - 1) ^ 1);
	return memo[a][b] = val;
}

int solve_dfs(int e, int o, int m){
	memset(memo, -1, sizeof(memo));
	_k = m;
	int ans = dfs(e, o, m);
	return ans;
}

int solve(int e, int o, int m){
	if (m == 0)return o % 2;
	if (o == 0) return 0;
	if (e + o + 1 == m) return 0;
	if (m > o * 2) return 0;
	if (m < e * 2) return m % 2;
	else return (m+o+e) % 2;
}

void test(){
	FOR(e, 10){
		FOR(o, 10){
			printf("%d %d : ",e,o);
			FOR(k, e + o + 1){
				int x = solve_dfs(e, o, k);
				printf("%d ", x);
				int y = solve(e, o, k);
				if (x != y) {
					cout << "?";
				}
			}
			puts("");
		}
	}
}

int main(){

	// test();

	int n, m;
	cin >> n >> m;
	int e = 0, o = 0;
	FOR(i, n){
		int x; reader(x);
		if (x % 2 == 0) e++;
		else o++;
	}
	m = n - m;

	int ans = solve(e, o, m);

	if (ans) puts("Stannis");
	else puts("Daenerys");

	return 0;
}