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

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

const int Mod = 998244353;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
};

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;

#define pzz pair<Zi, Zi>

pzz operator + (pzz a, pzz b) {
	return pzz(a.fi + b.fi, a.sc + b.sc);
}
pzz operator + (pzz a, Zi b) {
	return pzz(a.fi, a.sc + b);
}
pzz operator * (pzz a, Zi b) {
	return pzz(a.fi * b, a.sc * b);
}

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int> A (n);
	for (auto& x : A) {
		cin >> x;
		m += x;
	}
	vector<Zi> a(m), b(m), c(m);
   	vector<pzz> f(m + 1);
	vector<Zi> g(m + 1, 0);
	Zi invn = ~Zi(n - 1), invm = ~Zi(m);
	for (int i = 0; i < m; i++) {
		Zi coef = Zi(1) - Zi(m - i) * invm * (n - 2) * invn;
		a[i] = i * invm;
		b[i] = (m - i) * invm * invn;
		c[i] = ~coef;
		a[i] *= c[i], b[i] *= c[i];
		assert(b[i].v);
		b[i] = ~b[i];
		a[i] *= b[i], c[i] *= b[i];
		a[i] = -a[i], c[i] = -c[i];
	}
	f[0] = pzz(1, 0);
	f[1] = pzz(b[0], c[0]);
	for (int i = 1; i < m; i++) {
		f[i + 1] = f[i] * b[i] + f[i - 1] * a[i] + c[i];
	}
	assert(f[m].fi.v);
	g[0] = -f[m].sc * ~f[m].fi;
	for (int i = 1; i < m; i++) {
		g[i] = g[0] * f[i].fi + f[i].sc;		
	}
	Zi ans = -(n - 1) * g[0];
	for (auto x : A) {
		ans += g[x];
	}
	ans *= ~Zi(n);
	cout << ans.v << '\n';
	return 0;
}