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

struct type
{
	int k;//k用于lower_bound/upper_bound/find
	int s;//s用于find_by_order/order_of_key/size
	type(int k=0):k(k),s(0)
	{
	}
	friend bool operator<(const type& a,const type& b)
	{
		rtn a.k<b.k;
	}
};
const int MAXNODE=1000000;
typedef struct struct_node* node;
struct struct_node{type k;node p,c[2];}pool[MAXNODE];
node top,null;

struct Initializer{Initializer(){top=pool,null=top++,null->p=null->c[0]=null->c[1]=null;}}initializer;

node make(const type& k)
{
	rtn top->k=k,top->p=top->c[0]=top->c[1]=null,top++;
}
void apply(node x)
{
}
void pushup(node x)
{
	if (x!=null)
	{
		x->k.s=x->c[0]->k.s+x->c[1]->k.s+1;
	}
}
void pushdown(node x)
{
}

void set(node x,bool d,node y)
{
	if (x!=null) x->c[d]=y;
	if (y!=null) y->p=x;
}
void rotate(node x,bool d)
{
	node y=x->p;
	pushdown(y),pushdown(x);
	set(y,d,x->c[!d]),set(y->p,y->p->c[1]==y,x),set(x,!d,y);
	pushup(y);
}
void splay(node x,node p=null)
{
	pushdown(x);
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

node lower_bound(node rt,const type& k)
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
node upper_bound(node rt,const type& k)
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
		if (x->c[0]->k.s==cnt) break;
		else if (x->c[0]->k.s<cnt) cnt-=x->c[0]->k.s+1,x=x->c[1];
		else x=x->c[0];
	}
	rtn x;
}
node min(node rt)
{
	node x=rt;
	whl(x->c[0]!=null) pushdown(x),x=x->c[0];
	rtn x;
}
node max(node rt)
{
	node x=rt;
	whl(x->c[1]!=null) pushdown(x),x=x->c[1];
	rtn x;
}

struct tree
{
	node rt;
	tree():rt(null){}
	node lower_bound(const type& k)
	{
		node x=SplayTree::lower_bound(rt,k);
		if (x!=null) SplayTree::splay(x,null),rt=x;
		rtn x;
	}
	node upper_bound(const type& k)
	{
		node x=SplayTree::upper_bound(rt,k);
		if (x!=null) SplayTree::splay(x,null),rt=x;
		rtn x;
	}
	node find(const type& k)
	{
		node x=lower_bound(k);
		rtn x==null||k<x->k?null:x;
	}
	node find_by_order(int cnt)
	{
		node x=SplayTree::find_by_order(rt,cnt);
		if (x!=null) SplayTree::splay(x,null),rt=x;
		rtn x;
	}
	int order_of_key(const type& k)
	{
		node x=SplayTree::lower_bound(rt,k);
		if (x!=null) SplayTree::splay(x,null),rt=x;
		rtn x==null?x->k.s:x->c[0]->k.s;
	}
	node insert(const type& k)
	{
		node x=SplayTree::upper_bound(rt,k);
		splay(x);
		node y=make(k);
		if (x==null) set(y,0,rt);
		else set(y,0,x->c[0]),set(x,0,null),set(y,1,x);
		pushup(x),pushup(y),rt=y;
		rtn rt;
	}
	node erase(const type& k)
	{
		node x=find(k);
		if (x!=null)
		{
			if (x->c[1]==null)
			{
				rt=x->c[0];
				set(null,0,x->c[0]);
				set(x,0,null);
			}
			else
			{
				node y=SplayTree::min(x->c[1]);
				SplayTree::splay(y,x);
				set(null,1,y),set(y,0,x->c[0]),set(x,0,null),set(x,1,null);
				pushup(y),rt=y;
			}
		}
		rtn x;
	}
	int size()
	{
		rtn rt->k.s;
	}
};

}
}
}
