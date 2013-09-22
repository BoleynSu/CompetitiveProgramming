#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long int lli;
#define mp make_pair
#define sz(x) (int((x).size()))

const int N=200200,M=2000010;
int top=0,stack[N],bcc=0,belong[N],dfn[N],low[N];
bool instack[N];
int idx=0;
int q[N],dis[N];
struct G
{
    int next[M],v[M],head[N],t;
    inline void add(int a,int b)
    {
        next[++t]=head[a];v[t]=b;head[a]=t;
        next[++t]=head[b];v[t]=a;head[b]=t;
    }
    void dfs(int x,int fa)
    {
        int i;
        dfn[x]=low[x]=++idx;
        instack[stack[++top]=x]=true;
        for(i=head[x];i;i=next[i])
        if((i>>1)!=fa)
        {
            if(!dfn[v[i]])
            {
                dfs(v[i],i>>1);
                low[x]=min(low[v[i]],low[x]);
            }
            else if(instack[v[i]])low[x]=min(low[x],dfn[v[i]]);
        }
        if(low[x]==dfn[x])
        {
            bcc++;
            do
            {
                i=stack[top--];
                instack[i]=false;
                belong[i]=bcc;
                instack[i]=false;
            }while(i!=x);
        }
    }
    int bfs(int S)
    {
        int h,tail,i,s;
        q[h=tail=1]=S;
        memset(dis,-1,sizeof(dis));
        dis[S]=0;
        while(h<=tail)
        {
            s=q[h++];
            for(i=head[s];i;i=next[i])
                if(dis[v[i]]==-1)
                {
                    dis[v[i]]=dis[s]+1;
                    q[++tail]=v[i];
                }
        }
        int id=1;
        for(i=1;i<=bcc;i++)
            if(dis[i]>dis[id])id=i;
        return id;
    }
}G,H;
pair<int,int>e[M];
int n,m;
char _stack[32*1024*1024];

int main()
{
    __asm__("movl %%esp, (%%eax);\n"::"a"(_stack));
    __asm__("movl %%eax, %%esp;\n"::"a"(_stack+sizeof _stack));
    int a,b,i,k=0,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        k=0;
        bcc=0;
        G.t=H.t=1;
        memset(G.head,0,sizeof(G.head));
        memset(H.head,0,sizeof(H.head));
        memset(dfn,0,sizeof(dfn));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            G.add(a,b);
        }
        for(i=1;i<=n;i++)
            if(!dfn[i])
                G.dfs(i,-2);
        for(i=1;i<=n;i++)
            for(j=G.head[i];j;j=G.next[j])
                if(belong[i]!=belong[G.v[j]])
                {
                    if(belong[i]<belong[G.v[j]])
                        e[++k]=make_pair(belong[i],belong[G.v[j]]);
                    else e[++k]=make_pair(belong[G.v[j]],belong[i]);

                }
        sort(e+1,e+1+k);
        for(i=1;i<=k;i++)
        {
            if(e[i]!=e[i-1])H.add(e[i].first,e[i].second);
        }
//        printf("%d\n",bcc);
        a=H.bfs(1);
        b=H.bfs(a);
        printf("%d\n",bcc-1-dis[b]);
    }
    __asm__("movl (%%eax), %%esp;\n"::"a"(_stack));
}
