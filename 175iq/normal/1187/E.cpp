#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define clr(arr) memset((arr), 0, sizeof(arr))
#define setval(arr,value) memset(arr,value,sizeof(arr)) //set elements of array to some value
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]
//sort(begin(v), end(v), [] (int a, int b) { return a > b; });
 
 
//Constants
#define EPS 1e-8
#define PI 2*acos(0.0)
#define INF 0x3f3f3f3f
#define MOD 998244353
 
//Printing
#define coutA(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutA(a,0,a.size()-1)
 
//Checking bound
#define IN(i,l,r)   (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r)  (l<=i&&i<r)
#define INR(i,l,r)  (l<i&&i<=r)
 
//For loops
#define F(i,a,b)    for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FR(i,b,a)   for(int i=b; i>a; i--)
#define FRE(i,b,a)  for(int i=b; i>=a; i--)
#define FA(n,container)   for(auto n : container)
 
//For debug 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//Definitions
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vb vector<bool> 
#define vvi vector<vector<int> > 
#define viwv(vecname, N, value) vector<int> vecname(N, value) 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define vvig(vecname, N) vector<vector<int> > vecname(N) //For Graph 
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
//Directions
const int fx[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }
 
int N = 2e5 + 10;
vvig(gr,N);
vector<ll> dp(N,-1);
vector<ll> siz(N,0);
ll ans = -INF;
 
int calcsiz(int u, int p=-1)
{
    siz[u]=1;
    FA(v,gr[u])
    {
        if(v==p)
            continue;
        siz[u]+=calcsiz(v,u);
    }
    return siz[u];
}
 
ll calcdp(int u, int p=-1)
{
    dp[u]=siz[u];
    FA(v,gr[u]) 
    {
        if(v==p)
            continue;
        dp[u]+=calcdp(v,u);
    }
    return dp[u];
}
 
void reroot(int u, int p=-1)
{
    ans = max(ans,dp[u]);
    FA(v,gr[u]) 
    {
        if(v==p)
            continue;

        ll befsu = siz[u], befdpu = dp[u],  befdpv = dp[v];
            
        siz[u]-=siz[v];
        dp[u] -=dp[v];
        dp[u] -=siz[v];
 
        siz[v]+=siz[u];
        dp[v] +=dp[u];
        dp[v] +=siz[u];  
 
        reroot(v,u);
 
        siz[u] = befsu;
        dp[u]  =  befdpu;
        dp[v]  = befdpv ;

    }    
}
 
int main()
{
    fastIO;
    
    cini(n);
    F(i,0,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
    }
    calcsiz(1);
    debug(siz);
    calcdp(1);
    reroot(1);
    cout<<ans;
    return 0;
}