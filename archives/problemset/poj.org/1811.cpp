
/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-12-21
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
#define ins insert
#define rnk order_of_key
#define sel find_by_order
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(x))
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
#define runtime() cerr
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
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename ostream,typename type>ostream& operator<<(ostream& cout,const pr<type,type>& x){rtn cout<<"("<<x.x<<","<<x.y<<")";}
template<typename type>pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
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


/*
 * Package: StandardCodeLibrary.NumberTheory
 * Last Update: 2012-12-21
 * Description:
 * O(n)的筛法求素数表;
 * Rabin-Miller素数测试;
 * Pollard's rho大数分解;
 * 计算phi;
 * 扩展gcd;
 * 中国剩余定理;
 * 指数循环节.
 * */

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
enum{MAXP=10000000,MAXPS=664579};
bool isp[MAXP+1];//isp[x]=x是否为素数
int pp[MAXP+1];//pp[x]=x在素数表中的位置(从0开始)
int fac[MAXP+1];//fax[x]=x最小的质因子(x<=1时无意义)
int ps;//素数表的大小
int p[MAXPS];//素数表
void make_prime_table()
{
	fl(isp,true);
	isp[0]=isp[1]=false;
	ft(i,2,MAXP)
	{
		if (isp[i]) pp[p[ps]=i]=ps,ps++,fac[i]=i;
		for (int j=0;p[j]*i<=MAXP;j++)
		{
			isp[p[j]*i]=false,fac[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
}

lli mulWithMod(lli x,lli y,lli z)
{
	lli ret=0;
	x%=z;
	y%=z;
	whl(y)
	{
		if (y&1)
		{
			ret+=x;
			if (ret>=z) ret-=z;
		}
		x<<=1;
		if (x>=z) x-=z;
		y>>=1;
	}
	rtn ret;
}
lli powWithMod(lli x,lli y,lli z)
{
	lli ret=1;
	x%=z;
	whl(y)
	{
		if (y&1) ret=mulWithMod(ret,x,z);
		y>>=1;
		x=mulWithMod(x,x,z);
	}
	rtn ret;
}

//Rabin-Miller素数测试
bool isProbablePrime(lli n,lli k=50)
{
	if (n<=1) rtn false;
	else if (n<=3) rtn true;
	else
	{
		lli d=n-1;
		whl(!(d&1)) d>>=1;
		rep(i,k)
		{
			lli a=rand()%(n-3)+2;//2 to n-2
			lli x=powWithMod(a,d,n);
			if (x==1) continue;
			whl(d!=n-1&&x!=n-1&&x!=1)
			{
				x=mulWithMod(x,x,n);
				d<<=1;
			}
			if (x!=n-1) rtn false;
		}
		rtn true;
	}
}

//Pollard's rho大数分解
lli factor(lli n,lli k=50)
{
	if (isProbablePrime(n,k)) rtn n;
	lp
	{
		lli d=1,x=rand()%(n-1)+1,//1 to n-1
				y=rand()%(n-1)+1,//1 to n-1
				c=rand()%n;
		if (c==0) c++;//c!=0
		if (c==n-2) c++;//c!=n-2
		lli loop=0;
		whl(d==1)
		{
			loop++;
			if (((-loop)&loop)==loop) y=x;
			x=(mulWithMod(x,x,n)+c)%n;
			if (x==y) break;
			d=gcd(y-x+n,n);
			if (d!=1&&d!=n) rtn factor(d,k);
		}
	}
}

//计算phi
lli phi(lli x,lli k=50)
{
	lli ret=x;
	whl(x!=1)
	{
		lli d=factor(x,k);//如果是小范围的 此处可用fac[x]代替
		ret/=d;
		ret*=d-1;
		whl(x%d==0) x/=d;
	}
	rtn ret;
}

//扩展gcd
lli gcd(lli a,lli b,lli& x,lli& y)
{
	if (b)
	{
		lli g=gcd(b,a%b,y,x);
		rtn y-=a/b*x,g;
	}
	else rtn x=1,y=0,a;
}

//中国剩余定理
//一般地,中国剩余定理是指若有一些两两互质的整数m[i],则对任意的整数a[i],以下联立同余方程组对模m[i]有公解
//x mod m[i]=a[i]
lli chinese_remainder(lli n,lli m[],lli a[])
{
	lli lcm=1;
	rep(i,n) lcm*=m[i];
	lli ans=0;
	rep(i,n)
	{
		lli Mi=lcm/m[i],x,y;
		gcd(Mi,m[i],x,y);
		ans+=Mi*x*a[i];
		ans%=lcm;
	}
	if (ans<0) ans+=lcm;
	rtn ans;
}

//指数循环节
//如果(a,p)=1		a^x%p=a^(x%phi(p))%p
//否则若x>=phi(p)	a^x%p=a^(x%phi(p)+phi(p))%p
lli mod(lli x,lli phip)
{
	rtn x>=phip?x%phip+phip:x;
}

int main()
{
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        lli x;
        cin>>x;
        if (isProbablePrime(x)) cout<<"Prime"<<endl;
        else
        {
            lli mind=x;
            while (x!=1)
            {
                  lli d=factor(x);
                  if (mind>d) mind=d;
                  while (x%d==0) x/=d;
            }
            cout<<mind<<endl;
        }
    }
}
