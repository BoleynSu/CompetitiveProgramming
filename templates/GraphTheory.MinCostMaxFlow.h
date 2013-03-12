/*
 * Package: StandardCodeLibrary.GraphTheory.MinCostMaxFlow
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c;cost_type d
 * add_edge(u,v,c,d) 加一条u到v的容量为c代价为d的有向边,加一条v到u的容量为0代价为-d的有向边
 * min_cost_max_flow:
 * min_cost_max_flow(最大流,最小费用)
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
const int MAXV=1000000;
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
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
					p[i->v]=i;
				}
		}
		if (d[T]==oo) break;
		else
		{
			flow_type delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta;
			flow+=delta;
			cost+=d[T]*delta;
		}
	}
}

}
}
}
