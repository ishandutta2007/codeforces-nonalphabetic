#include <bits/stdc++.h>
using namespace std;
        
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
   
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
// ----------------------------- (Debug) ------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while((token = strtok(NULL,", "))) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*>) { cerr << ""; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef LOCAL
#define debug(...) { debugg(tokenizer(harg(LINE, __VA_ARGS__)),__LINE__, __VA_ARGS__); cerr << endl;}
#else
#define debug(...) { }
#endif
/// -----------------------------------------------------------------------
 
///------------------For Online test------------------ ///
#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" ";((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
///------------------For Online test------------------ ///
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
 
#define int ll
#define INFI (int)2e9
#define INFL (ll)1e18
 
void solve()
{
    cini2(n, m);
    cins(s);

    int x = s.sz-1;
    int maxiR = 0, miniL = 0, cur = 0;
    vector<pii> vec1;
    FE(i,1,x)
    {
        if(s[i] == 'R')
            cur++;
        else if(s[i] == 'L')
            cur--;

        maxiR = max(maxiR, cur);
        miniL = min(miniL, cur);
        vec1.pb({miniL, maxiR});
    }
    debug(miniL, maxiR);

    int maxiU = 0, miniD = 0;
    cur = 0;
    vector<pii> vec2;
    FE(i,1,x)
    {
        if(s[i] == 'U')
            cur++;
        else if(s[i] == 'D')
            cur--;

        maxiU = max(maxiU, cur);
        miniD = min(miniD, cur);
        vec2.pb({miniD, maxiU});
    }
    debug(maxiU, miniD);

    int n1 = vec1.sz, l1 = 0, r1 = 0;
    FRE(i,n1-1,0)
    {
        if(abs(vec1[i].fi) + abs(vec1[i].se) <= m-1)
        {
            l1 = -vec1[i].fi;
            r1 = vec1[i].se;
            break;
        }
    }

    int n2 = vec2.sz, u2 = 0, d2 = 0;
    FRE(i,n2-1,0)
    {
        if(abs(vec2[i].fi) + abs(vec2[i].se) <= n-1)
        {
            d2 = -vec2[i].fi;
            u2 = vec2[i].se;
            break;
        }
    }

    cout<<u2+1<<" "<<l1+1<<"\n";

    return;
}   
 
signed main()
{
    fastIO; 
            
    int T = 1;
    cin>>T;
    
    FE(i,1,T)
    {
        solve();
    }
    return 0;
}