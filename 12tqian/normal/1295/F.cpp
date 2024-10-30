#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const long double PI = 4*atan(1);

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define resz resize
#define ins insert

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...);
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }

	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);

	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
		pr(t); pr(ts...);
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}");
	}
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}");
	}

	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
	}

	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) {
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }

	friend bool operator==(const mi& a, const mi& b) {
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
const int MAXN = 55;
const int MAXC = 1e3 + 5;
int n;
ll l[MAXN];
ll r[MAXN];
map<int, int> conv;
int uconv[MAXC];
vpi gap;
/// current loc, current interval, number of stuff in that interval
/// when transitioning to new interval or finishing on smth, multiply
mi dp[MAXN][MAXC][MAXN];
bool cont[MAXN][MAXC];
vi trans[MAXN];
bool in(pi big, pi small){
    if(big.f<=small.f && small.s<=big.s) return true;
    return false;
}
mi inve[MAXC];
mi ways[MAXC][MAXN];
int main(){
    f0r(i, MAXC){
        if(i == 0) inve[i] = 1;
        else inve[i] = inve[i-1]/i;
    }
    mi tot = 1;
    re(n);
    f0r(i, n) re(l[i], r[i]);
    f0r(i, n) tot *= (r[i] - l[i]+1);
    reverse(l, l+n); reverse(r, r+n);
    set<int> pts;
    f0r(i, n) pts.insert(l[i]), pts.insert(r[i]);
    int cnt = 0;
    for(int x: pts){
        conv[x] = cnt;
        uconv[cnt] = x;
        cnt++;
    }
    f0r(i, sz(pts)){
        gap.eb(mp(uconv[i], uconv[i]));
        if(i<sz(pts) && uconv[i]+1<=uconv[i+1]-1) gap.eb(mp(uconv[i]+1, uconv[i+1]-1));
    }
    sort(all(gap));
    f0r(i, n){
        f0r(j, sz(gap)){
            if(in(mp(l[i], r[i]), gap[j])) cont[i][j] = true;
        }
    }
    f0r(i, sz(gap)){
        f0r(j, n+1){
            mi len = gap[i].s - gap[i].f + 1;
            mi top = len + j - 1;
            ways[i][j] = 1;
            f0r(it, j){
                ways[i][j] *= (top - it);
            }
            ways[i][j] *= inve[j];
        }
    }
    int num = sz(gap);
    f0r(i, n){
        if(i == 0){
            f0r(t, num){
                if(cont[i][t]) dp[i][t][1] = 1;
            }
        }
        else{
            /// transition
            f0r(t, num){
                f0r(bef, t+1){
                    if(!cont[i][t] || !cont[i-1][bef]) continue;
                    if(t == bef){
                        f1r(j, 2, n+1){
                            dp[i][t][j] += dp[i-1][bef][j-1];
                        }
                    }
                    else{
                        f1r(j, 1, n+1){
                            dp[i][t][1] += dp[i-1][bef][j]*ways[bef][j];
                        }
                    }
                }
            }
        }
    }
    mi res = 0;
    f0r(t, num){
        f1r(j, 1, n+1){
            res += dp[n-1][t][j]*ways[t][j];
            if(j == 1){
                mi val = dp[n-1][t][j] * ways[t][j];
                mi act = 0;
                f1r(n1, l[0], gap[t].f){
                    f1r(n2, gap[t].f, gap[t].s+1){
                        act+=1;
                    }
                }
            }
        }
    }
    ps(res/tot);
    return 0;
}