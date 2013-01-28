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
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s,t) for (t::itr e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define forin(i,charset) for (char const* i=charset;*i;i++)
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
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& set){rep(i,sz(set))set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}

#define oo 19930309

int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b,--a,--b;
	vvi adj(n),radj(n);
	rep(i,m)
	{
		int ui,vi;
		cin>>ui>>vi,--ui,--vi;
		adj[ui].pb(vi),radj[vi].pb(ui);
	}
	int k;
	cin>>k;
	vec<vvi> graph(k+1);
	vec<vb> is_cut(k+1,vb(n));
	rep(i,k)
	{
		int si,ti;
		cin>>si>>ti,--si,--ti;
		vi d(n,oo),dd(n,oo);
		que<int> q;
		d[si]=0;
		q.push(si);
		whl(sz(q))
		{
			int u=q.front();
			q.pop();
			rep(i,sz(adj[u]))
			{
				int v=adj[u][i];
				if (d[v]==oo) d[v]=d[u]+1,q.push(v);
			}
		}
		dd[ti]=0;
		q.push(ti);
		whl(sz(q))
		{
			int u=q.front();
			q.pop();
			rep(i,sz(radj[u]))
			{
				int v=radj[u][i];
				if (dd[v]==oo) dd[v]=dd[u]+1,q.push(v);
			}
		}
		graph[i].resize(n);
		if (d[ti]!=oo)
		{
			vvi cut(n);
			rep(u,n) if (d[u]+dd[u]==d[ti])
			{
				rep(j,sz(adj[u]))
				{
					int v=adj[u][j];
					if (d[v]+dd[v]==d[ti]&&d[u]+1==d[v])
						graph[i][u].pb(v);
				}
				cut[d[u]].pb(u);
			}
			rep(du,n) if (sz(cut[du])==1) is_cut[i][cut[du].front()]=true;
		}
	}
	vvi d(k+1,vi(n,oo));
	rep(i,k) d[i][b]=0;
	graph[k++].resize(n);
	bool upd;
	do
	{
		upd=false;
		rep(i,k)
		{
			rep(u,n)
			{
				rep(j,k) if (is_cut[j][u])
				{
					if (cmin(d[i][u],d[j][u]+1)) upd=true;
					//if (u==a) prt(u),prt(d[j][u]),prt(i),prt(j);
				}
				if (sz(graph[i][u]))
				{
					int get=0;
					rep(j,sz(graph[i][u]))
					{
						int v=graph[i][u][j];
						cmax(get,d[i][v]);
						//if (u==a) prt(v),prt(get),prt(i);
					}
					if (cmin(d[i][u],get)) upd=true;
				}
				//if (d[i][u]!=oo) cout<<i<<" "<<u<<" "<<d[i][u]<<" "<<i<<endl;
			}
		}
	}
	whl(upd);
	//prt(k-1);
	int ans=d[k-1][a];
	if (ans==oo) cout<<-1<<endl;
	else cout<<ans<<endl;
}

