#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

enum{MAXN=3000,MAXM=MAXN*MAXN,MAXQ=10000};
struct edge{int v,n;};
edge edges[(MAXN-1)*2];
int top;
int adj[MAXN];
int N,M,Q;
int f[MAXN][MAXN];
map<pair<int,int>,int> mst;
map<pair<int,int>,int> cut;

void add_edge(int u,int v)
{
    edges[top].v=v;
    edges[top].n=adj[u];
    adj[u]=top++;
    edges[top].v=u;
    edges[top].n=adj[v];
    adj[v]=top++;
}
void dfs_first(int u,int father,int root)
{
    for (int e=adj[u];e!=-1;e=edges[e].n)
        if (edges[e].v!=father)
        {
            dfs_first(edges[e].v,u,root);
            if (f[root][u]>f[root][edges[e].v])
                f[root][u]=f[root][edges[e].v];
        }
}
int dfs_second(int u,int father,int root)
{
    int min=f[u][root];
    for (int e=adj[u];e!=-1;e=edges[e].n)
        if (edges[e].v!=father)
        {
            int get=dfs_second(edges[e].v,u,root);
            if (min>get) min=get;
        }
    return min;
}

int main()
{
    cin.sync_with_stdio(false);
    for (;;)
    {
        cin>>N>>M;
        if (N==0&&M==0) break;
        memset(f,0x7f,sizeof f);
        for (int i=0;i<M;i++)
        {
            int x,y;
            cin>>x>>y;
            cin>>f[x][y];
            f[y][x]=f[x][y];
        }
        int qh,qt;
        int q[MAXN];
        int pre[MAXN];
        int d[MAXN];
        int total=0;
        memset(d,0x7f,sizeof d);
        pre[0]=-1;
        d[q[qh=qt=0]=0]=0;
        top=0;
        memset(adj,-1,sizeof adj);
        mst.clear();
        while (qh<=qt)
        {
            int u=q[qh++];
            if (pre[u]!=-1)
            {
                add_edge(pre[u],u);
                mst[make_pair(u,pre[u])]=mst[make_pair(pre[u],u)]=f[u][pre[u]];
                f[u][pre[u]]=f[pre[u]][u]=0x7f7f7f7f;
            }
            double mind=0x7f7f7f7f;
            int minv=-1;
            for (int v=0;v<N;v++)
                if (d[v]!=0)
                {
                    if (d[v]>f[u][v])
                    {
                        pre[v]=u;
                        d[v]=f[u][v];
                    }
                    if (mind>d[v])
                        mind=d[minv=v];
                }
            if (minv!=-1)
            {
                total+=mind;
                d[q[++qt]=minv]=0;
            }
        }
        for (int i=0;i<N;i++) dfs_first(i,-1,i);
        cut.clear();
        for (int i=0;i<N;i++)
            if (pre[i]!=-1)
                cut[make_pair(i,pre[i])]=cut[make_pair(pre[i],i)]=dfs_second(pre[i],i,i);
        cin>>Q;
        double answer=0;
        for (int i=0;i<Q;i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            answer+=total;
            if (mst.count(make_pair(x,y)))
            {
                if (c>cut[make_pair(x,y)]) answer+=cut[make_pair(x,y)];
                else answer+=c;
                answer-=mst[make_pair(x,y)];
            }
        }
        answer/=Q;
        printf("%.4f\n",answer);
    }
}

