//#pragma GCC optimize("Ofast")
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
    sz[v] = 1;
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

/*
set<pair<ll,ll>> kek;

void add(ll L, ll R)
{
    auto it = kek.lower_bound({L+1,-1});
    if (it!=kek.begin())
    {
        it--;
        if (it->Y>=R) return;
    }
    while (true)
    {
        it = kek.lower_bound({L,-1});
        if (it!=kek.end() and it->Y<=R) kek.erase(it);
        else break;
    }
    kek.insert({L,R});
}*/

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), pr(n+1);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (ll i=0;i<n;i++)
    {
        cin >> b[i];
        pr[i+1] = (pr[i]+a[i]-b[i]);
    }
    //kek.clear();
    //for (ll i=0;i<n;i++) add(i,i+1);
    vector<pair<ll,ll>> ord;
    for (ll i=0;i<m;i++)
    {
        ll L, R;
        cin >> L >> R;
        L--;
        //add(L,R);
        ord.push_back({L,R});
    }
    //for (auto x: kek) ord.push_back(x);
    ll sz = ord.size();
    vector<vector<ll>> g(n+1);
    vector<ll> C(sz);
    vector<ll> Q;
    for (ll i=0;i<m;i++)
    {
        ll L = ord[i].X;
        ll R = ord[i].Y;
        if (pr[L]!=0)
        {
            C[i]++;
            g[L].push_back(i);
        }
        if (pr[R]!=0)
        {
            g[R].push_back(i);
            C[i]++;
        }
        if (C[i]==0) Q.push_back(i);
    }
    set<ll> bad;
    for (ll i=0;i<=n;i++)
    {
        if (pr[i]!=0) bad.insert(i);
    }
    for (ll i=0;i<Q.size();i++)
    {
        ll L = ord[Q[i]].X;
        ll R = ord[Q[i]].Y;
        while (true)
        {
            auto it = bad.lower_bound(L);
            if (it==bad.end() or *it>R) break;
            for (ll x: g[*it])
            {
                C[x]--;
                if (C[x]==0) Q.push_back(x);
            }
            bad.erase(it);
        }
    }
    if (bad.size()==0) cout << "YES\n";
    else cout << "NO\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}