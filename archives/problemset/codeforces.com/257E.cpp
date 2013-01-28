//begin #include <Core>
/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-1-4
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
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;
#if __GNUC__>=4 and __GNUC_MINOR__>=7
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#elif __GNUC__>=4 and __GNUC_MINOR__>=6
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#endif

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+10;
const db eps=1e-10;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename ostream,typename type>ostream& operator<<(ostream& cout,const pr<type,type>& x){rtn cout<<"("<<x.x<<","<<x.y<<")";}
template<typename type>pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;
//end #include <Core>

struct segtr
{
#define nd(l,r) st[((l)+(r))|((l)!=(r))]
#define rt nd(l,r)
#define lrt nd(l,m)
#define rrt nd(m+1,r)
static const lli MAXN=100000;
struct node{vec<pii> lst;lli sz;};
node st[(MAXN<<1)-1];
void upd_ins(lli l,lli r,lli p,pii v)
{
	if (p<l||r<p) rtn;
	else if (p<=l&&r<=p) rt.lst.pb(v),rt.sz=sz(rt.lst);
	else
	{
		lli m=(l+r)>>1;
		upd_ins(l,m,p,v),upd_ins(m+1,r,p,v);
		rt.sz=lrt.sz+rrt.sz;
	}
}
void upd_clr(lli l,lli r,lli p)
{
	if (p<l||r<p) rtn;
	else if (p<=l&&r<=p) rt.lst.clear(),rt.sz=sz(rt.lst);
	else
	{
		lli m=(l+r)>>1;
		upd_clr(l,m,p),upd_clr(m+1,r,p);
		rt.sz=lrt.sz+rrt.sz;
	}
}
lli qry(lli l,lli r,lli L,lli R)
{
	if (R<l||r<L) rtn 0;
	else if (L<=l&&r<=R) rtn rt.sz;
	else
	{
		lli m=(l+r)>>1;
		rtn qry(l,m,L,R)+qry(m+1,r,L,R);
	}
}
#undef rrt
#undef lrt
#undef rt
#undef nd
};
segtr bst;
segtr est;
set<lli> es;

int main()
{
	lli n,m;
	cin>>n>>m;
	vec<pr<pii,pii> > dat(n);
	vec<lli> ans(n);
	rep(i,n) cin>>dat[i].x.x>>dat[i].y.x>>dat[i].y.y,--dat[i].y.x,--dat[i].y.y,dat[i].x.y=i;
	srt(dat);
	lli cur=0,curt=0;
	lli datp=0;
	lp
	{
		lli delta=+oo;

		lli dwn=bst.qry(0,m-1,0,cur)+est.qry(0,m-1,0,cur);
		lli up=bst.qry(0,m-1,cur,m-1)+est.qry(0,m-1,cur,m-1);

		if (up||dwn)
			if (up>=dwn) cmin(delta,*es.lb(cur)-cur);
			else cmin(delta,cur-*--es.ub(cur));

		if (datp<n) cmin(delta,dat[datp].x.x-curt);

		if (delta==oo) break;

		if (curt==dat[datp].x.x)
		{
			bst.upd_ins(0,m-1,dat[datp].y.x,mp(dat[datp].y.y,dat[datp].x.y));
			es.ins(dat[datp].y.x);
			datp++;
		}
		else if (sz(est.st[cur<<1].lst))
		{
			rep(i,sz(est.st[cur<<1].lst))
					ans[est.st[cur<<1].lst[i].x]=curt;
			est.upd_clr(0,m-1,cur);
			if (!bst.qry(0,m-1,cur,cur)) es.ers(cur);
		}
		else if (sz(bst.st[cur<<1].lst))
		{
			rep(i,sz(bst.st[cur<<1].lst))
				est.upd_ins(0,m-1,bst.st[cur<<1].lst[i].x,mp(bst.st[cur<<1].lst[i].y,0)),
				es.ins(bst.st[cur<<1].lst[i].x);
			bst.upd_clr(0,m-1,cur);
			if (!est.qry(0,m-1,cur,cur)) es.ers(cur);
		}

		if (up||dwn)
			if (up>=dwn) cur=cur+delta;
			else cur=cur-delta;
		curt+=delta;
	}
	rep(i,n) cout<<ans[i]<<endl;
}

