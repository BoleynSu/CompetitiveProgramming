/*
AUTHOR: Su Jiao
DATE: 2010-8-24
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

const int MAXE=100*2;
const int MAXV=6-0+1;
typedef struct struct_edge* edge;
struct struct_edge{int v,id;char dir;edge n;};
struct_edge pool[MAXE];
edge top=pool;
edge adj[MAXV];
int degree[MAXV];
int used[MAXE/2];
int list[MAXE/2+1];
int listtop;
int size[MAXV][MAXV];
edge edges[MAXV][MAXV][MAXE];
int printed[MAXE/2];
void add_edge(int u,int v,int id)
{
     degree[u]++,edges[u][v][size[u][v]++]=top,
     top->v=v,top->id=id,top->dir='+',top->n=adj[u],adj[u]=top++;
     degree[v]++,edges[v][u][size[v][u]++]=top,
     top->v=u,top->id=id,top->dir='-',top->n=adj[v],adj[v]=top++;
}
void find_circuit(int u)
{
     for (edge i=adj[u];i;i=i->n)
         if (!used[i->id])
         {
            used[i->id]=true;
            find_circuit(i->v);
         }
     list[listtop++]=u;
}
void print(int u,int v)
{
     for (int i=0;i<size[u][v];i++)
         if (!printed[edges[u][v][i]->id])
         {
            cout<<edges[u][v][i]->id+1<<" "<<edges[u][v][i]->dir<<endl;
            printed[edges[u][v][i]->id]=true;
            break;
         }
}

int main()
{
    int N,a,b;
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>a>>b,add_edge(a,b,i);
    int odc=0;
    int S;
    for (int u=0;u<MAXV;u++)
        if (degree[u])
           S=u;
    #define odd(x) ((x)&1)
    for (int u=0;u<MAXV;u++)
        if (odd(degree[u]))
           odc++,S=u;
    if (odc==0||odc==2)
    {
       find_circuit(S);
       if (listtop==N+1)
          for (int i=1;i<listtop;i++)
              print(list[i-1],list[i]);
       else cout<<"No solution"<<endl;
    }
    else cout<<"No solution"<<endl;
}
