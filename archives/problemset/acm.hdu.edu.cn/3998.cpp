#include <cstdio>
#include <map>
#include <utility>
#include <queue>
using namespace std; 

enum{MAXN=199339};
int n;
int a[MAXN];
int f[MAXN];
int st[MAXN*4];

void insert(int p,int value,int L,int R,int root=1)
{
     if (p<L||R<p) return;
     else
     {
         if (value>st[root])
            st[root]=value;
         if (L==R) return;
         int LL=L,LR=(L+R)>>1,Lroot=root<<1,
             RL=LR+1,RR=R,Rroot=Lroot|1;
         insert(p,value,LL,LR,Lroot);
         insert(p,value,RL,RR,Rroot);
     }
}
int query(int l,int r,int L,int R,int root=1)
{
    if (r<L||R<l||L>R) return 0;
    else if (l<=L&&R<=r) return st[root];
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1,
            RL=LR+1,RR=R,Rroot=Lroot|1;
        int LV=query(l,r,LL,LR,Lroot);
        int RV=query(l,r,RL,RR,Rroot);
        return LV>RV?LV:RV;
    }
}





/*

AUTHOR: Su Jiao

DATE: 2010-7-19

DESCRIPTION:

ÍøÂçÁ÷ ÂÒ×ö

http://acm.pku.edu.cn/JudgeOnline/problem?id=3155

*/

#include <stdio.h>

#include <string.h>

 

const int oo=(~0u)>>1;

const int MAXV=11020;

const int MAXE=620000;

typedef struct struct_edge* edge;

struct struct_edge{int v,c;edge n,b;};

struct_edge pool[MAXE];

edge top=pool;

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


int main()
{
    while (scanf("%d",&n)!=EOF)
    {
          map<int,int> s;
          map<int,vector<int> > sv;
          memset(st,0,sizeof st);
          for (int i=0;i<n;i++)
              scanf("%d",a+i),s.insert(make_pair(a[i],0));
          int L=0,R=-1;
          for (map<int,int>::iterator it=s.begin();it!=s.end();it++)
              it->second=++R;
          for (int i=0;i<n;i++)
              a[i]=s[a[i]];
          
          memset(adj,0,sizeof(adj));
          memset(d,0,sizeof(d));
          memset(dn,0,sizeof(dn));
          top=pool;
          S=n,T=n+1,V=n+2;
          
          for (int i=0;i<n;i++)
          {
              f[i]=query(0,a[i]-1,L,R)+1;
              insert(a[i],f[i],L,R);
              sv[f[i]].push_back(i);
              const vector<int>& front=sv[f[i]-1];
              if (front.size()==0) add_edge(S,i,1);
              for (int j=0;j<front.size();j++)
                  add_edge(front[j],i,1);
          }
          int fmax=query(L,R,L,R);
          for (int i=0;i<n;i++)
              if (f[i]==fmax) add_edge(i,T,1);
          
          printf("%d\n%d\n",fmax,sap());
    }
}

