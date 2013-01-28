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

/*
 * 1 2
 * 1 2 3 2
 * 1 2 3 4 3 2
 * 1 2 3 4 5 4 3 2
 * 1 2 3 4 5 6 5 4 3 2
 * */

vec<lli> a;
vec<lli> st[6+2][10+2];
void ins(lli p,lli x)
{
	lli delta=x-a[p];
	a[p]=x;
	ft(i,2,6)
	{
		//prt(i),prt(p%((i-1)*2)),prt(delta);
		bit_inc(st[i][p%((i-1)*2)],p,delta);
	}
}
lli qry(lli l,lli r,lli z)
{
	lli ans=0;
	rep(i,(z-1)*2)
	{
		ans+=(bit_sum(st[z][(l+i)%((z-1)*2)],r)-bit_sum(st[z][(l+i)%((z-1)*2)],l-1))*min<lli>(i+1,z*2-(i+1));
		//prt(ans);
		//prt((l+i)%((z-1)*2));
		//prt((bit_sum(st[z][(l+i)%((z-1)*2)],r)-bit_sum(st[z][(l+i)%((z-1)*2)],l-1)));
		//prt(min<lli>(i+1,z*2-(i-1)));
	}
	rtn ans;
}

int main()
{
	int n;
	cin>>n;
	a.resize(n);
	ft(i,2,6) rep(j,(i-1)*2) st[i][j].resize(n);
	rep(i,n)
	{
		lli ai;
		cin>>ai;
		ins(i,ai);
	}
	int m;
	cin>>m;
	rep(i,m)
	{
		int t;
		cin>>t;
		switch (t)
		{
		case 1:
		{
			lli p,x;
			cin>>p>>x;
			ins(--p,x);
		}
			break;
		case 2:
		{
			lli l,r,z;
			cin>>l>>r>>z;
			cout<<qry(--l,--r,z)<<endl;
		}
			break;
		}
	}
}

