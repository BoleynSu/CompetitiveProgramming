#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > adj(n+2);
	vector<pair<int,int> > edges(m);
	for (int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i]=make_pair(u,v);
	}
	vector<int> distS(n+2);
	vector<int> distT(n+2);
	vector<double> fS(n+2);
	vector<double> fT(n+2);
	{
		vector<bool> inq(n+2);
		queue<int> q;
		inq[1]=true;
		distS[1]=0;
		q.push(1);
		fS[1]=1;
		for (int i=0;i<n;i++)
		{
			int u=q.front();
			for (int j=0;j<adj[u].size();j++)
			{
				int v=adj[u][j];
				if (!inq[v])
				{
					inq[v]=true;
					distS[v]=distS[u]+1;
					q.push(v);
					fS[v]=fS[u];
				}
				else if (distS[v]==distS[u]+1)
				{
					fS[v]+=fS[u];
				}
			}
			q.pop();
		}
	}
	{
		vector<bool> inq(n+2);
		queue<int> q;
		inq[n]=true;
		distT[n]=0;
		q.push(n);
		fT[n]=1;
		for (int i=0;i<n;i++)
		{
			int u=q.front();
			for (int j=0;j<adj[u].size();j++)
			{
				int v=adj[u][j];
				if (!inq[v])
				{
					inq[v]=true;
					distT[v]=distT[u]+1;
					q.push(v);
					fT[v]=fT[u];
				}
				else if (distT[v]==distT[u]+1)
				{
					fT[v]+=fT[u];
				}
			}
			q.pop();
		}
	}
	int mind=distS[n];
	double answer=0;
	for (int u=1;u<=n;u++)
	{
		//cout<<fS[u]<<" "<<fT[u]<<endl;
		double c=0;
		for (int i=0;i<m;i++)
			if (edges[i].first==u||edges[i].second==u)
			{
				if (distS[edges[i].first]+distT[edges[i].second]+1==mind) c+=fS[edges[i].first]*fT[edges[i].second];
				else if (distT[edges[i].first]+distS[edges[i].second]+1==mind) c+=fT[edges[i].first]*fS[edges[i].second];
			}
		//cout<<u<<" "<<c<<endl;
		double get=double(c)/double(fS[n]);

		if (get>answer) answer=get;
	}
	printf("%.8f\n",answer);
}

