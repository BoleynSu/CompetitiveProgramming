/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-12-08
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
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(x))
#ifdef ONLINE_JUDGE
#define endl '\n'
#define prt(x) cerr
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() cerr
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#define DEBUG
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

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+20;
const db eps=1e-8;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& set){rep(i,sz(set))set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;


int sg(int x)
{
	if (x<4) rtn 0;
	else if (x<16) rtn 1;
	else if (x<82) rtn 2;
	else if (x<6724) rtn 0;
	else if (x<50626) rtn 3;
	else rtn 1;
}
int SG(lli x)
{
	if (x>=881918)
	{
		lli b=sqrt(sqrt(x)),e=sqrt(x);
		whl(sqr(sqr(b))<x) b++;
		whl(sqr(sqr(b-1))>=x&&b>0) b--;
		whl(sqr(e)>x&&e>0) e--;
		whl(sqr(e+1)<=x) e++;
		if (b>=50626) b=50626;
		else if (b>=6724) b=6724;
		else if (b>=82) b=82;
		else if (b>=16) b=16;
		else if (b>=4) b=4;
		else if (b>=0) b=0;
		if (e>=50626) e=50626;
		else if (e>=6724) e=6724;
		else if (e>=82) e=82;
		else if (e>=16) e=16;
		else if (e>=4) e=4;
		else if (e>=0) e=0;
		si s;
		ft(j,b,e)
		{
			if (j==0) j=4-1;
			if (j==4) j=16-1;
			if (j==16) j=82-1;
			if (j==82) j=6724-1;
			if (j==6724) j=50626-1;
			s.insert(sg(j));
		}
		int sg=0;
		whl(s.count(sg)) sg++;
		rtn sg;
	}
	else rtn sg(x);
}

int main()
{
//	static int sg[1000000];
//	int n=881918;
//	rep(i,n)
//	{
//		si s;
//		int b=sqrt(sqrt(i)),e=sqrt(i);
//		whl(sqr(sqr(b))<i) b++;
//		whl(sqr(sqr(b-1))>=i&&b>0) b--;
//		whl(sqr(e)>i&&e>0) e--;
//		whl(sqr(e+1)<=i) e++;
//		b=max(0,b);
//		e=min(e,i-1);
//		ft(j,b,e)
//		{
//			s.insert(sg[j]);
//			if (j==0) j=4-1;
//			if (j==4) j=16-1;
//			if (j==16) j=82-1;
//			if (j==82) j=6724-1;
//			if (j==6724) j=50626-1;
//		}
//		sg[i]=0;
//		whl(s.count(sg[i])) sg[i]++;
//		if (!i||sg[i]!=sg[i-1]) prt(i),prt(sg[i]);
//		//prt(b),prt(e);
//	}
//	rtn 0;
	int n;
	cin>>n;
	vec<lli> a(n);
	rep(i,n) cin>>a[i];
	int sg=0;
	rep(i,n) sg^=SG(a[i]);
	cout<<(sg?"Furlo ":"Rublo")<<endl;
}
