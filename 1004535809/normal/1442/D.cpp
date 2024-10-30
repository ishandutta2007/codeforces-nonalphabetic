//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=3000;
int n,k,len[MAXN+5];
ll sum[MAXN+5],res=0;
vector<int> a[MAXN+5];
struct knap{
	ll dp[MAXN+5];
	void clear(){memset(dp,0,sizeof(dp));}
	knap(){clear();}
	void insert(int v,ll w){for(int i=k;i>=v;i--) chkmax(dp[i],dp[i-v]+w);}
};
knap cur;
void solve(int l,int r){
	if(l==r){
		ll s=0;
		for(int i=0;i<=a[l].size();i++){
			if(k>=i) chkmax(res,s+cur.dp[k-i]);
			if(i!=a[l].size()) s+=a[l][i];
		} return;
	} int mid=l+r>>1;knap tmp=cur;
	for(int i=l;i<=mid;i++) cur.insert(len[i],sum[i]);
	solve(mid+1,r);cur=tmp;
	for(int i=mid+1;i<=r;i++) cur.insert(len[i],sum[i]);
	solve(l,mid);cur=tmp;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1,x;j<=len[i];j++){
			scanf("%d",&x);sum[i]+=x;
			a[i].pb(x);
		}
	} solve(1,n);
	printf("%lld\n",res);
	return 0;
}