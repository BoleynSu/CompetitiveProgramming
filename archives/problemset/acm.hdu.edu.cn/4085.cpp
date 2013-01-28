#include <cstdio>
#include <cstring>
using namespace std;

template<typename type>
bool check_min(type& a,const type& b)
{
    return a>b?a=b,true:false;
}

enum{MAXN=50,MAXK=5,oo=19930309};
int n,m,k;
int dist[MAXN][MAXN];
int f[1<<(MAXK*2)][MAXN];
bool match(int set)
{
    int a=0,b=0;
    for (int i=0;i<k;i++)
    {
        if (set&(1<<i)) a++;
        if (set&(1<<(k+i))) b++;
    }
    return a==b;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dist[i][j]=oo;
        while (m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--,v--;
            check_min(dist[u][v],w);
            check_min(dist[v][u],w);
        }
        for (int i=0;i<n;i++) dist[i][i]=0;
        for (int s=0;s<n;s++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    if (dist[i][j]>dist[i][s]+dist[s][j])
                        dist[i][j]=dist[i][s]+dist[s][j];
        for (int i=0;i<(1<<(k*2));i++)
            for (int j=0;j<n;j++)
                f[i][j]=oo;
        for (int i=0;i<k;i++)
            for (int j=0;j<n;j++)
                f[1<<i][j]=dist[i][j];
        for (int i=0;i<k;i++)
            for (int j=0;j<n;j++)
                f[1<<(k+i)][j]=dist[n-k+i][j];
        for (int set=0;set<(1<<(k*2));set++)
        {
            for (int subset=set&(set-1);subset;subset=(subset-1)&set)
                for (int i=0;i<n;i++)
                    check_min(f[set][i],f[subset][i]+f[set^subset][i]);
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    check_min(f[set][i],f[set][j]+(match(set)?0:dist[j][i]));
        }
        int answer=oo;
        for (int i=0;i<n;i++)
            check_min(answer,f[(1<<(k*2))-1][i]);
        if (answer==oo) puts("No solution");
        else printf("%d\n",answer);
    }
}

