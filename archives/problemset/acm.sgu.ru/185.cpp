/*
AUTHOR: Su Jiao
DATE: 2010-7-21
DESCRIPTION:
网络流 乱做
http://acm.sgu.ru/problem.php?contest=0&problem=185
*/
#include <stdio.h>

const int oo=19930309;
const int MAXV=400+2;

int S,T;
int d[MAXV][MAXV];
int dis[MAXV];
bool inq[MAXV];
int q[MAXV];
int head,tail;

void SPFA()
{
     for (int i=S;i<=T;i++) dis[i]=oo;
     inq[q[head=tail=0]=S]=true;
     dis[S]=0;
     while (head<=tail)
     {
           int u;
           inq[u=q[(head++)%MAXV]]=false;
           for (int v=S;v<=T;v++)
               if (d[u][v]&&dis[v]>dis[u]+d[u][v])
               {
                  if (!inq[v])
                     inq[q[(++tail)%MAXV]=v]=true;
                  dis[v]=dis[u]+d[u][v];
               }
     }
}
namespace sj
{
          const int oo=(~0u)>>1;
          const int MAXV=400+2;
          const int MAXE=400*400;
          typedef struct struct_edge* edge;
          struct struct_edge{int v,c;edge n,b;};
          struct_edge pool[MAXE];
          edge top;
          int S,T,V;
          edge adj[MAXV];
          int d[MAXV],dn[MAXV+1];
          void add_edge(int u,int v,int c)
          {
               top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
               top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
               adj[u]->b=adj[v],adj[v]->b=adj[u];
          }
          int augment(int u,int e)
          {
              if (u==T) return e;
              if (d[S]==V) return 0;
              int f=0,mind=V-1;
              for (edge i=adj[u];i;i=i->n)
                  if (i->c)
                  {
                     if (d[u]==d[i->v]+1)
                     {
                        int df=augment(i->v,e<i->c?e:i->c);
                        i->c-=df;
                        i->b->c+=df;
                        e-=df;
                        f+=df;
                        if (e==0) return f;
                     }
                     if (mind>d[i->v]) mind=d[i->v];
                  }
              if (f) return f;
              else
              {
                  if (!--dn[d[u]]) d[S]=V;
                  else dn[d[u]=mind+1]++;
                  return 0;
              }
          }
          int sap()
          {
              int f=0;
              dn[0]=V;
              while (d[S]<V) f+=augment(S,oo);
              return f;
          }
          void dfs(int u)
          {
               if (u==T) printf("%d\n",u);
               else
               {
                   printf("%d ",u);
                   for (edge i=adj[u];i;i=i->n)
                       if ((!i->c)&&(!((i-pool)&1)))
                       {
                          i->c++;
                          i->b->c--;
                          dfs(i->v);
                          break;
                       }
               }
          }
}

int main()
{
    int n,m,x,y,l;
    scanf("%d%d",&n,&m),S=1,T=n;
    for (int u=S;u<=T;u++)
        for (int v=S;v<=T;v++)
            d[u][v]=oo;
    for (int i=0;i<m;i++)
        scanf("%d%d%d",&x,&y,&l),d[x][y]=d[y][x]=l;
    SPFA();
    sj::top=sj::pool;
    sj::S=S,sj::T=T,sj::V=n;
    for (int u=S;u<=T;u++)
        for (int v=S;v<=T;v++)
            if (dis[u]+d[u][v]==dis[v])
               sj::add_edge(u,v,1);
    if (sj::sap()<2) printf("No solution\n");
    else
    {
        sj::dfs(sj::S);
        sj::dfs(sj::S);
    }
}
