//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
////#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const long double PI = 4 * atan((long double) 1);

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
		//cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;
struct mi {
	ll val;
	explicit operator ll() const { return val; }
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

const int MAX = 1e5 + 5;
const int LOG = 20;

int depth[MAX];
int par[MAX][LOG];
int id[MAX];
int a[MAX];
pi range[MAX];

vector<int> adj[MAX];

int n;
int num = -1;
int root = 0;

int dfs_id(int src, int par){
    num++;
    id[src] = num;
    int mn = num;
    int mx = num;
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        ckmax(mx, dfs_id(nxt, src));
    }
    range[src] = mp(mn, mx);
    return mx;
}
int kth_parent(int src, int up){
    for(int it = LOG-1; it>= 0; it--){
        if(up>= (1<<it)){
            up -= (1<<it);
            src = par[src][it];
        }
    }
    return src;
}
void dfs_process(int cur, int prev) {
    par[cur][0] = prev;
    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        depth[nxt] = depth[cur] + 1;
        dfs_process(nxt, cur);
    }
}
inline void process() {
    depth[0] = 0;
    dfs_process(0, 0);
    for (int lvl = 0; lvl < LOG - 1; lvl ++) for (int cur = 0; cur< n; cur++) {
        int mid = par[cur][lvl];
        par[cur][lvl + 1] = par[mid][lvl];
    }
}
inline int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int it = LOG - 1; it >= 0; it--)
        if (depth[u] - depth[v] >= (1 << it))
            u = par[u][it];
    if (u == v) return u;
    for (int it = LOG - 1; it >= 0; it--) {
        if (par[u][it] != par[v][it]) {
            u = par[u][it];
            v = par[v][it];
        }
    }
    return par[u][0];
}
template<class T, int SZ> struct LazySeg {
	T sum[2*SZ], lazy[2*SZ];
	LazySeg() { F0R(i,2*SZ) sum[i] = lazy[i] = 0; }
	void push(int ind, int L, int R) { /// modify values for current node
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		sum[ind] += (R-L+1)*lazy[ind]; lazy[ind] = 0;
	} // recalc values for current node
	void pull(int ind) { sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	T qsum(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
};
int anc(int src, int top){
    int len = depth[src]-depth[top];
    if(len<1)exit(0);
    return kth_parent(src, len-1);
}
LazySeg<ll, (1<<17)>  seg;
void change_down(int src, int x){
    if(src == root) src = 0;
    seg.upd(range[src].f, range[src].s, x);
    assert(LCA(src, root) != src || src == 0);
}
void change_up(int src, int x){

    if(src == root) {
        change_down(0, x);
        return;
    }
    seg.upd(0, n-1, x);
    int srca = anc(root, src);
    seg.upd(range[srca].f, range[srca].s, -x);
}


int main(){
    // setIO("");
    int q;
    re(n, q);
    f0r(i, n) re(a[i]);
    f0r(i, n-1){
        int u, v; re(u, v);
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    process();
    dfs_id(0, -1);
    f0r(i, n) seg.upd(id[i], id[i], a[i]);
    f0r(i, q){;
        int t; re(t);
        if(t == 1){
            int v; re(v);
            root = v-1;
        }
        else if(t == 2){
            int u, v, x;
            re(u, v, x);
            u--;
            v--;
            if(u == root || v == root){
                change_down(0, x);
                continue;
            }
            int top = LCA(LCA(u, v), root);
            if(u == v){
                if(top == u) change_up(u, x);
                else change_down(u, x);
                continue;
            }
            if(depth[u]>depth[v]) swap(u, v);
            if(top == root) change_down(LCA(u,v), x);
            else if(top == u) change_up(LCA(root, v), x);
            else if(top == v) change_up(LCA(root, u), x);
            else{
                int ua = anc(u, top);
                int va = anc(v, top);
                int ra = anc(root, top);
                if(ra == ua) change_up(LCA(u, root), x);
                else if(ra == va) change_up(LCA(v, root), x);
                else if(ua == va) change_down(LCA(u,v), x);
                else change_up(top, x);
            }
        }
        else{
            int v; re(v);
            v--;
            int lca = LCA(v, root);
            if(v == root) ps(seg.qsum(0, n-1));
            else if(lca == v){
                ll tot = seg.qsum(0, n-1);
                int ra = anc(root, v);
                tot -= seg.qsum(range[ra].f, range[ra].s);
                ps(tot);
            }
            else ps(seg.qsum(range[v].f, range[v].s));
        }
    }
    return 0;
}