#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

#define oo 0x0f0f0f0f
#define MAXEDGE 510000
#define MAXV 2002
 
typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXEDGE];
edge top;
int S,T,V;
edge adj[MAXV];
int q[MAXV];
bool inq[MAXV];
int head,tail;
edge p[MAXV];
int d[MAXV];
void add_edge(int u,int v,int c,int d)
{
     top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v];
     adj[v]->b=adj[u];
}
int min_cost_flow()
{
    int flow=0,cost=0;
    int dT=oo;
    for (;;)
    {
        memset(d,oo,sizeof(d));
        inq[q[head=tail=0]=S]=true;
        d[S]=0;
        p[S]=0;
        while (head<=tail)
        {
              int u;
              inq[u=q[(head++)%MAXV]]=false;
              for (edge i=adj[u];i;i=i->n)
                  if (i->c&&d[i->v]>d[u]+i->d)
                  {
                     if (!inq[i->v])
                        inq[q[(++tail)%MAXV]=i->v]=true;
                     d[i->v]=d[u]+i->d;
                     p[i->v]=i;
                  }
        }
        if (d[T]>dT||d[T]==oo) break;
        else
        {
            int delta=oo;
            for (edge i=p[T];i;i=p[i->b->v])
                if (delta>i->c) delta=i->c;
            for (edge i=p[T];i;i=p[i->b->v])
                i->c-=delta,i->b->c+=delta;
            flow+=delta;
            cost+=d[T]*delta;
            dT=d[T];
        }
    }
    return flow;
}

int main()
{
    int Tc;
    scanf("%d",&Tc);
    for (int t=0;t<Tc;t++)
    {
        int N;
        scanf("%d",&N);
        memset(adj,0,sizeof(adj));
        top=pool;
        S=1,T=N;
        for (;;)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if (!u) break;
            add_edge(u,v,1,w);
            add_edge(v,u,1,w);
        }
        if (N==1) puts("0");
        else printf("%d\n",min_cost_flow());
    }
}


