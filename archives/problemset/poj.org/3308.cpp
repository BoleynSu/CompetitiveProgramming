/*
AUTHOR: Su Jiao
DATE: 2010-7-19
DESCRIPTION:
网络流 乱做
http://acm.pku.edu.cn/JudgeOnline/problem?id=3308
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

const double oo=1e10;
const double zero=1e-10;
const int MAXV=1000000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v;double c;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T,V;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
int head,tail;
void add_edge(int u,int v,double c)
{
     top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}
bool is_zero(double a)
{
     return fabs(a)<=zero;
}
bool relabel()
{
     for (int i=0;i<V;d[i++]=V) ;
     d[q[head=tail=0]=T]=0;
     while (head<=tail)
     {
           int u=q[head++];
           for (edge i=adj[u];i;i=i->n)
               if (!is_zero(i->b->c)&&d[i->v]==V)
                  d[q[++tail]=i->v]=d[u]+1;
           if (d[S]!=V) return true;
     }
     return false;
}
double augment(int u,double e)
{
       if (u==T) return e;
       double f=0;
       for (edge i=adj[u];i&&!is_zero(e);i=i->n)
           if (!is_zero(i->c)&&d[u]==d[i->v]+1)
           {
              double df=augment(i->v,e<i->c?e:i->c);
              i->c-=df,i->b->c+=df,e-=df,f+=df;
           }
       return f;
}
double dinic()
{
       double f=0;
       while (relabel()) f+=augment(S,oo);
       return f;
}

const int SIZE=1000;
int t;
int m,n,l;
int main()
{
    scanf("%d",&t);
    for (int tt=0;tt<t;tt++)
    {
        scanf("%d%d%d",&m,&n,&l);
        top=pool;
        memset(adj,0,sizeof(adj));
        S=0,T=m+n+1,V=m+n+2;
        for (int i=1;i<=m;i++)
        {
            double a;
            scanf("%lf",&a);
            add_edge(S,i,log(a));
        }
        for (int i=1;i<=n;i++)
        {
            double a;
            scanf("%lf",&a);
            add_edge(i+m,T,log(a));
        }
        for (int i=0;i<l;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add_edge(a,b+m,oo);
        }
        printf("%.4f\n",double(exp(dinic())));
    }
}
