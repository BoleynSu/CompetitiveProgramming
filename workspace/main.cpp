/*
 * Package: StandardCodeLibrary.Core
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
#if __GNUC__>=4 and __GNUC_MINOR__>=6
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#endif
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
#define typeof decltype
#endif
using namespace std;

#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s) for (typeof((s).begin()) e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=(set)&((set)-1);subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0))
#ifdef DEBUG
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#else
#define endl (char('\n'))
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
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
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef vec<pii> vpii;
typedef vec<pdd> vpdd;
#if __GNUC__>=4 and __GNUC_MINOR__>=6
using __gnu_cxx::rope;
#endif
#if __GNUC__>=4 and __GNUC_MINOR__>=7
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#elif __GNUC__>=4 and __GNUC_MINOR__>=6
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#endif

int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gamma=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

/*
 * Package: StandardCodeLibrary.StringAlgorithms.SuffixArray
 * */

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{
namespace SuffixArray
{

const int LOG2_MAXLENGTH=20;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
typedef char string[MAXLENGTH];
string s;
int len;
int _a[MAXLENGTH],_b[MAXLENGTH],_c[MAXLENGTH],_d[MAXLENGTH];
int* srt;
int* SA=_a;
int* rnk=_b;
int* TSA=_c;
int* Trnk=_d;
void get_SA()
{
	srt=Trnk;
	rep(i,256) srt[i]=0;
	rep(i,len) srt[s[i]]++;
	repf(i,1,256) srt[i]+=srt[i-1];
	rep(i,len) SA[--srt[s[i]]]=i;
	rnk[SA[0]]=0;
	repf(i,1,len)
		rnk[SA[i]]=rnk[SA[i-1]]+(s[SA[i]]!=s[SA[i-1]]);
	for (int block=1;rnk[SA[len-1]]!=len-1;block<<=1)
	{
		srt=Trnk;
		rep(i,len) srt[rnk[SA[i]]]=i;
		fdt(i,len-1,0) if (SA[i]-block>=0) TSA[srt[rnk[SA[i]-block]]--]=SA[i]-block;
		repf(i,len-block,len) TSA[srt[rnk[i]]--]=i;
		int* swap;
		swap=SA,SA=TSA,TSA=swap;
		swap=rnk,rnk=Trnk,Trnk=swap;
		rnk[SA[0]]=0;
		repf(i,1,len)
			rnk[SA[i]]=rnk[SA[i-1]]+(Trnk[SA[i]]!=Trnk[SA[i-1]]
									||Trnk[SA[i]+block]!=Trnk[SA[i-1]+block]);
	}
}
int* ht;
void get_height()
{
	ht=TSA;
	for (int i=0,h=0;i<len;i++)
	{
		if (h) h--;
		if (rnk[i])
		{
			int j=SA[rnk[i]-1];
			whl(s[i+h]==s[j+h]) h++;
		}
		ht[rnk[i]]=h;
	}
}
int* log2;
int rmq[LOG2_MAXLENGTH+1][MAXLENGTH];
void get_RMQ()
{
	log2=Trnk-1;
	log2[1]=0;
	ft(i,2,len) log2[i]=log2[i>>1]+1;
	rep(i,len) rmq[0][i]=i;
	ft(log,1,log2[len])
	{
		int exp=1<<log,exp_div_2=exp>>1;
		rep(i,len-exp+1)
		{
			int a=rmq[log-1][i];
			int b=rmq[log-1][i+exp_div_2];
			rmq[log][i]=ht[a]<ht[b]?a:b;
		}
	}
}
int RMQ(int a,int b)
{
	int log=log2[b-a+1];
	int exp=1<<log;
	a=rmq[log][a],b=rmq[log][b-exp+1];
	rtn ht[a]<ht[b]?a:b;
}
int LCP(int a,int b)
{
	if (a==b) rtn len-a;
	a=rnk[a],b=rnk[b];
	if (a>b) rtn ht[RMQ(b+1,a)];
	else rtn ht[RMQ(a+1,b)];
}

}
}
}

using namespace StandardCodeLibrary::StringAlgorithms::SuffixArray;

#define nd(l,r) (st[((l)+(r))|((l)!=(r))])
#define rt nd(l,r)
#define lc nd(l,m)
#define rc nd(m+1,r)
struct node{lli sum;int lzv;bool lz;};
node st[(100000<<1)+1];
void upd(int l,int r,int L,int R,int v)
{
	if (R<l||r<L) ;
	else if (L<=l&&r<=R)
	{
		rt.sum=lli(r-l+1)*v;
		rt.lzv=v;
		rt.lz=true;
	}
	else
	{
		int m=(l+r)>>1;
		if (rt.lz)
		{
			rt.lz=false;
			lc.sum=lli(m-l+1)*rt.lzv;
			lc.lzv=rt.lzv;
			lc.lz=true;
			rc.sum=lli(r-m)*rt.lzv;
			rc.lzv=rt.lzv;
			rc.lz=true;
		}
		upd(l,m,L,R,v),upd(m+1,r,L,R,v);
		rt.sum=lc.sum+rc.sum;
	}
}
lli qry(int l,int r,int L,int R)
{
	if (R<l||r<L) rtn 0;
	else if (L<=l&&r<=R) rtn rt.sum;
	else
	{
		int m=(l+r)>>1;
		if (rt.lz)
		{
			rt.lz=false;
			lc.sum=lli(m-l+1)*rt.lzv;
			lc.lzv=rt.lzv;
			lc.lz=true;
			rc.sum=lli(r-m)*rt.lzv;
			rc.lzv=rt.lzv;
			rc.lz=true;
		}
		rtn qry(l,m,L,R)+qry(m+1,r,L,R);
	}
}

int main()
{
	cin>>s;
	len=strlen(s)+1;
	get_SA();
	get_height();
	get_RMQ();
	lli ans=-len;
	rep(i,len)
	{
		upd(0,len-1,ht[i],len-1,i-1);
		ans+=lli(len-SA[i])*i-qry(0,len-1,0,len-SA[i]-1);
		prt(ans);
	}
	cout<<ans<<endl;
}
