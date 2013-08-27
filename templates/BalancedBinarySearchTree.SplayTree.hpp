/*
 * Package: StandardCodeLibrary.BalancedBinarySearchTree.SplayTree
 * Usage:
 * MAXNODE:SplayTree最多有多少个节点,null会占用一个节点
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace BinarySearchTree
{
namespace SplayTree
{

typedef int key_type;
struct data
{
	key_type k;//k用于lower_bound/upper_bound/find
	int s;//s用于find_by_order/order_of_key/size
};
const int MAXNODE=1;
typedef struct struct_node* node;
struct struct_node:data{node p,c[2];}pool[MAXNODE];
node top,null;

struct Initializer{Initializer(){top=pool,null=top++,null->p=null->c[0]=null->c[1]=null;}}initializer;

node make(const key_type& k)
{
	rtn top->k=k,top->s=0,top->p=top->c[0]=top->c[1]=null,top++;
}
void apply(node x)
{
}
void pushup(node x)
{
	x->s=x->c[0]->s+x->c[1]->s+1;
}
void pushdown(node x)
{
}

//pushdown rt到x这条链上的所有节点 如果不是用的自带pushdown的函数(如lower_bound)获得的x 则可能会用到此函数
node stk[MAXNODE];
int stks;
void pushdownto(node x)
{
	do stk[stks++]=x;
	whl(x=x->p,x!=null);
	whl(stks) pushdown(stk[--stks]);
}

void set(node x,bool d,node y)
{
	x->c[d]=y;
	y->p=x;
}
void rotate(node x,bool d)
{
	node y=x->p;
	set(y,d,x->c[!d]),set(y->p,y->p->c[1]==y,x),set(x,!d,y);
	pushup(y);
}
void splay(node x,node p=null)
{
	whl(x->p!=p)
	{
		bool xd=x->p->c[1]==x,xpd=x->p->p->c[1]==x->p;
		if(x->p->p==p) rotate(x,xd);
		else
		{
			if(xpd==xd) rotate(x->p,xpd);
			else rotate(x,xd);
			rotate(x,xpd);
		}
	}
	pushup(x);
}

node lower_bound(node rt,const key_type& k)
{
	node l=rt,r=null;
	whl(l!=null)
	{
		pushdown(l);
		if (l->k<k) l=l->c[1];
		else r=l,l=l->c[0];
	}
	rtn r;
}
node upper_bound(node rt,const key_type& k)
{
	node l=rt,r=null;
	whl(l!=null)
	{
		pushdown(l);
		if (k<l->k) r=l,l=l->c[0];
		else l=l->c[1];
	}
	rtn r;
}
node find_by_order(node rt,int cnt)
{
	node x=rt;
	whl(x!=null)
	{
		pushdown(x);
		if (x->c[0]->s==cnt) break;
		else if (x->c[0]->s<cnt) cnt-=x->c[0]->s+1,x=x->c[1];
		else x=x->c[0];
	}
	rtn x;
}
node min(node rt)
{
	node x,y=rt;
	do x=y,y=x->c[0],pushdown(x);
	whl(y!=null);
	rtn x;
}
node max(node rt)
{
	node x,y=rt;
	do x=y,y=x->c[1],pushdown(x);
	whl(y!=null);
	rtn x;
}

struct tree
{
	node rt;
	tree():rt(null){}
	node lower_bound(const key_type& k)
	{
		node x=SplayTree::lower_bound(rt,k);
		if (x!=null) splay(x,null),rt=x;
		rtn x;
	}
	node upper_bound(const key_type& k)
	{
		node x=SplayTree::upper_bound(rt,k);
		if (x!=null) splay(x,null),rt=x;
		rtn x;
	}
	node find(const key_type& k)
	{
		node x=lower_bound(k);
		rtn x==null||k<x->k?null:x;
	}
	node find_by_order(int cnt)
	{
		node x=SplayTree::find_by_order(rt,cnt);
		if (x!=null) splay(x,null),rt=x;
		rtn x;
	}
	int order_of_key(const key_type& k)
	{
		node x=lower_bound(k);
		rtn x==null?size():x->c[0]->s;
	}
	node insert(const key_type& k)
	{
		node x=SplayTree::upper_bound(rt,k);
		node y=make(k);
		if (x==null) set(y,0,rt);
		else splay(x),set(y,0,x->c[0]),set(x,0,null),set(y,1,x),pushup(x);
		pushup(y),rt=y;
		rtn rt;
	}
	//注意:需要保证rt到x这条链上的所有节点都被pushdown过
	void erase(node x)
	{
		if (x!=null)
		{
			splay(x,null),rt=x;
			if (x->c[1]==null)
			{
				rt=x->c[0];
				set(null,0,x->c[0]),set(x,0,null);
			}
			else
			{
				node y=min(x->c[1]);
				splay(y,x);
				set(null,1,y),set(y,0,x->c[0]),set(x,0,null),set(x,1,null);
				pushup(y),rt=y;
			}
		}
	}
	node erase(const key_type& k)
	{
		node x=find(k);
		erase(x);
		rtn x;
	}
	int size()
	{
		rtn rt->s;
	}
};

}
}
}
