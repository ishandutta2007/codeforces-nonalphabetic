#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#include <iomanip>
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

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]"; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

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

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

const int MOD = 1e9 + 7; // 998244353;
const ld PI = acos((ld) -1);

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
    mi& operator*=(const mi& m) { val = (ll) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int main(){
//    setIO("");
    string s; re(s);
    int n = sz(s);
    vector<pair<int, string>> ans(n);
    vector<pair<char, int>> rev;
    vector<int> label;
    int it1=0;
    int it2=0;
    vector<int> l(n);
    int cnt=0;
    while(it1!=n){
        while(it2!=n-1&&s[it1]==s[it2+1]) it2++;
        f1r(i, it1, it2+1) l[i]=cnt;
        cnt++;
        it1=++it2;
    }
    int tot = 0;
    for(int i = n-1; i >= 0; i--){
        rev.eb(s[i], 1);
        label.eb(l[i]);
        tot++;
        while(sz(rev) >= 2){
            int sz = sz(rev);
            if(rev[sz-1].f==rev[sz-2].f&&label[sz-1]==label[sz-2]){
                rev[sz-2].s+=rev[sz-1].s;
                rev.pop_back();
                label.pop_back();
                continue;
            }
            int it = sz-2;
            while(it >= 0 && rev[sz-1].f == rev[it].f) it--;
            if(it<0){
                if(rev.back().s%2==0){
                    tot-=rev.back().s;
                    rev.pop_back();
                    label.pop_back();
                }
                else{
                    tot-=(rev.back().s-1);
                    rev.back().s = 1;
                }
                break;
            }
            if(rev[sz-1].f<rev[it].f){
                break;
            }
            else if(rev[sz-1].f>rev[it].f){
                if(rev[sz-1].s%2==0){
                    tot -= rev.back().s;
                    rev.pop_back();
                    label.pop_back();
                }
                else{
                    tot -= ((rev[sz-1].s)-1);
                    rev[sz-1].s %= 2;
                    break;
                }
            }

        }
        if(sz(rev)==1){
            if(rev[0].s%2==0) {
                tot -= rev.back().s;
                rev.pop_back();
                label.pop_back();
            }
            else {
                tot -= (rev[0].s-1);
                rev[0].s = 1;
            }
        }
        ans[i].f = tot;
        if(tot<=10){
            string fr = "";
            for(int it = sz(rev)-1; it>=0; it--){
                f0r(j, rev[it].s){
                    fr+=rev[it].f;
                }
            }
            ans[i].s = fr;
            continue;
        }
        int cnt = 0;
        int it = sz(rev)-1;
        string fr = "";
        while(sz(fr) < 5){
            f0r(j, rev[it].s){
                fr += rev[it].f;
                if(sz(fr) >= 5){
                    break;
                }
            }
            it--;
        }
        string ba = "";
        it = 0;
        while(sz(ba) < 2){
            f0r(j, rev[it].s){
                ba += rev[it].f;
                if(sz(ba) >= 2){
                    break;
                }
            }
            it++;
        }
        reverse(all(ba));
        ans[i].s = (fr+"..."+ba);
    }
    f0r(i, n){
        ps(ans[i].f, ans[i].s);
    }
    return 0;
}