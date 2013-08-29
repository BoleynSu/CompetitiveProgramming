/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间;
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

//用于减少代码量的宏;
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rrepf(i,a,b) for (int i=(a)-1;i>=(b);--i)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
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
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))

//调试相关的宏;
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<"第"<<__LINE__<<"行\t: "<<#x"\t="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型;
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

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数;
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
inline void make_set(vpii& st){rep(i,sz(st))st[i]=mp(i,1);}
inline int find_set(vpii& st,int x){int y=x,z;whl(y!=st[y].x)y=st[y].x;whl(x!=st[x].x)z=st[x].x,st[x].x=y,x=z;rtn y;}
inline bool union_set(vpii& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?(st[a].y>st[b].y?st[a].x=b,st[a].y+=st[b].y:st[b].x=a,st[b].y+=st[a].y),true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化;
struct Initializer{
#ifndef DEBUG
Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
~Initializer(){runtime();}
#endif
}initializer;

////非标准;
//#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//typedef __gnu_cxx::rope<char> rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount
/*
 * Package: StandardCodeLibrary.NumberTheory
 * Description:
 * O(n)的筛法求素数表;
 * 带mod的乘法;
 * 带mod的指数函数;
 * Rabin-Miller素数测试;
 * Pollard's rho大数分解;
 * 计算phi;
 * 扩展gcd;
 * 中国剩余定理;
 * 指数循环节;
 * */

namespace StandardCodeLibrary
{
namespace Math
{
namespace NumberTheory
{

typedef unsigned long long big;

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
const int MAXP=10000000;
const int MAXPS=664579;
bool isp[MAXP+1];//isp[x]=x是否为素数
int pp[MAXP+1];//pp[x]=x在素数表中的位置(从0开始)
int fac[MAXP+1];//fac[x]=x最小的质因子(x<=1时无意义)
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

//带mod的加法 0<=a,b<mod
#define add(a,b,mod) ((a)>=(mod)-(b)?(b)-((mod)-(a)):(a)+(b))
//带mod的乘法 0<=a,b<mod
big mul(big a,big b,big mod)
{
    big c=0;
    whl(b)
    {
        if (b&1) c=add(c,a,mod);
        a=add(a,a,mod);
        b>>=1;
    }
    rtn c;
}
//带mod的指数函数 0<=a,b<mod
big pow(big a,big b,big mod)
{
    big c=1;
    whl(b)
    {
        if (b&1) c=mul(c,a,mod);
        a=mul(a,a,mod);
        b>>=1;
    }
    rtn c;
}
//Rabin-Miller素数测试 n>1且n为奇数
bool witness(big n)
{
    big nm1=n-1;
    big a=rand()%nm1+1;
    big d=nm1;
    whl((d&1)==0) d>>=1;
    big x=pow(a,d,n);
    if (x==1) rtn true;
    lp
    {
        if (x==nm1) rtn true;
        d<<=1;
        if (d==nm1) rtn false;
        x=mul(x,x,n);
    }
}
//Rabin-Miller素数测试 n>=2
bool isprime(big n,int k=20)
{
    if (n%2==0) rtn n==2;
    else
    {
        rep(i,k) if (!witness(n)) rtn false;
        rtn true;
    }
}
//Pollard's rho大数分解 n>1且n为合数
big rho(big n)
{
    if (n%2==0) rtn big(2);
    else
    {
        big d;
        big c=rand()%n;
        big x=rand()%n;
        big y=x;
        do
        {
            x=add(mul(x,x,n),c,n);
            y=add(mul(y,y,n),c,n);
            y=add(mul(y,y,n),c,n);
            if (x>y) d=gcd(x-y,n);
            else d=gcd(y-x,n);
        }
        whl(d==1);
        rtn d;
    }
}
//Pollard's rho大数分解 n>1
big factor(big n,int k=20)
{
    if (isprime(n,k)) rtn n;
    else
    {
        big d;
        do d=rho(n);
        whl(d==1||d==n);
        rtn factor(d);
    }
}
#undef add

//计算phi
lli phi(lli x,int k=20)
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
//如果(a,p)=1        a^x%p=a^(x%phi(p))%p
//否则若x>=phi(p)    a^x%p=a^(x%phi(p)+phi(p))%p
lli mod(lli x,lli phip)
{
    rtn x>=phip?x%phip+phip:x;
}

}
}
}
using namespace StandardCodeLibrary::Math::NumberTheory;

int main()
{
    int f[32+2];
    ft(i,1,32) f[i]=(i+1)*(i+1)*(i+1)-i*i*i-i*i*i+(i-1)*(i-1)*(i-1);
    int T;
    sf("%d",&T);
    whl(T--)
    {
        int L,G;
        sf("%d%d",&G,&L);
        //GCD(A,B,C)=1 LCM(A,B,C)=L/G;
        int ans=1;
        if (L%G==0)
        {
            int x=L/G;
            whl(x!=1)
            {
                int y=factor(x);
                int z=0;
                whl(x%y==0) z++,x/=y;
                ans*=f[z];
            }
        }
        else ans=0;
        pf("%d\n",ans);
    }
}
