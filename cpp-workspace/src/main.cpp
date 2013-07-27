/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间
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
using namespace std;

//用于减少代码量的宏
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rrepf(i,a,b) for (int i=(a)-1;i>=(b);--i)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))

//调试相关的宏
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型
typedef unsigned long long int lli;
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

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
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
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化
struct Initializer
{
#ifndef DEBUG
	Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
	~Initializer(){runtime();}
#endif
}initializer;

////非标准
//#define feach(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//using __gnu_cxx::rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount

const int MAXV=1000000;
const int MAXE=1000000;
typedef struct struct_edge* edge;
struct struct_edge{int v;edge n;}pool[MAXE];
edge top;
int V;
edge adj[MAXV];
void build_graph(int v)
{
	top=pool;
	memset(adj,0,sizeof(adj));
	V=v;
	//add_edge(u,v);
}
void add_edge(int u,int v)
{
	top->v=v,top->n=adj[u],adj[u]=top++;
}
int ord;
int dfn[MAXV];
int low[MAXV];
int stks;
int stk[MAXV];
bool ins[MAXV];
int cnt;
int bl[MAXV];
void dfs(int u)
{
	dfn[u]=low[u]=++ord;
	ins[stk[stks++]=u]=true;
	for (edge i=adj[u];i;i=i->n)
		if (!dfn[i->v]) dfs(i->v),cmin(low[u],low[i->v]);
		else if (ins[i->v]) cmin(low[u],dfn[i->v]);
	if (dfn[u]==low[u])
	{
		cnt++;
		int v;
		do ins[v=stk[--stks]]=false,bl[v]=cnt;
		whl(v!=u);
	}
}
void tarjan()
{
	clr(dfn);
	rep(i,V) if (!dfn[i]) dfs(i);
}

#define T(x) (x)
#define F(x) ((x)+N)
int N;
void build_2sat(int n)
{
	N=n;
	build_graph(N*2);
	/*
	A[x]				=add_edge(F(x),T(x));
	NOT A[x]			=add_edge(T(x),F(x));
	A[x] AND A[y]		=add_edge(F(x),T(x)),add_edge(F(y),T(y));
	A[x] AND NOT A[y]	=add_edge(F(x),T(x)),add_edge(T(y),F(y));
	A[x] OR A[y]		=add_edge(F(x),T(y)),add_edge(F(y),T(x));
	A[x] OR NOT A[y]	=add_edge(F(x),F(y)),add_edge(T(y),T(x));
	NOT (A[x] AND A[y])	=add_edge(T(x),F(y)),add_edge(T(y),F(x));
	NOT (A[x] OR A[y])	=add_edge(T(x),F(x)),add_edge(T(y),F(y));
	A[x] XOR A[y]		=add_edge(F(x),T(y)),add_edge(F(y),T(x)),add_edge(T(x),F(y)),add_edge(T(y),F(x));
	NOT (A[x] XOR A[y])	=add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
	A[x] XOR NOT A[y]	=add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
	u到v有边表示选u必选v
	*/
}
bool possible_2sat()
{
	tarjan();
	rep(i,N) if (bl[T(i)]==bl[F(i)]) rtn false;
	rtn true;
}

int main()
{
	int n;
	whl(cin>>n)
	{
		vvi b(n,vi(n));
		cin>>b;
		bool yes=true;
		rep(d,31)
		{
			build_2sat(n);
			rep(i,n) rep(j,n)
			{
				int dgt=(b[i][j]>>d)&1;
				if (i==j)
				{
					if (dgt&1) yes=false;
				}
				else
				{
					if ((i&1)&&(j&1))
					{
						if (dgt) add_edge(F(i),T(j)),add_edge(F(j),T(i));
						else add_edge(T(i),F(i)),add_edge(T(j),F(j));
					}
					else if (!(i&1)&&!(j&1))
					{
						if (dgt) add_edge(F(i),T(i)),add_edge(F(j),T(j));
						else add_edge(T(i),F(j)),add_edge(T(i),F(j));
					}
					else
					{
						if (dgt) add_edge(F(i),T(j)),add_edge(F(j),T(i)),add_edge(T(i),F(j)),add_edge(T(j),F(i));
						else add_edge(F(i),F(j)),add_edge(F(j),F(i)),add_edge(T(i),T(j)),add_edge(T(j),T(i));
					}
				}
			}
			if (!possible_2sat()) yes=false;
		}
		cout<<(yes?"YES":"NO")<<endl;
	}
}
