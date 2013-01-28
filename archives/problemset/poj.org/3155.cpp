#include <stdio.h>
#include <string.h>

const int oo=(~0u)>>1;
const int MAXV=1102;
const int MAXE=6200;
typedef struct struct_edge* edge;
struct struct_edge{int v,c;edge n,b;};
struct_edge pool[MAXE];
edge top=pool;
int S,T,V;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
int head,tail;
void add_edge(int u,int v,int c)
{
     top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}
bool relabel()
{
     for (int i=0;i<V;d[i++]=oo) ;
     d[q[head=tail=0]=T]=0;
     while (head<=tail)
     {
           int u=q[head++];
           for (edge i=adj[u];i;i=i->n)
               if (i->b->c&&d[i->v]==oo)
                  d[q[++tail]=i->v]=d[u]+1;
           if (d[S]!=oo) return true;
     }
     return false;
}
int augment(int u,int e)
{
    if (u==T) return e;
    int f=0;
    for (edge i=adj[u];i&&e;i=i->n)
        if (i->c&&d[u]==d[i->v]+1)
           if (int df=augment(i->v,e<i->c?e:i->c))
              i->c-=df,i->b->c+=df,e-=df,f+=df;
    return f;
}
int dinic()
{
    int f=0;
    while (relabel()) f+=augment(S,oo);
    return f;
}
int sap(){return dinic();}

const int MAXN=100,MAXM=1000;
const int XX=MAXN*MAXN*MAXN;
int n,m;
int a[MAXM],b[MAXM];
bool visited[MAXN+MAXM+2];
int total;

void build_network(int rate)
{
     memset(adj,0,sizeof(adj));
     top=pool;
     S=n+m,T=m+n+1,V=n+m+2;
     for (int i=0;i<n;i++)
         add_edge(S,i,rate);
     for (int i=0;i<m;i++)
         add_edge(a[i]-1,n+i,oo),
         add_edge(b[i]-1,n+i,oo),
         add_edge(n+i,T,XX);
}
void dfs(int u)
{
     visited[u]=true;
     for (edge i=adj[u];i;i=i->n)
         if (!visited[i->v]&&i->c)
            dfs(i->v);
}
void read()
{
     scanf("%d%d",&n,&m);
     for (int i=0;i<m;i++)
         scanf("%d%d",a+i,b+i);
}
void write()
{
     if (!m)
     {
        printf("%d\n%d\n",1,1);
        return;
     }
     int L=0*XX,R=m*XX,best;
     do
     {
       int mid=(L+R)>>1;
       build_network(mid);
       int g=m*XX-sap();
       if (g<=0) R=mid;
       else L=mid,best=L;
     }
     while (L+1!=R);
     build_network(best);
     sap();
     dfs(S);
     for (int i=0;i<n;i++)
         if (!visited[i]) total++;
     printf("%d\n",total);
     for (int i=0;i<n;i++)
         if (!visited[i])
            printf("%d\n",i+1);
}

int main()
{
    read();
    write();
}
