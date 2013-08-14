/*
 * Package: StandardCodeLibrary.GraphTheory.StronglyConnectedComponents
 * Description:
 * 有向图的强连通分量:Tarjan's Algorithm
 * Usage:
 * MAXV:需要为点分配多少空间,点一定要从0到V-1，即MAXV应该等于最大点数
 * MAXE:需要为边分配多少空间
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;
 * add_edge(u,v) 加一条u到v的有向边
 * tarjan:
 * bl[u]=u所在的强连通分量的编号,编号从0开始
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace StronglyConnectedComponents
{

const int MAXV=1000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v;edge n;}pool[MAXE];
edge top;
int V;
edge adj[MAXV];
void build_graph(int v)
{
	top=pool,clr(adj);
	V=v;//点数
	//add_edge(u,v);
}
void add_edge(int u,int v)
{
	top->v=v,top->n=adj[u],adj[u]=top++;
}
int ord;
int dfn[MAXV];
int low[MAXV];
int stks;
int stk[MAXV];
bool ins[MAXV];
int cnt;
int bl[MAXV];
void dfs(int u)
{
	dfn[u]=low[u]=++ord;
	ins[stk[stks++]=u]=true;
	for (edge i=adj[u];i;i=i->n)
		if (!dfn[i->v]) dfs(i->v),cmin(low[u],low[i->v]);
		else if (ins[i->v]) cmin(low[u],dfn[i->v]);
	if (dfn[u]==low[u])
	{
		int v;
		do ins[v=stk[--stks]]=false,bl[v]=cnt;
		whl(v!=u);
		cnt++;
	}
}
void tarjan()
{
	ord=0,clr(dfn),cnt=0;
	rep(i,V) if (!dfn[i]) dfs(i);
}

}
}
}
