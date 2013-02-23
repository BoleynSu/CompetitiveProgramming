/*
 * Package: StandardCodeLibrary.Core
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#if __GNUC__>=4 and __GNUC_MINOR__>=6
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#endif
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
#define typeof decltype
#endif
using namespace std;

#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s) for (typeof((s).begin()) e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=(set)&((set)-1);subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0))
#ifdef DEBUG
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#else
#define endl (char('\n'))
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#endif

typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef vec<pii> vpii;
typedef vec<pdd> vpdd;
#if __GNUC__>=4 and __GNUC_MINOR__>=7
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#elif __GNUC__>=4 and __GNUC_MINOR__>=6
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#endif

int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

namespace BinarySearchTree
{
namespace SizeBalancedTree
{

typedef int type;
const int MAXNODE=20000000;
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

using BinarySearchTree::SizeBalancedTree::tree;

#define nd(l,r) (st[(((l)+(r))|((l)!=(r)))])
#define rt nd(l,r)
#define lrt nd(l,m)
#define rrt nd(m+1,r)
const int MAXN=100000;
typedef tree node;
node st[(MAXN<<1)-1];
void ins(int l,int r,int p,int x)
{
	if (p<l||r<p) ;
	else if (p<=l&&r<=p) rt.ins(x);
	else
	{
		int m=(l+r)>>1;
		ins(l,m,p,x),ins(m+1,r,p,x);
		rt.ins(x);
	}
}
void ers(int l,int r,int p,int x)
{
	if (p<l||r<p) ;
	else if (p<=l&&r<=p) rt.ers(x);
	else
	{
		int m=(l+r)>>1;
		ers(l,m,p,x),ers(m+1,r,p,x);
		rt.ers(x);
	}
}
int qry_left(int l,int r,int p,int x)
{
	if (p<l) rtn 0;
	else if (r<=p) rtn sz(rt)-rt.rnk(x+1);
	else
	{
		int m=(l+r)>>1;
		rtn qry_left(l,m,p,x)+qry_left(m+1,r,p,x);
	}
}
int qry_right(int l,int r,int p,int x)
{
	if (r<p) rtn 0;
	else if (p<=l) rtn rt.rnk(x);
	else
	{
		int m=(l+r)>>1;
		rtn qry_right(l,m,p,x)+qry_right(m+1,r,p,x);
	}
}
#undef rc
#undef lc
#undef rt
#undef nd

int main()
{
	int n,m;
	cin>>n>>m;
	vi a(n),p(n);
	lli sum=0;
	rep(i,n)
	{
		cin>>a[i],p[--a[i]]=i;
		ins(0,n-1,i,a[i]);
		sum+=qry_left(0,n-1,i,a[i])+qry_right(0,n-1,i,a[i]);
	}
	rep(i,m)
	{
		cout<<sum<<endl;
		int ai;
		cin>>ai,--ai;
		sum-=qry_left(0,n-1,p[ai]-1,ai)+qry_right(0,n-1,p[ai]+1,ai);
		ers(0,n-1,p[ai],ai);
	}
}
