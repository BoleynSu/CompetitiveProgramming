/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c;
 * add_edge(u,v,c) 加一条u到v的容量为c的有向边,加一条v到u的容量为0的有向边
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

const int oo=0x7f7f7f7f;
const int MAXV=1000000;
const int MAXE=1000000;
typedef int flow_type;
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
void add_edge(int u,int v,flow_type c)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
	//if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;
}
int d[MAXV];
int q[MAXV];
int qh,qt;
bool relabel()
{
	fl(d,oo),d[q[qh=qt=0]=T]=0;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge i=adj[u];i;i=i->n)
			if (i->b->c&&cmin(d[i->v],d[u]+1))
				if ((q[++qt]=i->v)==S) rtn true;
	}
	rtn false;
}
//递归增广
flow_type augment(int u,flow_type e)
{
	if (u==T) return e;
	flow_type f=0;
	for (edge i=adj[u];i&&e;i=i->n)
		if (i->c&&d[u]==d[i->v]+1)
			if (flow_type df=augment(i->v,min(e,i->c)))
				i->c-=df,i->b->c+=df,e-=df,f+=df;
	return f;
}
//非递归增广
int st,us[MAXV];
flow_type es[MAXV],fs[MAXV],f,df;
edge is[MAXV],cur[MAXV];
#define push(nu,ne) u=nu,e=ne,st++,us[st]=u,es[st]=e,fs[st]=0,is[st]=cur[u]
#define pop() df=fs[st],st--,st>=0?is[st]->c-=df,is[st]->b->c+=df,es[st]-=df,is[st]=is[st]->n,fs[st]+=df:f+=df
flow_type improved_augment(int u,flow_type e)
{
    f=0,st=-1,cpy(cur,adj);
    push(u,e);
    whl(st>=0)
    {
        if (us[st]==T) fs[st]=es[st],pop();
        else if (!is[st]||!es[st]) pop();
        else if (is[st]->c&&d[us[st]]==d[is[st]->v]+1) cur[us[st]]=is[st],push(is[st]->v,min(es[st],is[st]->c));
        else is[st]=is[st]->n;
    }
    rtn f;
}
#undef pop
#undef push
flow_type dinic()
{
	flow_type f=0;
	while (relabel()) f+=improved_augment(S,oo);
	return f;
}

}
}
}
