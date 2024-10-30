#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

#define NCR 
const int NC=1000005,MOD=M;
ll inv[NC],fac_inv[NC],fac[NC];
void initialize()
{
    ll i;
    inv[1]=1;
    for(i=2;i<=NC-2;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD; 
    fac[0]=fac[1]=1;
    for(i=2;i<=NC-2;i++)
        fac[i]=i*fac[i-1]%MOD;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=NC-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    return (fac[n]*fac_inv[r]%MOD)*fac_inv[n-r]%MOD;
}

const int N = 1e6+10;

ll pfx[N],sfx[N];

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    ll val = 0,ans = 0;
    pfx[0] = sfx[k+3] = 1;
    for(int i=1;i<=k+2;++i)
    {
        pfx[i] = (pfx[i-1] * (n-i))%M;
        pfx[i] = (pfx[i]+M)%M;
    }
    for(int i=k+2;i>=1;--i)
    {
        sfx[i] = sfx[i+1] * (n-i)%M;
        sfx[i] = (sfx[i]+M)%M;
    }
    for(int i=1;i<=k+2;++i)
    {
        ll u = fac_inv[i-1]*fac_inv[k+2-i]%M;
        if((k+2-i)&1)
            u = (M-u)%M;
        val = (val + power(i,k,M))%M;
        u = (u*val)%M;
        ans = (ans + u*pfx[i-1]%M*sfx[i+1]%M)%M;
    }
    cout<<ans;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}