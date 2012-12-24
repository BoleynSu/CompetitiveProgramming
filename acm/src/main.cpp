/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-12-21
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
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define forin(i,charset) for (cstr i=charset;*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define rnk order_of_key
#define sel find_by_order
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(x))
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
#define runtime() cerr
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
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Last Update: 2012-12-21
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * add_edge:
 * 输入int u,v,c
 * add_edge(u,v,c) 加一条u到v的容量为c的有向边,加一条v到u的容量为0的有向边
 * build_graph:构图,详细见函数内的注释
 * dinic:
 * 输出int
 * dinic()=最大流
 * */

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace Dinic_sAlgorithm
{

#define oo 0x7f7f7f7f
const int MAXV=1000000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v,c;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
int qh,qt;
void add_edge(int u,int v,int c)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
bool relabel()
{
	fl(d,oo),d[q[qh=qt=0]=T]=0;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge i=adj[u];i;i=i->n)
			if (i->b->c&&cmin(d[i->v],d[u]+1))
				if ((q[++qt]=i->v)==S) rtn true;
	}
	rtn false;
}
//递归增广
int augment(int u,int e)
{
	if (u==T) return e;
	int f=0;
	for (edge i=adj[u];i&&e;i=i->n)
		if (i->c&&d[u]==d[i->v]+1)
			if (int df=augment(i->v,min(e,i->c)))
				i->c-=df,i->b->c+=df,e-=df,f+=df;
	return f;
}
//非递归增广
int st,us[MAXV],es[MAXV],fs[MAXV],f,df,ret;
edge is[MAXV],cur[MAXV];
#define push(u,e) us[st+1]=u,es[st+1]=e,fs[st+1]=0,is[st+1]=cur[u],st++
#define pop() df=fs[st--],st>=0?is[st]->c-=df,is[st]->b->c+=df,es[st]-=df,is[st]=is[st]->n,fs[st]+=df:f+=df
int improved_augment(int u,int e)
{
    f=0,st=-1,cpy(cur,adj);
    push(u,e);
    whl(st>=0)
    {
        if (us[st]==T) fs[st]=es[st],pop();
        else if (!is[st]||!es[st]) pop();
        else if (is[st]->c&&d[us[st]]==d[is[st]->v]+1) cur[us[st]]=is[st],push(is[st]->v,min(es[st],is[st]->c));
        else is[st]=is[st]->n;
    }
    rtn f;
}
int dinic()
{
	int f=0;
	while (relabel()) f+=improved_augment(S,oo);
	return f;
}
void build_network()
{
	top=pool,clr(adj);
	//S,T;//源,汇
	//add_edge(u,v,c);
}

}
}
}

/*
 * Package: StandardCodeLibrary.GraphTheory.Edmonds'sMatchingAlgorithm
 * Last Update: 2012-12-21
 * Usage:
 * MAXV:需要为点分配多少空间,点一定要从0到V-1，即MAXV应该等于最大点数
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * V:点数
 * add_edge:
 * 输入int u,v
 * add_edge(u,v) 加一条u到v的边和一条v到u的边
 * build_graph:构图,详细见函数内的注释
 * edmonds:
 * 输出int
 * edmonds()=最大匹配数
 * 附加输出:
 * 如果match[u]==NOT_NODE则u没有被匹配
 * 否者u与match[u]匹配
 * */

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace Edmonds_sMatchingAlgorithm
{

const int MAXV=100;
const int MAXE=MAXV*MAXV*2;
const int NOT_NODE=-1;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
int V;
struct_edge pool[MAXE];
edge top;
edge adj[MAXV];
void build_graph()
{
	top=pool;
	clr(adj);
	//V;//点数
	//Warning:
	//V必须严格等于图中的点的数目
	//add_edge(u,v);
}
void add_edge(int u,int v)
{
	top->v=v,top->n=adj[u],adj[u]=top++;
	top->v=u,top->n=adj[v],adj[v]=top++;
}
int match[MAXV];
int qh,qt;
int q[MAXV];
bool inq[MAXV];
int father[MAXV];
int base[MAXV];
bool ib[MAXV];
bool ip[MAXV];
int LCA(int root,int u,int v)
{
	clr(ip);
	lp
	{
		ip[u=base[u]]=true;
		if (u==root) break;
		u=father[match[u]];
	}
	lp
	{
		if (ip[v=base[v]]) rtn v;
		else v=father[match[v]];
	}
}
void mark_blossom(int lca,int u)
{
	whl(base[u]!=lca)
	{
		int v=match[u];
		ib[base[u]]=true;
		ib[base[v]]=true;
		u=father[v];
		if (base[u]!=lca) father[u]=v;
	}
}
void blossom_contraction(int s,int u,int v)
{
	int lca=LCA(s,u,v);
	clr(ib);
	mark_blossom(lca,u);
	mark_blossom(lca,v);
	if (base[u]!=lca) father[u]=v;
	if (base[v]!=lca) father[v]=u;
	rep(u,V)
		if (ib[base[u]])
		{
			base[u]=lca;
			if (!inq[u]) inq[q[++qt]=u]=true;
		}
}
int find_augmenting_path(int s)
{
	clr(inq),fl(father,NOT_NODE);
	for (int i=0;i<V;i++) base[i]=i;
	inq[q[qh=qt=0]=s]=true;
	whl(qh<=qt)
	{
		int u=q[qh++];
		for (edge e=adj[u];e;e=e->n)
		{
			int v=e->v;
			if (base[u]!=base[v]&&match[u]!=v)
			{
				if ((v==s)||(match[v]!=NOT_NODE&&father[match[v]]!=NOT_NODE))
					blossom_contraction(s,u,v);
				else if (father[v]==NOT_NODE)
				{
					father[v]=u;
					if (match[v]==NOT_NODE) rtn v;
					else if (!inq[match[v]]) inq[q[++qt]=match[v]]=true;
				}
			}
		}
	}
	rtn NOT_NODE;
}
int augment_path(int s,int t)
{
	int u,v,w;
	u=t;
	whl(u!=NOT_NODE)
	{
		v=father[u];
		w=match[v];
		match[v]=u;
		match[u]=v;
		u=w;
	}
	rtn t!=NOT_NODE;
}
int edmonds()
{
	int matchc=0;
	fl(match,NOT_NODE);
	for (int u=0;u<V;u++)
		if (match[u]==NOT_NODE)
		matchc+=augment_path(u,find_augmenting_path(u));
	rtn matchc;
}

}
}
}

/*
 * Package: StandardCodeLibrary.GraphTheory.MinCostMaxFlow
 * Last Update: 2012-12-22
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * add_edge:
 * 输入int u,v,c,d
 * add_edge(u,v,c,d) 加一条u到v的容量为c代价为d的有向边,加一条v到u的容量为0代价为-d的有向边
 * build_graph:构图,详细见函数内的注释
 * min_cost_max_flow:
 * min_cost_max_flow(最大流,最小费用)
 * */

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace MinCostMaxFlow
{

#define oo 0x7f7f7f7f
const int MAXE=1000000;
const int MAXV=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v,c,d;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
bool inq[MAXV];
int qh,qt;
void add_edge(int u,int v,int c,int d)
{
	top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
edge p[MAXV];
void min_cost_max_flow(int& flow,int& cost)
{
	flow=0,cost=0;
	lp
	{
		fl(d,oo),inq[q[qh=qt=0]=S]=true,d[S]=0,p[S]=0;
		whl(qh<=qt)
		{
			int u=q[(qh++)%MAXV];
			inq[u]=false;
			for (edge i=adj[u];i;i=i->n)
				if (i->c&&cmin(d[i->v],d[u]+i->d))
				{
					if (!inq[i->v]) inq[q[(++qt)%MAXV]=i->v]=true;
					p[i->v]=i;
				}
		}
		if (d[T]==oo) break;
		else
		{
			int delta=oo;
			for (edge i=p[T];i;i=p[i->b->v]) cmin(delta,i->c);
			for (edge i=p[T];i;i=p[i->b->v]) i->c-=delta,i->b->c+=delta;
			flow+=delta;
			cost+=d[T]*delta;
		}
	}
}
void build_network()
{
	top=pool,clr(adj);
	//S,T;//源,汇
	//add_edge(u,v,c,d);
}

}
}
}

/*
 * Package: StandardCodeLibrary.NumberTheory
 * Last Update: 2012-12-21
 * Description:
 * O(n)的筛法求素数表;
 * 带mod的乘法;
 * 带mod的指数函数;
 * Rabin-Miller素数测试;
 * Pollard's rho大数分解;
 * 计算phi;
 * 扩展gcd;
 * 中国剩余定理;
 * 指数循环节;
 * */

namespace StandardCodeLibrary
{
namespace NumberTheory
{

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
enum{MAXP=10000000,MAXPS=664579};
bool isp[MAXP+1];//isp[x]=x是否为素数
int pp[MAXP+1];//pp[x]=x在素数表中的位置(从0开始)
int fac[MAXP+1];//fax[x]=x最小的质因子(x<=1时无意义)
int ps;//素数表的大小
int p[MAXPS];//素数表
void make_prime_table()
{
	fl(isp,true);
	isp[0]=isp[1]=false;
	ft(i,2,MAXP)
	{
		if (isp[i]) pp[p[ps]=i]=ps,ps++,fac[i]=i;
		for (int j=0;p[j]*i<=MAXP;j++)
		{
			isp[p[j]*i]=false,fac[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
}

//带mod的乘法
lli mulWithMod(lli x,lli y,lli z)
{
	lli ret=0;
	x%=z;
	y%=z;
	whl(y)
	{
		if (y&1)
		{
			ret+=x;
			if (ret>=z) ret-=z;
		}
		x<<=1;
		if (x>=z) x-=z;
		y>>=1;
	}
	rtn ret;
}

//带mod的指数函数
lli powWithMod(lli x,lli y,lli z)
{
	lli ret=1;
	x%=z;
	whl(y)
	{
		if (y&1) ret=mulWithMod(ret,x,z);
		y>>=1;
		x=mulWithMod(x,x,z);
	}
	rtn ret;
}

//Rabin-Miller素数测试
bool isProbablePrime(lli n,lli k=50)
{
	if (n<=1) rtn false;
	else if (n<=3) rtn true;
	else
	{
		lli d=n-1;
		whl(!(d&1)) d>>=1;
		rep(i,k)
		{
			lli a=rand()%(n-3)+2;//2 to n-2
			lli x=powWithMod(a,d,n);
			if (x==1) continue;
			whl(d!=n-1&&x!=n-1&&x!=1)
			{
				x=mulWithMod(x,x,n);
				d<<=1;
			}
			if (x!=n-1) rtn false;
		}
		rtn true;
	}
}

//Pollard's rho大数分解
lli factor(lli n,lli k=50)
{
	if (isProbablePrime(n,k)) rtn n;
	lp
	{
		lli d=1,x=rand()%(n-1)+1,//1 to n-1
				y=rand()%(n-1)+1,//1 to n-1
				c=rand()%n;
		if (c==0) c++;//c!=0
		if (c==n-2) c++;//c!=n-2
		lli loop=0;
		whl(d==1)
		{
			loop++;
			if (((-loop)&loop)==loop) y=x;
			x=(mulWithMod(x,x,n)+c)%n;
			if (x==y) break;
			d=gcd(y-x+n,n);
			if (d!=1&&d!=n) rtn factor(d,k);
		}
	}
}

//计算phi
lli phi(lli x,lli k=50)
{
	lli ret=x;
	whl(x!=1)
	{
		lli d=factor(x,k);//如果是小范围的 此处可用fac[x]代替
		ret/=d;
		ret*=d-1;
		whl(x%d==0) x/=d;
	}
	rtn ret;
}

//扩展gcd
lli gcd(lli a,lli b,lli& x,lli& y)
{
	if (b)
	{
		lli g=gcd(b,a%b,y,x);
		rtn y-=a/b*x,g;
	}
	else rtn x=1,y=0,a;
}

//中国剩余定理
//一般地,中国剩余定理是指若有一些两两互质的整数m[i],则对任意的整数a[i],以下联立同余方程组对模m[i]有公解
//x mod m[i]=a[i]
lli chinese_remainder(lli n,lli m[],lli a[])
{
	lli lcm=1;
	rep(i,n) lcm*=m[i];
	lli ans=0;
	rep(i,n)
	{
		lli Mi=lcm/m[i],x,y;
		gcd(Mi,m[i],x,y);
		ans+=Mi*x*a[i];
		ans%=lcm;
	}
	if (ans<0) ans+=lcm;
	rtn ans;
}

//指数循环节
//如果(a,p)=1		a^x%p=a^(x%phi(p))%p
//否则若x>=phi(p)	a^x%p=a^(x%phi(p)+phi(p))%p
lli mod(lli x,lli phip)
{
	rtn x>=phip?x%phip+phip:x;
}

}
}


int main()
{
}
