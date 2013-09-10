/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Description:
 * Dinic实现的最大流算法;
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c,bc;
 * add_edge(u,v,c,bc=0) 加一条u到v的容量为c的有向边,加一条v到u的容量为bc的有向边
 * dinic:
 * 输出flow_type
 * dinic()=最大流
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace DinicsAlgorithm
{

const int MAX_DIST=0x7f7f7f7f;
const int MAXV=1;
const int MAXE=2;
typedef int flow_type;
const int MAX_FLOW=oo;
typedef struct struct_edge* edge;
struct struct_edge{int v;flow_type c;edge n,b;}pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
void build_graph(int s,int t)
{
	top=pool,clr(adj);
	S=s,T=t;//源,汇
	//add_edge(u,v,c);
}
void add_edge(int u,int v,flow_type c,flow_type bc=0)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=bc,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
	if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;//防止add_edge(u,u,c)时出现RE
}
int d[MAXV];
int q[MAXV];
int qh,qt;
bool relabel()
{
	fl(d,MAX_DIST),d[q[qh=qt=0]=T]=0;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge i=adj[u];i;i=i->n)
			if (i->b->c&&cmin(d[i->v],d[u]+1))
				if ((q[++qt]=i->v)==S) rtn true;
	}
	rtn false;
}
edge cur[MAXV];
flow_type augment(int u,flow_type e)
{
	if (u==T) rtn e;
	flow_type f=0;
	for (edge& i=cur[u];i;i=i->n)
	{
		if (i->c&&d[u]==d[i->v]+1)
			if (flow_type df=augment(i->v,min(e,i->c)))
				i->c-=df,i->b->c+=df,e-=df,f+=df;
		if (!e) break;
	}
	rtn f;
}
flow_type dinic()
{
	flow_type f=0;
	while (relabel()) cpy(cur,adj),f+=augment(S,MAX_FLOW);
	rtn f;
}

}
}
}
