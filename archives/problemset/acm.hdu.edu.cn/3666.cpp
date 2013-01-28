#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=400+2,MAXM=400+2;
const double oo=1e6;
int N,M,L,U;
int C[MAXN][MAXM];

const int MAXE=MAXN*MAXM*2;
const int MAXV=MAXN+MAXM;
struct edge_struct{edge_struct* n;int v;double l;};
typedef edge_struct* edge;
edge_struct pool[MAXE];
edge top;
int V,E;
edge adj[MAXV];
void init_graph()
{
     top=pool;
     V=E=0;
     memset(adj,0,sizeof(adj));
}
void add_edge(int u,int v,double l)
{
     if (!adj[u]) V++;
     E++;
     top->n=adj[u],top->v=v,top->l=l;
     adj[u]=top++;
}
bool SPFA(int S)
{
     double d[MAXV];
     int qh,qt;
     int q[MAXV];
     bool inq[MAXV];
     int inqc[MAXV];
     for (int u=0;u<V;u++) d[u]=+oo;
     memset(inq,0,sizeof(inq));
     memset(inqc,0,sizeof(inqc));
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
               if (d[v]-d[u]>e->l)
               {
                  d[v]=d[u]+e->l;
                  //next 2 lines are wrong
                  inqc[v]++;
                  if (inqc[v]>V) return false;
                  if (!inq[v])
                  {
                     inq[q[qt++]=v]=true;
                     if (qt==MAXV) qt=0;
                     inq[v]=true;
                  }
               }
           }
     }
     return true;
}

int main()
{
    while (scanf("%d%d%d%d",&N,&M,&L,&U)!=EOF)
    {
          for (int i=0;i<N;i++)
              for (int j=0;j<M;j++)
                  scanf("%d",C[i]+j);
          init_graph();
          for (int i=0;i<N;i++)
              for (int j=0;j<M;j++)
              {
                  add_edge(i,N+j,log(double(U)/double(C[i][j])));
                  add_edge(N+j,i,-log(double(L)/double(C[i][j])));
              }
          if (SPFA(0)) printf("YES\n");
          else printf("NO\n");
    }
}

