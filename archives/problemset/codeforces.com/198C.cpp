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
const db eps=1e-9;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){return a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){return a>b?a=b,true:false;}
template<typename type>inline int sgn(const type& x){return (x>0)-(x<0);}
template<>inline int sgn(const db& x){return (x>+eps)-(x<-eps);}
template<typename type>
void inc(vec<type>& st,int x,type inc){whl(x<sz(st)) st[x]+=inc,x+=lb(x);}
template<typename type>
type sum(vec<type>& st,int x){type s=0;while (x>0) s+=st[x],x-=lb(x);rtn s;}

int main()
{
	pr<db,db> p,s;
	db pv,sv,R,r;
	cin>>p.x>>p.y>>pv;
	R=sqrt(sqr(p.x)+sqr(p.y));
	cin>>s.x>>s.y>>sv>>r;
	db pt=atan2(p.y,p.x);
	db st=atan2(s.y,s.x);
	db sr=sqrt(sqr(s.x)+sqr(s.y));
	db a=acos(r/sr)+acos(r/R);

	db myeps=1e-5;
	db ans=inf,nxtdel,nnxtdel,nnnxtdel,nnnnxtdel;
	for (db delta=-pi;delta<=pi;delta+=myeps)
	{
		db tt=st+delta;
		pr<db,db> t;
		t.x=R*cos(tt),t.y=R*sin(tt);
		db t1;
		if (abs(delta)<=a) t1=sqrt(sqr(t.x-s.x)+sqr(t.y-s.y))/sv;
		else t1=((abs(delta)-a)*r+sqrt(sqr(sr)-sqr(r))+sqrt(sqr(R)-sqr(r)))/sv;
		db t2=(tt-pt)*R/pv;
		db x=(t1-t2)/(2.0*pi*R/pv);
		if (x-int(x)<=eps) x=int(x);
		else x=int(x+1);
		db rt=x*(2.0*pi*R/pv)+t2;
		if (cmin(ans,rt)) nxtdel=delta;
	}
	for (db del=-1.0;del<=1.0;del+=myeps)
	{
		db delta=nxtdel+del*(1e-3);
		db tt=st+delta;
		pr<db,db> t;
		t.x=R*cos(tt),t.y=R*sin(tt);
		db t1;
		if (abs(delta)<=a) t1=sqrt(sqr(t.x-s.x)+sqr(t.y-s.y))/sv;
		else t1=((abs(delta)-a)*r+sqrt(sqr(sr)-sqr(r))+sqrt(sqr(R)-sqr(r)))/sv;
		db t2=(tt-pt)*R/pv;
		db x=(t1-t2)/(2.0*pi*R/pv);
		if (x-int(x)<=eps) x=int(x);
		else x=int(x+1);
		db rt=x*(2.0*pi*R/pv)+t2;
		if (cmin(ans,rt)) nnxtdel=delta;
	}
	for (db del=-1.0;del<=1.0;del+=myeps)
	{
		db delta=nnxtdel+del*(1e-6);
		db tt=st+delta;
		pr<db,db> t;
		t.x=R*cos(tt),t.y=R*sin(tt);
		db t1;
		if (abs(delta)<=a) t1=sqrt(sqr(t.x-s.x)+sqr(t.y-s.y))/sv;
		else t1=((abs(delta)-a)*r+sqrt(sqr(sr)-sqr(r))+sqrt(sqr(R)-sqr(r)))/sv;
		db t2=(tt-pt)*R/pv;
		db x=(t1-t2)/(2.0*pi*R/pv);
		if (x-int(x)<=eps) x=int(x);
		else x=int(x+1);
		db rt=x*(2.0*pi*R/pv)+t2;
		if (cmin(ans,rt)) nnnxtdel=delta;
	}
	for (db del=-1.0;del<=1.0;del+=myeps)
	{
		db delta=nnnxtdel+del*(1e-9);
		db tt=st+delta;
		pr<db,db> t;
		t.x=R*cos(tt),t.y=R*sin(tt);
		db t1;
		if (abs(delta)<=a) t1=sqrt(sqr(t.x-s.x)+sqr(t.y-s.y))/sv;
		else t1=((abs(delta)-a)*r+sqrt(sqr(sr)-sqr(r))+sqrt(sqr(R)-sqr(r)))/sv;
		db t2=(tt-pt)*R/pv;
		db x=(t1-t2)/(2.0*pi*R/pv);
		if (x-int(x)<=eps) x=int(x);
		else x=int(x+1);
		db rt=x*(2.0*pi*R/pv)+t2;
		if (cmin(ans,rt)) nnnnxtdel=delta;
	}
	for (db del=-1.0;del<=1.0;del+=myeps)
	{
		db delta=nnnnxtdel+del*(1e-12);
		db tt=st+delta;
		pr<db,db> t;
		t.x=R*cos(tt),t.y=R*sin(tt);
		db t1;
		if (abs(delta)<=a) t1=sqrt(sqr(t.x-s.x)+sqr(t.y-s.y))/sv;
		else t1=((abs(delta)-a)*r+sqrt(sqr(sr)-sqr(r))+sqrt(sqr(R)-sqr(r)))/sv;
		db t2=(tt-pt)*R/pv;
		db x=(t1-t2)/(2.0*pi*R/pv);
		if (x-int(x)<=eps) x=int(x);
		else x=int(x+1);
		db rt=x*(2.0*pi*R/pv)+t2;
		cmin(ans,rt);
	}
	printf("%.50f\n",ans);
}

