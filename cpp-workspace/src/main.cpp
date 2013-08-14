#include <BalancedBinarySearchTree.SplayTree>

using namespace StandardCodeLibrary::BinarySearchTree::SplayTree;
int main()
{
	tree t;
	t.ins(type(1));
	t.ins(type(1));
	t.ins(type(1));
	t.ins(type(2));
	t.ins(type(1));
	t.ins(type(2));
	rep(i,sz(t)) cerr<<(t.find_by_order(i)->k.k)<<","<<(t.find_by_order(i)->k.k)<<" ";cerr<<endl;
	rrep(i,sz(t))
	{
		t.ers(t.find_by_order(sz(t)/2)->k);
		rep(i,sz(t)) cerr<<(t.find_by_order(i)->k.k)<<","<<(t.find_by_order(i)->k.k)<<" ";cerr<<endl;
	}
}
