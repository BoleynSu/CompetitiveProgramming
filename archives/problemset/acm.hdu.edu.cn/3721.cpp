#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=2500;
const int oo=(~0u)>>1;
const int NOT_A_NODE=-1;
struct struct_edge
{
    struct_edge* n;
    int v,d;
};
typedef struct_edge* edge;
struct_edge pool[MAXN*2];
edge top;
edge adj[MAXN];
void init_graph()
{
    top=pool;
    memset(adj,0,sizeof(adj));
}
void add_edge(int u,int v,int d)
{
    top->v=v,top->d=d,top->n=adj[u],adj[u]=top++;
    top->v=u,top->d=d,top->n=adj[v],adj[v]=top++;
}
int N;

void dfs(int now,int father)
{
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int longestnode,longest;
void dfs(int x,int father,int cut,int length=0)
{
    if (length>longest)
    {
        longestnode=x;
        longest=length;
    }
    for (edge e=adj[x];e;e=e->n)
    {
        if (e->v!=cut&&e->v!=father)
            dfs(e->v,x,cut,length+e->d);
    }
}
int h1,h2;
int dist[MAXN];
bool get_core_path(int x,int father,int cut,int target)
{
    if (x==target)
    {
        dist[x]=0;
        int h1_=max(dist[x],longest-dist[x]);
        if (h1_<h1)
        {
            h1=h1_;
            h2=longest-h1_;
        }
        return true;
    }
    for (edge e=adj[x];e;e=e->n)
        if (e->v!=father&&e->v!=cut)
        {
            if (get_core_path(e->v,x,cut,target))
            {
                dist[x]=dist[e->v]+e->d;
                int h1_=max(dist[x],longest-dist[x]);
                if (h1_<h1)
                {
                    h1=h1_;
                    h2=longest-h1_;
                }
                return true;
            }
        }
    return false;
}
void get_h1_and_h2(int x,int y)
{
    int a,b;
    longest=-oo;
    dfs(x,y,y);
    a=longestnode;
    longest=-oo;
    dfs(longestnode,y,y);
    b=longestnode;
    h1=h2=+oo;
    get_core_path(a,NOT_A_NODE,y,b);
}
int move(int x,int y,int z)
{
    get_h1_and_h2(x,y);
    int lh1=h1,lh2=h2;
    get_h1_and_h2(y,x);
    int rh1=h1,rh2=h2;
    return max(lh1+max(lh2,z+rh1),rh1+max(rh2,z+lh1));
}

int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        scanf("%d",&N);
        init_graph();
        for (int i=1;i<N;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
        }
        int result=+oo;
        for (int u=0;u<N;u++)
            for (edge e=adj[u];e;e=e->n)
            {
                int get=move(u,e->v,e->d);
                if (get<result) result=get;
            }
        if (N==1) result=0;
        printf("Case %d: %d\n",tc,result);
    }
    return 0;
}
