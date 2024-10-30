#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

int _runtimeTerror_()
{
    string s;
    cin>>s;
    int n = sz(s);
    vector<ll> dp(n+1,0);
    dp[0] = 0;
    ll ans = 0;
    int last = 0;
    for(int i=1;i<=n;++i)
    {
        if(s[i-1] == '?')
        {
            dp[i] = (i - last) + dp[last];
        }
        else if(last == 0)
            dp[i] = i,last = i;
        else 
        {
            if(s[last-1] == s[i-1])
            {
                if((i-last)%2)
                    dp[i] = i - last;
                else
                    dp[i] = i - last + dp[last];
            }
            else
            {
                if((i-last)%2)
                    dp[i] = i - last + dp[last];
                else
                    dp[i] = i - last;
            }
            last = i;
        }
        ans += dp[i];
    }
    // debug(dp);
    cout<<ans<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}