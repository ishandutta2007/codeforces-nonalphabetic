#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-8
#define INF 0x3f3f3f3f
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug `
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//Definitions 
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

vviwv(mat, 520, 520, 0);

int main()
{
    fastIO;
    cini2(n,m);

    FE(i,1,n)
        FE(j,1,m)
            cin>>mat[i][j];

    vviwv(one, 520, 12, 0);
    vviwv(zero, 520, 12, 0);

    FE(i,1,n)
    {
        FE(bt, 0, 9)
        {
            FE(j,1,m)
            {
                if((1<<bt)&(mat[i][j]))
                    one[i][bt] = 1;
                else
                    zero[i][bt] = 1;
            }
        }
    }

    vi cntone(12, 0);
    vi cntzero(12, 0);

    int cntz = 0, cnto = 0;
    FE(bt, 0, 9)
    {
        cntz = 0;
        cnto = 0;
        FE(i,1,n)
        {
            if(one[i][bt])
                cnto++;
            if(zero[i][bt])
                cntz++;
        }
        cntone[bt]  = cnto;
        cntzero[bt] = cntz;
    }
    debug(cntone);
    debug(cntzero);
    
    int ansone = -INF, anszero = -INF, ansbt;
    FE(bt, 0, 9)
    {
        for (int one = 1; one <=n ; one+=2)
        {
            if((one <= cntone[bt]) && ((n-one)<=cntzero[bt]))
            {   
                ansone = one;
                anszero = n-ansone;
                ansbt = bt;
                cout<<"TAK"<<endl;
                goto en1;
            }
        }
    }
    en1:;
    if(ansone == -INF)
    {
        cout<<"NIE";
        return 0;
    }

    vi ans(m+10), mark(n+10,0);
    debug(ansbt);
    int takenone = 0;
    FE(i,1,n)
    {
        if(!mark[i])
        {
            FE(j,1,m)
            {
                if((one[i][ansbt]) && (zero[i][ansbt]==0))
                {
                    if((1<<ansbt)&(mat[i][j]))
                    {
                        ans[i] = j;
                        takenone++;
                        mark[i] = 1;
                        break;
                    }                
                }
            }
            if(takenone==ansone)
                break;            
        }
    }

    int takenzero = 0;
    FE(i,1,n)
    {
        if(!mark[i])
        {
            FE(j,1,m)
            {
                if((one[i][ansbt]==0) && (zero[i][ansbt]==1))
                {
                    if( ((1<<ansbt)&(mat[i][j])) == 0 ) 
                    {
                        mark[i]=1;
                        ans[i] = j;
                        takenzero++;
                        break;
                    }                    
                }
            }
            if(takenzero==anszero)
                break;
        }
    }
    if(takenone == ansone && takenzero == anszero)
    {
        coutRV(ans, 1, n);
        return 0;
    }
    else
    {
        if(takenone  < ansone)
        {                
            FE(i,1,n)
            {
                if(!mark[i])
                {
                    FE(j,1,m)
                    {
                        if((1<<ansbt)&(mat[i][j]))
                        {
                            ans[i] = j;
                            takenone++;
                            mark[i] = 1;
                            break;
                        }
                    }
                    if(takenone==ansone)
                        break;
                    
                }
            }
        }
        if(takenzero < anszero)
        {
            FE(i,1,n)
            {
                if(!mark[i])
                {
                    FE(j,1,m)
                    {
                        if( ((1<<ansbt)&(mat[i][j])) == 0 ) 
                        {
                            ans[i] = j;
                            mark[i] = 1;
                            takenzero++;
                            break;
                        }
                    }
                    if(takenzero==anszero)
                        break;
                }
            }            
        }
    }
    coutRV(ans, 1, n);

    return 0;
}