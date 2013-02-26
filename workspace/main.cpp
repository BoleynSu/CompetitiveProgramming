#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define sz(x) (int((x).size()))

#define oo 19930309

void bit_inc(vector<int>& st,int x,int inc)
{
	while (x<sz(st)) st[x]+=inc,x|=x+1;
}
int bit_sum(const vector<int> & st,int x)
{
	int s=0;
	while (x>=0) s+=st[x],x=(x&(x+1))-1;
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,qry;
	cin>>n>>qry;
	vector<vector<int> > adj(n);
	repf(i,1,n)
	{
		int a,b;
		cin>>a>>b,--a,--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> d(n,oo);
	vector<int> rt(n);
	queue<int> q;
	vector<vector<int> > st(n);
	d[0]=0;
	q.push(0);
	while (sz(q))
	{
		int u=q.front();
		q.pop();
		rep(i,sz(adj[u]))
		{
			int v=adj[u][i];
			if (d[v]==oo)
			{
				d[v]=d[u]+1;
				rt[v]=u?rt[u]:v;
				st[rt[v]].resize(d[v]);
				q.push(v);
			}
		}
	}
	int als=0;
	vector<int> alst(n);
	rep(i,qry)
	{
		int t;
		cin>>t;
		if (t)
		{
			int v;
			cin>>v,--v;
			if (v) cout<<als+bit_sum(alst,d[v]-1)+bit_sum(st[rt[v]],d[v]-1)<<endl;
			else cout<<als<<endl;
		}
		else
		{
			int v,x,qd;
			cin>>v>>x>>qd,--v;
			if (v)
			{
				int alp=qd-d[v];
				if (alp>=0)
				{
					als+=x;
					bit_inc(alst,alp,-x),
					bit_inc(st[rt[v]],alp,x),
					bit_inc(st[rt[v]],d[v]+qd,-x);
				}
				else
				{
					bit_inc(st[rt[v]],d[v]-qd-1,x);
					bit_inc(st[rt[v]],d[v]+qd,-x);
				}
			}
			else
			{
				als+=x;
				bit_inc(alst,qd,-x);
			}
		}
	}
}

