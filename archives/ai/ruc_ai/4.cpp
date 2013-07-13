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
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
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

//常用数据类型
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

//非标准
#define feach(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using __gnu_cxx::rope;
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#define ctz __builtin_ctz
#define clz __builtin_clz
#define bc __builtin_popcount

struct Config
{
	int h,w;
	vvi t,b,o;
	int p,k;
	Config()
	{
		cin>>h>>w;
		t=b=o=vvi(h,vi(w));
		cin>>t>>b>>o;
		cin>>p>>k;
	}
}config;

struct Graph
{
	map<pii,int> id;
	vpii nd;
	vi b;
	vvi adj;
	Graph()
	{
		rep(i,config.h) rep(j,config.w) if (config.t[i][j]==0)
		{
			id.insert(mp(mp(i,j),sz(id)));
			nd.pb(mp(i,j));
			b.pb(config.b[i][j]);
		}
		adj=vvi(sz(nd));
		rep(i,sz(nd))
		{
			rep(d,4)
			{
				pii u=nd[i]+mp(dx[d],dy[d]);
				if (id.count(u))
					adj[i].pb(id[u]);
			}
			rep(j,sz(adj[i]))
				repf(k,j,sz(adj[i]))
					if (b[adj[i][j]]<b[adj[i][k]])
						swap(adj[i][j],adj[i][k]);
		}
	}
}graph;

struct Strategy
{
	deque<pii> d;
	deque<pr<pii,int> > a;
};

struct Undo
{
	int ttl;
	vpii n;
	vpii o;
};

struct GraphState
{
	int p;
	int cr;
	int ttl;
	vi o,n;
	vec<Undo> udl;
	GraphState()
	{
	}
	GraphState(int p,int cr):p(p),cr(cr),o(sz(graph.nd)),n(sz(graph.nd))
	{
	}
	GraphState(const Config& c):p(c.p),cr(0),o(sz(graph.nd)),n(sz(graph.nd))
	{
		rep(i,c.h) rep(j,c.w) if (graph.id.count(mp(i,j)))
			o[graph.id[mp(i,j)]]=c.o[i][j];
	}
	int me() const
	{
		rtn p;
	}
	int enemy() const
	{
		rtn 3-p;
	}
	int need(int to) const
	{
		int B=n[to];
		int S=graph.b[to];
		int K=config.k;
		int C=K*B/10+S;
		rtn C;
	}
	void getTotal()
	{
		ttl=0;
		rep(i,sz(graph.nd)) if (o[i]==me()) ttl+=graph.b[i];
	}
	void distribute(int p,int to,int num)
	{
		Undo ud;
		ud.ttl=ttl;
		ud.n.pb(mp(to,n[to]));
		udl.pb(ud);
		ttl-=num;
		n[to]+=num;
	}
	void attack(int p,int from,int to,int num)
	{
		int A=num;
		int B=n[to];
		int S=graph.b[to];
		int K=config.k;
		int C=K*B/10+S;
		if (A>C)
		{
			Undo ud;
			ud.ttl=ttl;
			ud.n.pb(mp(from,n[from]));
			ud.n.pb(mp(to,n[to]));
			ud.o.pb(mp(to,o[to]));
			udl.pb(ud);
			o[to]=p;
			n[to]=A-C;
			n[from]-=A;
		}
		else
		{
			int D=min((A-1)*10/K,B);
			Undo ud;
			ud.ttl=ttl;
			ud.n.pb(mp(from,n[from]));
			ud.n.pb(mp(to,n[to]));
			udl.pb(ud);
			n[to]-=D;
			n[from]-=A;
		}
	}
	void undo()
	{
		Undo& ud=udl.back();
		ttl=ud.ttl;
		rep(i,sz(ud.n)) n[ud.n[i].x]=ud.n[i].y;
		rep(i,sz(ud.o)) o[ud.o[i].x]=ud.o[i].y;
		udl.pop_back();
	}
	void update()
	{
		int t;
		whl(cin>>t,~t)
		{
			if (t==1)
			{
				pii p;
				int n;
				cin>>p>>n;
				distribute(enemy(),graph.id[p],n);
			}
			if (t==2)
			{
				pii p1,p2;
				int n;
				cin>>p1>>p2>>n;
				attack(enemy(),graph.id[p1],graph.id[p2],n);
			}
		}
		cr++;
	}
	void apply(const Strategy& s)
	{
		rep(i,sz(s.d))
		{
			distribute(me(),s.d[i].x,s.d[i].y),
			cout<<"1 "<<graph.nd[s.d[i].x]<<" "<<s.d[i].y<<endl;
		}
		rep(i,sz(s.a))
			attack(me(),s.a[i].x.x,s.a[i].x.y,s.a[i].y),
			cout<<"2 "<<graph.nd[s.a[i].x.x]<<" "<<graph.nd[s.a[i].x.y]<<" "<<s.a[i].y<<endl;
		cout<<"-1"<<endl;
		cr++;
	}
	void show() const
	{
		rep(i,config.h) rep(j,config.w)
		{
			if (graph.id.count(mp(i,j)))
				cerr<<(o[graph.id[mp(i,j)]]==me()?"m":
						o[graph.id[mp(i,j)]]==enemy()?"e":
						"p")
					<<n[graph.id[mp(i,j)]]
					<<"\t";
			else cerr<<"x\t";
			if (j+1==config.w) cerr<<endl;
		}
	}
}graphState(config);

struct AI
{
	static const int MAX_ROUND=2;

	int alpha,beta;
	pr<Strategy,int> best;

	int currentRound;
	GraphState currentState;
	Strategy currentStrategy;

	void dfs(int currentPlace)
	{
		if (alpha>=beta) rtn;
		currentState.p=currentState.enemy();
		AI ai;
		pr<Strategy,int> get=ai.getStrategy(currentState,currentRound+1,alpha,beta);
		currentState.p=currentState.enemy();
		if (currentState.me()==config.p)
		{
			cmax(alpha,get.y);
			if (get.y>best.y) best.y=get.y,best.x=currentStrategy;
		}
		else
		{
			cmin(beta,get.y);
			if (get.y<best.y) best.y=get.y,best.x=currentStrategy;
		}
		rep(i,sz(graph.adj[currentPlace]))
		{
			int nextPlace=graph.adj[currentPlace][i];
			if (currentState.o[nextPlace]!=currentState.me())
			{
				currentStrategy.a.pb(mp(mp(currentPlace,nextPlace),currentState.n[currentPlace]));
				currentState.attack(currentState.me(),
									currentStrategy.a.back().x.x,
									currentStrategy.a.back().x.y,
									currentStrategy.a.back().y);
				if (currentState.o[nextPlace]!=currentState.me())
				{
					currentState.undo();
					currentStrategy.a.pop_back();
					continue;
				}
				dfs(nextPlace);
				currentState.undo();
				currentStrategy.a.pop_back();
			}
		}
	}
	pr<Strategy,int> getStrategy(const GraphState& cs,int cr=0,int a=-oo,int b=+oo)
	{
		alpha=a,beta=b;
		if (cr==MAX_ROUND)
		{
			int value=0;
			rep(i,sz(graph.nd)) if (cs.o[i])
			{
				if (cs.o[i]==config.p)
				{
					value+=graph.b[i]*12;
					value+=cs.n[i]*8;
				}
				else
				{
					value-=graph.b[i]*9;
					value-=cs.n[i]*6;
				}
			}
			best.y=value;
		}
		else
		{
			currentState=cs;
			currentRound=cr;

			currentState.getTotal();
			if (currentState.me()==config.p) best.y=-oo;
			else best.y=+oo;
			rep(i,sz(graph.nd)) if (currentState.o[i]==currentState.me())
			{
				currentStrategy.d.pb(mp(i,currentState.ttl));
				currentState.distribute(currentState.me(),
										currentStrategy.d.back().x,
										currentStrategy.d.back().y);
				dfs(i);
				currentState.undo();
				currentStrategy.d.pop_back();
			}
		}
		rtn best;
	}

	pr<Strategy,int> getStrategyForTest(const GraphState& gs,int cr=0)
	{
		pr<Strategy,int> best;
		best.y=-oo;
		GraphState graphState=gs;
		graphState.getTotal();
		whl(graphState.ttl)
		{
			rep(i,sz(graph.nd)) if (graphState.o[i]==graphState.me())
			{
				if (!graphState.ttl) break;
				rep(j,sz(graph.adj[i]))
					if (graphState.o[graph.adj[i][j]]!=graphState.me())
					{
						pii d=mp(i,unsigned(rand())%graphState.ttl+1);
						graphState.distribute(graphState.me(),d.x,d.y);
						best.x.d.pb(d);
						break;
					}
			}
		}
		rep(i,sz(graph.nd)) if (graphState.o[i]==graphState.me()&&graphState.n[i])
		{
			int u=i;
			whl(graphState.o[u]==graphState.me())
			{
				bool fnd=false;
				rep(j,sz(graph.adj[u]))
					if (graphState.o[graph.adj[u][j]]!=graphState.me())
					{
						int v=graph.adj[u][j];
						pr<pii,int> a=mp(mp(u,v),graphState.n[u]);
						graphState.attack(graphState.me(),a.x.x,a.x.y,a.y);
						best.x.a.pb(a);
						u=v;
						fnd=true;
						break;
					}
				if (!fnd) break;
			}
			if (graphState.o[u]!=graphState.me())
			{
				graphState.undo();
				best.x.a.pop_back();
			}
		}
		rtn best;
	}
}ai;

struct Game
{
	static const int MAX_ROUND=300;
	Game()
	{
		rep(i,MAX_ROUND)
		{
			if (i%2+1==config.p) graphState.apply(ai.getStrategy(graphState).x);
			else graphState.update();
#ifdef DEBUG
			graphState.show();
			runtime();
#endif
		}
	}
}game;

#ifndef DEBUG
int cnt;
int maxd;
GraphState currentState=graphState;
void dfs(int currentPlace)
{
	if (+oo/10000-currentState.n[currentPlace]<=20) cnt++;
	cmax(maxd,+oo/10000-currentState.n[currentPlace]);
	prt(+oo/10000-currentState.n[currentPlace]);
	rep(i,sz(graph.adj[currentPlace]))
	{
		int nextPlace=graph.adj[currentPlace][i];
		if (currentState.o[nextPlace]!=currentState.me())
		{
			currentState.attack(currentState.me(),
								currentPlace,
								nextPlace,
								currentState.n[currentPlace]);
			if (currentState.o[nextPlace]!=currentState.me())
			{
				currentState.undo();
				continue;
			}
			dfs(nextPlace);
			currentState.undo();
		}
	}
}

int main()
{
	runtime();
	currentState.distribute(currentState.me(),
							30,
							+oo/10000);
	dfs(30);
	prt(cnt);
	prt(maxd);
}
#else
int main()
{
}
#endif
