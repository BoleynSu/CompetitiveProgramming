#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

enum{MAXN=1000,MAXD=400};
struct Order{int s,t,v;};
int n;
Order order[MAXN];

#define oo 0x7f7f7f7f
#define MAXEDGE 2+400*2+1000*2
#define MAXV 402

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

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=0;i<n;i++) cin>>order[i].s>>order[i].t>>order[i].v;
        memset(adj,0,sizeof(adj));
        top=pool;
        S=0,T=MAXD+1;
        add_edge(S,1,2,0);
        for (int i=1;i<=MAXD;i++)
            add_edge(i,i+1,oo,0);
        for (int i=0;i<n;i++)
            add_edge(order[i].s,order[i].t+1,1,-order[i].v);
        cout<<-min_cost_flow()<<endl;
    }
}

