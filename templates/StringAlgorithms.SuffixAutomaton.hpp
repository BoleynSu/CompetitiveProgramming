/*
 * Package: StandardCodeLibrary.StringAlgorithms.SuffixAutomaton
 * Description:
 * 后缀自动机;
 * Usage:
 * MAXNODE:后缀自动机最多有多少个节点
 * MAXALPHABET:字母表大小
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{
namespace SuffixAutomaton
{

const int MAXNODE=1000000;
const int MAXALPHABET=26;
typedef struct struct_node* node;
struct struct_node{node n[MAXALPHABET];node lnk;int len;bool isc;}pool[MAXNODE];
node top;

struct Initializer{Initializer(){top=pool,clr(pool);}}initializer;

class SuffixAutomaton
{
protected:
	node rt,lst;
public:
	SuffixAutomaton():rt(top++),lst(rt){rt->isc=true;}
	void extend(int c)
	{
		node u=top++;
		u->len=lst->len+1;
		node v=lst;
		whl(v&&!v->n[c]) v->n[c]=u,v=v->lnk;
		if (v)
		{
			node vnc=v->n[c];
			if (v->len+1==vnc->len) u->lnk=vnc;
			else
			{
				node nvnc=top++;
				*nvnc=*vnc,nvnc->len=v->len+1,nvnc->isc=true,vnc->lnk=nvnc;
				whl(v&&v->n[c]==vnc) v->n[c]=nvnc,v=v->lnk;
				u->lnk=nvnc;
			}
		}
		else u->lnk=rt;
		lst=u;
	}
};

}
}
}
