#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

const int N=120,M=102000;
const int inf=0x3f3f3f3f;
int head[N],v[M],c[M],nxt[M],t;
int q[N],dis[N];
int S,T;
bool vis[20000][N];
struct E
{
	int a,b;
}e[M];
int top=0;
int n,m,K;
int maxflow[N][N];
bool g[N][N];
int fa[N];
int gf(int x)
{
	if(fa[x]!=x)fa[x]=gf(fa[x]);
	return fa[x];
}
inline void add(int a,int b,int cc)
{
	nxt[++t]=head[a];v[t]=b;c[t]=cc;head[a]=t;
	nxt[++t]=head[b];v[t]=a;c[t]=cc;head[b]=t;
}
bool bfs()
{
	static int h,tail,s,i;
	memset(dis,-1,sizeof(dis));
	dis[q[h=tail=1]=S]=0;
	while(h<=tail)
	{
		s=q[h++];
		for(i=head[s];i;i=nxt[i])
			if(dis[v[i]]==-1&&c[i])
			{
				dis[v[i]]=dis[s]+1;
				if(v[i]==T)return true;
				q[++tail]=v[i];
			}
	}
	return false;
}
int aug(int x,int sum)
{
	if(x==T)return sum;
	int i,os=sum,a;
	for(i=head[x];i&&sum;i=nxt[i])
	if(dis[v[i]]==dis[x]+1&&c[i])
	{
		a=aug(v[i],min(sum,c[i]));
		sum-=a;c[i]-=a;c[i^1]+=a;
	}
	if(os==sum)dis[x]=-1;
	return os-sum;
}
void init()
{
	int i,j;
	memset(head,0,sizeof(head));t=1;
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
			if(g[i][j])add(i,j,1);
}
void dfs(int x,int p)
{
	int i;
	vis[p][x]=true;
	for(i=head[x];i;i=nxt[i])if(c[i]&&!vis[p][v[i]])dfs(v[i],p);
}
void work(int x)
{
	int x1,x2,i,j,flow=0;
	S=T=0;
	for(i=1;i<=n;i++)
		if(vis[x][i])
		{
			if(!S)S=i;
			else if(!T)T=i;
		}
	if(!T)return ;
	init();
	while(bfs())flow+=aug(S,inf);
	x1=++top;
	x2=++top;
	memset(vis[x1],false,sizeof(vis[x1]));
	memset(vis[x2],false,sizeof(vis[x2]));
	dfs(S,x1);
	for(i=1;i<=n;i++)if(!vis[x1][i])vis[x2][i]=true;
	for(i=1;i<=n;i++)if(vis[x1][i])
		for(j=1;j<=n;j++)if(vis[x2][j])
			maxflow[i][j]=maxflow[j][i]=min(maxflow[i][j],flow);
	for(i=1;i<=n;i++)vis[x1][i]&=vis[x][i];
	for(i=1;i<=n;i++)vis[x2][i]&=vis[x][i];
	work(x1);
	work(x2);
}
int main()
{
	int i,j;
	bool flag;
	while(~scanf("%d%d%d",&n,&m,&K))
	{
		memset(g,false,sizeof(g));
		for(i=1;i<=m;i++)
			scanf("%d%d",&e[i].a,&e[i].b),g[e[i].a][e[i].b]=g[e[i].b][e[i].a]=true;
		flag=true;
		while(flag)
		{
			top=1;
			flag=false;
			memset(maxflow,inf,sizeof(maxflow));
			top=1;
			memset(vis[top],false,sizeof(vis[top]));
			for(i=1;i<=n;i++)
				vis[top][i]=true;
			work(top);
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(maxflow[i][j]<K&&g[i][j])
						flag=true,g[i][j]=g[j][i]=false;
		}
		for(i=1;i<=n;i++)
			fa[i]=i;
//		for(i=1;i<=n;i++,puts(""))
//			for(j=1;j<=n;j++)
//				printf("%d ",maxflow[i][j]);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(g[i][j])
					fa[gf(i)]=gf(j);
		for(i=1;i<=n;i++)
			fa[i]=gf(i);
		sort(fa+1,fa+1+n);
		int ans=0;
		for(i=1;i<=n;i++)
			if(fa[i]!=fa[i-1])ans++;
		printf("%d\n",ans);
	}
}
//const int MAXN=14;
//int dp[MAXN][MAXN];
//
//int main()
//{
////	int ans = 0;
////	for (int i = 0; i <= 10; i++)
////		for (int j = i; j <= 10; j++)
////			for (int k = j; k <= 10; k++)
////				for (int l = k; l <= 10; l++)
////					for (int m = l; m <= 10; m++)
////						for (int n = m; n <= 10; n++)
////							for (int o = n; o <= 10; o++)
////								for (int p = o; p <= 10; p++)
////									if (i + j + k + l + m + n + o + p == 8)
////										ans++;
////	cout << ans << endl;
//	for (int i=0;i<MAXN;i++) dp[0][i]=1;
//	for (int i=1;i<MAXN;i++)
//		for (int j=1;j<MAXN;j++)
//			dp[i][j]=dp[i][j-1]+(i-j>=0?dp[i-j][j]:0);
//	for (int i=0;i<MAXN;i++)
//	{
//		for (int j=1;j<=i;j++)
//			cout<<dp[i][j]-dp[i][j-1]<<" ";
//		cout<<endl;
//	}
//	for (int i=1;i<MAXN;i++)
//	{
//		cout<<dp[i][i]<<endl;
//	}
//}
