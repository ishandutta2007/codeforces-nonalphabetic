#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

const ll mod = 1000000007;

ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}


ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
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
    return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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


int parent[600001];
int rnk[600001];

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
}

//ll t[1200000];
//ll del[1200000];

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/


/*void update (int v, int tl, int tr, int pos, ll val) {
    if (tl==tr)
    {
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (pos<=tm)
    {
        update(2*v,tl,tm,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    else
    {
        update(2*v+1,tm+1,tr,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    //update(2*v,tl,tm,l,tm,val);
    //update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}



ll get (int v, int tl, int tr, int l, int r) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/

vector<set<pair<ll,ll>>> kek;
vector<vector<ll>> g;
vector<ll> d, h;

void dfs0(int u, int p, int H)
{
    h[u] = H;
    for (int v: g[u])
    {
        if (v==p) continue;
        dfs0(v,u,H-1);
    }
}

void dfs(int u, int p)
{

    for (int v: g[u])
    {
        if (v==p) continue;
        dfs(v,u);
        while (kek[v].size()>0)
        {
            if (kek[v].begin()->X<h[u])
            {
                kek[v].erase(kek[v].begin());
            } else break;
        }
        if (kek[v].size()==0)
        {
            kek[u].clear();
            return;
        }
        if (kek[v].size()>kek[u].size())
        {
            swap(kek[u],kek[v]);
            swap(d[u],d[v]);
        }
        ll mnv = kek[v].begin()->Y+d[v];
        ll mnu = kek[u].begin()->Y+d[u];
        d[u] += mnv;
        for (auto cur: kek[v])
        {
            ll H = cur.X;
            ll S = cur.Y+d[v]+mnu-d[u];
            auto it = kek[u].lower_bound({H,0});
            if (it!=kek[u].end() and it->Y<=S) continue;
            kek[u].insert({H,S});
            it = kek[u].lower_bound({H,0});
            while (it!=kek[u].begin())
            {
                it--;
                if (it->Y>=S)
                {
                    kek[u].erase(it);
                    it = kek[u].lower_bound({H,0});
                } else break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    h.resize(n);
    kek.resize(n);
    g.resize(n);
    d.resize(n);
    for (int i=1;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs0(0,-1,n);
    for (int i=0;i<n;i++)
    {
        kek[i].insert({0,0});
    }
    for (int i=0;i<m;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        auto it = kek[u].lower_bound({h[v],0});
        if (it!=kek[u].end() and it->Y<=c) continue;
        kek[u].insert({h[v],c});
        it = kek[u].lower_bound({h[v],0});
        while (it!=kek[u].begin())
        {
            it--;
            if (it->Y>=c)
            {
                kek[u].erase(it);
                it = kek[u].lower_bound({h[v],0});
            } else break;
        }
    }
    dfs(0,-1);
    if (kek[0].size()==0)
    {
        cout << -1 << endl;
    } else cout << kek[0].begin()->Y+d[0] << endl;
}