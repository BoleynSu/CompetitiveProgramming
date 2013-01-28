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
#define rep(i,n) for (lli i=0;i<(n);++i)
#define ft(i,a,b) for (lli i=(a);i<=(b);++i)
#define fdt(i,a,b) for (lli i=(a);i>=b;--i)
#define feach(e,s,t) for (t::itr e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (lli subset=set&(set-1);subset;subset=(subset-1)&set)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define cpy(x,y) memcpy((x),(y),sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((lli)(x).size())
#define len(x) ((lli)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) (x).resize(unique(all(x))-x.begin())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf prllif
#define pdb(prcs,x) prllif("%."#prcs"f",(abs(x)<1e-##prcs)?0.0:x)
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new lli);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(lli*)0=0;whl(0)
#define runtime() prllif("Used: %.3fms\n",db(clock())/CLOCKS_PER_SEC);

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<lli> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<lli, lli> pii;
typedef pr<db,db> pdd;
typedef pr<str,lli> psi;
typedef map<lli,lli> mii;
typedef map<str,lli> msi;
typedef map<char,lli> mci;
typedef set<lli> si;
typedef set<str> ss;
typedef que<lli> qi;
typedef prq<lli> pqi;

//const lli oo=(~0u)>>1;
const lli oo=(~0ull)>>1;
const db inf=1e+8;
const db eps=1e-8;
const db pi=acos(-1.0);
const lli MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
lli dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
lli sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,lli x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,lli x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,lli size){set.resize(size);rep(i,size)set[i]=i;}
inline lli find_set(vi& set,lli x){lli y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,lli a,lli b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}

int main()
{
	lli n,m;
	scanf("%I64d%I64d",&n,&m);//cin>>n>>m;
	vi cnt(n);
	rep(i,m*2)
	{
		int p;
		scanf("%I64d",&p),cnt[--p]++;//cin>>p,cnt[--p]++;
	}
	lli ans=n*(n-1)*(n-2)/6,sum=0;
	rep(i,n) sum+=cnt[i]*(n-1-cnt[i]);
	ans-=sum/2;
	cout<<ans<<endl;
	return 0;
}

