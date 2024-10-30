#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
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

#define f1r(i,a,b) for (int i = (a); i < (b); ++i)
#define f0r(i,a) f1r(i,0,a)
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
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]"; }

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);
	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...); }
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
		pr(t); pr(ts...); }
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}"); }
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}"); }
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); }
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) { val = (ll)val*m.val%MOD;
		return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
const int MAX = 2e5 + 5;
const int INF = 1e9;
ll a[MAX], b[MAX];
int loc[MAX];
ll x, y; ll k;
ll ans = 0;
bool ok = true;
ll dp[MAX];
int in[MAX];
ll solve_bad(vi v, int len){

    if(sz(v) == 0) return 0;
    f0r(i, len+1) dp[i] = INF;
    f0r(i, len+1) in[i] = 0;
    for(auto z: v) in[z] = 1;
    ll cur = 0;
    ll cnt = 0;
////    ps(v);
    f0r(i, len+1){
        cnt += in[i];
        if(i>=k){
            cnt -= in[i-k];
            if(in[i-k]){
                cur = dp[i-k];
            }
            else ckmin(cur, dp[i-k]);
        }
        if(cnt) {
            if(i>=k-1) dp[i] = 1 + cur;
            else dp[i] = INF;
        }
        else dp[i] = cur;
//        ps(i, dp[i], "WH");
    }
    int last = 0;
    f0r(i, sz(v)) last = v[i];
    ll best = INF;
    f1r(i, last, len+1) ckmin(best, dp[i]);
    if(best>=INF) return -1;
    return best*x;
}
ll resolve(ll len){
    if(y*k<=x) return len*y;
    return len/k*x + (len%k)*y;
}
void solve(int l, int r){
    ll mx = max(a[l], a[r]);
    l++; r--;
    if(l>r) return;
    vi bad;
    f1r(i, l, r+1){
        if(a[i]>mx) bad.eb(i);
    }

    int ed = r-l;
    f0r(i, sz(bad)) bad[i] -= l;
    if(y*k<=x){
        int len = ed+1;
        if(sz(bad) == 0) {
            ans += resolve(len); return;
        }
        ll tot = ed+1;
        if(tot<k){
            ok = false; return;
        }
        tot -= k;
        ans += x;
        ans += tot*y;
        return;
    }
    ll amt = (solve_bad(bad, ed));
    if(amt == -1) {
        ok = false; return;
    }
    ans += amt;
    int le = r-l+1 - amt/x*k;
    amt = resolve(le);
    if(amt == -1){
        ok = false; return;
    }
    ans += amt;
}
int main(){
    setIO("");
    int n, m; re(n, m);
    re(x, k, y);
    f1r(i, 1, n+1) re(a[i]);
    f1r(i, 1, m+1) re(b[i]);
    int it = 1;
    int cur = 1;
    while(cur<=m&&it<=n){
        if(a[it] == b[cur]) {
            it++; cur++;
            continue;
        }
        it++;
    }
    if(cur != m+1){
        ps(-1); return 0;
    }
    vi good;
    f1r(i, 1, n+1) loc[a[i]] = i;
    f1r(i, 1, m+1) good.eb(loc[b[i]]);
    f0r(i, sz(good)+1){
        if(i == 0){
            solve(0, good[i]);
        }
        else if(i == sz(good)){
            solve(good[i-1], n+1);
        }
        else{
            solve(good[i-1], good[i]);
        }
    }
    if(ok) ps(ans);
    else ps(-1);
}