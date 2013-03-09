/*
 * Package: StandardCodeLibrary.StringAlgorithms.AhoCorasickAlgorithm
 * Usage:
 * MAXNODE:AC自动机最多有多少个节点
 * MAXALPHABET:字母表大小
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{
namespace AhoCorasickAlgorithm
{

const int MAXNODE=1000000;
const int MAXALPHABET=26;
typedef bool info;
struct struct_node{struct_node* n[MAXALPHABET];struct_node* f;info i;int v;};
typedef struct_node* node;
struct_node pool[MAXNODE];
node top;
int cnt;

struct Initializer{Initializer(){top=pool,clr(pool);}}initializer;

class ACAutomation
{
protected:
	node rt;
	virtual void update(info&,const info&)=0;
	virtual void calculate(const info&)=0;
public:
	ACAutomation():rt(top++){}
	void insert(vi s,const info& i)
	{
		node u=rt;
		rep(i,sz(s))
		{
			if (!u->n[s[i]]) u->n[s[i]]=top++;
			u=u->n[s[i]];
		}
		update(u->i,i);
	}
	void build()
	{
		que<node> q;
		rt->f=rt,q.push(rt);
		whl(sz(q))
		{
			node u=q.front();
			q.pop();
			rep(c,MAXALPHABET) if (u->n[c])
			{
				if (u==rt) u->n[c]->f=rt;
				else
				{
					node v=u->f;
					whl(v!=rt&&!v->n[c]) v=v->f;
					if (v->n[c]) v=v->n[c];
					u->n[c]->f=v;
				}
				q.push(u->n[c]);
			}
		}
	}
	void query(vi s)
	{
		cnt++;
		node u=rt;
		rep(i,sz(s))
		{
			whl(u!=rt&&!u->n[s[i]]) u=u->f;
			if (u->n[s[i]]) u=u->n[s[i]];
			node v=u;
			whl(v!=rt&&v->v!=cnt)
				calculate(v->i),v->v=cnt,v=v->f;
		}
	}
};

}
}
}
