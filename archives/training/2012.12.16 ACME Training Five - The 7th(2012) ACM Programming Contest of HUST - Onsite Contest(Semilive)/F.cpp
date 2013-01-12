/****************************************************************
	Problem: 1612
	User: RUC_Acme
	Language: C++
	Result: Accepted
	Time:308 ms
	Memory:1936 kb
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> adj[100000];

int sg[100][100];

int dfs1(int u,int p=-1)
{
	int ans=0;
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (v==p) continue;
		int get=dfs1(v,u)+1;
		ans^=get;
	}
	return ans;
}
int dfs2k1(int u,int p=-1)
{
	int ans=0;
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (v==p) continue;
		int get=dfs2k1(v,u);
		if (get%2==0) get++;
		else get--;
		ans^=get;
	}
	return ans;
}


int main()
{
//	for (int k=1;k<100;k++)
//		for (int sgi=0;sgi<100;sgi++)
//		{
//			set<int> s;
//			s.insert(sg[k-1][sgi]);
//			for (int i=0;i<sgi;i++) s.insert(sg[k][i]);
//			int mex=0;
//			while (s.count(mex)) mex++;
//			sg[k][sgi]=mex;
//			if (k==9) printf("%d %d %d\n",k,sgi,sg[k][sgi]);
//		}
//	return 0;
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++)
	{
		scanf("%d",&N);
		for (int i=0;i<N;i++)
		{
			adj[i].clear();
		}
		for (int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int get1=dfs1(0);
		int get2k1=dfs2k1(0);
		int q;
		scanf("%d",&q);
		for (int i=0;i<q;i++)
		{
			int k;
			scanf("%d",&k);
			if (k%2==0||(k==1&&!get1)||(k%2==1&&k>1&&!get2k1)) puts("littleSheep");
			else puts("tclsm");
		}
	}
}