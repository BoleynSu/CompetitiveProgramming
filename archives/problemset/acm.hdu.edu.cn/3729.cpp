#include <cstdio>
#include <cstring>
using namespace std;

#define oo 0x7f7f7f7f7f7f7f7fll
#define MAXEDGE 400000
#define MAXV 200000

typedef struct struct_edge* edge;
struct struct_edge{int v,c;long long int d;edge n,b;};
struct_edge pool[MAXEDGE];
edge top;
int S,T,V;
edge adj[MAXV];
int q[MAXV];
bool inq[MAXV];
int head,tail;
edge p[MAXV];
long long int d[MAXV];
void add_edge(int u,int v,int c,long long int d)
{
     top->v=v;
     top->c=c;
     top->d=d;
     top->n=adj[u];
     adj[u]=top++;
     top->v=u;
     top->c=0;
     top->d=-d;
     top->n=adj[v];
     adj[v]=top++;
     adj[u]->b=adj[v];
     adj[v]->b=adj[u];
}
int min_cost_flow()
{
    int flow=0,cost=0;
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
        if (d[T]==oo) break;
        else
        {
            long long int delta=oo;
            for (edge i=p[T];i;i=p[i->b->v])
                if (delta>i->c) delta=i->c;
            for (edge i=p[T];i;i=p[i->b->v])
                i->c-=delta,i->b->c+=delta;
            flow+=delta;
            cost+=d[T]*delta;
        }
    }
    return flow;
}


int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        int N;
        bool cted[200000];
        scanf("%d",&N);
        memset(adj,0,sizeof(adj));
        memset(cted,0,sizeof(cted));
        top=pool;
        S=0,T=N+1;
        for (int i=N;i>=1;i--)
            add_edge(S,i,1,-((1ll)<<(i-1)));
        for (int i=1;i<=N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=x;j<=y;j++)
            {
                add_edge(i,T+j,1,0);
                if (!cted[j]) cted[j]=true,add_edge(T+j,T,1,0);
            }
        }
        int rest;
        printf("%d\n",rest=min_cost_flow());
        for (edge e=adj[S];e;e=e->n)
            if (!e->c) printf("%d%c",e->v,(--rest)?' ':'\n');
    }
    return 0;
}
