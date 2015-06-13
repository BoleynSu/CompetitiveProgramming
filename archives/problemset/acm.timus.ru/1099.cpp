#include <iostream>
#include <cstring>
using namespace std;

const int MAXV=222;
const int MAXE=MAXV*MAXV*2;
const int NOT_NODE=-1;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
int V;
struct_edge pool[MAXE];
edge top;
edge adj[MAXV];
void init()
{
     top=pool;
     memset(adj,0,sizeof(adj));
}
void add_edge(int u,int v)
{
     top->v=v,top->n=adj[u],adj[u]=top++;
     top->v=u,top->n=adj[v],adj[v]=top++;
}

int match[MAXV];
int qh,qt;
int q[MAXV];
bool inq[MAXV];
int father[MAXV];
int base[MAXV];
bool inb[MAXV];
int LCA(int root,int u,int v)
{
    static bool inp[MAXV];
    memset(inp,0,sizeof(inp));
    for (;;)
    {
        inp[u=base[u]]=true;
        if (u==root) break;
        u=father[match[u]];
    }
    for (;;)
    {
        if (inp[v=base[v]]) return v;
        else v=father[match[v]];
    }
}
void mark_blossom(int lca,int u)
{
     while (base[u]!=lca)
     {
           int v=match[u];
           inb[base[u]]=true;
           inb[base[v]]=true;
           u=father[v];
           if (base[u]!=lca) father[u]=v;
     }
}
void blossom_contraction(int s,int u,int v)
{
     int lca=LCA(s,u,v);
     memset(inb,0,sizeof(inb));
     mark_blossom(lca,u);
     mark_blossom(lca,v);
     if (base[u]!=lca) father[u]=v;
     if (base[v]!=lca) father[v]=u;
     for (int u=0;u<V;u++)
         if (inb[base[u]])
         {
            base[u]=lca;
            if (!inq[u]) inq[q[++qt]=u]=true;
         }
}
int find_augmenting_path(int s)
{
    memset(inq,0,sizeof(inq));
    memset(father,NOT_NODE,sizeof(father));
    for (int i=0;i<V;i++) base[i]=i;
    inq[q[qh=qt=0]=s]=true;
    while (qh<=qt)
    {
          int u=q[qh++];
          for (edge e=adj[u];e;e=e->n)
          {
              int v=e->v;
              if (base[u]!=base[v]&&match[u]!=v)
              {
                 if ((v==s)||(match[v]!=NOT_NODE&&father[match[v]]!=NOT_NODE))
                    blossom_contraction(s,u,v);
                 else if (father[v]==NOT_NODE)
                 {
                      father[v]=u;
                      if (match[v]==NOT_NODE) return v;
                      else if (!inq[match[v]]) inq[q[++qt]=match[v]]=true;
                 }
              }
          }
    }
    return NOT_NODE;
}
int augment_path(int s,int t)
{
    int u,v,w;
    u=t;
    while (u!=NOT_NODE)
    {
          v=father[u];
          w=match[v];
          match[v]=u;
          match[u]=v;
          u=w;
    }
    return t!=NOT_NODE;
}
int edmonds()
{
    int matchc=0;
    memset(match,NOT_NODE,sizeof(match));
    for (int u=0;u<V;u++)
        if (match[u]==NOT_NODE)
           matchc+=augment_path(u,find_augmenting_path(u));
    return matchc;
}

bool ed[222][222];

int main()
{
    int u,v;
    cin>>V;
    init();
    while (cin>>u>>v)
          if (!ed[u-1][v-1])
          {
             add_edge(u-1,v-1);
             ed[u-1][v-1]=ed[v-1][u-1]=true;
          }
    cout<<edmonds()*2<<endl;
    for (int i=0;i<V;i++)
        if (i<match[i])
           cout<<i+1<<" "<<match[i]+1<<endl;
}
