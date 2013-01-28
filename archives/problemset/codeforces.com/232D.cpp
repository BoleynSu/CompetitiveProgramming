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
const lli MOD=1000000007;

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

const int LOG2_MAXLENGTH=19;
const int MAXLENGTH=200000+1993;
typedef int S[MAXLENGTH];
typedef int* int_pointer;
int_pointer SORT;
int _SA[MAXLENGTH],_rank[MAXLENGTH],_TSA[MAXLENGTH],_Trank[MAXLENGTH];
int_pointer SA=_SA,rank=_rank,TSA=_TSA,Trank=_Trank;
struct SORT_SA
{
	int* s;
	bool operator()(int a,int b)
	{
		rtn s[a]<s[b];
	}
};
void get_SA(S s,int length)
{
     SORT_SA ssa;
     ssa.s=s;
     ft(i,1,length) SA[i]=i;
     sort(SA+1,SA+length,ssa);
     rank[SA[1]]=1;
     for (int i=2;i<=length;i++)
         if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
         else rank[SA[i]]=rank[SA[i-1]]+1;

     SORT=Trank;
     for (int block=1;rank[SA[length]]!=length;block<<=1)
     {
         SORT=Trank;
         for (int i=1;i<=length;i++) SORT[rank[SA[i]]]=i;
         for (int i=length;i>=1;i--)
             if (SA[i]-block>=1)
                TSA[SORT[rank[SA[i]-block]]--]=SA[i]-block;
         for (int i=length-block+1;i<=length;i++)
             TSA[SORT[rank[i]]--]=i;
         int_pointer swap;
         swap=SA,SA=TSA,TSA=swap;
         swap=rank,rank=Trank,Trank=swap;
         rank[SA[1]]=1;
         for (int i=2;i<=length;i++)
             if (Trank[SA[i]]==Trank[SA[i-1]]
                &&Trank[SA[i]+block]==Trank[SA[i-1]+block])
                rank[SA[i]]=rank[SA[i-1]];
             else rank[SA[i]]=rank[SA[i-1]]+1;
     }
}
int_pointer height;
void get_height(S s,int length)
{
     height=TSA;
     for (int i=1,h=0;i<=length;i++)
     {
         if (h) h--;
         if (rank[i]!=1)
         {
            int j=SA[rank[i]-1];
            while (s[i+h]==s[j+h]) h++;
         }
         height[rank[i]]=h;
     }
}
int_pointer LOG2;
int rmq[LOG2_MAXLENGTH][MAXLENGTH];
void get_RMQ(int length)
{
     LOG2=Trank;
     LOG2[1]=0;
     for (int i=2;i<=length;i++) LOG2[i]=LOG2[i-1]+(i==(i&(-i)));
     for (int i=1;i<=length;i++) rmq[0][i]=i;
     for (int log=1;log<=LOG2[length];log++)
     {
         int exp=1<<log,exp_div_2=exp>>1;
         for (int i=1;i<=length-exp+1;i++)
         {
             int a=rmq[log-1][i];
             int b=rmq[log-1][i+exp_div_2];
             rmq[log][i]=height[a]<height[b]?a:b;
         }
     }
}
int RMQ(int a,int b)
{
    int log=LOG2[b-a+1];
    int exp=1<<log;
    a=rmq[log][a],b=rmq[log][b-exp+1];
    return height[a]<height[b]?a:b;
}
int LCP(int a,int b)
{
    a=rank[a],b=rank[b];
    if (a>b) return height[RMQ(b+1,a)];
    else return height[RMQ(a+1,b)];
}
vi st[200000<<2];
void insert(int l,int r,int p,int v,int rt=1)
{
	if (p<l||r<p) rtn;
	else if (p<=l&&r<=p) st[rt].pb(v);
	else
	{
		int ll=l,lr=(l+r)>>1,lrt=rt<<1;
		int rl=lr+1,rr=r,rrt=lrt|1;
		insert(ll,lr,p,v,lrt),insert(rl,rr,p,v,rrt);
		st[rt].pb(v);
	}
}
int query(int l,int r,int L,int R,int x,int y,int rt=1)
{
	if (R<l||r<L) rtn 0;
	else if (L<=l&&r<=R) rtn sz(st[rt])-(upper_bound(all(st[rt]),y)-lower_bound(all(st[rt]),x));
	else
	{
		int ll=l,lr=(l+r)>>1,lrt=rt<<1;
		int rl=lr+1,rr=r,rrt=lrt|1;
		rtn query(ll,lr,L,R,x,y,lrt)+query(rl,rr,L,R,x,y,rrt);
	}
}

int n;
S s;
int sum[200000+1993];

int main()
{
	int n;
	scanf("%d",&n);
	ft(i,1,n) scanf("%d",&s[i]);
	repf(i,1,n) s[i]=s[i+1]-s[i];
	s[n]=+oo;
	repf(i,1,n) s[n+i]=-s[i];
	n*=2;
	get_SA(s,n);
	get_height(s,n);
	get_RMQ(n);
	ft(i,n/2+1,n) insert(1,n,rank[i],i-n/2);
	int q;
	scanf("%d",&q);
	rep(i,q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int x=r-l,y=rank[l];
		int L,R,ll,rr;
		L=0,R=y;
		whl(L+1!=R)
		{
			int mid=(L+R)>>1;
			if (LCP(SA[mid],l)>=x) R=mid;
			else L=mid;
		}
		ll=R;
		L=y,R=n+1;
		whl(L+1!=R)
		{
			int mid=(L+R)>>1;
			if (LCP(SA[mid],l)>=x) L=mid;
			else R=mid;
		}
		rr=L;
		printf("%d\n",query(1,n,ll,rr,l-x,r));
	}
}

