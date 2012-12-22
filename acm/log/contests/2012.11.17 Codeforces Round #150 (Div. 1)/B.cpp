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
#define prt(x) cerr<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s\n";

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

int main()
{
	int n,m,h,t;
	cin>>n>>m>>h>>t;
	vvi adj(n);
	vi u(m),v(m);
	rep(i,m)
	{
		cin>>u[i]>>v[i],--u[i],--v[i];
		adj[u[i]].pb(v[i]),adj[v[i]].pb(u[i]);
	}
	rep(i,n) srt(adj[i]);
	rep(i,m) if ((sz(adj[u[i]])-1>=h&&sz(adj[v[i]])-1>=t)||(sz(adj[u[i]])-1>=t&&sz(adj[v[i]])-1>=h))
	{
		int a,b,c=0,aneed,bneed;
		vi lst;
		int it=0,jt=0;
		whl(it<sz(adj[u[i]])&&jt<sz(adj[v[i]]))
		{
			if (adj[u[i]][it]<adj[v[i]][jt]) it++;
			else if (adj[u[i]][it]>adj[v[i]][jt]) jt++;
			else lst.pb(adj[u[i]][it]),it++,jt++,c++;
		}

		a=sz(adj[u[i]])-1,b=sz(adj[v[i]])-1;
		aneed=h-min(a-c,h),bneed=t-min(b-c,t);
		if (aneed+bneed<=c)
		{
			cout<<"YES"<<endl;
			cout<<u[i]+1<<" "<<v[i]+1<<endl;
			rep(it,sz(adj[u[i]]))
			{
				if (!binary_search(all(lst),adj[u[i]][it])&&adj[u[i]][it]!=v[i]) cout<<adj[u[i]][it]+1<<char(--h?' ':'\n');
				if (!h) break;
			}
			rep(it,aneed) cout<<lst[it]+1<<char(--h?' ':'\n');
			rep(it,sz(adj[v[i]]))
			{
				if (!binary_search(all(lst),adj[v[i]][it])&&adj[v[i]][it]!=u[i]) cout<<adj[v[i]][it]+1<<char(--t?' ':'\n');
				if (!t) break;
			}
			repf(it,aneed,aneed+bneed) cout<<lst[it]+1<<char(--t?' ':'\n');
			return 0;
		}
		swap(u[i],v[i]);
		a=sz(adj[u[i]])-1,b=sz(adj[v[i]])-1;
		aneed=h-min(a-c,h),bneed=t-min(b-c,t);
		if (aneed+bneed<=c)
		{
			cout<<"YES"<<endl;
			cout<<u[i]+1<<" "<<v[i]+1<<endl;
			rep(it,sz(adj[u[i]]))
			{
				if (!binary_search(all(lst),adj[u[i]][it])&&adj[u[i]][it]!=v[i]) cout<<adj[u[i]][it]+1<<char(--h?' ':'\n');
				if (!h) break;
			}
			rep(it,aneed) cout<<lst[it]+1<<char(--h?' ':'\n');
			rep(it,sz(adj[v[i]]))
			{
				if (!binary_search(all(lst),adj[v[i]][it])&&adj[v[i]][it]!=u[i]) cout<<adj[v[i]][it]+1<<char(--t?' ':'\n');
				if (!t) break;
			}
			repf(it,aneed,aneed+bneed) cout<<lst[it]+1<<char(--t?' ':'\n');
			return 0;
		}
	}
	cout<<"NO"<<endl;
}