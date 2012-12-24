/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Last Update: 2012-12-21
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * add_edge:
 * 输入int u,v,c
 * add_edge(u,v,c) 加一条u到v的容量为c的有向边,加一条v到u的容量为0的有向边
 * build_graph:构图,详细见函数内的注释
 * dinic:
 * 输出int
 * dinic()=最大流
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace Dinic_sAlgorithm
{

const int oo=0x7f7f7f7f;
const int MAXV=1000000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v,c;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
int qh,qt;
void add_edge(int u,int v,int c)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
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
int augment(int u,int e)
{
	if (u==T) return e;
	int f=0;
	for (edge i=adj[u];i&&e;i=i->n)
		if (i->c&&d[u]==d[i->v]+1)
			if (int df=augment(i->v,min(e,i->c)))
				i->c-=df,i->b->c+=df,e-=df,f+=df;
	return f;
}
//非递归增广
int st,us[MAXV],es[MAXV],fs[MAXV],f,df,ret;
edge is[MAXV],cur[MAXV];
#define push(u,e) us[st+1]=u,es[st+1]=e,fs[st+1]=0,is[st+1]=cur[u],st++
#define pop() df=fs[st--],st>=0?is[st]->c-=df,is[st]->b->c+=df,es[st]-=df,is[st]=is[st]->n,fs[st]+=df:f+=df
int improved_augment(int u,int e)
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
int dinic()
{
	int f=0;
	while (relabel()) f+=improved_augment(S,oo);
	return f;
}
void build_network()
{
	top=pool,clr(adj);
	//S,T;//源,汇
	//add_edge(u,v,c);
}

}
}
}
