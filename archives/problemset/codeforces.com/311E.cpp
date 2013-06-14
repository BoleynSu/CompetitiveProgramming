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
#include <ext/rope>
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
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
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
#define rev(x) reverse(all(x))
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
#if __GNUC__>=4 and __GNUC_MINOR__>=6
using __gnu_cxx::rope;
#endif
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
db gam=0.5772156649015328606;
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
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
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
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;
/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Usage:
 * MAXV:需要为点分配多少空间,点只要在0到MAXV-1就可以了，即MAXV应该大于最大编号
 * MAXE:需要为边分配多少空间,一条边对应一条正向边和一条反向边，即MAXE要等于实际最大边数*2
 * build_graph:构图,详细见函数内的注释
 * add_edge:
 * 输入int u,v;flow_type c;
 * add_edge(u,v,c) 加一条u到v的容量为c的有向边,加一条v到u的容量为0的有向边
 * dinic:
 * 输出flow_type
 * dinic()=最大流
 * */

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace DinicsAlgorithm
{

const int oo=0x7f7f7f7f;
const int MAXV=1000000;
const int MAXE=1000000;
typedef int flow_type;
typedef struct struct_edge* edge;
struct struct_edge{int v;flow_type c;edge n,b;}pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
void build_graph(int s,int t)
{
	top=pool,clr(adj);
	S=s,T=t;//源,汇
	//add_edge(u,v,c);
}
void add_edge(int u,int v,flow_type c)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
	if (u==v) adj[u]->n->b=adj[u],adj[v]->b=adj[v]->n;//防止add_edge(u,u,c)时出现RE
}
int d[MAXV];
int q[MAXV];
int qh,qt;
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
flow_type augment(int u,flow_type e)
{
	if (u==T) return e;
	flow_type f=0;
	for (edge i=adj[u];i&&e;i=i->n)
		if (i->c&&d[u]==d[i->v]+1)
			if (flow_type df=augment(i->v,min(e,i->c)))
				i->c-=df,i->b->c+=df,e-=df,f+=df;
	return f;
}
//非递归增广
int st,us[MAXV];
flow_type es[MAXV],fs[MAXV],f,df;
edge is[MAXV],cur[MAXV];
#define push(nu,ne) u=nu,e=ne,st++,us[st]=u,es[st]=e,fs[st]=0,is[st]=cur[u]
#define pop() df=fs[st],st--,st>=0?is[st]->c-=df,is[st]->b->c+=df,es[st]-=df,is[st]=is[st]->n,fs[st]+=df:f+=df
flow_type improved_augment(int u,flow_type e)
{
	f=0,st=-1,cpy(cur,adj),push(u,e);
	whl(st>=0)
	{
		if (us[st]==T) fs[st]=es[st],pop();
		else if (!is[st]||!es[st]) pop();
		else if (is[st]->c&&d[us[st]]==d[is[st]->v]+1) cur[us[st]]=is[st],push(is[st]->v,min(es[st],is[st]->c));
		else is[st]=is[st]->n;
	}
	rtn f;
}
#undef pop
#undef push
flow_type dinic()
{
	flow_type f=0;
	while (relabel()) f+=improved_augment(S,oo);
	return f;
}

}
}
}
using namespace StandardCodeLibrary::GraphTheory::DinicsAlgorithm;

//最小割
//参考 胡伯涛 2007年国家集训队论文 《最小割模型在信息学竞赛中的应用》

int main()
{
	int n,m,g;
	cin>>n>>m>>g;
	int earn=0;
	//S for sex = 0
	//T for sex = 1
	build_graph(n+m,n+m+1);
	vi sex(n),v(n);
	cin>>sex>>v;
	rep(i,n)
	{
		if (sex[i]==0)
		{
			add_edge(S,i,v[i]);
			add_edge(i,T,0);
		}
		else
		{
			add_edge(S,i,0);
			add_edge(i,T,v[i]);
		}
	}
	vi wantedSex(m);
	vi w(m);
	vvi lst(m);
	vi isFriend(m);
	rep(i,m)
	{
		int k;
		cin>>wantedSex[i]>>w[i]>>k;
		lst[i]=vi(k);
		cin>>lst[i]>>isFriend[i];
		rep(j,sz(lst[i])) lst[i][j]--;
	}
	rep(i,m)
	{
		earn+=w[i];
		if (wantedSex[i]==0)
		{
			add_edge(S,n+i,isFriend[i]?w[i]+g:w[i]);
			add_edge(n+i,T,0);
		}
		else
		{
			add_edge(S,n+i,0);
			add_edge(n+i,T,isFriend[i]?w[i]+g:w[i]);
		}
		rep(j,sz(lst[i]))
		{
			if (sex[lst[i][j]]==0&&wantedSex[i]==1)
				add_edge(lst[i][j],n+i,::oo);
			if (sex[lst[i][j]]==1&&wantedSex[i]==0)
				add_edge(n+i,lst[i][j],::oo);
		}
		rep(j,i)
		{
			bool same=false;
			rep(k,sz(lst[i]))
				rep(l,sz(lst[j]))
					if (lst[i][k]==lst[j][l])
						same=true;
			if (same)
			{
				if (wantedSex[i]==0&&wantedSex[j]==1)
					add_edge(n+i,n+j,::oo);
				if (wantedSex[i]==1&&wantedSex[j]==0)
					add_edge(n+j,n+i,::oo);
			}
		}
	}
	int lose=dinic();
	cout<<earn-lose<<endl;
}

