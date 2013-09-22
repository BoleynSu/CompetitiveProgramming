#include <cstdio>
#include <iostream>
#include <vector>
#include<vector>
#include <utility>
using namespace std;
#define pb push_back
typedef double db;
#define rep(i,n) for (int i=0;i<(n);i++)

typedef long long int lli;

#include <cstdio>
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5200,M=N*2;
int next[M],v[M],head[N],t=1;
int dfn[N],low[N];
int n,m;
struct E
{
    int a,b;
}e[N];
int d[N],stack[N];
int ans,idx,top=0;
bool vis[N];
int cnt[N];
vector<int>tt;
void add(int a,int b)
{
    next[++t]=head[a];v[t]=b;head[a]=t;d[a]++;
    next[++t]=head[b];v[t]=a;head[b]=t;d[b]++;
}
void dfs(int u)
{
    int i;
    tt.pb(u);vis[u]=true;
    low[u]=dfn[u]=++idx;
    for(i=head[u];i;i=next[i])
        {
            if(!dfn[v[i]])
            {
                dfs(v[i]);
                low[u]=min(low[u],low[v[i]]);
                if(low[v[i]]>=dfn[u])
                    cnt[u]++;
            }
            else low[u]=min(low[u],dfn[v[i]]);
        }
}
void sol(int u)
{
    int i,sa=0,sb=0,j;
    idx=0;
    memset(dfn,0,sizeof(dfn));
    memset(head,0,sizeof(head));
    memset(vis,false,sizeof(vis));
    t=1;
    for(i=1;i<=m;i++)
        if(e[i].a!=u&&e[i].b!=u)
            add(e[i].a,e[i].b);
    //printf("%d :",u);
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=n;i++)
        if(!vis[i]&&i!=u)
        {
            sa++;
            tt.clear();
            cnt[i]--;
            dfs(i);
            if(tt.size()>1)sb=max(sb,1);
            //printf("%d\n",int(tt.size()));
            for(j=0;j<tt.size();j++){
                if(cnt[tt[j]]>=sb)sb=cnt[tt[j]]+1;
            //printf("%d:%d\n",tt[j],1+cnt[tt[j]]);
            }
        }
    //printf("%d %d %d\n",u,sa,sb);
    ans=max(sa+sb-1,ans);
}
int main()
{
    int i;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        for(i=1;i<=m;i++)
            scanf("%d%d",&e[i].a,&e[i].b),e[i].a++,e[i].b++;
        for(i=1;i<=n;i++)
        {
            sol(i);
        }
        printf("%d\n",ans);
    }
}
