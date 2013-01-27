//begin #include <Core>
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
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;
#if __GNUC__>=4 and __GNUC_MINOR__>=7
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#elif __GNUC__>=4 and __GNUC_MINOR__>=6
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#endif

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+10;
const db eps=1e-10;
const db pi=acos(-1.0);
const int dx[]={-1,1,0,0,-1,-1,1,1,0};
const int dy[]={0,0,-1,1,-1,1,-1,1,0};
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<"("<<x.x<<","<<x.y<<")";}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type b){rtn mp(a.x/b,a.y/b);}
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
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;
//end #include <Core>

//typedef unsigned char type;
//const type MAXN=7,MAXM=70;
//type st[MAXM];
//type clsts[1<<MAXN];
//type clst[1<<MAXN][1<<MAXN];
//type f[1<<MAXN][1<<MAXN],g[1<<MAXN][1<<MAXN][1<<MAXN];
//
//int main()
//{
//	int m,n;
//	cin>>m>>n;
//	rep(i,m) rep(j,n)
//	{
//		char c;
//		cin>>c;
//		st[i]=(st[i]<<1)|(c=='*');
//	}
//
//	type rs1n=1<<n;
//	rep(s1,rs1n) rep(s2,rs1n)
//	{
//		bool can=true;
//		for (type i=1;i<rs1n;i<<=1)
//			if (!((s1&i)||(s2&i))||!(!(i>>1)||((s1&i)||(s1&(i>>1)))))
//				can=false;
//		if (can) clst[s1][clsts[s1]++]=s2;
//	}
//
//	fl(f,254);
//	f[rs1n-1][rs1n-1]=0;
//	rep(i,m)
//	{
//		fl(g,254);
//		rep(s1,rs1n) rep(s2,rs1n) g[st[i]][s1][s2]=f[s1][s2];
//		rep(s1,rs1n) if ((s1&st[i])==st[i]&&s1!=st[i])
//		{
//			type s=s1^st[i];
//			type i=s&-s;
//			rep(s2,rs1n) rep(s3,rs1n)
//			{
//				if ((s2&i)) cmin(g[s1][s2][s3],type(g[s1^i][s2^i][s3]+1));
//				if ((s1&(i<<1))) cmin(g[s1][s2][s3],type(g[s1^i^(i<<1)][s2][s3]+1));
//			}
//		}
//		fl(f,254);
//		rep(s1,rs1n) rep(s2,rs1n) rep(i,clsts[s2]) cmin(f[s1][s2],g[s1][s2][clst[s2][i]]);
//	}
//	type ans=254;
//	rep(s1,rs1n) rep(i,clsts[s1]) cmin(ans,f[s1][clst[s1][i]]);
//	cout<<int(ans)<<endl;
//}

typedef unsigned char State;
#define oo 0x39393939

const int MAXN=7,MAXM=70;
int n,m;
State st[MAXM];
int ps2lsts[1<<MAXN][1<<MAXN];
State ps2lst[1<<MAXN][1<<MAXN][1<<MAXN];
int s3lsts[1<<MAXN];
State s3lst[1<<MAXN][1<<MAXN];
int f[1<<MAXN][1<<MAXN],g[1<<MAXN][1<<MAXN];
int bit_count[1<<MAXN];

void dfs(State lst[],int& lsts,int s1,int s2)
{
	if (s1)
	{
		int i=s1&-s1;
		if (s2&i) dfs(lst,lsts,s1^i,s2^i);
		if (s1&(i<<1)) dfs(lst,lsts,s1^i^(i<<1),s2);
	}
	else lst[lsts++]=s2;
}

int main()
{
	cin>>m>>n;
	rep(i,m) rep(j,n)
	{
		char c;
		cin>>c;
		st[i]=(st[i]<<1)|(c=='*');
	}

	State max=(1<<n);
	rep(s2,max) rep(s3,max)
	{
		bool psb=true;
		for (State i=1;i<max;i<<=1)
			if ((!(s2&i)&&!(s3&i))||((i<<1)!=max&&!(s2&i)&&!(s2&(i<<1))))
				psb=false;
		if (psb) s3lst[s2][s3lsts[s2]++]=s3;
	}
	rep(s1,max) rep(s2,max) dfs(ps2lst[s1][s2],ps2lsts[s1][s2],s1,s2);
	rep(s,max) for (State i=1;i!=max;i<<=1) if (s&i) bit_count[s]++;

	fl(f,oo);
	f[max-1][max-1]=0;
	rep(i,m)
	{
		fl(g,oo);
		rep(s1,max) if (!(s1&st[i]))
			rep(s2,max) rep(ps2i,ps2lsts[s1][s2]) rep(s3i,s3lsts[s2])
				cmin(g[s1|st[i]][s2],f[ps2lst[s1][s2][ps2i]][s3lst[s2][s3i]]+(bit_count[s1]+bit_count[s2^ps2lst[s1][s2][ps2i]])/2);
		cpy(f,g);
	}

	int ans=oo;
	rep(s2,max) rep(s3i,s3lsts[s2]) cmin(ans,f[s2][s3lst[s2][s3i]]);
	cout<<ans<<endl;
}
