#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}


ll sum(ll a, ll b)
{
    a += b;
    if (a>=mod) a -= mod;
    //a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    else return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a);
        a = mul(a,a);
        b >>= 1LL;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 30;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*
void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pew(n, mod-2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}*/


/*
int parent[1200001];
int rnk[1200001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}*/


ll t[1200000], t2[1200000], del[1200000];

void build()
{
    for (ll i=0;i<1200000;i++) t[i] = t2[i] = del[i] = 0;
}

void recalc(ll v, ll tl, ll tr, ll D)
{
    ll len = tr-tl+1;
    del[v] = (del[v]+D)%mod;
    t2[v] = (t2[v]+D*D%mod*len+2*t[v]*D)%mod;
    t[v] = (t[v]+D*len)%mod;
}

void push(ll v, ll tl, ll tr, ll tm)
{
    if (del[v]==0) return;
    recalc(2*v,tl,tm,del[v]);
    recalc(2*v+1,tm+1,tr,del[v]);
    del[v] = 0;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll D)
{
    if (tl>=l and tr<=r)
    {
        recalc(v,tl,tr,D);
        return;
    }
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    if (tm>=l) upd(v*2,tl,tm,l,r,D);
    if (tm<r) upd(v*2+1,tm+1,tr,l,r,D);
    t[v] = (t[2*v]+t[2*v+1])%mod;
    t2[v] = (t2[2*v]+t2[2*v+1])%mod;
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t2[v];
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    ll x = 0;
    if (tm>=l) x += get(v*2,tl,tm,l,r);
    if (tm<r) x += get(v*2+1,tm+1,tr,l,r);
    return x%mod;
}

vector<vector<pair<ll,ll>>> g;
vector<ll> d, L, R;

ll T = 0;
ll n;


void dfs(ll u, ll p, ll H, ll D)
{
    d[u] = D;
    L[u] = T++;
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        ll D2 = (D+g[u][i].Y)%mod;
        dfs(v,u,H+1,D2);
    }
    R[u] = T-1;
}

vector<vector<pair<ll,ll>>> Q;
vector<ll> ans;

void dfs1(ll u, ll p)
{
    for (ll i=0;i<Q[u].size();i++)
    {
        ll v = Q[u][i].X;
        ll j = Q[u][i].Y;
        ans[j] = 2*get(1,0,n-1,L[v],R[v])-get(1,0,n-1,0,n-1);
        ans[j] = (ans[j]+mod*mod)%mod;
    }
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        ll len = g[u][i].Y;
        upd(1,0,n-1,0,n-1,len);
        upd(1,0,n-1,L[v],R[v],(-2*len)%mod);
        dfs1(v,u);
        upd(1,0,n-1,0,n-1,-len);
        upd(1,0,n-1,L[v],R[v],(2*len)%mod);
    }
}

void solve()
{
    cin >> n;
    g.resize(n);
    L.resize(n);
    R.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    d.resize(n);
    dfs(0,-1,0,0);
    build();
    for (ll i=0;i<n;i++)
    {
        upd(1,0,n-1,L[i],L[i],d[i]);
    }
    ll q;
    cin >> q;
    Q.resize(n);
    ans.resize(q);
    for (ll i=0;i<q;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        Q[u].push_back({v,i});
    }
    dfs1(0,-1);
    for (ll i=0;i<q;i++) cout << ans[i] << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    /*ll T;
    T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }*/
}