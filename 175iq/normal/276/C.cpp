#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define clr(arr) memset((arr), 0, sizeof(arr))
#define setval(arr,value) memset(arr,value,sizeof(arr)) //set elements of array to some value
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define found(c,value) ((c).find(value) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)
 
//Constants
#define EPS 1e-8
#define PI 2*acos(0.0)
#define INF 0x3f3f3f3f
#define MOD 1e9+7
 
//Printing
#define coutA(a,L,R) FE(i,L,R) cout<<a[i]<<(i==R?'\n':' ')
#define coutV(a) coutA(a,0,a.size()-1)
 
//Checking bound
#define IN(i,l,r)   (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r)  (l<=i&&i<r)
#define INR(i,l,r)  (l<i&&i<=r)
 
//For loops
#define F(i,a,b) 	for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FR(i,a,b)   for(int i=b; i>a; i--)
#define FRE(i,a,b)  for(int i=b; i>=a; i--)
 
//For debug
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;	
#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define debugv(vec) FE(i,0,vec.sz-1) cerr<<vec[i]<<(i==vec.sz-1?'\n':' ') 
 
//Definitions
#define vi vector<int>  
#define vvi vector<vector<int> > 
#define viwv(vecname, N, value) vector<int> vecname(N, value) 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define vvig(vecname, N) vector<vector<int> > vecname(N) //For Graph 
 
#define ii pair<int,int>  
#define ll long long  
 
int main()
{
	int n,q;
	cin>>n>>q;
 
	viwv(arr,n,0);
	F(i,0,n)
	{
		cin>>arr[i];
	}
 
	viwv(sum,n+1,0);
	int a,b;
	F(i,0,q)
	{
		cin>>a>>b;
		sum[a-1]++;
		sum[b]--;
	}
 
	FE(i,1,n)
	{
		sum[i] = sum[i-1] + sum[i];
	}
	sort(all(sum),greater<int>());
	sort(all(arr),greater<int>());
 
	ll ans = 0;
	F(i,0,n)
	{
		ans+= (ll)sum[i]*(ll)arr[i];
	}
	cout<<ans;
}