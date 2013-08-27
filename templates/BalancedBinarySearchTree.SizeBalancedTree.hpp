/*
 * Package: StandardCodeLibrary.BalancedBinarySearchTree.SizeBalancedTree
 * Usage:
 * MAXNODE:SizeBalancedTree最多有多少个节点,null会占用一个节点
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace BinarySearchTree
{
namespace SizeBalancedTree
{

typedef int type;
const int MAXNODE=1;
typedef struct struct_node* node;
struct struct_node{type k;int s;node c[2];}pool[MAXNODE];
node top,null;

struct Initializer{Initializer(){top=pool,null=top++,null->s=0,null->c[0]=null->c[1]=null;}}initializer;

node make(const type& k)
{
	rtn top->k=k,top->s=1,top->c[0]=top->c[1]=null,top++;
}
void rotate(node& x,bool d)
{
	node y=x->c[!d];
	x->c[!d]=y->c[d],y->c[d]=x;
	y->s=x->s,x->s=x->c[0]->s+x->c[1]->s+1;
	x=y;
}
void maintain(node& x,bool d)
{
	if (x->c[d]->c[d]->s>x->c[!d]->s) rotate(x,!d);
	else if (x->c[d]->c[!d]->s>x->c[!d]->s) rotate(x->c[d],d),rotate(x,!d);
	else rtn;
	rep(d,2) maintain(x->c[d],d);
	rep(d,2) maintain(x,d);
}
//须确保树上没有和k相同的元素
void insert(node& x,const type& k)
{
	if (x==null) x=make(k);
	else
	{
		bool d=x->k<k;
		x->s++,insert(x->c[d],k),maintain(x,d);
	}
}
//须确保删除的元素k一定在树上
type erase(node& x,const type& k)
{
	bool d=x->k<k;
	x->s--;
	if (k==x->k||x->c[d]==null)
	{
		type y=x->k;
		if (x->c[0]==null||x->c[1]==null) x=x->c[x->c[0]==null];
		else x->k=erase(x->c[0],k);
		rtn y;
	}
	else rtn erase(x->c[d],k);
}
int size(node x)
{
	rtn x->s;
}
//找不到返回null
node find(node x,const type& k)
{
	whl(x!=null&&x->k!=k) x=x->c[x->k<k];
	rtn x;
}
//返回第一个不小于k的元素的排名 排名从0开始
int order_of_key(node x,const type& k)
{
	int y=0;
	whl(x!=null)
	{
		bool d=x->k<k;
		if (d) y+=x->c[0]->s+1;
		x=x->c[d];
	}
	rtn y;
}
//返回排名为s的元素 排名从0开始 如果s超出范围 返回null
node find_by_order(node x,int s)
{
	whl(x!=null&&x->c[0]->s!=s)
	{
		bool d=x->c[0]->s<s;
		if (d) s-=x->c[0]->s+1;
		x=x->c[d];
	}
	rtn x;
}
node min(node x)
{
	whl(x->c[0]!=null) x=x->c[0];
	rtn x;
}
node max(node x)
{
	whl(x->c[1]!=null) x=x->c[1];
	rtn x;
}
//返回第一个小于k的元素 如果没有比k小的元素则返回null
node pred(node x,const type& k)
{
	if (x==null) rtn null;
	else if (x->k==k) rtn max(x->c[0]);
	else if (x->k<k)
	{
		node y=pred(x->c[1],k);
		if (y==null) rtn x;
		else rtn y;
	}
	else rtn pred(x->c[0],k);
}
//返回第一个大于k的元素 如果没有比k大的元素则返回null
node succ(node x,const type& k)
{
	if (x==null) rtn null;
	else if (x->k==k) rtn min(x->c[1]);
	else if (x->k<k) rtn succ(x->c[1],k);
	else
	{
		node y=succ(x->c[0],k);
		if (y==null) rtn x;
		else rtn y;
	}
}

struct tree
{
	node rt;
	tree():rt(SizeBalancedTree::null){}
	void insert(const type& k){if (!count(k)) SizeBalancedTree::insert(rt,k);}
	void erase(const type& k){if (count(k)) SizeBalancedTree::erase(rt,k);}
	int size(){rtn SizeBalancedTree::size(rt);}
	node find(const type& k){rtn SizeBalancedTree::find(rt,k);}
	int count(const type& k){rtn SizeBalancedTree::find(rt,k)!=SizeBalancedTree::null;}
	int order_of_key(const type& k){rtn SizeBalancedTree::order_of_key(rt,k);}
	node find_by_order(int s){rtn SizeBalancedTree::find_by_order(rt,s);}
	node min(){rtn SizeBalancedTree::min(rt);}
	node max(){rtn SizeBalancedTree::max(rt);}
	node pred(const type& k){rtn SizeBalancedTree::pred(rt,k);}
	node succ(const type& k){rtn SizeBalancedTree::succ(rt,k);}
};

}
}
}
