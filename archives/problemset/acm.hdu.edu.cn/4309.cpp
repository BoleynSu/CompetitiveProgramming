#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define foreach(e,set) for (typeof((set).begin()) e=(set).begin();e!=(set).end();e++)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define clr(x) memset((x),0,sizeof(x))
#define prt(x) cout<<#x<<"="<<x<<endl
#define prtm(x,y) cout<<x<<y<<endl

typedef long long int lli;
typedef vector<int> vint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int oo=(~0u)>>1;
const lli ool=(~0ull)>>1;
const double inf=1e100;
const double eps=1e-8;

#define oo 0x7f7f7f7f
#define MAXEDGE 100000
#define MAXV 10000

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
int maxflow,mincost;
void min_cost_flow(int flow,int cost)
{
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
    if (maxflow==flow)
    {
        if (mincost>cost) mincost=cost;
    }
    else if (maxflow<flow)
    {
        maxflow=flow;
        mincost=cost;
    }
}

int n,m;
int bridge_number;
int rc[10000];
int ru[10000];
int rv[10000];
int rw[10000];
int rp[10000];
bool fixed_bridge[10000];
int bridge[10000];

void dfs(int i=0)
{
    if (i==bridge_number)
    {
        int cost=0;
        top=pool;
        clr(adj);
        S=0,T=n+1;
        for (int u=1;u<=n;u++)
            add_edge(S,u,rc[u],0);
        rep(i,m)
        {
            int u=ru[i],v=rv[i],w=rw[i],p=rp[i];
            if (p>0)
            {
                add_edge(u,v,1,0);
                if (fixed_bridge[i])
                {
                    add_edge(u,v,oo,0);
                    cost+=w;
                }
            }
            else if(p<0)
            {
                add_edge(u,v,oo,0);
                add_edge(u,T,w,0);
            }
            else add_edge(u,v,oo,0);
        }
        min_cost_flow(0,cost);
    }
    else
    {
        fixed_bridge[bridge[i]]=true;
        dfs(i+1);
        fixed_bridge[bridge[i]]=false;
        dfs(i+1);
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for (int u=1;u<=n;u++)
            scanf("%d",rc+u);
        bridge_number=0;
        rep(i,m)
        {
            scanf("%d%d%d%d",ru+i,rv+i,rw+i,rp+i);
            if (rp[i]>0) bridge[bridge_number++]=i;
        }
        maxflow=0;
        mincost=oo;
        dfs();
        if (maxflow) cout<<maxflow<<" "<<mincost<<endl;
        else cout<<"Poor Heaven Empire"<<endl;
    }
}

