#include<cstdio>
int g[1010];
void init(){
g[1]=1;
g[2]=1;
g[3]=2;
g[4]=2;
g[5]=2;
g[6]=3;
g[7]=3;
g[8]=3;
g[9]=3;
g[10]=4;
g[11]=4;
g[12]=4;
g[13]=4;
g[14]=4;
g[15]=5;
g[16]=5;
g[17]=5;
g[18]=5;
g[19]=5;
g[20]=5;
g[21]=6;
g[22]=6;
g[23]=6;
g[24]=6;
g[25]=6;
g[26]=6;
g[27]=6;
g[28]=7;
g[29]=7;
g[30]=7;
g[31]=7;
g[32]=7;
g[33]=7;
g[34]=7;
g[35]=7;
g[36]=8;
g[37]=8;
g[38]=8;
g[39]=8;
g[40]=8;
g[41]=8;
g[42]=8;
g[43]=8;
g[44]=8;
g[45]=9;
g[46]=9;
g[47]=9;
g[48]=9;
g[49]=9;
g[50]=9;
g[51]=9;
g[52]=9;
g[53]=9;
g[54]=9;
g[55]=10;
g[56]=10;
g[57]=10;
g[58]=10;
g[59]=10;
g[60]=10;}
int main()
{
	init();
    int N;
    scanf("%d",&N);
    int ans = 0;
    for(int i=0; i<N; ++i)
    {
        int T;
        scanf("%d",&T);
        ans ^= g[T];
    }
    if(ans) printf("NO");
    else printf("YES");
    puts("");
    return 0;
}