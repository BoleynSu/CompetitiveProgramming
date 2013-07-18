/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间
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

//用于减少代码量的宏
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))

//调试相关的宏
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

//常用数据类型
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

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
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
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化
struct Initializer
{
#ifndef DEBUG
	Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
	~Initializer(){runtime();}
#endif
}initializer;

//非标准
#define feach(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using __gnu_cxx::rope;
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#define ctz __builtin_ctz
#define clz __builtin_clz
#define bc __builtin_popcount

int a[24];
int b[2];
pr<pii,int> lst2[2][1<<12];
int lst2s[2];
pr<pr<pii,pii>,int> lst3[2][531441];
int lst3s[2];

void dfs2(int a[],int n,pr<pii,int> lst[],int& lsts,int sum0,int cnt0,int i)
{
	if (i==n)
	{
		lst[lsts++].x=mp(sum0,cnt0);
	}
	else
	{
		dfs2(a,n,lst,lsts,min(lli(sum0)+a[i],lli(oo)),cnt0+1,i+1);
		dfs2(a,n,lst,lsts,sum0,cnt0,i+1);
	}
}
void dfs3(int a[],int n,pr<pr<pii,pii>,int> lst[],int& lsts,int sum0,int cnt0,int sum1,int cnt1,int i)
{
	if (i==n)
	{
		lst[lsts++].x=mp(mp(sum0,cnt0),mp(sum1,cnt1));
	}
	else
	{
		dfs3(a,n,lst,lsts,min(lli(sum0)+a[i],lli(oo/2)),cnt0+1,sum1,cnt1,i+1);
		dfs3(a,n,lst,lsts,sum0,cnt0,min(lli(sum1)+a[i],lli(oo/2)),cnt1+1,i+1);
		dfs3(a,n,lst,lsts,sum0,cnt0,sum1,cnt1,i+1);
	}
}

lli get2(pr<pii,int> lst0[],int lst0s,pr<pii,int> lst1[],int lst1s,pii sum)
{
	lli ans=0;
	int i=0;
	fdt(j,lst1s-1,0)
	{
		whl(i+1<lst0s&&lst0[i].x+lst1[j].x<sum) i++;
		if (lst0[i].x+lst1[j].x==sum) ans+=lli(lst0[i].y)*lli(lst1[j].y);
	}
	rtn ans;
}
lli get3(pr<pr<pii,pii>,int> lst0[],int lst0s,pr<pr<pii,pii>,int> lst1[],int lst1s,pr<pii,pii> sum)
{
	lli ans=0;
	int i=0;
	fdt(j,lst1s-1,0)
	{
		whl(i+1<lst0s&&lst0[i].x+lst1[j].x<sum) i++;
		if (lst0[i].x+lst1[j].x==sum) ans+=lli(lst0[i].y)*lli(lst1[j].y);
	}
	rtn ans;
}

int main()
{
	int n;
	cin>>n;
	rep(i,n) cin>>a[i];
	int k;
	cin>>k;
	rep(i,k) cin>>b[i];
	sort(a,a+n),sort(b,b+k);
	k=unique(b,b+k)-b;
	dfs2(a,n/2,lst2[0],lst2s[0],0,0,0);
	dfs2(a+n/2,n-n/2,lst2[1],lst2s[1],0,0,0);
	dfs3(a,n/2,lst3[0],lst3s[0],0,0,0,0,0);
	dfs3(a+n/2,n-n/2,lst3[1],lst3s[1],0,0,0,0,0);
	rep(i,2)
	{
		sort(lst2[i],lst2[i]+lst2s[i]),sort(lst3[i],lst3[i]+lst3s[i]);
		int j;
		j=0;
		rep(k,lst2s[i])
		{
			lst2[i][j].x=lst2[i][k].x;
			lst2[i][j].y=1;
			whl(k+1<lst2s[i]&&lst2[i][k+1].x==lst2[i][j].x) k++,lst2[i][j].y++;
			j++;
		}
		lst2s[i]=j;
		j=0;
		rep(k,lst3s[i])
		{
			lst3[i][j].x=lst3[i][k].x;
			lst3[i][j].y=1;
			whl(k+1<lst3s[i]&&lst3[i][k+1].x==lst3[i][j].x) k++,lst3[i][j].y++;
			j++;
		}
		lst3s[i]=j;
	}
	lli ans=1;
	ft(i,1,n) ans=mod(ans*i);
	if (k==0) ;//do nothing
	else if (k==1)
	{
		ft(i,1,n)
		{
			lli m=1;
			ft(j,1,i) m=mod(m*j);
			ft(j,1,n-i) m=mod(m*j);
			ans-=get2(lst2[0],lst2s[0],lst2[1],lst2s[1],mp(b[0],i))*m;
		}
	}
	else if (k==2)
	{
		ft(i,1,n)
		{
			lli m=1;
			ft(j,1,i) m=mod(m*j);
			ft(j,1,n-i) m=mod(m*j);
			ans-=get2(lst2[0],lst2s[0],lst2[1],lst2s[1],mp(b[0],i))*m;
		}
		ft(i,1,n)
		{
			lli m=1;
			ft(j,1,i) m=mod(m*j);
			ft(j,1,n-i) m=mod(m*j);
			ans-=get2(lst2[0],lst2s[0],lst2[1],lst2s[1],mp(b[1],i))*m;
		}
		ft(i,1,n) ft(j,1,n-i)
		{
			lli m=1;
			ft(k,1,i) m=mod(m*k);
			ft(k,1,j) m=mod(m*k);
			ft(k,1,n-i-j) m=mod(m*k);
			ans+=get3(lst3[0],lst3s[0],lst3[1],lst3s[1],mp(mp(b[0],i),mp(b[1]-b[0],j)))*m;
		}
	}
	else ;//never happen
	ans=mod(ans);
	if (ans<0) ans+=MOD;
	cout<<ans<<endl;
}

