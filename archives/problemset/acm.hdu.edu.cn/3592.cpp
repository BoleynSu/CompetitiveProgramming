#include <cstdio>
#include <cstring>
using namespace std;

enum{MAXV=100000,MAXE=100000};
struct Edge{int u,v,w;};
int E;
Edge edge[MAXE];
int d[MAXV];
bool reached[MAXV];

int bellman_ford(int V)
{
    memset(reached,0,sizeof reached);
    d[1]=0;
    reached[1]=true;
    for (int i=1;i<=V;i++)
    {
        for (int e=0;e<E;e++)
            if (reached[edge[e].u]&&(!reached[edge[e].v]||d[edge[e].v]>d[edge[e].u]+edge[e].w))
            {
                d[edge[e].v]=d[edge[e].u]+edge[e].w,
                reached[edge[e].v]=true;
                if (i==V) return -1;
            }
    }
    if (!reached[V]) return -2;
    return d[V];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=0;t<T;t++)
    {
        int N,X,Y;
        scanf("%d%d%d",&N,&X,&Y);
        E=0;
        for (int i=1;i<N;i++)
            edge[E].u=i+1,edge[E].v=i,edge[E].w=0,
            E++;
        for (int i=0;i<X;i++)
            scanf("%d%d%d",&edge[E].u,&edge[E].v,&edge[E].w),
            E++;
        for (int i=0;i<Y;i++)
            scanf("%d%d%d",&edge[E].v,&edge[E].u,&edge[E].w),
            edge[E].w=-edge[E].w,
            E++;
        printf("%d\n",bellman_ford(N));
    }
}

