#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = double;
#define X first
#define Y second

ll mod = 1000000007;

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

/*
const ll base = 10;

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>=base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> mod;
    //vector<vector<vector<ll>>> dp(3,vector<vector<ll>> (n+1,vector<ll>(n+1)));
    vector<vector<ll>> c(n+1);
    for (int i=0;i<=n;i++)
    {
        c[i].resize(i+1);
        c[i][0] = c[i][i] = 1;
        for (int j=1;j<i;j++) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
    }
    /*dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = 1;
    for (int L=1;L<=n;L++)
    {
        for (int q=1;q<=n;q++)
        {
            dp[2][L][q] += dp[2][L-1][q-1];
            if (L>1) dp[2][L][q] += dp[2][L-1][q-1];
            if (L>2)
            {
                if (L==3) dp[2][L][q] += dp[2][0][q-1];
                else
                {
                    dp[2][L][q] += dp[2][L-2][q-1];
                    dp[2][L][q] += dp[2][L-2][q-1];
                }
            }
            dp[1][L][q] += dp[1][L-1][q-1];
            if (L>1) dp[1][L][q] += dp[1][L-2][q-1];
        }
        for (int q=1;q<=n;q++)
        {
            for (int k=3;k<=L-2;k++)
            {
                for (int q1=1;q1<q;q1++) dp[2][L][q] += dp[2][k-1][q1]*dp[2][L-k][q-q1-1]%mod*c[q-1][q1]%mod;
            }
            dp[2][L][q] %= mod;
            for (int k=3;k<=L;k++)
            {
                for (int q1=1;q1<q;q1++) dp[1][L][q] += dp[2][k-1][q1]*dp[1][L-k][q-q1-1]%mod*c[q-1][q1]%mod;
            }
            dp[1][L][q] %= mod;
            for (int k=1;k<=L;k++)
            {
                for (int q1=0;q1<q;q1++) dp[0][L][q] += dp[1][k-1][q1]*dp[1][L-k][q-q1-1]%mod*c[q-1][q1]%mod;
            }
            dp[0][L][q] %= mod;
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) ans += dp[0][n][i];
    ans %= mod;
    cout << ans << endl;*/
    vector<ll> p2(n+1);
    p2[0] = 1;
    for (int i=1;i<=n;i++) p2[i] = p2[i-1]*2%mod;
    vector<vector<ll>> dp(n+2,vector<ll>(n+1));
    dp[0][0] = 1;
    for (int L=2;L<=n+1;L++)
    {
        for (int k=1;k<L;k++)
        {
            for (int x=0;x+k<=n;x++)
            {
                dp[L][k+x] += dp[L-k-1][x]*p2[k-1]%mod*c[k+x][x]%mod;
                dp[L][k+x] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) ans += dp[n+1][i];
    ans %= mod;
    cout << ans << endl;
}