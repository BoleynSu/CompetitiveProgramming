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

const int MAXN=50003;
const int MAXC=3;
int N,C;
int val[MAXN],is[MAXN];
vector<int> adj[MAXN];
map<int,lli> f[MAXN][MAXC+2];

lli dp(int u,int p,int c)
{
    if (!f[u][c].count(p))
    {
        lli& ans=f[u][c][p];
        ans=val[u];
        if (c>is[u])
        {
            for (int i=0;i<sz(adj[u]);i++)
            {
                int v=adj[u][i];
                if (v!=p)
                {
                    if (ans<dp(v,u,c-is[u])+val[u])
                        ans=dp(v,u,c-is[u])+val[u];
                }
            }
        }
        //cout<<u<<p<<c<<":"<<f[mp(mp(u,p),c)]<<endl;
    }
    return f[u][c][p];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&N,&C);
        for (int i=0;i<N;i++) scanf("%d%d",&val[i],&is[i]);
        for (int i=1;i<N;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        lli ans=0;
        for (int i=0;i<N;i++)
        {
            //cout<<dp(i,-1,C)<<endl;
            if (ans<dp(i,-1,C)) ans=dp(i,-1,C);
        }
        printf("%I64d\n",ans);
        for (int i=0;i<N;i++)
        {
            adj[i].clear();
            for (int j=0;j<=C;j++)
                f[i][j].clear();
        }
    }
}
