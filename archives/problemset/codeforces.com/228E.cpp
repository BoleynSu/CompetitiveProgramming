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
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() printf("Used: %.3fms\n",db(clock())/CLOCKS_PER_SEC);

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int, int> pii;
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
const db inf=1e+8;
const db eps=1e-8;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

vvi adj;
map<pii,int> color;
vi cc;

vi lst;
bool dfs(int u,int ccu,int p=-1)
{
	cc[u]=ccu;
	lst.pb(u);
	rep(i,sz(adj[u]))
		if (adj[u][i]!=p)
		{
			int v=adj[u][i];
			int ccv=!(cc[u]^color[mp(u,v)]);
			if (cc[v]==-1) dfs(v,ccv,u);
			else if (cc[v]!=ccv) rtn false;
		}
	rtn true;
}

int main()
{
	int n,m;
	cin>>n>>m;
	adj.resize(n);
	rep(i,m)
	{
		int u,v,c;
		cin>>u>>v>>c;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
		color[mp(u,v)]=color[mp(v,u)]=c;
	}
	bool possible=true;
	vi ans;
	vb visited(n);
	cc.resize(n,-1);
	rep(i,n)
	{
		if (visited[i]) continue;
		rep(i,sz(lst)) cc[lst[i]]=-1;
		lst.clear();
		if (dfs(i,1))
		{
			rep(i,sz(lst))
			{
				if (cc[lst[i]]==1) ans.pb(lst[i]);
				if (cc[lst[i]]!=-1) visited[lst[i]]=true;
			}
			continue;
		}
		rep(i,sz(lst)) cc[lst[i]]=-1;
		lst.clear();
		if (dfs(i,0))
		{
			rep(i,sz(lst))
			{
				if (cc[lst[i]]==1) ans.pb(lst[i]);
				if (cc[lst[i]]!=-1) visited[lst[i]]=true;
			}
			continue;
		}
		possible=false;
	}

	if (possible)
	{
		cout<<sz(ans)<<endl;
		rep(i,sz(ans)) cout<<ans[i]+1<<char(i+1==sz(ans)?'\n':' ');
	}
	else cout<<"Impossible"<<endl;
}

