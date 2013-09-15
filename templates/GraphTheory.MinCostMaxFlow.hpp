/*
 * Package: StandardCodeLibrary.GraphTheory.MinCostMaxFlow
 * Description:
 * SPFA+Dijkstra实现的Successive Shortest Path with potentials最小费用最大流;
 * Usage:
 * MAXV:需要为点分配多少空间,点必须在0到V-1之间，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c;cost_type d;
 * add_edge(u,v,c,d) 加一条u到v的容量为c代价为d的有向边,加一条v到u的容量为0代价为-d的有向边
 * min_cost_max_flow:
 * 输入bool has_negative_edges 初始图是否含有负权边
 * min_cost_max_flow(flow,cost,has_negative_edges)
 * 运行后flow会加上最大流 cost会加上对应的最小费用
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace MinCostMaxFlow
{

const int MAXV=1;
const int MAXE=2;
typedef int flow_type;
typedef int cost_type;
const int MAX_FLOW=oo;
const int MAX_COST=0x7f7f7f7f;
typedef struct struct_edge* edge;
struct struct_edge{int v;flow_type c;cost_type d;edge n,b;}pool[MAXE];
edge top;
int V=MAXV,S,T;
edge adj[MAXV];
void build_graph(int v,int s,int t)
{
	top=pool,clr(adj);
	V=v,S=s,T=t;//点的编号的范围为[0,v),源,汇
	//add_edge(u,v,c,d);
}
void add_edge(int u,int v,flow_type c,cost_type d)
{
	top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
	if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;//防止add_edge(u,u,c,d)时出现RE
}
cost_type h[MAXV],d[MAXV];
int q[MAXV];
bool inq[MAXV];
int qh,qt;
edge p[MAXV];
void min_cost_max_flow(flow_type& flow,cost_type& cost,bool has_negative_edges=true)
{
	if (has_negative_edges)
	{
		fl(h,MAX_COST),fl(inq,false),qh=0,qt=-1;
		rep(i,V) h[i]=0,q[++qt]=i,inq[i]=true;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(h[i->v],h[u]+i->d))
				{
					p[i->v]=i;
					if (cmax(inq[i->v],true)) q[(++qt)%MAXV]=i->v;
				}
		}
	}
	else clr(h);
	lp
	{
		fl(d,MAX_COST),fl(inq,false);
		prq<pr<cost_type,int> > Q;
		d[S]=0,p[S]=0,Q.push(mp(-d[S],S));
		whl(sz(Q))
		{
			int u=Q.top().y;
			Q.pop();
			if (cmax(inq[u],true))
				for (edge i=adj[u];i;i=i->n)
					if (i->c&&!inq[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
						p[i->v]=i,Q.push(mp(-d[i->v],i->v));
		}
		if (d[T]==MAX_COST) break;
		else
		{
			flow_type delta=MAX_FLOW;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
			flow+=delta;
			rep(i,V) h[i]+=d[i];
		}
	}
}

}
}
}
