#include<cstdio>
#include<algorithm>
using namespace std;
#define N 113
#define mod 1000000007
int n,p,ct=102,nw,rb[N]={0,2,3,4,6,8,12,14,18,26,38,39,56,57,80,84,119,120,173,178,254,259,362,381,536,543,779,804,1145,1168,1631,1717,2414,2446,3506,3621,5153,5259,7340,7729,10865,11010,15779,16297,23189,23668,33032,34783,48893,49548,71006,73339,104351,106509,148646,156526,220019,222969,319529,330028,469580,479293,668909,704370,990086,1003363,1437881,1485129,2113112,2156821,3010091,3169668,4455389,4515136,6470465,6683083,9509006,9705697,13545410,14263509,20049251,20318115,29117093,30073876,42790529,43675639,60954347,64185793,90221630,91431520,131026919,135332445,192557381,196540378,274294562,288836071,405997337,411441843,589621136,608996005,866508215,884431704,999999999},vl[N]={0,0,1,2,1,2,0,1,2,0,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1};
int su[4],as;
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int main()
{
	scanf("%d%d",&n,&p);p--;
	if(p<=2){printf("0\n");return 0;}
	for(int i=1;i<=ct;i++)rb[i]=min(p,rb[i]),su[vl[i]]=(su[vl[i]]+1ll*(rb[i]-rb[i-1])*(p*2-rb[i]-rb[i-1]+1)/2)%mod;
	for(int p=-1;p<2;p+=2)for(int q=-1;q<2;q+=2)as=(as+pw((1ll*mod*2+su[0]+su[1]*p+su[2]*q)%mod,n))%mod;
	as=(pw(1ll*p*(p+1)/2%mod,n)+mod-1ll*(mod+1)/4*as%mod)%mod;
	printf("%d\n",as);
}