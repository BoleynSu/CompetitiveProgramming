/****************************************************************
	Problem: 1608
	User: RUC_Acme
	Language: C++
	Result: Accepted
	Time:40 ms
	Memory:644 kb
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

int N,M;
vector<int> adj[10000];
int w[10000];

bool calced[10000];
int dp[10000];
int abs(int x)
{
	return x>=0?x:-x;
}
int dfs(int u,int t)
{
	if (!calced[u])
	{
		calced[u]=true;
		if (u==t) dp[u]=abs(w[u]);
		else
		{
			dp[u]=0;
			if (w[u]>=0)
			{
				for (unsigned i=0;i<adj[u].size();i++)
				{
					int v=adj[u][i];
					int get=dfs(v,t);
					if (get&&dp[u]<get+abs(w[u])) dp[u]=get+abs(w[u]);
				}
			}
		}
	}
	return dp[u];
}

int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		for (int i=1;i<=N;i++) adj[i].clear();
		for (int i=0;i<M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
		}
		for (int i=2;i<=N;i++) scanf("%d",w+i);
		int minw=0;
		for (int i=2;i<=N;i++) if (minw>w[i]) minw=w[i];
		if (minw)
		{
			int ans=0;
			for (int i=2;i<=N;i++)
				if (w[i]==minw)
				{
					memset(calced,0,sizeof(calced));
					int get=dfs(1,i);
					if (ans<get) ans=get;
				}
			if (ans) printf("%d\n",ans);
			else puts("What is a fucking day!");
		}
		else puts("What is a fucking day!");
	}
}