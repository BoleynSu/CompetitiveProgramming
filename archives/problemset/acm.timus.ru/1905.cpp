#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define sf scanf
#define pf printf
#define rep(i,n) for (int i=0;i<(n);i++)
#define repf(i,b,e) for (int i=(b);i<(e);i++)
#define ft(i,b,e) for (int i=(b);i<=(e);i++)
#define fdt(i,b,e) for (int i=(b);i>=(e);i--)
#define x first
#define y second
typedef pair<int,int> pii;

template<typename T>
bool cmin(T& a,const T& b)
{
	return a>b?a=b,true:false;
}

int n,m;
map<pii,pii> pre;
map<pii,int> preid;
map<pii,vector<pii> > adj;
map<pii,vector<int> > id;
pii s,t;

int main()
{
	sf("%d%d",&n,&m);
	rep(i,m)
	{
		sf("%d%d%d%d",&t.first,&s.first,&t.second,&s.second);
		s.y=-s.y;
		t.y=-t.y;
		adj[s].push_back(t);
		id[s].push_back(i);
	}
	sf("%d%d%d%d",&t.first,&s.first,&t.second,&s.second);
	s.y=-s.y;
	t.y=-t.y;
	adj[s],adj[t];
	queue<pii> q;
	q.push(s);
	pre[s]=s;
	while (!q.empty())
	{
		pii u=q.front();
		vector<pii>& get=adj[u];
		vector<int>& getid=id[u];
		q.pop();
		rep(i,get.size())
		{
			pii v=get[i];
			if (!pre.count(v))
			{
				q.push(v);
				pre[v]=u;
				preid[v]=getid[i];
			}
		}
		map<pii,vector<pii> >::iterator it=adj.upper_bound(u);
		if (it!=adj.end()&&it->x.x==u.x)
		{
			pii v=it->x;
			if (!pre.count(v))
			{
				q.push(v);
				pre[v]=u;
				preid[v]=-1;
			}
		}
	}
	vector<int> lst;
	if (pre.count(t))
	{
		while (pre[t]!=t)
		{
			pii u=pre[t];
			if (preid[t]>=0) lst.push_back(preid[t]);
			t=u;
		}
		pf("%d\n",lst.size());
		rep(i,lst.size())
		{
			pf("%d%c",lst[i]+1,i+1==lst.size()?'\n':' ');
		}
	}
	else puts("Impossible");
}