#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define rint register int
#define ll long long 
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
    return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T> void read(T &x)
{
    rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
    while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
}
char sr[1<<24],z[20]; ll Z,C1=-1;
template<class T>void wer(T x)
{
    if (x<0) sr[++C1]='-',x=-x;
    while (z[++Z]=x%10+48,x/=10);
    while (sr[++C1]=z[Z],--Z);
}
IL void wer1()
{
    sr[++C1]=' ';
}
IL void wer2()
{
	sr[++C1]='\n';
}
const int N=2e6;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
	   int n,k;
	   cin>>n>>k;
	   rep(i,1,n) cin>>a[i]; a[0]=-1e9;
	   int cnt=0; 
	   rep(i,1,n) if (a[i]!=a[i-1]) cnt++;
	   int num=0;
	   if (cnt==1&&k==1)
	   {
	   	 if(a[n]==0) cout<<0<<endl;
	   	 else cout<<1<<endl;
	   } else if (k==1)
	   {
	   	  cout<<-1<<endl; 
	   } else
	   {
	     while (cnt>0)
	     {
	   	    if (cnt>k) cnt-=k-1, num++;
	   	    if (cnt<=k) num++,cnt=0;
	     }
	     cout<<num<<endl;
       }
	}
	return 0;
}