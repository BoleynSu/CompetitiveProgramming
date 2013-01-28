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

//O(n)的筛法求素数表
//MAXPS=[1,MAXP]中素数的个数
enum{MAXP=400000,MAXPS=33860};
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

lli calc(lli n,lli r)
{
        vi p;
        lli x=n;
        whl (x!=1)
        {
            lli y;
            p.pb(y=fac[x]);
            whl(x%y==0) x/=y;
        }
        lli sum=0;
        fdt(msk,(1<<sz(p))-1,1)
        {
               int mult=1,bits=0;
               rep(i,sz(p)) if (msk&(1<<i)) bits++,mult*= p[i];

               lli cur=r/mult;
               if (bits&1) sum +=cur*(cur+1)/2*mult;
               else sum-=cur*(cur+1)/2*mult;
        }
        rtn r*(r+1)/2-sum;
}
int main()
{
    make_prime_table();
    int t;
    scanf("%d",&t);
    whl(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        mii s;
        rep(i,m)
        {
            int op;
            scanf("%d",&op);
            if (op==1)
            {
                int l,r,p;
                scanf("%d%d%d",&l,&r,&p);
                lli ans=calc(p,r)-calc(p,l-1);
                for (mii::itr it=s.lower_bound(l);it!=s.end()&&it->x<=r;it++)
                    if (gcd(it->y,p)==1)
                    {
                        if (gcd(it->x,p)==1) ans+=it->y-it->x;
                        else ans+=it->y;
                    }
                    else if (gcd(it->x,p)==1) ans+=-it->x;
                printf("%I64d\n",ans);
            }
            else
            {
                int x,p;
                scanf("%d%d",&x,&p);
                s[x]=p;
            }
        }
    }
}
