// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    int mask = n - 1;

    if(k == n - 1) {
        if(n == 4) {
            cout << "-1\n";
            return 0;
        }
        cout << "0 2\n";
        cout << "1 " << n - 3 << "\n";
        cout << n - 2 << " " << n - 1 << "\n";
        for(int i=3;i<n/2;++i) {
            cout << i << " " << (i ^ mask) << "\n";
        }
        return 0;
    }

    if(k == 0) {
        for(int i=0;i<n/2;++i) {
            cout << i << " " << (i ^ mask) << "\n";
        }
        return 0;
    }
    cout << "0 " << (k ^ mask) << "\n";
    cout << mask << " " << k << "\n";
    for(int i=0;i<n/2;++i) {
        if(i == 0 || i == k || i == (k ^ mask)) {
            continue;
        }
        cout << i << " " << (i ^ mask) << "\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}