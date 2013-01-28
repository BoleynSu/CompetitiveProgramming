#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct struct_edge{struct_edge* n;int v,l;};
typedef struct_edge* edge;
const int LOG2_MAXN=16+1;
const int MAXN=50000+2;
int N,M;
struct_edge pool[MAXN*2];
edge top;
edge adj[MAXN];
int length[MAXN];
int from[MAXN];
int rminq[LOG2_MAXN][MAXN];
int rmaxq[LOG2_MAXN][MAXN];
int log2[MAXN];

void getLOG2()
{
    log2[1]=0;
    for (int i=2;i<MAXN;i++)
        log2[i]=log2[i-1]+((i&-i)==i);
}
void init()
{
    memset(adj,0,sizeof(adj));
    top=pool;
}
void add_edge(int u,int v,int l)
{
    top->l=l,top->v=v,top->n=adj[u],adj[u]=top++;
    top->l=l,top->v=u,top->n=adj[v],adj[v]=top++;
}
void dfs_first(int u,int f=0)
{
    length[u]=0,from[u]=0;
    for (edge e=adj[u];e;e=e->n)
        if (e->v!=f)
        {
            dfs_first(e->v,u);
            if (length[u]<length[e->v]+e->l) length[u]=length[e->v]+e->l,from[u]=e->v;
        }
}
void dfs_second(int u,int l=0,int f=0)
{
    int max=0;
    if (l>length[u]) length[u]=l,from[u]=f;
    else max=l;
    for (edge e=adj[u];e;e=e->n)
        if (e->v!=f&&e->v!=from[u]&&max<length[e->v]+e->l)
            max=length[e->v]+e->l;
    for (edge e=adj[u];e;e=e->n)
        if (e->v!=f)
        {
            if (e->v==from[u]) dfs_second(e->v,max+e->l,u);
            else dfs_second(e->v,length[u]+e->l,u);
        }
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void getRMQ()
{
    for (int i=1;i<=N;i++)
        rminq[0][i]=rmaxq[0][i]=length[i];
    for (int i=1;(1<<i)<=N;i++)
    {
        int i_=i-1;
        for (int j=1;j+(1<<i)-1<=N;j++)
            rminq[i][j]=min(rminq[i_][j],rminq[i_][j+(1<<i_)]),
            rmaxq[i][j]=max(rmaxq[i_][j],rmaxq[i_][j+(1<<i_)]);
    }
}
int query(int Q)
{
    int h=1,t=1,answer;
    while (t<=N)
    {
        int a=log2[t-h+1];
        if (max(rmaxq[a][h],rmaxq[a][t-(1<<a)+1])-min(rminq[a][h],rminq[a][t-(1<<a)+1])<=Q) answer=t-h+1;
        else h++;
        t++;
    }
    return answer;
}

int main()
{
    cin.sync_with_stdio(false);
    getLOG2();
    for (;;)
    {
        cin>>N>>M;
        if (N==0&&M==0) break;
        init();
        for (int i=1;i<N;i++)
        {
            int u,v,l;
            cin>>u>>v>>l;
            add_edge(u,v,l);
        }
        dfs_first(1);
        dfs_second(1);
        getRMQ();
        for (int i=0;i<M;i++)
        {
            int Q;
            cin>>Q;
            cout<<query(Q)<<endl;
        }
    }
}

