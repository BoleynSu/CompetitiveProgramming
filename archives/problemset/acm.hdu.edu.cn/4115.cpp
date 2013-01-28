#include <cstring>
using namespace std;
const int MAXV=1000000;
const int MAXE=2000000;
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
#define T(x) (((x)<<1)|1)
#define F(x) ((x)<<1)
void build_2sat()
{
     stop=spool;
     memset(set,0,sizeof(set));
     build_graph();
     //add_edge(u,v);
     /*
     A[x]                  =add_edge(F(x),T(x));
     NOT A[x]              =add_edge(T(x),F(x));
     A[x] AND A[y]         =add_edge(F(x),T(x)),add_edge(F(y),T(y));
     A[x] AND NOT A[y]     =add_edge(F(x),T(x)),add_edge(T(y),F(y));
     A[x] OR A[y]          =add_edge(F(x),T(y)),add_edge(F(y),T(x));
     A[x] OR NOT A[y]      =add_edge(F(x),F(y)),add_edge(T(y),T(x));
     NOT (A[x] AND A[y])   =add_edge(T(x),F(y)),add_edge(T(y),F(x));
     NOT (A[x] OR A[y])    =add_edge(T(x),F(x)),add_edge(T(y),F(y));
     A[x] XOR A[y]         =add_edge(F(x),T(y)),add_edge(F(y),T(x)),add_edge(T(x),F(y)),add_edge(T(y),F(x));
     NOT (A[x] XOR A[y])   =add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
     A[x] XOR NOT A[y]     =add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
     u到v有边表示选u必选v,如果要输出一个可行解,
     */
}
void function_2sat(int block,int node)
{
     block_id[node]=block;
     stop->v=node,stop->n=set[node],set[node]=stop++;
}
#include <iostream>
using namespace std;
bool possible_2sat()
{
     tarjan(function_2sat);
     for (int i=0;i<(V>>1);i++)
         if (block_id[T(i)]==block_id[F(i)])
            return false;
     return true;
}

int N,M;
int B[MAXV];
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        cin>>N>>M;
        V=N*2;
        build_2sat();
        for (int i=0;i<N;i++)
            cin>>B[i],B[i]--;
        for (int i=0;i<M;i++)
        {
            int a,b,k;
            cin>>a>>b>>k;
            a--,b--;
            if (k)
            {
               if (B[a]==B[b])
               {
                  add_edge(T(a),F(b));
                  add_edge(F(b),T(a));
                  add_edge(F(a),T(b));
                  add_edge(T(b),F(a));
               }
               else if ((B[a]+1)%3==B[b])
               {
                   add_edge(F(a),F(b));
                   add_edge(T(b),T(a));
               }
               else
               {
                   add_edge(F(b),F(a));
                   add_edge(T(a),T(b));
               }
            }
            else
            {
                if (B[a]==B[b])
                {
                   add_edge(T(a),T(b));
                   add_edge(F(b),F(a));
                   add_edge(T(b),T(a));
                   add_edge(F(a),F(b));
                }
                else if ((B[a]+1)%3==B[b])
                {
                     add_edge(T(a),F(a));
                     add_edge(F(b),T(b));
                }
                else
                {
                    add_edge(T(b),F(b));
                    add_edge(F(a),T(a));
                }
            }
        }
        cout<<"Case #"<<t<<": "<<(possible_2sat()?"yes":"no")<<endl;
    }
}






