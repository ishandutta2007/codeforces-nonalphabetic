#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,s,e,ans,Test_num;
int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=0;
		for(int i=1;i<=n;++i)read(a[i]);
		for(s=1,e=n;;)
		{
			for(;s<=e && !a[s];++s);
			for(;s<=e && a[e];--e);
			if(s>e)break;
			++s,--e,++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}