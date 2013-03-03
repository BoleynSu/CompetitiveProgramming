//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include<cstdio>
#include<string>
#include<map>
#include <sstream>
using namespace std;

vector<int> adj[1000+1],dis[1000+1];
void add_edge(int u,int v,int d)
{
	adj[u].push_back(v);
	dis[u].push_back(d);
}
bool ins[1000+1];
int d[1000+1];
bool cmin(int& a,int b)
{
	return a>b?a=b,true:false;
}
bool spfa(int u)
{
	for (unsigned i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (cmin(d[v],d[u]+dis[u][i]))
		{
			if (ins[v]) return false;
			ins[v]=true;
			if (!spfa(v)) return false;
			ins[v]=false;
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		for (int i=0;i<=n;i++) adj[i].clear(),dis[i].clear();
		for (int i=0;i<m;i++)
		{
			int l,r,a,b;
			cin>>l>>r>>a>>b;
			add_edge(l-1,r,b);
			add_edge(r,l-1,-a);
		}
		for (int i=0;i<n;i++) add_edge(i+1,i,10000),add_edge(i,i+1,10000);
//		for (int i=1;i<=n;i++)
//		{
//			int l=-10000-1,r=10000;
//			add_edge(i,i-1,0);
//			while (l+1!=r)
//			{
//				dis[i].back()=(l+r)/2;
//				memset(ins,0,sizeof(ins));
//				memset(d,0x3f,sizeof(d));
//				d[0]=0;
//				ins[0]=true;
//				if (spfa(0)) r=dis[i].back();
//				else l=dis[i].back();
//			}
//			dis[i].back()=r;
//		}
		memset(ins,0,sizeof(ins));
		memset(d,0x3f,sizeof(d));
		d[0]=0;
		ins[0]=true;
		if (!spfa(0)) cout<<"The spacecraft is broken!"<<endl;
		else
		{
			for (int i=0;i<n;i++) cout<<d[i+1]-d[i]<<char(i+1==n?'\n':' ');
		}
	}
}
