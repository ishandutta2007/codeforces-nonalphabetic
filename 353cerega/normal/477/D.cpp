//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = int;
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




void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    vector<vector<ll>> dp2(n+1,vector<ll>(n+1,mod));
    dp[0][0] = 1;
    dp2[0][0] = 0;
    vector<vector<ll>> D(n+1,vector<ll>(n+1));
    for (ll i=0;i<=n;i++) D[i][n] = 0;
    for (ll R=n-1;R>=0;R--)
    {
        for (ll L=R;L>=0;L--)
        {
            if (s[L]!=s[R]) D[L][R] = 0;
            else D[L][R] = D[L+1][R+1]+1;
        }
    }
    for (ll R=0;R<n;R++)
    {
        if (s[R]=='0') continue;
        ll S = 0;
        ll F = mod;
        for (ll L=R,R2=R;R2<=n;L--,R2++)
        {
            if (L>=0)
            {
                ll S2 = (S+dp[L][R])%mod;
                ll F2 = min(F,dp2[L][R]);
                ll d = D[L][R];
                if (d+R>=R2 or s[d+R]=='1')
                {
                    dp[R][R2] = (dp[R][R2]+S2)%mod;
                    dp2[R][R2] = min(dp2[R][R2],F2+1);
                }
                else
                {
                    dp[R][R2] = (dp[R][R2]+S)%mod;
                    dp2[R][R2] = min(dp2[R][R2],F+1);
                }
                S = S2;
                F = F2;
            }
            else
            {
                dp[R][R2] = (dp[R][R2]+S)%mod;
                dp2[R][R2] = min(dp2[R][R2],F+1);
            }
        }
    }
    ll A = 0;
    for (ll i=0;i<n;i++) A = (A+dp[i][n])%mod;
    cout << A << "\n";
    A = mod;
    for (ll i=n-1;i>=n-20 and i>=0;i--)
    {
        if (dp2[i][n]!=mod)
        {
            ll B = 0;
            for (ll j=i;j<n;j++)
            {
                B = (B*2+(s[j]-'0'))%mod;
            }
            B = (B+dp2[i][n])%mod;
            A = min(A,B);
        }
    }
    if (A!=mod)
    {
        cout << A << "\n";
        return;
    }
    for (ll i=n-1;i>=0;i--)
    {
        if (dp2[i][n]!=mod)
        {
            A = 0;
            for (ll j=i;j<n;j++)
            {
                A = (A*2+(s[j]-'0'))%mod;
            }
            A = (A+dp2[i][n])%mod;
            cout << A << "\n";
            return;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}