/*
 * Package: StandardCodeLibrary.StringAlgorithms.AhoCorasickAlgorithm
 * Description:
 * AC自动机 Aho-Corasick Algorithm;
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
typedef bool data;
typedef struct struct_node* node;
struct struct_node{node n[MAXALPHABET];node f;data d;int v;}pool[MAXNODE];
node top;
int cnt;

struct Initializer{Initializer(){top=pool,clr(pool);}}initializer;

class ACAutomaton
{
protected:
	node rt;
	virtual void update(data&,const data&)=0;
	virtual void calculate(const data&)=0;
public:
	ACAutomaton():rt(top++){}
	void insert(vi s,const data& d)
	{
		node u=rt;
		rep(i,sz(s))
		{
			if (!u->n[s[i]]) u->n[s[i]]=top++;
			u=u->n[s[i]];
		}
		update(u->d,d);
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
				calculate(v->d),v->v=cnt,v=v->f;
		}
	}
};

}
}
}
