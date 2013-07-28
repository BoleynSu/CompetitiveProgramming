/*
 * Package: StandardCodeLibrary.GraphTheory.Edmonds'sMatchingAlgorithm
 * Description:
 * 带花树实现的一般图最大匹配;
 * Usage:
 * MAXV:需要为点分配多少空间,点一定要从0到V-1，即MAXV应该等于最大点数
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * V:点数
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v
 * add_edge(u,v) 加一条u到v的边和一条v到u的边
 * edmonds:
 * 输出int
 * edmonds()=最大匹配数
 * 附加输出:
 * 如果match[u]==NOT_NODE则u没有被匹配
 * 否者u与match[u]匹配
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace EdmondssMatchingAlgorithm
{

const int MAXV=100;
const int MAXE=MAXV*MAXV*2;
const int NOT_NODE=-1;
typedef struct struct_edge* edge;
struct struct_edge{int v;edge n;}pool[MAXE];
edge top;
int V;
edge adj[MAXV];
void build_graph(int v)
{
	top=pool,clr(adj);
	V=v;//点数 V必须严格等于图中的点的数目
	//add_edge(u,v);
}
void add_edge(int u,int v)
{
	top->v=v,top->n=adj[u],adj[u]=top++;
	top->v=u,top->n=adj[v],adj[v]=top++;
}
int match[MAXV];
int qh,qt;
int q[MAXV];
bool inq[MAXV];
int father[MAXV];
int base[MAXV];
bool ib[MAXV];
bool ip[MAXV];
int LCA(int root,int u,int v)
{
	clr(ip);
	lp
	{
		ip[u=base[u]]=true;
		if (u==root) break;
		u=father[match[u]];
	}
	lp
	{
		if (ip[v=base[v]]) rtn v;
		else v=father[match[v]];
	}
}
void mark_blossom(int lca,int u)
{
	whl(base[u]!=lca)
	{
		int v=match[u];
		ib[base[u]]=true;
		ib[base[v]]=true;
		u=father[v];
		if (base[u]!=lca) father[u]=v;
	}
}
void blossom_contraction(int s,int u,int v)
{
	int lca=LCA(s,u,v);
	clr(ib);
	mark_blossom(lca,u);
	mark_blossom(lca,v);
	if (base[u]!=lca) father[u]=v;
	if (base[v]!=lca) father[v]=u;
	rep(u,V)
		if (ib[base[u]])
		{
			base[u]=lca;
			if (!inq[u]) inq[q[++qt]=u]=true;
		}
}
int find_augmenting_path(int s)
{
	clr(inq),fl(father,NOT_NODE);
	for (int i=0;i<V;i++) base[i]=i;
	inq[q[qh=qt=0]=s]=true;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge e=adj[u];e;e=e->n)
		{
			int v=e->v;
			if (base[u]!=base[v]&&match[u]!=v)
			{
				if ((v==s)||(match[v]!=NOT_NODE&&father[match[v]]!=NOT_NODE))
					blossom_contraction(s,u,v);
				else if (father[v]==NOT_NODE)
				{
					father[v]=u;
					if (match[v]==NOT_NODE) rtn v;
					else if (!inq[match[v]]) inq[q[++qt]=match[v]]=true;
				}
			}
		}
	}
	rtn NOT_NODE;
}
int augment_path(int s,int t)
{
	int u,v,w;
	u=t;
	whl(u!=NOT_NODE)
	{
		v=father[u];
		w=match[v];
		match[v]=u;
		match[u]=v;
		u=w;
	}
	rtn t!=NOT_NODE;
}
int edmonds()
{
	int matchc=0;
	fl(match,NOT_NODE);
	for (int u=0;u<V;u++)
		if (match[u]==NOT_NODE)
		matchc+=augment_path(u,find_augmenting_path(u));
	rtn matchc;
}

}
}
}
