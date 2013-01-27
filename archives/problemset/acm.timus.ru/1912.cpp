#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int,int> P;

int n,m;
char g[1024][1024];
int si,sj,ti,tj;
vector<P> adj[250+2][250+2];
map<P,int> d[250+2][250+2];
deque<pair<P,P> > Q;

int my_abs(int x)
{
	return x>=0?x:-x;
}
bool check(P a,P b)
{
	return my_abs(a.first-b.first)<=1&&my_abs(a.second-b.second)<=1&&(!(a.first==b.first&&a.second==b.second))&&(0<=b.first&&b.first<=n+1&&0<=b.second&&b.second<=m+1);
}
int dist(P s,P t)
{
	return !((s.first<1||s.first>n||s.second<1||s.second>m)&&(t.first<1||t.first>n||t.second<1||t.second>m));
}

int main()
{
	scanf("%d%d",&n,&m),getchar();
	for (int i=0;i<=n*2;i++) gets(g[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			int x=i*2+1,y=j*2+1;
			if (g[x-1][y]=='.') adj[i+1][j+1].push_back(P(i,j+1)),adj[i][j+1].push_back(P(i+1,j+1));
			if (g[x+1][y]=='.') adj[i+1][j+1].push_back(P(i+2,j+1)),adj[i+2][j+1].push_back(P(i+1,j+1));
			if (g[x][y-1]=='.') adj[i+1][j+1].push_back(P(i+1,j)),adj[i+1][j].push_back(P(i+1,j+1));
			if (g[x][y+1]=='.') adj[i+1][j+1].push_back(P(i+1,j+2)),adj[i+1][j+2].push_back(P(i+1,j+1));
			if (g[x][y]=='1') si=i+1,sj=j+1;
			if (g[x][y]=='2') ti=i+1,tj=j+1;
		}
	for (int i=0;i<=n;i++)
	{
		adj[i][0].push_back(P(i+1,0));
		adj[i+1][0].push_back(P(i,0));
		adj[i][m+1].push_back(P(i+1,m+1));
		adj[i+1][m+1].push_back(P(i,m+1));
	}
	for (int i=0;i<=m;i++)
	{
		adj[0][i].push_back(P(0,i+1));
		adj[0][i+1].push_back(P(0,i));
		adj[n+1][i].push_back(P(n+1,i+1));
		adj[n+1][i+1].push_back(P(n+1,i));
	}
	d[si][sj][P(ti,tj)]=1;
	Q.push_back(make_pair(P(si,sj),P(ti,tj)));
	while (!Q.empty())
	{
		P s=Q.front().first,t=Q.front().second;
		//cout<<s.first<<","<<s.second<<" "<<t.first<<","<<t.second<<endl;
		Q.pop_front();
		int D=d[s.first][s.second][t];
		if ((s.first<1||s.first>n||s.second<1||s.second>m)&&(t.first<1||t.first>n||t.second<1||t.second>m))
		{
			printf("%d\n",D-1);
			return 0;
		}
		for (unsigned i=0;i<adj[s.first][s.second].size();i++)
		{
			P ss=adj[s.first][s.second][i];
			if (check(t,ss)&&!d[ss.first][ss.second][t])
				d[ss.first][ss.second][t]=D+dist(s,ss),dist(s,ss)?Q.push_back(make_pair(ss,t)):Q.push_front(make_pair(ss,t));
		}
		for (unsigned i=0;i<adj[t.first][t.second].size();i++)
		{
			P tt=adj[t.first][t.second][i];
			if (check(s,tt)&&!d[s.first][s.second][tt])
				d[s.first][s.second][tt]=D+dist(t,tt),dist(t,tt)?Q.push_back(make_pair(s,tt)):Q.push_front(make_pair(s,tt));
		}
	}
	puts("Death");
	return 0;
}
