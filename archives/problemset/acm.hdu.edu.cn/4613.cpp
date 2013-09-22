#ifndef DEBUG
//https://github.com/boleynsu/acmicpc-codes/blob/master/templates/Core.hpp
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
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define rrepf(i,a,b) fdt(i,(a)-1,b)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
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
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;

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
inline lli bin_pow(lli x,lli y){lli z=1;whl(y){if(y&1)z=mod(z*x);x=mod(sqr(x)),y>>=1;}rtn z;}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));rrep(i,y){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
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
#else
//上面部分的代码生成的Precompiled Headers
#include <Core>
#endif

const int MAXN=25000;
int nxt[MAXN];
struct pt
{
    db x,y,d,l;
    pt(){}
    pt(db x,db y):x(x),y(y){}
};
pt p[MAXN];
int ts,s1s,s2s;
pr<db,db> t[MAXN],s1[MAXN],s2[MAXN];
double dis(const pt& a,const pt& b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
bool cmp(const pt& a,const pt& b)
{
    if (fabs(a.d-b.d)<eps) return a.l<b.l;
    else return a.d<b.d;
}
double dot(const pt& a,const pt& b)
{
    return a.x*b.x+a.y*b.y;
}
double cross(const pt& a,const pt& b)
{
    return a.x*b.y-a.y*b.x;
}
bool eq(const pair<double,double>& a,const pair<double,double>& b)
{
    return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
}
void read(int& cnt)
{
    cnt=0;

    int k;
    scanf("%d",&k);
    double x=0,y=0;
    for (int i=0;i<k;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        x+=p[i].x,y+=p[i].y;
    }
    x/=k,y/=k;
    pt o=pt(x,y);
    for (int i=0;i<k;i++) if (dis(o,p[i])<eps)
    {
        cnt++;
        p[i--]=p[--k];
    }
    double maxd=0;
    for (int i=0;i<k;i++)
    {
        double d=dis(o,p[i]);
        if (maxd<d) maxd=d;
    }
    for (int i=0;i<k;i++)
    {
        p[i].x=(p[i].x-o.x)/maxd;
        p[i].y=(p[i].y-o.y)/maxd;
        p[i].d=atan2(p[i].y,p[i].x);
        p[i].l=sqr(p[i].x)+sqr(p[i].y);
    }
    sort(p,p+k,cmp);
    ts=(k);
    for (int i=0,j=k-1;i<k;j=i++) t[i]=(mp(p[i].l,i?p[i].d-p[j].d:p[i].d-p[j].d+2*pi));
}
void read2(int& cnt)
{
    cnt=0;

    int k;
    scanf("%d",&k);
    double x=0,y=0;
    for (int i=0;i<k;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        x+=p[i].x,y+=p[i].y;
    }
    x/=k,y/=k;
    pt o=pt(x,y);
    for (int i=0;i<k;i++) if (dis(o,p[i])<eps)
    {
        cnt++;
        p[i--]=p[--k];
    }
    double maxd=0;
    for (int i=0;i<k;i++)
    {
        double d=dis(o,p[i]);
        if (maxd<d) maxd=d;
    }
    for (int i=0;i<k;i++)
    {
        p[i].x=(p[i].x-o.x)/maxd;
        p[i].y=(p[i].y-o.y)/maxd;
        p[i].d=atan2(p[i].y,p[i].x);
        p[i].l=sqr(p[i].x)+sqr(p[i].y);
    }
    sort(p,p+k,cmp);
    s1s=(k);
    for (int i=0,j=k-1;i<k;j=i++) s1[i]=(mp(p[i].l,i?p[i].d-p[j].d:p[i].d-p[j].d+2*pi));
    for (int i=0;i<k;i++)
    {
        p[i].x=-p[i].x;
        p[i].d=-p[i].d;
    }
    reverse(p,p+k);
    for (int i=0;i<k;i++)
    {
        int b=i,e=i+1;
        whl(e<k&&dbcmp(p[b].d,p[e].d)==0) e++;
        reverse(p+b,p+e);
        i=e-1;
    }
    //sort(p,p+k,cmp);
    s2s=(k);
    for (int i=0,j=k-1;i<k;j=i++) s2[i]=(mp(p[i].l,i?p[i].d-p[j].d:p[i].d-p[j].d+2*pi));
}
bool match(pair<double,double> s[],int ss)
{
    if (ss!=ts) return false;
    if (ts==0) return true;
    int j=-1;
    for (int _i=0;_i<ss*2;_i++)
    {
        int i=_i>=ss?_i-ss:_i;
        while (j!=-1&&!eq(t[j+1],s[i])) j=nxt[j];
        if (eq(t[j+1],s[i])) j++;
        if (j==ts-1) return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int tcnt;
        read(tcnt);
        //for (int i=0;i<sz(t);i++)
        //    printf("%f %f\n",t[i].x,t[i].y);
        int j=-1;
        nxt[0]=-1;
        for (int i=1;i<ts;i++)
        {
            while (j!=-1&&!eq(t[j+1],t[i])) j=nxt[j];
            if (t[j+1]==t[i]) j++;
            nxt[i]=j!=-1&&i+1<ts&&eq(t[j+1],t[i+1])?nxt[j]:j;
        }
        int n;
        scanf("%d",&n);
        while (n--)
        {
            int scnt;
            read2(scnt);
            //for (int i=0;i<sz(s2);i++)
            //    printf("%f %f\n",s2[i].x,s2[i].y);
            puts((scnt==tcnt)&&(match(s1,s1s)||match(s2,s2s))?"Yes":"No");
        }
        puts("");
    }
}

