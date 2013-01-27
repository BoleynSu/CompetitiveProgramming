
//begin #include <Core>
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
//end #include <Core>

//begin #include <GraphTheory.Dinic'sAlgorithm>
/*
 * Package: StandardCodeLibrary.GraphTheory.Dinic'sAlgorithm
 * Last Update: 2012-12-21
 * Usage:
 * MAXV:Ã©Å“â‚¬Ã¨Â¦ÂÃ¤Â¸ÂºÃ§â€šÂ¹Ã¥Ë†â€ Ã©â€¦ÂÃ¥Â¤Å¡Ã¥Â°â€˜Ã§Â©ÂºÃ©â€”Â´,Ã§â€šÂ¹Ã¥ÂÂªÃ¨Â¦ÂÃ¥Å“Â¨0Ã¥Ë†Â°MAXV-1Ã¥Â°Â±Ã¥ÂÂ¯Ã¤Â»Â¥Ã¤Âºâ€ Ã¯Â¼Å’Ã¥ÂÂ³MAXVÃ¥Âºâ€Ã¨Â¯Â¥Ã¥Â¤Â§Ã¤ÂºÅ½Ã¦Å“â‚¬Ã¥Â¤Â§Ã§Â¼â€“Ã¥ÂÂ·
 * MAXE:Ã©Å“â‚¬Ã¨Â¦ÂÃ¤Â¸ÂºÃ¨Â¾Â¹Ã¥Ë†â€ Ã©â€¦ÂÃ¥Â¤Å¡Ã¥Â°â€˜Ã§Â©ÂºÃ©â€”Â´,Ã¤Â¸â‚¬Ã¦ÂÂ¡Ã¨Â¾Â¹Ã¥Â¯Â¹Ã¥Âºâ€Ã¤Â¸â‚¬Ã¦ÂÂ¡Ã¦Â­Â£Ã¥Ââ€˜Ã¨Â¾Â¹Ã¥â€™Å’Ã¤Â¸â‚¬Ã¦ÂÂ¡Ã¥ÂÂÃ¥Ââ€˜Ã¨Â¾Â¹Ã¯Â¼Å’Ã¥ÂÂ³MAXEÃ¨Â¦ÂÃ§Â­â€°Ã¤ÂºÅ½Ã¥Â®Å¾Ã©â„¢â€¦Ã¦Å“â‚¬Ã¥Â¤Â§Ã¨Â¾Â¹Ã¦â€¢Â°*2
 * add_edge:
 * Ã¨Â¾â€œÃ¥â€¦Â¥int u,v,c
 * add_edge(u,v,c) Ã¥Å  Ã¤Â¸â‚¬Ã¦ÂÂ¡uÃ¥Ë†Â°vÃ§Å¡â€žÃ¥Â®Â¹Ã©â€¡ÂÃ¤Â¸ÂºcÃ§Å¡â€žÃ¦Å“â€°Ã¥Ââ€˜Ã¨Â¾Â¹,Ã¥Å  Ã¤Â¸â‚¬Ã¦ÂÂ¡vÃ¥Ë†Â°uÃ§Å¡â€žÃ¥Â®Â¹Ã©â€¡ÂÃ¤Â¸Âº0Ã§Å¡â€žÃ¦Å“â€°Ã¥Ââ€˜Ã¨Â¾Â¹
 * build_graph:Ã¦Å¾â€žÃ¥â€ºÂ¾,Ã¨Â¯Â¦Ã§Â»â€ Ã¨Â§ÂÃ¥â€¡Â½Ã¦â€¢Â°Ã¥â€ â€¦Ã§Å¡â€žÃ¦Â³Â¨Ã©â€¡Å
 * dinic:
 * Ã¨Â¾â€œÃ¥â€¡Âºint
 * dinic()=Ã¦Å“â‚¬Ã¥Â¤Â§Ã¦ÂµÂ
 * */

namespace StandardCodeLibrary
{
namespace GraphTheory
{
namespace Dinic_sAlgorithm
{

const int oo=0x7f7f7f7f;
const int MAXV=100000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v,c;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T;
edge adj[MAXV];
void add_edge(int u,int v,int c)
{
	top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
	top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
	adj[u]->b=adj[v],adj[v]->b=adj[u];
}
void build_graph()
{
	top=pool,clr(adj);
	//S,T;//Ã¦ÂºÂ,Ã¦Â±â€¡
	//add_edge(u,v,c);
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
//Ã©â‚¬â€™Ã¥Â½â€™Ã¥Â¢Å¾Ã¥Â¹Â¿
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
//Ã©ÂÅ¾Ã©â‚¬â€™Ã¥Â½â€™Ã¥Â¢Å¾Ã¥Â¹Â¿
int st,us[MAXV],es[MAXV],fs[MAXV],f,df;
edge is[MAXV],cur[MAXV];
#define push(nu,ne) u=nu,e=ne,st++,us[st]=u,es[st]=e,fs[st]=0,is[st]=cur[u]
#define pop() df=fs[st],st--,st>=0?is[st]->c-=df,is[st]->b->c+=df,es[st]-=df,is[st]=is[st]->n,fs[st]+=df:f+=df
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

}
}
}
//end #include <GraphTheory.Dinic'sAlgorithm>
using namespace StandardCodeLibrary::GraphTheory::Dinic_sAlgorithm;

int main()
{
	int N;
	cin>>N;
	ft(i,1,N)
	{
		int x,y;
		cin>>x>>y;
	}
	int M;
	cin>>M;
	vec<pr<edge,edge> > ans(M);
	build_graph();
	S=1,T=N;
	rep(i,M)
	{
		int u,v,c;
		cin>>u>>v>>c;
		ans[i].x=top;
		add_edge(u,v,c);
		ans[i].y=top;
		add_edge(v,u,c);
	}
	cout<<dinic()<<endl;
	rep(i,M) cout<<(ans[i].x->b->c>=ans[i].y->b->c?ans[i].y->v:ans[i].x->v)<<" "<<(ans[i].x->b->c>=ans[i].y->b->c?ans[i].x->v:ans[i].y->v)<<" "<<(ans[i].x->b->c>=ans[i].y->b->c?ans[i].x->b->c-ans[i].y->b->c:ans[i].y->b->c-ans[i].x->b->c)<<endl;
}
