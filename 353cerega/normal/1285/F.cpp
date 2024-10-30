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



int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll mx = 100000;
    vector<vector<ll>> d(mx+1), q(mx+1);
    vector<ll> a(mx+1);
    for (ll i=1;i<=mx;i++)
    {
        if (i!=1 and d[i].size()==1)
        {
            for (ll j=i;j<=mx;j+=i)
            {
                q[j].push_back(i);
            }
        }
        for (ll j=i;j<=mx;j+=i)
        {
            d[j].push_back(i);
        }
    }
    for (ll z=0;z<n;z++)
    {
        ll x;
        cin >> x;
        a[x] = 1;
        for (ll w: d[x]) a[w] = 1;
    }
    vector<vector<ll>> pr(mx+1);
    vector<ll> T(mx+1);
    for (ll i=1;i<=mx;i++)
    {
        ll sz = mx/i;
        pr[i].resize(sz+1);
        for (ll j=1;i*j<=mx;j++)
        {
            pr[i][j] = pr[i][j-1]+a[i*j];
            T[i] += a[i*j];
        }
    }
    ll A = 1;
    for (ll x=1;x<=mx;x++)
    {
        if (a[x]==0) continue;
        ll sz = q[x].size();
        ll sz2 = (1LL<<sz);
        vector<ll> D(sz2), S(sz2);
        S[0] = 1;
        D[0] = 1;
        for (ll m=1;m<sz2;m++)
        {
            for (ll b=0;b<sz;b++)
            {
                if (m&(1LL<<b))
                {
                    S[m] = -S[m-(1LL<<b)];
                    D[m] = D[m-(1LL<<b)]*q[x][b];
                    break;
                }
            }
        }
        ll L = 0, R = mx+1;
        while (R-L>1)
        {
            ll M = (R+L)/2;
            ll M2 = M-1;
            ll Q = 0;
            for (ll m=0;m<sz2;m++)
            {
                Q += S[m]*(T[D[m]]-pr[D[m]][M2/D[m]]);
            }
            if (Q==0) R = M;
            else L = M;
        }
        A = max(A,L*x);
    }
    cout << A << "\n";
}