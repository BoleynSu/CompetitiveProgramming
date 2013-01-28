#include <cstdio> 
int n, m, k;
#define size 102
#define Max 0x7fffffff
struct edge{int from, to, val, next, cost;} e[5400];
int v[size], cnt, pre[size], pos[size], dis[size], que[size * 10];
bool vst[size];
int need[50][50], have[50][50], g[50][50][50], sum[50];
int s,t,flow;
//ZKW 接口： 构图 build_network() 求最小费用流 zkw()
#include <cstring>
using namespace std;
namespace sujiao
{
const int oo=(~0u)>>1;
const int MAXV=100000;//最多有多少个点
const int MAXE=100000;//最多有多少条边 注意 一条边对应一条正向边和一条反向边
typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T,V;
edge adj[MAXV],cur[MAXV];
int d[MAXV],vis[MAXV];
void add_edge(int u,int v,int c,int d)
{
     top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}
int augment(int u,int e)
{
    #define min(a,b) ((a)<(b)?(a):(b))
    if (u==T) return e;
    vis[u]=true;
    for (edge i=cur[u];i;i=i->n)
        if (i->c&&!vis[i->v]&&d[u]==d[i->v]+i->d)
           if (int df=augment(i->v,min(e,i->c)))
           {
              i->c-=df;
              i->b->c+=df;
              cur[u]=i;
              return df;
           }
    cur[u]=0;
    return 0;
}
bool relabel()
{
     int delta=oo;
     for (int i=0;i<V;i++)
         if (vis[i])
            for (edge j=adj[i];j;j=j->n)
                if (j->c&&(!vis[j->v])&&(d[j->v]+j->d-d[i]<delta))
                   delta=d[j->v]+j->d-d[i];
     if (delta==oo) return false;
     for (int i=0;i<V;i++)
     {
         if (vis[i])
            d[i]+=delta,vis[i]=false;
         cur[i]=adj[i];
     }
     return true;
}
int zkw()
{
    int cost=0,flow;
    do
      do
        flow=augment(S,oo),
        cost+=d[S]*flow,
        ::flow+=flow;
      while (flow);
    while (relabel());
    return cost;
}
void build_network()
{
     memset(adj,0,sizeof(adj));
     memset(cur,0,sizeof(cur));
     memset(d,0,sizeof(d));
     memset(vis,0,sizeof(vis));
     top=pool;
     S=::s,T=::t,V=::t+1;
     //add_edge(u,v,c,d);//加一条u到v的容量为c费用为d的有向边
}
}
int main()
{
    while(scanf("%d%d%d", &n, &m, &k) && (n || m || k))
    {
        memset(sum, 0, sizeof(int) * (k + 1));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
                scanf("%d", &need[i][j]), sum[j] += need[i][j];
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= k; j++)
                scanf("%d", &have[i][j]);
        for(int k1 = 1; k1 <= k; k1++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                    scanf("%d", &g[k1][i][j]);
        int ans = 0;
        bool flag = true;
        for(int i = 1; i <= k; i++)
        {
          s = 0, t = n + m + 1;
          sujiao::build_network();
            for(int j = 1; j <= n; j++) sujiao::add_edge(s, j, need[j][i], 0),sujiao::add_edge( j,s, need[j][i], 0);
            for(int j = 1; j <= m; j++) sujiao::add_edge(j + n, t, have[j][i], 0),sujiao::add_edge( t,j + n, have[j][i], 0);
            for(int j = 1; j <= n; j++)
                for(int j2 = 1; j2 <= m; j2++)
                    sujiao::add_edge(j, j2 + n, 2000000000, g[i][j][j2]),sujiao::add_edge( j2 + n,j, 2000000000,- g[i][j][j2]);
            flow = 0;
            int cost = sujiao::zkw();
            if (flow != sum[i]) {flag = false;break;}
            ans += cost;
        }
        if (!flag) printf("-1\n");
        else printf("%d\n", ans);
    }
}
