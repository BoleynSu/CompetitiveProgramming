#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=500000;
const int BOB=0,ALICE=1;
const int OMG=-1;
const int oo=(~0u)>>1;
int n,L,R;

const int MAXE=MAXN-1;
const int MAXV=MAXN;
struct edge_struct{edge_struct* n;int v;int l;};
typedef edge_struct* edge;
edge_struct pool[MAXE];
edge top;
edge adj[MAXV];
void init_graph()
{
     top=pool;
     memset(adj,0,sizeof(adj));
}
void add_edge(int u,int v,int l)
{
     top->n=adj[u],top->v=v,top->l=l;
     adj[u]=top++;
}

int f(int player,int L,int R,int node)
{
    int result;
    if (player==BOB)
    {
       result=-oo;
       if (adj[node])
          for (edge e=adj[node];e;e=e->n)
          {
              int get=f(ALICE,L-e->l,R-e->l,e->v);
              if (get!=+oo&&(get+e->l>result)) result=get+e->l;
          }
       else if (L<=0&&R>=0) result=0;
    }
    else
    {
        result=+oo;
        if (adj[node])
           for (edge e=adj[node];e;e=e->n)
           {
              int get=f(BOB,L-e->l,R-e->l,e->v);
               if (get!=-oo&&get+e->l<result) result=get+e->l;
           }
        else if (L<=0&&R>=0) result=0;
    }
    return result;
}
bool is_number[256];
void init_input()
{
     for (int i='0';i<='9';i++) is_number[i]=true;
}
bool read(int& n)
{
     char get;
     do if ((get=getchar())==EOF) return false;
     while (!is_number[get]);
     n=0;
     do n=((n<<3)+(n<<1))+(get-'0');
     while (is_number[get=getchar()]);
     return true;
}

int main()
{
    init_input();
    while (read(n)&&read(L)&&read(R))
    {
          init_graph();
          for (int i=1;i<n;i++)
          {
              int u,v,l;
              read(u),read(v),read(l);
              add_edge(u,v,l);
          }
          int get=f(BOB,L,R,0);
          if (get==-oo) printf("Oh, my god!\n");
          else printf("%d\n",get);
    }
}

