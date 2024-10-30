#include<bits/stdc++.h>
typedef long long ll;
struct pii
{int L,R,v;}P[]=
{
	(pii){1,2,0},
	(pii){3,3,1},
	(pii){4,4,2},
	(pii){5,6,1},
	(pii){7,8,2},
	(pii){9,12,0},
	(pii){13,14,1},
	(pii){15,18,2},
	(pii){19,26,0},
	(pii){27,38,1},
	(pii){39,39,2},
	(pii){40,56,0},
	(pii){57,57,2},
	(pii){58,80,1},
	(pii){81,84,2},
	(pii){85,119,0},
	(pii){120,120,2},
	(pii){121,173,1},
	(pii){174,178,2},
	(pii){179,254,0},
	(pii){255,259,2},
	(pii){260,362,1},
	(pii){363,381,2},
	(pii){382,536,0},
	(pii){537,543,2},
	(pii){544,779,1},
	(pii){780,804,2},
	(pii){805,1145,0},
	(pii){1146,1168,2},
	(pii){1169,1631,1},
	(pii){1632,1717,2},
	(pii){1718,2414,0},
	(pii){2415,2446,2},
	(pii){2447,3506,1},
	(pii){3507,3621,2},
	(pii){3622,5153,0},
	(pii){5154,5259,2},
	(pii){5260,7340,1},
	(pii){7341,7729,2},
	(pii){7730,10865,0},
	(pii){10866,11010,2},
	(pii){11011,15779,1},
	(pii){15780,16297,2},
	(pii){16298,23189,0},
	(pii){23190,23668,2},
	(pii){23669,33032,1},
	(pii){33033,34783,2},
	(pii){34784,48893,0},
	(pii){48894,49548,2},
	(pii){49549,71006,1},
	(pii){71007,73339,2},
	(pii){73340,104351,0},
	(pii){104352,106509,2},
	(pii){106510,148646,1},
	(pii){148647,156526,2},
	(pii){156527,220019,0},
	(pii){220020,222969,2},
	(pii){222970,319529,1},
	(pii){319530,330028,2},
	(pii){330029,469580,0},
	(pii){469581,479293,2},
	(pii){479294,668909,1},
	(pii){668910,704370,2},
	(pii){704371,990086,0},
	(pii){990087,1003363,2},
	(pii){1003364,1437881,1},
	(pii){1437882,1485129,2},
	(pii){1485130,2113112,0},
	(pii){2113113,2156821,2},
	(pii){2156822,3010091,1},
	(pii){3010092,3169668,2},
	(pii){3169669,4455389,0},
	(pii){4455390,4515136,2},
	(pii){4515137,6470465,1},
	(pii){6470466,6683083,2},
	(pii){6683084,9509006,0},
	(pii){9509007,9705697,2},
	(pii){9705698,13545410,1},
	(pii){13545411,14263509,2},
	(pii){14263510,20049251,0},
	(pii){20049252,20318115,2},
	(pii){20318116,29117093,1},
	(pii){29117094,30073876,2},
	(pii){30073877,42790529,0},
	(pii){42790530,43675639,2},
	(pii){43675640,60954347,1},
	(pii){60954348,64185793,2},
	(pii){64185794,90221630,0},
	(pii){90221631,91431520,2},
	(pii){91431521,131026919,1},
	(pii){131026920,135332445,2},
	(pii){135332446,192557381,0},
	(pii){192557382,196540378,2},
	(pii){196540379,274294562,1},
	(pii){274294563,288836071,2},
	(pii){288836072,405997337,0},
	(pii){405997338,411441843,2},
	(pii){411441844,589621136,1},
	(pii){589621137,608996005,2},
	(pii){608996006,866508215,0},
	(pii){866508216,884431704,2},
	(pii){884431705,1000000000,1}
};
const ll mod=1e9+7;
int n,p;
ll c[4],d[11111][4];
void calc(int d)
{
	for(pii g:P)
	{
		if(g.L>d)continue;
		if(g.R>d)g.R=d;
		ll R=((g.R-g.L+1)*1ll*d-((g.R-g.L+1)*1ll*(g.R+g.L)/2))%mod;
		(c[g.v]+=R)%=mod;
	}
}
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	calc(p);
	d[0][0]=1;
	register int i,ii,iii; 
	for(i=1;i<=n;i++)
		for(ii=0;ii<4;ii++)
			for(iii=0;iii<4;iii++)
				(d[i][ii]+=d[i-1][iii]*c[ii^iii])%=mod;
	printf("%lld\n",(d[n][1]+d[n][2]+d[n][3])%mod);
}
/*
Please don't let me down.
*/