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
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
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
#define foreach(e,set,type) for (type::iterator e=(set).begin();e!=(set).end();++e)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define sqr(x) (x)*(x)
#define lb(x) (x)&(-(x))
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
#define asrtWA(s) do if(!(s))exit(0);whl(false)
#define asrtTLE(s) do if(!(s))whl(true);whl(false)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(false)

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<string> vs;
typedef pr<int, int> pii;
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
const db inf=1e100;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){return a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){return a>b?a=b,true:false;}
template<typename type>inline int sgn(const type& x){return (x>0)-(x<0);}
template<>inline int sgn(const db& x){return (x>+eps)-(x<-eps);}

void inc(vi& st,int x,int inc)
{
	whl(x<sz(st))
		st[x]+=inc,x+=lb(x);
}
int sum(vi& st,int x)
{
	int s=0;
	while (x>0)
		s+=st[x],x-=lb(x);
	rtn s;
}

int main()
{
	int n;
	cin>>n;
	vvi adj(n);
	vec<pii> edg;
	rep(i,n-1)
	{
		int u,v;
		cin>>u>>v;
		edg.pb(mp(--u,--v));
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int rt=0;
	rep(i,n) if (sz(adj[i])>2) rt=i;
	vi id(n),dep(n);
	vi maxdep(sz(adj[rt]));
	rep(i,sz(adj[rt]))
	{
		int u=adj[rt][i],p=rt;
		id[u]=i;
		dep[u]=1;
		maxdep[id[u]]=dep[u];
		lp
		{
			bool nxt=false;
			rep(i,sz(adj[u]))
				if (adj[u][i]!=p)
				{
					p=u;
					u=adj[u][i];
					id[u]=id[p];
					dep[u]=dep[p]+1;
					maxdep[id[u]]=dep[u];
					nxt=true;
					break;
				}
			if (!nxt) break;
		}
	}
	vvi st(sz(adj[rt]));
	rep(i,sz(adj[rt])) st[i].resize(maxdep[i]+1,0);
	rep(i,sz(adj[rt])) ft(j,1,sz(st[i])) inc(st[i],j,+1);
	int m;
	cin>>m;
	rep(i,m)
	{
		int tp;
		cin>>tp;
		switch (tp)
		{
		case 1:
		{
			int e;
			cin>>e;
			--e;
			int p;
			if (dep[edg[e].x]>dep[edg[e].y]) p=edg[e].x;
			else p=edg[e].y;
			inc(st[id[p]],dep[p],+1);
		}
			break;
		case 2:
		{
			int e;
			cin>>e;
			--e;
			int p;
			if (dep[edg[e].x]>dep[edg[e].y]) p=edg[e].x;
			else p=edg[e].y;
			//prt(p);prt(id[p]);
			inc(st[id[p]],dep[p],-1);
		}
			break;
		case 3:
		{
			int u,v;
			cin>>u>>v;
			--u,--v;
			if (u==v) cout<<0<<endl;
			else if (u==rt)
			{
				if (sum(st[id[v]],dep[v])==dep[v]) cout<<dep[v]<<endl;
				else cout<<-1<<endl;
			}
			else if (v==rt)
			{
				if (sum(st[id[u]],dep[u])==dep[u]) cout<<dep[u]<<endl;
				else cout<<-1<<endl;
			}
			else if (id[u]==id[v])
			{
				if (sum(st[id[u]],dep[u])-sum(st[id[v]],dep[v])==dep[u]-dep[v]) cout<<abs(dep[u]-dep[v])<<endl;
				else cout<<-1<<endl;
			}
			else
			{
				if (sum(st[id[u]],dep[u])+sum(st[id[v]],dep[v])==dep[u]+dep[v]) cout<<abs(dep[u]+dep[v])<<endl;
				else cout<<-1<<endl;
			}
		}
			break;
		}
	}
}

