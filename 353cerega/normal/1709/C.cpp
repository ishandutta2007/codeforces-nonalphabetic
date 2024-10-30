//#pragma GCC optimize("Ofast")
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



void solve()
{
    string s;
    cin >> s;
    vector<ll> C(3);
    ll n = s.length();
    if (n%2!=0)
    {
        cout << "NO\n";
        return;
    }
    vector<ll> p;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='(') C[0]++;
        if (s[i]==')') C[1]++;
        if (s[i]=='?')
        {
            C[2]++;
            p.push_back(i);
        }
    }
    ll x = abs(C[0]-C[1]);
    if (x>C[2])
    {
        cout << "NO\n";
        return;
    }
    ll D0 = (C[2]+C[1]-C[0])/2;
    ll D1 = C[2]-D0;
    ll B = 0;
    ll k = D0;
    ll F = 0;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='?')
        {
            if (k>0)
            {
                s[i] = '(';
                k--;
            }
            else s[i] = ')';
        }
        if (s[i]=='(') B++;
        else B--;
        if (B<0) F = 1;
    }
    if (F==1)
    {
        cout << "NO\n";
        return;
    }
    if (D0==0 or D1==0)
    {
        cout << "YES\n";
        return;
    }
    swap(s[p[D0-1]],s[p[D0]]);
    B = 0;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='(') B++;
        else B--;
        if (B<0) F = 1;
    }
    if (F==1)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}