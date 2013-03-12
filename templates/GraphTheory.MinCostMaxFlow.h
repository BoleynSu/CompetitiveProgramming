/*
 * Package: StandardCodeLibrary.GraphTheory.MinCostMaxFlow
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c;cost_type d;
 * add_edge(u,v,c,d) 加一条u到v的容量为c代价为d的有向边,加一条v到u的容量为0代价为-d的有向边
 * min_cost_max_flow:
 * min_cost_max_flow(最大流,最小费用)
 * min_cost_max_flow_faster：
 * 输入bool has_negative_edges 初始图是否含有负权边
 * min_cost_max_flow_faster(最大流,最小费用,has_negative_edges)
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace MinCostMaxFlow
{

const int oo=0x7f7f7f7f;
const int MAXE=1000000;
const int MAXV=10000;
typedef int flow_type;
typedef int cost_type;
typedef struct struct_edge* edge;
struct struct_edge{int v;flow_type c;cost_type d;edge n,b;}pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
void build_graph(int s,int t)
{
	top=pool,clr(adj);
	S=s,T=t;//源,汇
	//add_edge(u,v,c,d);
}
void add_edge(int u,int v,flow_type c,cost_type d)
{
	top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
cost_type d[MAXV];
int q[MAXV];
bool inq[MAXV];
int qh,qt;
edge p[MAXV];
void min_cost_max_flow(flow_type& flow,cost_type& cost)
{
	flow=0,cost=0;
	lp
	{
		fl(d,oo),inq[q[qh=qt=0]=S]=true,d[S]=0,p[S]=0;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(d[i->v],d[u]+i->d))
				{
					p[i->v]=i;
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
				}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta,cost+=delta*i->d;
			flow+=delta;
		}
	}
}
int V=MAXV;
cost_type h[MAXV];
void min_cost_max_flow_faster(flow_type& flow,cost_type& cost,bool has_negative_edges=true)
{
	flow=0,cost=0;
	if (has_negative_edges)
	{
		fl(h,oo),fl(inq,false),qh=0,qt=-1;
		rep(i,V) h[i]=0,q[++qt]=i,inq[i]=true;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(h[i->v],h[u]+i->d))
				{
					p[i->v]=i;
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
				}
		}
	}
	else clr(h);
	lp
	{
		fl(d,oo),fl(inq,false);
		prq<pr<cost_type,int> > Q;
		d[S]=0,p[S]=0,Q.push(mp(-d[S],S));
		whl(sz(Q))
		{
			int u=Q.top().y;
			Q.pop();
			if (!inq[u])
			{
				inq[u]=true;
				for (edge i=adj[u];i;i=i->n)
				{
					if (i->c&&!inq[i->v]&&cmin(d[i->v],d[u]+i->d+h[u]-h[i->v]))
						p[i->v]=i,Q.push(mp(-d[i->v],i->v));
				}
			}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
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
