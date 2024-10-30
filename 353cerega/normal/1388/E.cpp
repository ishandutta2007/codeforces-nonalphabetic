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


bool cmp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b)
{
    if (a.X.X*b.X.Y<b.X.X*a.X.Y) return true;
    if (a.X.X*b.X.Y>b.X.X*a.X.Y) return false;
    return a.Y<b.Y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll,pair<ll,ll>>> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].Y.X >> a[i].Y.Y >> a[i].X;
    }
    sort(a.begin(),a.end());
    ll L = 0, R = n-1;
    vector<pair<pair<ll,ll>,ll>> ord;
    vector<pair<ll,ll>> num;
    ll Q = 0;
    for (ll i=0;i<n;i++)
    {
        //if (a[i].X>a[L].X or (a[i].X==a[L].X and a[i].Y.X<a[L].Y.X)) L = i;
        //if (a[i].X<a[R].X or (a[i].X==a[R].X and a[i].Y.Y>a[R].Y.Y)) R = i;
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=i+1;j<n;j++)
        {
            if (a[i].X==a[j].X) continue;
            ord.push_back({{a[j].Y.Y-a[i].Y.X,a[j].X-a[i].X},-2});
            ord.push_back({{a[j].Y.X-a[i].Y.X,a[j].X-a[i].X},Q});
            num.push_back({i,j});
            Q++;
            ord.push_back({{a[j].Y.X-a[i].Y.Y,a[j].X-a[i].X},-1});
        }
    }
    ord.push_back({{-10000000LL,1},-3});
    ord.push_back({{10000000LL,1},-3});
    sort(ord.begin(),ord.end(),cmp);
    ll W = 0;
    ld A = 1e15;
    cout.precision(20);
    for (ll z=0;z<ord.size();z++)
    {
        ld del = ord[z].X.X*1.0/ord[z].X.Y;
        if (W==0)
        {
            ld mn = a[L].Y.X-a[L].X*del;
            ld mx = a[R].Y.Y-a[R].X*del;
            A = min(A,mx-mn);
        }
        if (ord[z].Y==-2) W++;
        if (ord[z].Y==-1) W--;
        if (W==0)
        {
            ld mn = a[L].Y.X-a[L].X*del;
            ld mx = a[R].Y.Y-a[R].X*del;
            A = min(A,mx-mn);
        }
        if (ord[z].Y<0) continue;
        ll p = ord[z].Y;
        ll u = num[p].X;
        ll v = num[p].Y;
        if (L==u) L = v;
        else
        {
            if (L==v) L = u;
        }
        if (R==u) R = v;
        else
        {
            if (R==v) R = u;
        }
    }
    cout << A << endl;
}