#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;

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


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> L(n,-1), R(n,-1);
    ll A = 0;
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        if (R[a[i]]!=L[a[i]]) A++;
        if (L[a[i]]==-1) L[a[i]] = i;
        R[a[i]] = i;
    }
    vector<ll> nxt(n,-1);
    for (ll i=0;i<n;i++)
    {
        if (L[i]==-1) continue;
        nxt[L[i]] = R[i];
    }
    ll mx = -1;
    ll x = -1;
    set<pair<ll,ll>> kek;
    vector<vector<ll>> g(n);
    for (ll i=0;i<n;i++)
    {
        if (i==mx)
        {
            auto it = kek.begin();
            A -= it->X;
        }
        for (ll z: g[i]) kek.erase({z,i});
        if (nxt[i]==-1) continue;
        if (nxt[i]==i)
        {
            if (i<=mx) A++;
            continue;
        }
        ll Q = 1;
        A += 2;
        if (nxt[i]<=mx) continue;
        if (i>mx)
        {
            g[nxt[i]].push_back(Q+1);
            kek.insert({Q+1,nxt[i]});
            mx = nxt[i];
            continue;
        }
        Q = kek.begin()->X;
        g[nxt[i]].push_back(Q+1);
        kek.insert({Q+1,nxt[i]});
        mx = nxt[i];
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}