#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
using namespace fastio;
#endif
const int MAXN = 5e5;
int n, p[MAXN + 5];
struct fenwick {
	int t[MAXN + 5];
	void clear() {for (int i = 1; i <= n; i++) t[i] = 0;}
	void add(int x, int v) {for (int i = x; i <= n; i += (i & (-i))) t[i] += v;}
	int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
} T;
int c[MAXN + 5];
void solve() {
	scanf("%d", &n); ll invs = 0;
	for (int i = 1; i <= n; i++) c[i] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	T.clear(); for (int i = 1; i <= n; i++) invs += T.query(n - p[i] + 1), T.add(n - p[i] + 1, 1);
	T.clear(); for (int i = 1; i <= n; i++) c[i] += 2 * T.query(p[i]) - (i - 1), T.add(p[i], 1);
	T.clear(); for (int i = n; i; i--) c[i] += 2 * T.query(p[i]), T.add(p[i], 1);
	sort(c + 1, c + n + 1);
	for (int i = 0; i <= n; i++) printf("%lld%c", invs - 1ll * i * (i - 1) / 2, " \n"[i == n]), invs += c[i + 1];
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}