#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
int discrete(T* a, int* b, int n) {
	vector<T> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 5e5 + 5;

typedef class Event {
	public:
		int op, p, x;

		Event(int op, int p, int x) : op(op), p(p), x(x) {	}

		boolean operator < (Event b) const {
			if (p ^ b.p)
				return p < b.p;
			return op < b.op;
		} 
} Event;

#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:

		Input() : file(NULL)	{	};
		Input(FILE* file) : file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return (ss == st) ? (-1) : (buf[ss++]);
		}
} Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, double& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	if (x == '.') {
		double dec = 1;
		for ( ; ~(x = in.pick()) && digit(x); u = u + (dec *= 0.1) * (x - '0'));
	}
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, char* str) {
	char x;
	while (~(x = in.pick()) && x != '\n' && x != ' ')
		*(str++) = x;
	*str = 0;
	return in;
}

Input in (stdin);

typedef class Output {
	protected:
		const static int Limit = 65536;
		char *tp, *ed;
		char buf[Limit];
		FILE* file;
		int precision;

		void flush() {
			fwrite(buf, 1, tp - buf, file);
			fflush(file);
			tp = buf;
		}

	public:

		Output() {	}
		Output(FILE* file) : tp(buf), ed(buf + Limit), file(file), precision(6) {	}
		Output(const char *str) : tp(buf), ed(buf + Limit), precision(6) {
			file = fopen(str, "w");
		}
		~Output() {
			flush();
		}

		void put(char x) {
			if (tp == ed)
				flush();
			*(tp++) = x;
		}

		int get_precision() {
			return precision;
		}
		void set_percision(int x) {
			precision = x;
		}
} Output;

Output& operator << (Output& out, int x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, long long x) {
	static char buf[36];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, unsigned x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, char x)  {
	out.put(x);
	return out;
}

Output& operator << (Output& out, const char* str) {
	for ( ; *str; out.put(*(str++)));
	return out;
}

Output& operator << (Output& out, double x) {
	int y = x;
	x -= y;
	out << y << '.';
	for (int i = out.get_precision(); i; i--, y = x * 10, x = x * 10 - y, out.put(y + '0'));
	return out;
}

Output out (stdout);

int n;
set<int> S;
bitset<N> on;
int a[N], b[N], uf[N];

int find(int x) {
	return uf[x] == x ? x : (uf[x] = find(uf[x]));
}

void cover(int l, int r, int v) {
	for (int i = find(l); i <= r; i = find(uf[i] = i + 1))
		b[i] = v;
}

void update(int p, int v) {
	int L = *--S.lower_bound(p);
	int R = *S.lower_bound(p);
	int hl = (R - L - 1) >> 1;
	++L;
	if (on.test(L))
		cover(L, L + hl, v);
	if (on.test(R))
		cover(R - hl, R, v);
}

int main() {
	in >> n;
	vector<Event> E;
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		E.eb(0, a[i], i);
		E.eb(1, a[i], i);
	}
	for (int i = 1; i <= n + 1; i++) {
		uf[i] = i;
	}
	sort(E.begin(), E.end());
	for (int i = 0; i <= n; i++)
		S.insert(i);
	int ans = 0;
	for (auto e : E) {
		int p = e.x;
		if (!e.op) {
			if (p > 1 && on.test(p) == on.test(p - 1)) S.erase(p - 1);
			if (p < n && on.test(p) == on.test(p + 1)) S.erase(p);
			on.flip(p);
			if (p > 1 && on.test(p) == on.test(p - 1)) S.insert(p - 1);
			if (p < n && on.test(p) == on.test(p + 1)) S.insert(p);
		} else {
			int L = *--S.lower_bound(p);
			int R = *S.lower_bound(p);
			vmax(ans, (R - L - 1) >> 1);
			update(p, e.p);
			if (L) update(L, e.p);
			if (R < n) update(R + 1, e.p);
		}
	}
	out << ans << '\n';
	for (int i = 1; i <= n; i++)
		out << b[i] << " ";
	return 0;
}