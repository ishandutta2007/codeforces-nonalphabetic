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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
    }
    vector<ll> dx = {1,-1,0,0,1,1,-1,-1};
    vector<ll> dy = {0,0,1,-1,-1,1,-1,1};
    ll N = n*m;
    vector<vector<ll>> g(N);
    vector<ll> num(N), col(N);
    for (ll i=0;i<N;i++)
    {
        col[i] = 0;
        num[i] = i;
        g[i].push_back(i);
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]=='X') continue;
            ll p = i*m+j;
            for (ll d=0;d<8;d++)
            {
                ll x = i+dx[d];
                ll y = j+dy[d];
                if (x<0 or y<0 or x>=n or y>=m or s[x][y]=='X') continue;
                ll p2 = x*m+y;
                ll A = num[p];
                ll B = num[p2];
                if (A==B) continue;
                if (g[A].size()<g[B].size()) swap(A,B);
                for (ll q: g[B])
                {
                    num[q] = A;
                    g[A].push_back(q);
                }
                g[B].clear();
            }
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]!='X') continue;
            ll k = 0;
            for (ll d=0;d<4;d++)
            {
                ll x = i+dx[d];
                ll y = j+dy[d];
                if (s[x][y]=='X') k++;
            }
            if (k%2==1)
            {
                cout << "NO\n";
                return 0;
            }
            if (k==2)
            {
                for (ll d=0;d<4;d+=2)
                {
                    ll x = i+dx[d];
                    ll y = j+dy[d];
                    ll x2 = i-dx[d];
                    ll y2 = j-dy[d];
                    if (s[x][y]=='X' or s[x2][y2]=='X') continue;
                    ll p = x*m+y;
                    ll p2 = x2*m+y2;
                    ll A = num[p];
                    ll B = num[p2];
                    if (A==B) continue;
                    if (g[A].size()<g[B].size()) swap(A,B);
                    ll D = 1;
                    if (col[p]!=col[p2]) D = 1-D;
                    for (ll q: g[B])
                    {
                        num[q] = A;
                        col[q] = (col[q]+D)%2;
                        g[A].push_back(q);
                    }
                    g[B].clear();
                }
            }
        }
    }
    cout << "YES\n";
    vector<vector<ll>> a(n,vector<ll>(m));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]=='X') continue;
            ll p = i*m+j;
            if (col[p]==i%2) a[i][j] = 1;
            else a[i][j] = 4;
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (s[i][j]!='X') continue;
            for (ll d=0;d<4;d++)
            {
                ll x = i+dx[d];
                ll y = j+dy[d];
                if (s[x][y]=='X') continue;
                a[i][j] += a[x][y];
            }
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}