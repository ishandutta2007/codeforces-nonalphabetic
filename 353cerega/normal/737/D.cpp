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

inline ll pew(ll a, ll b, ll MOD)
{
    ll res = 1;
    while (b)
    {
        //if (b&1) res = mul(res,a);
        //a = mul(a,a);
        if (b&1) res = res*a%MOD;
        a = a*a%MOD;
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
}

//ll t[3200000];
//ll del[1200000];

/*
void build(int n)
{
    for (int i=0;i<=4*n;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v)
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

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] = (t[v]+val)%mod;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
}

ll get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);

}
*/

ll dp[100][100][4001];

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pr(n+1);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        pr[i+1] = pr[i]+a[i];
    }
    ll mx = 100;
    ll INF = 5000000000;
    for (ll i=0;i<=n;i++)
    {
        for (ll j=1;j<mx;j++)
        {
            for (ll d=0;d<mx;d++) dp[d][j][i] = -INF;
        }
    }
    for (ll k=mx-5;k>=1;k--)
    {
        for (ll p=n/2;p>=0;p--)
        {
            for (ll d=0;d<mx-5;d++)
            {
                ll L = n-p-p-d;
                if (L<0) continue;
                if (L<k)
                {
                    dp[d][k][p] = 0;
                    continue;
                }
                ll val = -INF;
                for (ll x=0;x<2;x++)
                {
                    ll curx = pr[p+x+k]-pr[p];
                    ll Lx = L-k-x;
                    if (Lx<0) continue;
                    ll mn = INF;
                    for (ll y=0;y<2;y++)
                    {
                        if (Lx<k+x+y) continue;
                        mn = min(mn,dp[d+y][k+x+y][p+k+x]-pr[p+L]+pr[p+L-k-x-y]);
                    }

                    if (mn==INF) mn = 0;
                    val = max(val,curx+mn);
                }
                dp[d][k][p] = val;
            }
        }
    }
    cout << dp[0][1][0] << endl;
}