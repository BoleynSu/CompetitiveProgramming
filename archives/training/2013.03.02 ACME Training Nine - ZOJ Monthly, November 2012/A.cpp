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
using namespace std;

bool calced[10000];
int sg[10000];
vector<vector<int> > adj;

int calc(int x)
{
	if (!calced[x])
	{
		calced[x]=true;
		set<int> mex;
		for (unsigned i=0;i<adj[x].size();i++)
		{
			mex.insert(calc(adj[x][i]));
		}
		for (int i=0;;i++) if (!mex.count(i))
		{
			sg[x]=i;
			break;
		}
	}
	return sg[x];
}

int main() {
	int n;
	while (cin>>n)
	{
		static int t;
		cout<<"Case "<<++t<<":"<<endl;
		adj=vector<vector<int> >(n);
		for (int i=0;i<n-1;i++)
		{
			int c;
			cin>>c;
			adj[i].resize(c);
			for (int j=0;j<c;j++) cin>>adj[i][j],--adj[i][j];
		}
		for (int i=0;i<n;i++) calced[i]=false;
		for (int i=0;i<n;i++) calc(i);
		int q;
		cin>>q;
		for (int i=0;i<q;i++)
		{
			int m;
			cin>>m;
			int SG=0;
			for (int i=0;i<m;i++)
			{
				int x;
				cin>>x,--x;
				SG^=sg[x];
			}
			if (SG) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	}
}
