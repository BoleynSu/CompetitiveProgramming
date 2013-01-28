#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

enum{oo=19930309,MAXV=100,MAXK=1000};
int N,M,S,E;
int dist[MAXV];
int map[MAXV][MAXV];
int K[MAXV];
bool visited[MAXV];
bool visitedK[MAXK];

bool search(int u,int d)
{
    if (u==E&&d>=0) return true;

    for (int i=0;i<N;i++) dist[i]=oo;
    dist[E]=0;
    memset(visited,0,sizeof visited);
    for (;;)
    {
        int mind=oo,mindi;
        for (int j=0;j<N;j++)
            if (!visited[j]&&!visitedK[K[j]]&&dist[j]<mind)
                mind=dist[mindi=j];
        visited[mindi]=true;
        if (mind==oo) return false;
        if (mindi==u)
        {
            if (mind>d) return false;
            else break;
        }
        for (int j=0;j<N;j++)
            if (!visited[j]&&!visitedK[K[j]])
                dist[j]=min(dist[j],dist[mindi]+map[mindi][j]);
    }

    visitedK[K[u]]=true;
    for (int v=0;v<N;v++)
        if (!visitedK[K[v]]&&map[u][v]!=oo)
        {
            if (search(v,d-map[u][v]))
                return true;
        }
    visitedK[K[u]]=false;
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&N,&M,&S,&E);
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                if (i==j) map[i][j]=0;
                else map[i][j]=oo;
        for (int i=0;i<M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            map[u][v]=min(map[u][v],w);
            map[v][u]=min(map[v][u],w);
        }
        for (int i=0;i<N;i++)
            scanf("%d",K+i);
        int L=-1,R=oo;
        while (L+1!=R)
        {
            int mid=(L+R)>>1;
            memset(visitedK,0,sizeof visitedK);
            if (search(S,mid)) R=mid;
            else L=mid;
        }
        if (R==oo) puts("-1");
        else printf("%d\n",R);
    }
}

