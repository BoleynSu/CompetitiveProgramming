#include <cstring>
using namespace std;
const int MAXV=20000;
const int MAXE=1000000;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
typedef void function(int block,int node);
int V;
struct_edge pool[MAXE];
edge top;
edge adj[MAXV];
void build_graph()
{
     top=pool;
     memset(adj,0,sizeof(adj));
     //V;
     //add_edge(u,v);
}
void add_edge(int u,int v)
{
     top->v=v,top->n=adj[u],adj[u]=top++;
}
int stamp;
int DFN[MAXV];
int LOW[MAXV];
int st;
int s[MAXV];
bool ins[MAXV];
bool visited[MAXV];
int depth;
edge e[MAXV];
int root[MAXV];
int block;

void tarjan(function f)
{
     memset(visited,0,sizeof(visited));
     memset(ins,0,sizeof(ins));
     st=0;
     block=0;
     for (int start=0;start<V;start++)
         if (!visited[start])
         {
            depth=0;
            root[depth]=start;
            e[depth]=adj[root[depth]];
            DFN[root[depth]]=LOW[root[depth]]=++stamp;
            ins[s[st++]=root[depth]]=true;
            visited[root[depth]]=true;
            do
            {
              if (e[depth])
              {
                 if (!visited[e[depth]->v])
                 {
                    int depth_=depth+1;
                    e[depth_]=adj[root[depth_]=e[depth]->v];
                    DFN[root[depth_]]=LOW[root[depth_]]=++stamp;
                    ins[s[st++]=root[depth_]]=true;
                    visited[root[depth_]]=true;
                    e[depth]=e[depth]->n;
                    depth++;
                 }
                 else if (ins[e[depth]->v])
                 {
                     if (LOW[root[depth]]>DFN[e[depth]->v])
                        LOW[root[depth]]=DFN[e[depth]->v];
                     e[depth]=e[depth]->n;
                 }
                 else e[depth]=e[depth]->n;
              }
              else
              {
                  if (LOW[root[depth]]==DFN[root[depth]])
                  {
                     do
                     {
                       ins[s[--st]]=false;
                       f(block,s[st]);
                     }
                     while (s[st]!=root[depth]);
                     block++;
                  }
                  if (depth>0)
                  {
                     int depth_=depth-1;
                     if (LOW[root[depth_]]>LOW[root[depth]])
                        LOW[root[depth_]]=LOW[root[depth]];
                  }
                  depth--;
              }
            }
            while (depth>=0);
         }
}

typedef struct_edge struct_list;
typedef edge list;
int block_id[MAXV];
struct_list spool[MAXV];
list stop;
list set[MAXV];
#define T(x) ((x)<<1)
#define F(x) (((x)<<1)|1)
void build_2sat()
{
     stop=spool;
     memset(set,0,sizeof(set));
     build_graph();
     //add_edge(u,v);
}
void function_2sat(int block,int node)
{
     block_id[node]=block;
     stop->v=node,stop->n=set[node],set[node]=stop++;
}
bool possible_2sat()
{
     tarjan(function_2sat);
     for (int i=0;i<(V>>1);i++)
         if (block_id[T(i)]==block_id[F(i)])
            return false;
     return true;
}

#include <iostream>
using namespace std;

int N,M;
int a[MAXV],b[MAXV];
int main()
{
    int T=1;
    for (int t=1;t<=T;t++)
    {
        cin>>N>>M;
        V=M*2;
        build_2sat();
        for (int i=0;i<M;i++)
        {
            cin>>a[i]>>b[i];
            if (a[i]>b[i])
            {
               int s=a[i];
               a[i]=b[i];
               b[i]=s;
            }
            for (int j=0;j<i;j++)
            {
                if ((a[i]<a[j]&&a[j]<b[i])^(a[i]<b[j]&&b[j]<b[i]))
                   add_edge(T(i),F(j)),
                   add_edge(F(i),T(j)),
                   add_edge(T(j),F(i)),
                   add_edge(F(j),T(i));
            }
        }
        cout<<(possible_2sat()?"panda is telling the truth...":"the evil panda is lying again")<<endl;
    }
}
