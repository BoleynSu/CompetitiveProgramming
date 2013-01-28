#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define v first
#define l second

const int MAXN=10000+2;
const int oo=(~0u)>>2;
int n;
int a[MAXN],b[MAXN],c[MAXN];
vector<pair<int,int> > adj[MAXN];
int answer;
int h1[MAXN],h2[MAXN];

int dfs(int node,int father_of_node=0)
{
    if (adj[node].size()>1)
    {
       h1[node]=oo;
       h2[node]=oo;
       for (int i=0;i<adj[node].size();i++)
           if (adj[node][i].v!=father_of_node)
           {
              dfs(adj[node][i].v,node);
              if (h1[adj[node][i].v]+adj[node][i].l<h1[node])
              {
                 h2[node]=h1[node];
                 h1[node]=h1[adj[node][i].v]+adj[node][i].l;
              }
              else if (h1[adj[node][i].v]+adj[node][i].l<h2[node])
              {
                   h2[node]=h1[adj[node][i].v]+adj[node][i].l;
              }
           }
    }
    else
    {
        h1[node]=0;
        h2[node]=oo;
    }
    if (h1[node]+h2[node]<answer)
       answer=h1[node]+h2[node];
}

int main()
{
    for (;;)
    {
        scanf("%d",&n);
        if (!n) break;
        for (int i=1;i<=n;i++)
            adj[i].resize(0);
        for (int i=1;i<n;i++)
        {
            scanf("%d%d%d",a+i,b+i,c+i);
            adj[a[i]].push_back(make_pair(b[i],c[i]));
            adj[b[i]].push_back(make_pair(a[i],c[i]));
        }
        
        int root=0;
        for (int i=1;i<=n;i++)
            if (adj[i].size()>1) root=i;
        if (root)
        {
           answer=oo;
           dfs(root);
        }
        else answer=c[1];
        printf("%d\n",answer);
    }
    return 0;
}

