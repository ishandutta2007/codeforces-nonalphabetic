#include<cstdio>
int n,k,p,q,Test_num;
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
		read(n),read(k);
		if(n&1)--k,p=(n-1)/2,q=(n+1)/2,k=k/p*q+(k%p),++k;
		printf("%d\n",((k-1)%n)+1);
	}
	return 0;
}