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

struct stn
{
	int cnt,dlt,clr;
};
stn st[26][100000<<2];

inline
void push_down_down(stn st[],int l,int r,int rt)
{
	int lrt=rt<<1,rrt=lrt|1;
	if (st[rt].clr)
	{
		if (l<r) st[lrt].clr=true,st[rrt].clr=true;
		st[rt].cnt=0;
		st[rt].dlt=0;
		st[rt].clr=false;
	}
	if (st[rt].dlt)
	{
		if (l<r) st[lrt].dlt+=st[rt].dlt,st[rrt].dlt+=st[rt].dlt;
		st[rt].cnt+=st[rt].dlt*(r-l+1);
		st[rt].dlt=0;
		st[rt].clr=false;
	}
}
inline
void push_down(stn st[],int l,int r,int rt)
{
	int ll=l,lr=(l+r)>>1,lrt=rt<<1;
	int rl=lr+1,rr=r,rrt=lrt|1;
	if (st[rt].clr)
	{
		if (l<r)
		{
			if (st[lrt].dlt) push_down_down(st,ll,lr,lrt);
			if (st[rrt].dlt) push_down_down(st,rl,rr,rrt);
			st[lrt].clr=true,st[rrt].clr=true;
		}
		st[rt].cnt=0;
		st[rt].dlt=0;
		st[rt].clr=false;
	}
	if (st[rt].dlt)
	{
		if (l<r)
		{
			if (st[lrt].clr) push_down_down(st,ll,lr,lrt);
			if (st[rrt].clr) push_down_down(st,rl,rr,rrt);
			st[lrt].dlt+=st[rt].dlt,st[rrt].dlt+=st[rt].dlt;
		}
		st[rt].cnt+=st[rt].dlt*(r-l+1);
		st[rt].dlt=0;
		st[rt].clr=false;
	}
}
void clear(stn st[],int l,int r,int L,int R,int rt=1)
{
	if (r<L||R<l) rtn;
	else if (L<=l&&r<=R)
	{
		push_down(st,l,r,rt);
		st[rt].clr=true;
	}
	else
	{
		int ll=l,lr=(l+r)>>1,lrt=rt<<1;
		int rl=lr+1,rr=r,rrt=lrt|1;
		push_down(st,l,r,rt);
		clear(st,ll,lr,L,R,lrt),clear(st,rl,rr,L,R,rrt);
		st[rt].cnt=(st[lrt].clr?0:st[lrt].cnt+st[lrt].dlt*(lr-ll+1))+(st[rrt].clr?0:st[rrt].cnt+st[rrt].dlt*(rr-rl+1));
	}
}
void insert(stn st[],int l,int r,int L,int R,int rt=1)
{
	if (r<L||R<l) rtn;
	else if (L<=l&&r<=R)
	{
		push_down(st,l,r,rt);
		st[rt].dlt++;
	}
	else
	{
		int ll=l,lr=(l+r)>>1,lrt=rt<<1;
		int rl=lr+1,rr=r,rrt=lrt|1;
		push_down(st,l,r,rt);
		insert(st,ll,lr,L,R,lrt),insert(st,rl,rr,L,R,rrt);
		st[rt].cnt=(st[lrt].clr?0:st[lrt].cnt+st[lrt].dlt*(lr-ll+1))+(st[rrt].clr?0:st[rrt].cnt+st[rrt].dlt*(rr-rl+1));
	}
}
int query(stn st[],int l,int r,int L,int R,int rt=1)
{
	if (r<L||R<l) rtn 0;
	else if (L<=l&&r<=R) rtn (st[rt].clr?0:st[rt].cnt+st[rt].dlt*(r-l+1));
	else
	{
		int ll=l,lr=(l+r)>>1,lrt=rt<<1;
		int rl=lr+1,rr=r,rrt=lrt|1;
		push_down(st,l,r,rt);
		rtn query(st,ll,lr,L,R,lrt)+query(st,rl,rr,L,R,rrt);
	}
}

char s[100000+2];
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	int l=0,r=n-1;
	rep(i,n) insert(st[s[i]-'a'],l,r,i,i);
	rep(i,m)
	{
		int li,ri;
		scanf("%d%d",&li,&ri),li--,ri--;
		int cnt[26];
		int odd=0;
		rep(i,26)
		{
			cnt[i]=query(st[i],l,r,li,ri);
			if (cnt[i]%2==1) odd++;
			if ((ri-li+1)%2==0&&odd>0) break;
			else if ((ri-li+1)%2==1&&odd>1) break;
		}
		if ((ri-li+1)%2==0&&odd>0) continue;
		else if ((ri-li+1)%2==1&&odd>1) continue;
		else
		{
			int ll=li,lr,rl,rr=ri;
			rep(i,26) if (cnt[i])
			{
				lr=ll+(cnt[i]>>1)-1,rl=rr-(cnt[i]>>1)+1;
				clear(st[i],l,r,li,ri);
				insert(st[i],l,r,ll,lr);
				insert(st[i],l,r,rl,rr);
				if (cnt[i]%2==1) insert(st[i],l,r,(li+ri)>>1,(li+ri)>>1);
				ll+=(cnt[i]>>1),rr-=(cnt[i]>>1);
			}
		}
	}
	rep(i,n) rep(j,26) if (query(st[j],l,r,i,i))
	{
		putchar('a'+j);
		break;
	}
	putchar('\n');
}

