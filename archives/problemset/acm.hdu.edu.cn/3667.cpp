#include <cstdio>
#include <cstring>
using namespace std;

int N,M,K;

const int oo=0x3f3f3f3f;
const int MAXE=(5000*5+2)*2;
const int MAXV=100+2;
struct edge_struct{edge_struct* n;edge_struct* b;int v,l,c;};
typedef edge_struct* edge;
edge_struct pool[MAXE];
edge top;
edge adj[MAXV];
void init_graph()
{
     top=pool;
     memset(adj,0,sizeof(adj));
}
void add_edge(int u,int v,int l,int c)
{
     top->n=adj[u],top->v=v,top->l=l,top->c=c;
     adj[u]=top++;
     top->n=adj[v],top->v=u,top->l=-l,top->c=0;
     adj[v]=top++;
     adj[u]->b=adj[v];
     adj[v]->b=adj[u];
}
int min_cost_flow(int S,int T)
{
    int flow_total=0,cost=0;
    for (;;)
    {
        int d[MAXV];
        int qh,qt;
        int q[MAXV];
        bool inq[MAXV];
        int inqc[MAXV];
        edge pre[MAXV];
        memset(d,oo,sizeof(d));
        memset(inq,0,sizeof(inq));
        memset(inqc,0,sizeof(inqc));
        memset(pre,0,sizeof(pre));
        d[S]=0;
        qh=qt=0;
        inq[q[qt++]=S]=true;
        inqc[S]++;
        while (qh!=qt)
        {
              int u=q[qh++];
              if (qh==MAXV) qh=0;
              inq[u]=false;
              for (edge e=adj[u];e;e=e->n)
              {
                  int v=e->v;
                  if (e->c&&d[v]-d[u]>e->l)
                  {
                     pre[v]=e;
                     d[v]=d[u]+e->l;
                     inqc[v]++;
                     if (!inq[v])
                     {
                        inq[q[qt++]=v]=true;
                        if (qt==MAXV) qt=0;
                        inq[v]=true;
                     }
                  }
              }
        }
        if (!pre[T]) break;
        else
        {
            int flow=+oo;
            int u;
            u=T;
            while (pre[u])
            {
                  if (pre[u]->c<flow) flow=pre[u]->c;
                  u=pre[u]->b->v;
            }
            u=T;
            while (pre[u])
            {
                  pre[u]->c-=flow;
                  pre[u]->b->c+=flow;
                  u=pre[u]->b->v;
            }
            cost+=flow*d[T];
            flow_total+=flow;
        }
    }
    if (flow_total!=K) return -1;
    else return cost;
}

int main()
{
    while (scanf("%d%d%d",&N,&M,&K)!=EOF)
    {
          init_graph();
          for (int i=0;i<M;i++)
          {
              int u,v,a,c;
              scanf("%d%d%d%d",&u,&v,&a,&c);
              for (int i=1;i<=c;i++)
                  add_edge(u,v,a*(2*i-1),1);
          }
          add_edge(0,1,0,K);
          printf("%d\n",min_cost_flow(0,N));
    }
}

