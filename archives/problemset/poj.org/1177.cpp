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
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define pb push_back
#define mp make_pair
#define itr iterator
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
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)

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
const db inf=1e8;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type lb(type x){rtn x&(-x);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x+=lb(x);}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;while (x>0)s+=st[x],x-=lb(x);rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

enum{MAX_REC=10000+1};
struct Rec
{
	int x1,y1,x2,y2;
};
int minx=-oo,maxx=+oo,miny=-oo,maxy=+oo;
int recs;
Rec rec[MAX_REC];
mii f;
int gs;
int g[MAX_REC*2];
struct Event
{
	int y1,y2,x,inc;
	friend bool operator<(const Event& a,const Event& b)
	{
		if (a.x==b.x) return a.inc>b.inc;
		else return a.x<b.x;
	}
};
int evts;
Event evt[MAX_REC*2];
struct Node
{
	int c,n,s,s2;
	bool lc,rc;
};
Node st[MAX_REC*2*4];
void insert(int L,int R,int inc,int l,int r,int rt=1)
{
	if (R<=l||r<=L) rtn;
	else if (L<=l&&r<=R) st[rt].c+=inc;
	else
	{
		int mid=(l+r)>>1,lrt=rt<<1,rrt=lrt|1;
		insert(L,R,inc,l,mid,lrt),insert(L,R,inc,mid,r,rrt);
	}
	if(st[rt].c>=2) st[rt].s2=g[r]-g[l];
	else if (r-l>1)
	{
		int lrt=rt<<1,rrt=lrt|1;
		if (st[rt].c) st[rt].s2=st[lrt].s+st[rrt].s;
		else st[rt].s2=st[lrt].s2+st[rrt].s2;
	}
	else st[rt].s2=0;

	if (st[rt].c)
	{
		st[rt].s=g[r]-g[l];
		st[rt].n=1;
		st[rt].lc=st[rt].rc=true;
	}
	else if (r-l>1)
	{
		int lrt=rt<<1,rrt=lrt|1;
		st[rt].s=st[lrt].s+st[rrt].s;
		st[rt].n=st[lrt].n+st[rrt].n-(st[lrt].rc&&st[rrt].lc);
		st[rt].lc=st[lrt].lc;
		st[rt].rc=st[rrt].rc;
	}
	else st[rt].s=st[rt].n=st[rt].lc=st[rt].rc=0;
}
void query(int& s,int& s2,int& n,int rt=1)
{
	s=st[rt].s;
	s2=st[rt].s2;
	n=st[rt].n;
}
void solve(lli& S,lli& C,lli& S2)
{
	f.clear();
	f[miny],f[maxy];
	rep(i,recs) f[rec[i].y1],f[rec[i].y2];

	gs=0;
	feach(i,f,mii) g[i->y=gs++]=i->x;

	evts=0;
	rep(i,recs)
	{
		evt[evts].x=max(rec[i].x1,minx),
		evt[evts].y1=rec[i].y1,
		evt[evts].y2=rec[i].y2,
		evt[evts].inc=+1,
		evts++;
		evt[evts].x=min(rec[i].x2,maxx),
		evt[evts].y1=rec[i].y1,
		evt[evts].y2=rec[i].y2,
		evt[evts].inc=-1,
		evts++;
	}
	sort(evt,evt+evts);

	S=0;
	C=0;
	S2=0;
	int lasts=0;
	clr(st);
	rep(i,evts)
	{
		int s,s2,n;
		query(s,s2,n);
		if (i) C+=lli(2)*lli(n)*lli(evt[i].x-evt[i-1].x);
		C+=abs(lasts-s);
		lasts=s;
		if (i) S+=lli(s)*lli(evt[i].x-evt[i-1].x);
		if (i) S2+=lli(s2)*lli(evt[i].x-evt[i-1].x);
		insert(f[evt[i].y1],f[evt[i].y2],evt[i].inc,0,gs-1);
	}
	C+=abs(lasts);
}


enum{MAXN=50000+1};
int W,H,N,M;
lli ans=0;
int xa[MAXN],xb[MAXN],ya[MAXN],yb[MAXN];

int main()
{
	cin>>recs;
	rep(i,recs) cin>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2;
	lli S,C,S2;
	solve(S,C,S2);
	cout<<C<<endl;
	rtn 0;
	cin.sync_with_stdio(false);
	whl(cin>>W>>H>>N>>M)
	{
		ans=0;
		rep(i,N) cin>>xa[i]>>ya[i]>>xb[i]>>yb[i];
		if (H>=M)
		{
			minx=0,maxx=W,miny=0,maxy=H;
			rep(i,N) rec[i].x1=xa[i]-M,rec[i].x2=xb[i],rec[i].y1=ya[i]-1,rec[i].y2=yb[i];
			rec[N].x1=maxx-M+1,rec[N].x2=maxx,rec[N].y1=miny,rec[N].y2=maxy;
			recs=N+1;
			lli S,C,S2;
			solve(S,C,S2);
			ans+=lli(W)*lli(H)-S;
		}
		if (W>=M)
		{
			minx=0,maxx=H,miny=0,maxy=W;
			rep(i,N) rec[i].x1=ya[i]-M,rec[i].x2=yb[i],rec[i].y1=xa[i]-1,rec[i].y2=xb[i];
			rec[N].x1=maxx-M+1,rec[N].x2=maxx,rec[N].y1=miny,rec[N].y2=maxy;
			recs=N+1;
			lli S,C,S2;
			solve(S,C,S2);
			ans+=lli(H)*lli(W)-S;
		}
		if (M==1) ans/=2;
		cout<<ans<<endl;
	}
}
