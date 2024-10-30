#include <bits/stdc++.h>
using namespace std;
        
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-6
#define INF 9e18
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R];
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
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
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

#define int ll

class SegTree
{
    public: 

    vll seg_tree;
    int n, siz, neutral_element;

    SegTree(int x)
    {           
        n = x;  // Storing a local copy of size of the array
        siz = 1;
        while(siz < x)
            siz *= 2;
        siz *= 2;

        // Set the neutral element. This should be the default value
        // of seg_tree array before buildTree too. 
        neutral_element = 0; 

        // Initializing seg_tree with default value i.e. neutral_element 
        FE(i, 1, siz)
            seg_tree.pb(neutral_element);
    }

    void buildTree(int si, int ss, int se, vi& arr)
    {
        if(ss==se)
        {
            seg_tree[si] = arr[ss];
            return;  
        }

        int mid = (ss+se)/2;

        buildTree(2*si, ss, mid, arr);
        buildTree(2*si+1, mid+1, se, arr);

        seg_tree[si] = max(seg_tree[2*si], seg_tree[2*si+1]);

        return;
    }

    void buildTree(vi& arr)
    {
        buildTree(1, 1, n, arr);
        return;
    }

    void updateTree(int si, int ss, int se, int qi, int v)
    {
        if(ss==se)
        {
            seg_tree[si] = v;
            return;
        }

        int mid = (ss+se)/2;

        if(qi <= mid)
            updateTree(2*si, ss, mid, qi, v);
        else
            updateTree(2*si+1, mid+1, se, qi, v);

        seg_tree[si] = max(seg_tree[2*si],  seg_tree[2*si+1]);

        return;
    }

    void updateTree(int qi, int v)
    {
        updateTree(1, 1, n, qi, v);
        return;
    }

    ll queryTree(int si, int ss, int se, int qs, int qe)
    {
        if(qs>se || ss>qe)
            return neutral_element;

        if(ss>=qs && se<=qe)
            return seg_tree[si];

        int mid = (ss+se)/2;
        ll lresult = queryTree(2*si, ss,  mid, qs, qe);
        ll rresult = queryTree(2*si+1, mid+1, se, qs, qe);

        return max(lresult, rresult);
    }

    ll queryTree(int qs, int qe)
    {
        return queryTree(1, 1, n, qs, qe);
    }
};
    
struct point
{
    int a, b, h;
    bool operator<(point& other) 
    {
        if(b == other.b)
            return a > other.a;
        return b > other.b;  
    }
};

void solve()
{            
    cini(n);

    vector<point> pt(n+1);
    FE(i,1,n)
        cin>>pt[i].a>>pt[i].b>>pt[i].h;

    int order = 0;
    map<int, int> M;

    FE(i,1,n)
    {
        M[pt[i].a] = 1;
        M[pt[i].b] = 1;
    }

    FA(x, M)
        M[x.fi] = ++order;    

    FE(i,1,n)
    {
        pt[i].a = M[pt[i].a];
        pt[i].b = M[pt[i].b];        
    }

    sort(1+all(pt));

    vll dp(2*n+1, 0);

    SegTree segA(2*n);
    segA.buildTree(dp);

    FE(i,1,n)
    {
        dp[pt[i].a] = pt[i].h + segA.queryTree(1, pt[i].b-1);
        segA.updateTree(pt[i].a, dp[pt[i].a]);
    }

    int maxi = 0;
    FE(i,1,2*n)
        maxi = max(maxi, dp[i]);

    cout<<maxi;

    return;
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t; 

    FE(i, 1, t)
        solve();

    return 0;
}