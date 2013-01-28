#include <cstdio> 
//ZKW 接口： 构图 build_network() 求最小费用流 zkw()
#include <cstring>
using namespace std;
namespace sujiao
{
//ZKW 接口： 构图 build_network() 求最小费用流 zkw()

const int oo=(~0u)>>1;
const int MAXV=100000;//最多有多少个点
const int MAXE=100000;//最多有多少条边 注意 一条边对应一条正向边和一条反向边
typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T,V;
edge adj[MAXV];
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
    int f=0;
    for (edge i=adj[u];i;i=i->n)
        if (i->c&&!vis[i->v]&&d[u]==d[i->v]+i->d)
        {
           int df=augment(i->v,min(e,i->c));
           i->c-=df;
           i->b->c+=df;
           e-=df,f+=df;
        }
    return f;
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
     }
     return true;
}
int zkw()
{
    int cost=0,flow;
    do
      do
        flow=augment(S,oo),
        cost+=d[S]*flow;
      while (flow);
    while (relabel());
    return cost;
}
void build_network()
{
     memset(adj,0,sizeof(adj));
     memset(d,0,sizeof(d));
     memset(vis,0,sizeof(vis));
     top=pool;
     //S,T,V;
     //add_edge(u,v,c,d);//加一条u到v的容量为c费用为d的有向边
}

} 


   const int inf = 1 << 30;
   #define maxn 5005
   #define maxm 500005
  #define MAX 105
  int n, r, c, s, t;
  int eh[maxn], dist[maxn], low[maxn], tot, pre[maxn], ans, anscost, m, h;
  bool visit[maxn];
  char maz[MAX][MAX];
   struct node {
      int x, y;
  }man[maxn], house[maxn];
  #define abs(x) (((x)>0)?((x)):(-(x)))
  int getdist(int i, int j) {
      return abs(man[i].x - house[j].x) + abs(man[i].y - house[j].y);
  }
int main() {
     while(~scanf("%d%d", &r, &c)) {
         getchar();
      tot = 0;
      m = h = 0;
      memset(eh, -1, sizeof(eh));
         if(!r && !c) break;
         for(int i = 0; i < r; i++) {
             for(int j = 0; j <= c; j++) {
                 scanf("%c", &maz[i][j]);
                 if(maz[i][j] == 'm') {
                     m++;
                     man[m].x = i, man[m].y = j;
                 }
                 if(maz[i][j] == 'H') {
                     h++;
                     house[h].x = i, house[h].y = j;
                 }
             }
         }
     memset(sujiao::adj,0,sizeof(sujiao::adj));
     memset(sujiao::d,0,sizeof(sujiao::d));
     memset(sujiao::vis,0,sizeof(sujiao::vis));
     sujiao::top=sujiao::pool;
     sujiao::S=0,sujiao::T=m + h + 1,sujiao::V=m + h + 2;
          s = 0, t = m + h + 1 ,n = m + h + 2;
         for(int i = 1; i <= m; i++) sujiao::add_edge(s, i, 1, 0);
         for(int i = 1; i <= h; i++) sujiao::add_edge(i + m, t, 1, 0);
         for(int i = 1; i <= m; i++)
             for(int j = 1; j <= h; j++)
                 sujiao::add_edge(i, m + j, 1, getdist(i, j));
         printf("%d\n", sujiao::zkw());
     }
 }