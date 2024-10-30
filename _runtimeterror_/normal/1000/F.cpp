#include<bits/stdc++.h>
using namespace std ;

#define ll int 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int n;
const int N = 500005;
int last[N];
int a[N];
vector<pair<int,int>> query[N];

struct node
{
    int minimum;
    int idx;
}fake{(int)1e9,N};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.minimum = min(a.minimum,b.minimum);
        if(ret.minimum==a.minimum)
            ret.idx = a.idx;
        else
            ret.idx = b.idx;
        return ret;
    }
    inline node make_node(int st,ll val)
    {
        node ret;
        ret.minimum=val;
        ret.idx = st;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(st,a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(st,val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int ans[N];

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=N-1;++i)
        last[i] = -1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        seg.a[i] = 1e9;
    }
    seg.buildTree(1,0,n-1);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;++i)
    {
        int l,r;
        cin>>l>>r;
        --l,--r;
        query[r].pb({l,i});
    }
    for(int i=0;i<n;++i)
    {
        int x = last[a[i]];
        if(last[a[i]]!=-1)
            seg.update(1,0,n-1,last[a[i]],1e9);
        last[a[i]] = i;
        seg.update(1,0,n-1,last[a[i]],x);
        for(auto j:query[i])
        {
            node u = seg.query(1,0,n-1,j.F,i);
            if(u.minimum<j.F)
                ans[j.S] = a[u.idx];
            else
                ans[j.S] = 0;
        }
    }
    for(int i=0;i<Q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}