/*
AUTHOR: Su Jiao
DATE: 2010-8-24
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

const int MAXE=14000*2;
const int MAXV=300+2;
typedef struct struct_edge* edge;
struct struct_edge{int v,d;edge n;};
struct node
{
       int c,r,t[2];
       int color(int timeline)
       {
           int alpha=timeline%(t[0]+t[1]);
           if (r<=alpha&&alpha<r+t[!c]) return !c;
           else return c;
       }
       int remain(int timeline)
       {
           int alpha=timeline%(t[0]+t[1]);
           if (alpha<r)
              return r-alpha;
           else if (alpha<r+t[!c])
                return r+t[!c]-alpha;
           else return t[0]+t[1]-alpha;
       }
};
struct_edge pool[MAXE];
edge top=pool;
int S,T;
int V,E;
node vertex[MAXV];
edge adj[MAXV];
const int oo=19930309;
int d[MAXV];
int visited[MAXV];
int pre[MAXV];
void add_edge(int u,int v,int d)
{
     top->v=v,top->d=d,top->n=adj[u],adj[u]=top++;
     top->v=u,top->d=d,top->n=adj[v],adj[v]=top++;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int wait(int u,int v,int now=0,int change_times=0)
{
    if (change_times>3) return oo;
    if (vertex[u].color(now)==vertex[v].color(now)) return now;
    else
    {
        int wt=wait(u,v,now+min(vertex[u].remain(now),vertex[v].remain(now)),change_times+1);
        if (wt==oo) return oo;
        else return wt;
    }
}
void dijkstra()
{
     for (int u=1;u<=V;u++)
         d[u]=oo;
     d[S]=0;
     for (int i=1;i<=V;i++)
     {
         int u,du=oo;
         for (int tu=1;tu<=V;tu++)
             if (!visited[tu]&&d[tu]<du)
                du=d[u=tu];
         visited[u]=true;
         for (edge i=adj[u];i;i=i->n)
             if (!visited[i->v])
             {
                int tdv=wait(u,i->v,d[u])+i->d;
                if (d[i->v]>tdv)
                   d[i->v]=tdv,
                   pre[i->v]=u;
             }
     }
}
void print(int u)
{
     if (u!=S) print(pre[u]);
     cout<<u<<char(u==T?'\n':' ');
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>S>>T;
    cin>>V>>E;
    for (int i=1;i<=V;i++)
    {
        char color;
        cin>>color>>vertex[i].r>>vertex[i].t[0]>>vertex[i].t[1];
        vertex[i].c=(color=='P');
    }
    for (int i=0;i<E;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        add_edge(a,b,d);
    }
    dijkstra();
    if (d[T]==oo) cout<<0<<endl;
    else
    {
        cout<<d[T]<<endl;
        print(T);
    }
}
