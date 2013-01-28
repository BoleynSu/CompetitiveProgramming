/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-11-17
 * */
#include <iostream>
#include <fstream>
#include <sstream>
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
#define fl(x,y) fill((x),(x)+sizeof(x)/sizeof(*(x)),y)
#define clr(x) fl(x,0)
#define cpy(x,y) copy((y),(y)+sizeof(y)/sizeof(*(y)),(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((int)(x).size())
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

bool my_less(const pr<pii,int>& a,const pr<pii,int>& b)
{
	return lli(a.x.x)*lli(b.x.y)<lli(b.x.x)*lli(a.x.y);
}

int hit(const vec<pr<pii,int> >& seg,int x,int y,const vi& a)
{
	vec<pr<pii,int> >::const_iterator it=lower_bound(all(seg),mp(mp(x,y),19930309),my_less);
	if (it==seg.end()||my_less(mp(mp(x,y),19930309),mp(mp(a[it->y],1),19930309))) return -1;
	else return it->y;
}
void calc(int& ans,int hl,int hr,const vec<pr<pii,int> >& tseg,const vec<pr<pii,int> >& fseg,int n,const vi& v,const vi& a)
{
	for (int time=0;time<=n;time++)
	{
		int x=100000,y;
		if (time%2==1) y=hl+(time-1)*100+hr;
		else y=hl+time*100-hr;
		int get=0,lastt=-1,lastf=-1;
		for (int i=1;i<=time;i++)
		{
			int ty=hl+(i-1)*100;//tx=x*ty/y;
			if (i%2==1)
			{
				int ind=hit(fseg,x*ty,y,a);
				if (ind!=-1&&ind!=lastf) get+=v[lastf=ind];
				else
				{
					get=-oo;
					break;
				}
			}
			else
			{
				int ind=hit(tseg,x*ty,y,a);
				if (ind!=-1&&ind!=lastt) get+=v[lastt=ind];
				else
				{
					get=-oo;
					break;
				}
			}
		}
		cmax(ans,get);
	}
}

int main()
{
	int hl,hr,n;
	cin>>hl>>hr>>n;
	vi v(n),a(n),b(n);
	str c(n,'\0');
	rep(i,n) cin>>v[i]>>c[i]>>a[i]>>b[i];
	vec<pr<pii,int> > tseg,fseg;
	rep(i,n)
	{
		if (c[i]=='T') tseg.pb(mp(mp(b[i],1),i));
		else fseg.pb(mp(mp(b[i],1),i));
	}
	int ans=-oo;
	srt(tseg),srt(fseg);
	calc(ans,hl,hr,tseg,fseg,n,v,a);
	calc(ans,100-hl,100-hr,fseg,tseg,n,v,a);
	cout<<ans<<endl;
}

