#include <cstdio>
#include <cstring>
using namespace std;

#define MAXV 102
#define MAXEDGE (2000+100)*2
#define oo 0x7f7f7f7f

typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXEDGE];
edge top;
int S,T,V;
edge adj[MAXV];
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
int max_flow;
int min_cost_flow()
{
    max_flow=0;
    int cost=0;
    for (;;)
    {
        static edge pre[MAXV];
        static int dis[MAXV];
        static bool inq[MAXV];
        static int q[MAXV];
        static int open,close;
        for (int i=0;i<MAXV;i++) dis[i]=oo,inq[i]=false;
        inq[q[open=close=0]=S]=true;
        pre[S]=0;
        dis[S]=0;
        while (close<=open)
        {
              int u;
              inq[u=q[(close++)%MAXV]]=false;
              for (edge i=adj[u];i;i=i->n)
                  if (i->c&&dis[i->v]>dis[u]+i->d)
                  {
                     dis[i->v]=dis[u]+i->d;
                     pre[i->v]=i;
                     if (!inq[i->v]) inq[q[(++open)%MAXV]=i->v]=true;
                  }
        }
        if (dis[T]==oo) break;
        int delta=oo;
        for (edge i=pre[T];i;i=pre[i->b->v])
            if (delta>i->c) delta=i->c;
        for (edge i=pre[T];i;i=pre[i->b->v])
        {
            i->c-=delta;
            i->b->c+=delta;
        }
        cost+=dis[T]*delta;
        max_flow+=delta;
    }
    return cost;
}

int in[MAXV],out[MAXV];

int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        int n,m,s,t,u,v,a,b,cost=0;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        top=pool;
        memset(adj,0,sizeof(adj));
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        S=0,T=n+1,V=n+2;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            if (b>=a)
            {
                add_edge(v,u,1,b-a);
                in[v]++;
                out[u]++;
                cost+=a;
            }
            else
            {
                add_edge(u,v,1,a-b);
                cost+=b;
            }
        }
        in[s]++;
        out[t]++;
        int need_flow=0;
        for (int i=1;i<=n;i++)
        {
            if (in[i]>out[i])
            {
                add_edge(S,i,in[i]-out[i],0);
                need_flow+=in[i]-out[i];
            }
            else if (out[i]>in[i]) add_edge(i,T,out[i]-in[i],0);
        }
        int min_cost=min_cost_flow();
        if (max_flow==need_flow) printf("Case %d: %d\n",tc,cost+min_cost);
        else printf("Case %d: impossible\n",tc);
    }
}

