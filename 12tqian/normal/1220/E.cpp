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
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
 
using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
const ll MOD = 1e9 + 7;
 
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
const int MAX = 2e5 + 5;
vi adj[MAX];
ll w [MAX];
int cut[MAX];
vi pnts;
template<int SZ> struct BCC {
    int N;
    vector<int> adj[SZ];
    vector<vector<pair<int, int>>> fin;
 
    void addEdge(int u, int v) {
        adj[u].push_back(v), adj[v].push_back(u);
    }
 
    int ti = 0, disc[SZ], low[SZ], comp[SZ], par[SZ];
    vector<pair<int, int>> st;
 
    void BCCutil(int u, bool root = 0) {
        disc[u] = low[u] = ti++;
        int child = 0;
        for (int i: adj[u]) {
            if (i != par[u]){
                if (disc[i] == -1) {
                    child ++; par[i] = u;
                    st.push_back({u,i});
                    BCCutil(i);
                    low[u] = min(low[u],low[i]);
 
                    if ((root && child > 1) || (!root && disc[u] <= low[i])) { // articulation point!
                        vector<pair<int, int>> tmp;
                        while (st.back() != make_pair(u,i)) tmp.push_back(st.back()), st.pop_back();
                        tmp.push_back(st.back()), st.pop_back();
                        fin.push_back(tmp);
                    }
                }
                else if (disc[i] < disc[u]) {
                    low[u] = min(low[u],disc[i]);
                    st.push_back({u,i});
                }
            }
        }
    }
 
    void bcc(int _N) {
        N = _N;
        for(int i = 1; i< N+1; i++){
            par[i] = disc[i] = low[i] = -1;
        }
        for(int i = 1; i<N+1; i++){
            if (disc[i] == -1) {
                BCCutil(i,1);
                if ((st).size()) fin.push_back(st);
                st.clear();
            }
        }
    }
};
BCC<MAX> bcc;
vi graph[MAX];
int vis[MAX];
int sub [MAX];
int parent[MAX];
int good[MAX];
ll path[MAX];
ll mx[MAX];
ll best = 0;
void dfs(int src){
	vis[src] = 1;
	for(int nxt: adj[src]){
		if(vis[nxt] == 1) continue;
		graph[nxt].eb(src);
		parent[nxt] = src;
		graph[src].eb(nxt);
		dfs(nxt);
	}
}
void dfs_sub(int src, int par){
	ckmax(sub[src], good[src]);
	for(int nxt: graph[src]){
		if(nxt == par) continue;
		dfs_sub(nxt, src);
		ckmax(sub[src], sub[nxt]);
	}
}
void dfs_sum(int src, int par){
	if(par != -1) path[src] = path[par] + w[src];
	for(int nxt: graph[src]){
		if(nxt == par) continue;
		dfs_sum(nxt, src);
	}
}
//ll best = 0;
void dfs_max(int src, int par){
	mx[src] = path[src];
	for(int nxt: graph[src]){
		if(nxt == par) continue;
		dfs_max(nxt, src);
		ckmax(mx[src], mx[nxt]);
	}
	//if(src == 7) ps(sub[src], path[src], mx[src], w[src], "HUH");
	if(sub[src] == 0) ckmax(best, mx[src] - path[src] + w[src]);
}
 
int main(){
	setIO("");
	int n, m;
	re(n, m);
	f0r(i, n){
		re(w[i]);
	}
	f0r(i, m){
		int u, v;
		re(u, v);
		u--; v--;
		adj[u].eb(v);
		adj[v].eb(u);
		bcc.addEdge(u+1, v+1);
	}

	bcc.bcc(n);
	int s;
	re(s);
	s--;

	f0r(i, n) good[i] = 0;

	for(auto& x: bcc.fin){
		if(sz(x) == 1) continue;
		for(auto& y: x){
			good[y.f-1] = 1;
			good[y.s-1] = 1;
		}
	}
	//return 0;
	dfs(s);
	dfs_sub(s, -1);
	good[s]=  1;
	//return 0;
	ll ans = 0;
	sub[s] = 1;
	parent[s] = -1;
	f0r(i, n){
		if(sub[i] == 1) ans += w[i];
	}
	//f0r(i, n) ps(i+1, good[i], "GOOD");
	//f0r(i, n) ps(i+1, sub[i], "SUB");
	//ll best //= 0;

	/*f0r(i,n){
		if(sz(adj[i]) == 1 && sub[i] == 0){
			int cur = i;
			ll cumsum = 0;
			while(cur != -1 && sub[cur] == 0){
				cumsum += w[cur];
				cur = parent[cur];
		
			}
			ckmax(best, cumsum);
		}
	}*/
	dfs_sum(s, -1);
	dfs_max(s, -1);
	ans += best;
	ps(ans);
	
	return 0;
}