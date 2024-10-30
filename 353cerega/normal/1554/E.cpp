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

vector<vector<ll>> g;

ll k;
vector<ll> dp;
ll ok = 1;

void dfs(ll u, ll p)
{
    dp[u] = 1;
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs(v,u);
        dp[u] += dp[v];
    }
}

void solve()
{
    ll n;
    cin >> n;
    g.clear();
    g.resize(n);
    dp.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> D;
    for (ll d=2;d<=n-1;d++)
    {
        if ((n-1)%d==0) D.push_back(d);
    }
    ll sz = D.size();
    vector<ll> A(sz);
    dfs(0,-1);
    for (ll i=0;i<sz;i++)
    {
        k = D[i];
        ok = 1;
        for (ll j=0;j<n;j++)
        {
            if (dp[j]%k!=0 and dp[j]%k!=1)
            {
                ok = 0;
                break;
            }
        }
        A[i] = ok;
    }
    for (ll i=0;i<sz;i++)
    {
        for (ll j=i+1;j<sz;j++)
        {
            if (A[i]==1 and A[j]==1 and D[j]%D[i]==0) A[i] = 0;
        }
    }
    vector<ll> ans(n+1);
    ans[1] = 1;
    for (ll i=1;i<n;i++) ans[1] = ans[1]*2%mod;
    for (ll i=0;i<sz;i++)
    {
        if (A[i]==1)
        {
            ans[1] = (ans[1]+mod-1)%mod;
            ans[D[i]] = 1;
        }
    }
    for (ll i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}