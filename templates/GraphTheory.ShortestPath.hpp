/*
 * Package: StandardCodeLibrary.GraphTheory.ShortestPath
 * Description:
 * 最短路:队列优化版的Bellman-ford(SPFA),Dijkstra,Johnson‘s Algorithm;
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;cost_type d
 * add_edge(u,v,d) 加一条u到v的权值为d的有向边
 * spfa:
 * 运行后d[u]=S到u的距离
 * dijkstra:
 * 运行后d[u]=S到u的距离
 * johnson_spfa:
 * 要求点的标号在0到V-1之间,运行后计算出了h数组
 * johnson_dijkstra:
 * 要求点的标号在0到V-1之间,需要先运行johnson_spfa,运行一次johnson_spfa后可使用不同的S多次运行johnson_dijkstra,运行后d[u]=S到u的距离
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace ShortestPath
{

const int MAXV=1;
const int MAXE=1;
typedef int cost_type;
const cost_type MAX_COST=0x7f7f7f7f;
typedef struct struct_edge* edge;
struct struct_edge{int v;cost_type d;edge n;}pool[MAXE];
edge top;
int S;
edge adj[MAXV];
cost_type d[MAXV];
int pre[MAXV];
bool vis[MAXV];
void build_graph(int s)
{
	top=pool,clr(adj);
	S=s;//源
	//add_edge(u,v,d);
}
void add_edge(int u,int v,cost_type d)
{
	top->v=v,top->d=d,top->n=adj[u],adj[u]=top++;
}
void spfa()
{
	fl(d,MAX_COST),fl(vis,false);
	qi Q;
	d[S]=0,pre[S]=-1,Q.push(S),vis[S]=true;
	whl(sz(Q))
	{
		int u=Q.front();
		vis[u]=false;
		Q.pop();
		for (edge i=adj[u];i;i=i->n)
			if (cmin(d[i->v],d[u]+i->d))
			{
				pre[i->v]=u;
				if (!vis[i->v]) Q.push(i->v),vis[i->v]=true;
			}
	}
}
void dijkstra()
{
	fl(d,MAX_COST),fl(vis,false);
	prq<pr<cost_type,int> > Q;
	d[S]=0,pre[S]=-1,Q.push(mp(-d[S],S));
	whl(sz(Q))
	{
		int u=Q.top().y;
		Q.pop();
		if (!vis[u])
		{
			vis[u]=true;
			for (edge i=adj[u];i;i=i->n)
				if (!vis[i->v]&&cmin(d[i->v],d[u]+i->d))
					pre[i->v]=u,Q.push(mp(-d[i->v],i->v));
		}
	}
}
int V=MAXV;
cost_type h[MAXV];
void johnson_spfa()
{
	fl(h,0),fl(vis,false);
	qi Q;
	rep(i,V) h[i]=0,Q.push(i),vis[i]=true;
	whl(sz(Q))
	{
		int u=Q.front();
		vis[u]=false;
		Q.pop();
		for (edge i=adj[u];i;i=i->n)
			if (cmin(h[i->v],h[u]+i->d)&&!vis[i->v])
				Q.push(i->v),vis[i->v]=true;
	}
}
void johnson_dijkstra()
{
	fl(d,MAX_COST),fl(vis,false);
	prq<pr<cost_type,int> > Q;
	d[S]=0,pre[S]=-1,Q.push(mp(-d[S],S));
	whl(sz(Q))
	{
		int u=Q.top().y;
		Q.pop();
		if (!vis[u])
		{
			vis[u]=true;
			for (edge i=adj[u];i;i=i->n)
				if (!vis[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
					pre[i->v]=u,Q.push(mp(-d[i->v],i->v));
		}
	}
	rep(i,V) d[i]+=h[i]-h[S];
}

}
}
}
