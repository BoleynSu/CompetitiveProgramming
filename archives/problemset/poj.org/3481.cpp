//Boleyn Su's Template for Codeforces
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

#define lp for(;;)
#define rep(i,n) for (int i=0;i<(n);++i)
#define repf(i,a,b) for (int i=a;i<(b);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s,t) for (t::itr e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define cpy(x,y) memcpy((x),(y),sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) (x).resize(unique(all(x))-x.begin())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) printf("%."#prcs"f",(abs(x)<1e-##prcs)?0.0:x)
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() printf("Used: %.3fs\n",db(clock())/CLOCKS_PER_SEC);

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+20;
const db eps=1e-8;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}

typedef pii type;
enum{MAXNODE=1000000};
struct struct_node
{
	struct_node* c[2];
	int s;
	type k;
};
typedef struct_node* node;
static struct_node pool[MAXNODE];
static node top,null;
static void init_splay()
{
	top=pool,null=top++,null->c[0]=null->c[1]=null,null->s=0;
}
struct splay
{
	node rt;
	splay()
	{
		top->c[0]=top->c[1]=null,resize(top),top->k=mp(oo,0),rt=top++;
	}
	void resize(node x){x->s=1+x->c[0]->s+x->c[1]->s;}
	void zig(bool d)
	{
		node t=rt->c[d];
		rt->c[d]=null->c[d],null->c[d]=rt,rt=t;
	}
	void zigzig(bool d)
	{
		node t=rt->c[d]->c[d];
		rt->c[d]->c[d]=null->c[d],null->c[d]=rt->c[d];
		rt->c[d]=null->c[d]->c[!d],null->c[d]->c[!d]=rt,resize(rt);
		rt=t;
	}
	void finish()
	{
		rep(d,2)
		{
			node t=null->c[d],p=rt->c[!d];
			whl(t!=null)
			{
				t=null->c[d]->c[d];
				null->c[d]->c[d]=p;
				p=null->c[d],resize(p);
				null->c[d]=t;
			}
			rt->c[!d]=p;
		}
		resize(rt);
	}
	void select(int k)
	{
		lp
		{
			int t;
			bool d=k>(t=rt->c[0]->s);
			if (k==t||rt->c[d]==null) break;
			if (d) k-=t+1;
			bool dd=k>(t=rt->c[d]->c[0]->s);
			if (k==t||rt->c[d]->c[dd]==null)
			{
				zig(d);
				break;
			}
			if (dd) k-=t+1;
			d!=dd?zig(d),zig(dd):zigzig(d);
		}
		finish();
	}
	void search(type x)
	{
		lp
		{
			bool d=x>rt->k;
			if (rt->c[d]==null) break;
			bool dd=x>rt->c[d]->k;
			if (rt->c[d]->c[dd]==null)
			{
				zig(d);
				break;
			}
			d!=dd?zig(d),zig(dd):zigzig(d);
		}
		finish();
		if (x>rt->k) select(rt->c[0]->s+1);
	}
	node insert(type x)
	{
		search(x);
		node oldrt=rt;
		top->c[0]=oldrt->c[0],top->c[1]=oldrt,top->k=x,rt=top++,oldrt->c[0]=null,resize(oldrt),resize(rt);
		rtn rt;
	}
	node erase(type x)
	{
		search(x);
		node oldrt=rt;
		rt=rt->c[1],select(0),rt->c[0]=oldrt->c[0],resize(rt);
		rtn oldrt;//delete oldrt
	}
	node find(type x){rtn search(x),rt;}
	node at(int k){rtn select(k),rt;}
	int index(type x){rtn search(x),rt->c[0]->s;}
	int size(){rtn rt->s-1;}
};

int main()
{
	ios_base::sync_with_stdio(false);
	init_splay();
	splay sp;
	lp
	{
		int op;
		cin>>op;
		if (op==1)
		{
			pii x;
			cin>>x.y>>x.x;
			sp.insert(x);
		}
		else if(op==2)
		{
			pii x=sp.at(sz(sp)-1)->k;
			sp.erase(x);
			cout<<x.y<<endl;
		}
		else if(op==3)
		{
			pii x=sp.at(0)->k;
			sp.erase(x);
			cout<<x.y<<endl;
		}
		else break;
	}
}
