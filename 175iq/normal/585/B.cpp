#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-6
#define INF 0x3f3f3f3f
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
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
#define ll long long 
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
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

int mark = 0, n;
vviwv(visited,4,110,0);
 
int check(int x, int y, vector<string>& board)
{
    if(x<=0 || x>=4)
        return 0;
        
    if(y>n)
        return 1;

    if(board[x][y]>='A' && board[x][y]<='Z')
        return 0;

    return 1;
}
 
void dfs(int X, int Y, vector<string>& board)
{
    if(Y >= n+1)
    {
        if(!mark)
            cout<<"YES"<<endl;
        mark = 1 ;
        return ;
    }
    if(visited[X][Y])
        return;
 
    visited[X][Y] = 1;
    if( check(X,Y+1,board) && check(X,Y+2,board) && check(X,Y+3,board) )
        dfs(X, Y+3, board);
    
    if( check(X,Y+1,board) && check(X-1,Y+1,board) && check(X-1,Y+2,board) && check(X-1,Y+3,board) )
        dfs(X-1, Y+3, board);
    
    if( check(X,Y+1,board) && check(X+1,Y+1,board) && check(X+1,Y+2,board) && check(X+1,Y+3,board) )
        dfs(X+1, Y+3, board);
 
    return;
}
 
void solve()
{
    int k;
    cin>>n>>k;
    
    vector<string> board(4);   
    int X,Y; 
    FE(i,1,3)
    {   
        cins(s);
        board[i] = s;
        for (int j = 1; j <= n; j++) 
        {
            if(s[j]=='s')
            {
                X = i;
                Y = j;
                break;
            }
        }
    }
    dfs(X, Y, board);

    if(!mark)
        cout<<"NO"<<endl;
    return;
}
 
int main()                              
{                                                                                                  
    fastIO; 
    cini(t); 
 
    while(t--)
    {
        mark = 0;
        FE(i,1,3)
            FE(j,1,100)
                visited[i][j] = 0;

        solve();
    }
 
    return 0;
}