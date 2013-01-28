/*
AUTHOR: Su Jiao
DATE: $DATA
DESCRIPTION:
动态规划 乱做
http://acm.pku.edu.cn/JudgeOnline/problem?id=1975
*/
#include <stdio.h>
#include <string.h>

const int MAXN=128;
int t,N,M,a,b;
int G[MAXN][MAXN];
int H[MAXN][MAXN];

int main()
{
    scanf("%d",&t);
    for (int tt=0;tt<t;tt++)
    {
        scanf("%d%d",&N,&M);
        memset(G,0,sizeof(G)),memset(H,0,sizeof(H));
        for (int i=0;i<M;i++)
            scanf("%d%d",&a,&b),G[--a][--b]=1,H[b][a]=1;
        for (int k=0;k<N;k++)
            for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                {
                    if (G[i][k]&&G[k][j])
                       G[i][j]=1;
                    if (H[i][k]&&H[k][j])
                       H[i][j]=1;
                }
        int answer=0;
        for (int i=0;i<N;i++)
        {
            int heavier=0;
            for (int j=0;j<N;j++)
                if (G[j][i]) heavier++;
            int lighter=0;
            for (int j=0;j<N;j++)
                if (H[j][i]) lighter++;
            if (heavier>=((N+1)>>1)||lighter>=((N+1)>>1)) answer++;
        } 
        printf("%d\n",answer);
    }
}
