#include <cstdio>
#include <cstring>
using namespace std;

enum{MAXN=150,MAXX=20000,oo=19930309};
int N,T;
int V[MAXN],C[MAXN];
int f[MAXX+2];
int g[MAXX+2];

int main()
{
    for (int t=1;;t++)
    {
        scanf("%d%d",&N,&T);
        if (N==0&&T==0) break;
        for (int i=0;i<N;i++)
            scanf("%d",&V[i]);
        for (int i=0;i<N;i++)
            scanf("%d",&C[i]);
        for (int x=0;x<=MAXX;x++) f[x]=oo;
        f[0]=0;
        for (int i=0;i<N;i++)
        {
            int c=C[i];
            while (c)
            {
                int tc=(c+1)/2;
                int v=V[i]*tc;
                for (int x=MAXX;x>=v;x--)
                    if (f[x]>f[x-v]+tc)
                        f[x]=f[x-v]+tc;
                c/=2;
            }
        }
        for (int x=0;x<=MAXX;x++) g[x]=oo;
        g[0]=0;
        for (int i=0;i<N;i++)
            for (int x=V[i];x<=MAXX;x++)
                if (g[x]>g[x-V[i]]+1)
                    g[x]=g[x-V[i]]+1;
        int answer=oo;
        for (int x=T;x<=MAXX;x++)
            if (answer>f[x]+g[x-T])
                answer=f[x]+g[x-T];
        if (answer==oo) answer=-1;
        printf("Case %d: %d\n",t,answer);
    }
}

