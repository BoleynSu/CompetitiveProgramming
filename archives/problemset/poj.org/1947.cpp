#include <iostream>
#include <vector>
using namespace std;

int N,P;
bool c[150+2][150+2];
int f[150+2][105+2];
vector<int> adj[150+2];
int indegree[150+2];
int answer;

void calc(int u,bool isRoot=true)
{
	for (int i=0;i<=P;i++)
		f[u][i]=N;
	f[u][1]=0;
	for (unsigned e=0;e<adj[u].size();e++)
	{
		int v=adj[u][e];
		calc(v,false);
		for (int p=P;p>=0;p--)
		{
			int nf=f[u][p]+1;
			for (int q=0;q<=p;q++)
				if (nf>f[u][q]+f[v][p-q])
					nf=f[u][q]+f[v][p-q];
			f[u][p]=nf;
		}
	}
	if (answer>f[u][P]+(isRoot?0:1)) answer=f[u][P]+(isRoot?0:1);
}

int main()
{
	cin>>N>>P;
	for (int i=1;i<N;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	answer=N;
	for (int u=1;u<=N;u++)
		if (!indegree[u])
			calc(u);
	cout<<answer<<endl;
}
