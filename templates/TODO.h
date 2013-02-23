#include <Core>
namespace BinarySearchTree
{
namespace SizeBalancedTree
{

typedef int type;
const int MAXNODE=1000000;
struct struct_node{type k;int s;struct_node* c[1<<1];};
typedef struct_node* node;
struct_node pool[MAXNODE];
node top,null;
struct Initializer{Initializer(){top=pool,null=top++,null->s=0,null->c[false]=null->c[true]=null;}}initializer;
void rotate(node& x,bool d)
{
	node y=x->c[!d];
	x->c[!d]=y->c[d],y->c[d]=x;
	y->s=x->s,x->s=x->c[false]->s+x->c[true]->s+1;
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
	if (x==null) x=top++,x->k=k,x->s=1,x->c[false]=x->c[true]=null;
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
		if (x->c[false]==null||x->c[true]==null) x=x->c[x->c[false]==null];
		else x->k=erase(x->c[false],k);
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
		if (d) y+=x->c[false]->s+1;
		x=x->c[d];
	}
	rtn y;
}
//返回排名为s的元素 排名从0开始 如果s超出范围 返回null
node find_by_order(node x,int s)
{
	whl(x!=null&&x->c[false]->s!=s)
	{
		bool d=x->c[false]->s<s;
		if (d) s-=x->c[false]->s+1;
		x=x->c[d];
	}
	rtn x;
}
node min(node x)
{
	whl(x->c[false]!=null) x=x->c[false];
	rtn x;
}
node max(node x)
{
	whl(x->c[true]!=null) x=x->c[true];
	rtn x;
}
//返回第一个小于k的元素 如果没有比k小的元素则返回null
node pred(node x,const type& k)
{
	if (x==null) rtn null;
	else if (x->k==k) rtn max(x->c[false]);
	else if (x->k<k)
	{
		node y=pred(x->c[true],k);
		if (y==null) rtn x;
		else rtn y;
	}
	else rtn pred(x->c[false],k);
}
//返回第一个大于k的元素 如果没有比k大的元素则返回null
node succ(node x,const type& k)
{
	if (x==null) rtn null;
	else if (x->k==k) rtn min(x->c[true]);
	else if (x->k<k) rtn succ(x->c[true],k);
	else
	{
		node y=succ(x->c[false],k);
		if (y==null) rtn x;
		else rtn y;
	}
}

class tree
{
	node rt;
public:
	tree():rt(SizeBalancedTree::null){}
	void insert(const type&  k){if (!count(k)) SizeBalancedTree::insert(rt,k);}
	void erase(const type&  k){if (count(k)) SizeBalancedTree::erase(rt,k);}
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
