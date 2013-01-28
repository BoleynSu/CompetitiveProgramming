#include <cstdio>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long int lli;

lli n;
lli p[100+2][2];
vector<lli> adj[100+2];
bool calced[100+2][3][2];
lli f[100+2][3][2];
lli dfs(lli u,lli isrt,lli wh,lli pr=0)
{
    if (calced[u][isrt][wh]) return f[u][isrt][wh];
    calced[u][isrt][wh]=true;
    lli& ans=f[u][isrt][wh];
    if (isrt==2)
    {
        ans=p[u][wh];
        lli cnt=0;
        for (unsigned i=0;i<adj[u].size();i++)
        {
            lli v=adj[u][i];
            if (v!=pr) cnt+=min(dfs(v,0,wh,u),dfs(v,1,!wh,u));
        }
        ans+=cnt;
    }
    else if (isrt==1)
    {
        ans=p[u][wh]/2;
        lli cnt=0;
        for (unsigned i=0;i<adj[u].size();i++)
        {
            lli v=adj[u][i];
            if (v!=pr) cnt+=min(dfs(v,0,wh,u),dfs(v,1,!wh,u));
        }
        lli get=((~0ull)>>1);
        for (unsigned i=0;i<adj[u].size();i++)
        {
            lli v=adj[u][i];
            if (v!=pr) get=min(get,cnt-min(dfs(v,0,wh,u),dfs(v,1,!wh,u))+dfs(v,1,wh,u));
        }
        if (get==((~0ull)>>1)) ans=((~0ull)>>1);
        else ans+=get;
        ans=min(ans,dfs(u,2,wh,pr));
    }
    else
    {
        ans=p[u][wh]/2;
        lli cnt=0;
        for (unsigned i=0;i<adj[u].size();i++)
        {
            lli v=adj[u][i];
            if (v!=pr)
            {
                cnt+=min(dfs(v,0,wh,u),dfs(v,1,!wh,u));
            }
        }
        ans+=cnt;
        ans=min(ans,dfs(u,1,wh,pr));
    }
    //cout<<u<<" "<<isrt<<" "<<wh<<":"<<ans<<endl;
    return  ans;
}

int main()
{
    while (~scanf("%I64d",&n))
    {
        for (lli j=0;j<2;j++) for (lli i=1;i<=n;i++) scanf("%I64d",&p[i][j]);
        for (lli i=1;i<=n;i++) adj[i].clear();
        for (lli i=1;i<n;i++)
        {
            lli u,v;
            scanf("%I64d%I64d",&u,&v),adj[u].push_back(v),adj[v].push_back(u);
        }
        memset(calced,false,sizeof(calced));
        lli ans=min(dfs(1,1,0),dfs(1,1,1));
        printf("%I64d\n",ans);
    }
}

