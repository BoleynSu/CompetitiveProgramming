#include <cstdio>
#include <cstring>
using namespace std;
 
#define oo 0x7f7f7f7f
#define MAXEDGE 100000
#define MAXV 500
 
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
            int delta=oo;
            for (edge i=p[T];i;i=p[i->b->v])
                if (delta>i->c) delta=i->c;
            for (edge i=p[T];i;i=p[i->b->v])
                i->c-=delta,i->b->c+=delta;
            flow+=delta;
            cost+=d[T]*delta;
        }
    }
    return cost;
}

#include <cstdio>
using namespace std;

char s[300000];
int begin[300],end[300];
int LCP(int i,int j)
{
    for (int k=0;;k++)
        if (begin[i]+k>end[i]||end[j]-k<begin[j]||s[begin[i]+k]!=s[end[j]-k])     
           return k;
}
int main()
{
    int N;
    while (scanf("%d",&N)!=EOF)
    {
          for (int i=0;i<N;i++)
          {
              scanf("%s",s+begin[i]);
              for (end[i]=begin[i];s[end[i]];end[i]++) ;
              begin[i+1]=end[i];
              end[i]--;
          }
          top=pool;
          S=N*2,T=N*2+1,V=N*2+2;
          memset(adj,0,sizeof adj);
          for (int i=0;i<N;i++)
          {
              add_edge(S,i,1,0);
              for (int j=0;j<N;j++)
                  if (i!=j) add_edge(i,N+j,1,-LCP(i,j));
                  else add_edge(i,N+j,1,0);
              add_edge(N+i,T,1,0);
          }
          printf("%d\n",-min_cost_flow());
    }
    return 0;
}

