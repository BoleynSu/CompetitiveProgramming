#include <stdio.h>
#include <string.h>

#define MAXN 500000
const int BOB=0,ALICE=1;
const int oo=(~0u)>>1;
int n,L,R;

typedef struct{void* n;int v;int l;} edge_struct;
typedef edge_struct* edge;
edge_struct pool[MAXN];
edge top;
edge adj[MAXN];

int f(int player,int L,int R,int node)
{
    int result;
    if (player==BOB)
    {
       result=-oo;
       if (adj[node])
       {
          edge e;
          for (e=adj[node];e;e=e->n)
          {
              int get=f(ALICE,L-e->l,R-e->l,e->v);
              if (get!=+oo&&(get+e->l>result)) result=get+e->l;
          }
       }
       else if (L<=0&&R>=0) result=0;
    }
    else
    {
        result=+oo;
        if (adj[node])
        {
           edge e;
           for (e=adj[node];e;e=e->n)
           {
              int get=f(BOB,L-e->l,R-e->l,e->v);
               if (get!=-oo&&get+e->l<result) result=get+e->l;
           }
        }
        else if (L<=0&&R>=0) result=0;
    }
    return result;
}

int main()
{
    for (;;)
    {
        int i,get;
        {
            char get;
            get=getchar();
            if (get==EOF) break;
            n=get-'0';
            while (((get=getchar())>='0')&&(get<='9')) n=((n<<3)+(n<<1))+(get-'0');
            L=0;
            while (((get=getchar())>='0')&&(get<='9')) L=((L<<3)+(L<<1))+(get-'0');
            R=0;
            while (((get=getchar())>='0')&&(get<='9')) R=((R<<3)+(R<<1))+(get-'0');
        }
        top=pool;
        memset(adj,0,sizeof(edge)*n);
        for (i=1;i<n;i++)
        {
            int u,v,l;
            char get;
            u=0;
            while (((get=getchar())>='0')&&(get<='9')) u=((u<<3)+(u<<1))+(get-'0');
            v=0;
            while (((get=getchar())>='0')&&(get<='9')) v=((v<<3)+(v<<1))+(get-'0');
            l=0;
            while (((get=getchar())>='0')&&(get<='9')) l=((l<<3)+(l<<1))+(get-'0');
            top->n=adj[u],top->v=v,top->l=l;
            adj[u]=top++;
        }
        getchar();
        get=f(BOB,L,R,0);
        if (get==-oo) printf("Oh, my god!\n");
        else printf("%d\n",get);
    }
}

