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

//const int oo=(~0u)>>1;
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
namespace min_cost_flow
{
/*
AUTHOR: Su Jiao
DATE: 2010-7-26
DESCRIPTION:
山东2009年省选 晨跑
*/
#include <stdio.h>
#include <string.h>

#define oo 0x7f7f7f7f7f7f7f7fll
#define MAXEDGE 1000000
#define MAXV 1000

typedef struct struct_edge* edge;
struct struct_edge{lli v,c,d;edge n,b;};
struct_edge pool[MAXEDGE];
edge top;
lli S,T;
edge adj[MAXV];
lli q[MAXV];
bool inq[MAXV];
lli qh,qt;
edge p[MAXV];
lli d[MAXV];
void add_edge(lli u,lli v,lli c,lli d)
{
     top->v=v,top->c=c,top->d=d,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->d=-d,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}
void min_cost_flow(lli& flow,lli& cost)
{
    flow=0,cost=0;
    for (;;)
    {
        memset(d,char(oo),sizeof(d));
        inq[q[qh=qt=0]=S]=true;
        d[S]=0;
        p[S]=0;
        while (qh<=qt)
        {
              lli u;
              inq[u=q[(qh++)%MAXV]]=false;
              for (edge i=adj[u];i;i=i->n)
                  if (i->c&&d[i->v]>d[u]+i->d)
                  {
                     if (!inq[i->v])
                        inq[q[(++qt)%MAXV]=i->v]=true;
                     d[i->v]=d[u]+i->d;
                     p[i->v]=i;
                  }
        }
        if (d[T]==oo) break;
        else
        {
            lli delta=oo;
            for (edge i=p[T];i;i=p[i->b->v])
                if (delta>i->c) delta=i->c;
            for (edge i=p[T];i;i=p[i->b->v])
                i->c-=delta,i->b->c+=delta;
            flow+=delta;
            cost+=d[T]*delta;
        }
    }
}
}

const lli MUL=1000000000,MAXM=20,MAXN=40,MUL1000=MUL*1000;
lli N,M,K;
lli w[MAXM];
lli sumw;
lli p[MAXN];
bool matrix[MAXN][MAXM];
lli f(lli i,lli x)
{
    rtn ((MUL*4-MUL*3*sqr(100-x)/1600)*w[i])/sumw;
}

int main()
{
    lp
    {
        cin>>N>>K>>M;
        if (N==0&&M==0&&K==0) break;
        sumw=0;
        rep(i,M) cin>>w[i],sumw+=w[i];
        rep(i,M) cin>>p[i];
        rep(i,N) rep(j,M) cin>>matrix[i][j];

        #define day(i) i
        #define course(i) N+i

        //S->day(i) K,0
        //day(i)->course(j) +oo,0
        //course(j)->T

        clr(min_cost_flow::adj),min_cost_flow::top=min_cost_flow::pool;
        min_cost_flow::S=N+M,min_cost_flow::T=N+M+1;

        rep(i,N) min_cost_flow::add_edge(min_cost_flow::S,day(i),K,0);
        lli more=0;
        rep(i,M)
        {
            if (p[i]<60) min_cost_flow::add_edge(course(i),min_cost_flow::T,60-p[i],-MUL1000),more+=60-p[i];
            ft(j,max(p[i],60ll),99) min_cost_flow::add_edge(course(i),min_cost_flow::T,1,-(f(i,j+1)-f(i,j)));
        }
        rep(i,N) rep(j,M) if (matrix[i][j]) min_cost_flow::add_edge(day(i),course(j),+oo,0);
        lli flow,cost;
        min_cost_flow::min_cost_flow(flow,cost);
        if ((-cost)/MUL1000!=more)
        {
            printf("%.6f\n",0.0);
            continue;
        }
        double ans=db((-cost)%MUL1000)/MUL;
        rep(i,M) ans+=db(f(i,max(p[i],60ll)))/MUL;
        printf("%.6f\n",ans);

    }
}
