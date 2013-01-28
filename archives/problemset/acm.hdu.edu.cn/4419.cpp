//Boleyn Su's Template for Codeforces
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include <list>
//#include <set>
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
//typedef set<int> si;
//typedef set<str> ss;
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

typedef lli type;//坐标类型
enum{MAX_REC=10000+1};
struct Rec
{
    type x1,y1,x2,y2;
};
type minx=-oo,maxx=+oo,miny=-oo,maxy=+oo;//边界
int recs;//矩形个数
Rec rec[MAX_REC];//矩形的信息
typedef map<type,int> ftype;
map<type,int> f;
int gs;
type g[MAX_REC*2];
struct Event
{
    type y1,y2,x;
    int inc;
    friend bool operator<(const Event& a,const Event& b)
    {
        if (a.x==b.x) return a.inc>b.inc;
        else return a.x<b.x;
    }
};
int evts;
Event evt[MAX_REC*2];
struct Node
{
    int c,n;
    type s,s2;
    bool lc,rc;
};
Node st[MAX_REC*2*4];
void insert(int L,int R,int inc,int l,int r,int rt=1)
{
    if (R<=l||r<=L) rtn;
    else if (L<=l&&r<=R) st[rt].c+=inc;
    else
    {
        int mid=(l+r)>>1,lrt=rt<<1,rrt=lrt|1;
        insert(L,R,inc,l,mid,lrt),insert(L,R,inc,mid,r,rrt);
    }
    if(st[rt].c>=2) st[rt].s2=g[r]-g[l];
    else if (r-l>1)
    {
        int lrt=rt<<1,rrt=lrt|1;
        if (st[rt].c) st[rt].s2=st[lrt].s+st[rrt].s;
        else st[rt].s2=st[lrt].s2+st[rrt].s2;
    }
    else st[rt].s2=0;

    if (st[rt].c)
    {
        st[rt].s=g[r]-g[l];
        st[rt].n=1;
        st[rt].lc=st[rt].rc=true;
    }
    else if (r-l>1)
    {
        int lrt=rt<<1,rrt=lrt|1;
        st[rt].s=st[lrt].s+st[rrt].s;
        st[rt].n=st[lrt].n+st[rrt].n-(st[lrt].rc&&st[rrt].lc);
        st[rt].lc=st[lrt].lc;
        st[rt].rc=st[rrt].rc;
    }
    else st[rt].s=st[rt].n=st[rt].lc=st[rt].rc=0;
}
void query(type& s,type& s2,type& n,int rt=1)
{
    s=st[rt].s;
    s2=st[rt].s2;
    n=st[rt].n;
}
//S返回并面积 C返回并周长 S2返回交面积
void solve(type& S,type& C,type& S2)
{
    f.clear();
    f[miny],f[maxy];
    rep(i,recs) f[rec[i].y1],f[rec[i].y2];

    gs=0;
    feach(i,f,ftype) g[i->y=gs++]=i->x;

    evts=0;
    rep(i,recs)
    {
        evt[evts].x=max(rec[i].x1,minx),
        evt[evts].y1=rec[i].y1,
        evt[evts].y2=rec[i].y2,
        evt[evts].inc=+1,
        evts++;
        evt[evts].x=min(rec[i].x2,maxx),
        evt[evts].y1=rec[i].y1,
        evt[evts].y2=rec[i].y2,
        evt[evts].inc=-1,
        evts++;
    }
    sort(evt,evt+evts);

    S=0;
    C=0;
    S2=0;
    type lasts=0;
    clr(st);
    rep(i,evts)
    {
        type s,s2,n;
        query(s,s2,n);
        if (i) C+=type(2)*type(n)*type(evt[i].x-evt[i-1].x);
        C+=abs(lasts-s);
        lasts=s;
        if (i) S+=type(s)*type(evt[i].x-evt[i-1].x);
        if (i) S2+=type(s2)*type(evt[i].x-evt[i-1].x);
        insert(f[evt[i].y1],f[evt[i].y2],evt[i].inc,0,gs-1);
    }
    C+=abs(lasts);
}

int RS,GS,BS;
Rec R[MAX_REC],G[MAX_REC],B[MAX_REC];

int main()
{
    int TC;
    scanf("%d",&TC);
    whl(TC--)
    {
        int n;
        scanf("%d",&n);
        RS=GS=BS=0;
        rep(i,n)
        {
            char c[2];
            Rec rec;
            scanf("%s%I64d%I64d%I64d%I64d",c,&rec.x1,&rec.y1,&rec.x2,&rec.y2);
            if (*c=='R') R[RS++]=(rec);
            if (*c=='G') G[GS++]=(rec);
            if (*c=='B') B[BS++]=(rec);
        }
        type r,g,b,rg,rb,gb,rgb;
        type S,C,S2;
        recs=0;
        rep(i,RS) rec[recs++]=R[i];
        solve(S,C,S2);
        r=S;
        recs=0;
        rep(i,GS) rec[recs++]=G[i];
        solve(S,C,S2);
        g=S;
        recs=0;
        rep(i,BS) rec[recs++]=B[i];
        solve(S,C,S2);
        b=S;
        recs=0;
        rep(i,RS) rec[recs++]=R[i];
        rep(i,GS) rec[recs++]=G[i];
        solve(S,C,S2);
        rg=S;
        recs=0;
        rep(i,RS) rec[recs++]=R[i];
        rep(i,BS) rec[recs++]=B[i];
        solve(S,C,S2);
        rb=S;
        recs=0;
        rep(i,GS) rec[recs++]=G[i];
        rep(i,BS) rec[recs++]=B[i];
        solve(S,C,S2);
        gb=S;
        recs=0;
        rep(i,RS) rec[recs++]=R[i];
        rep(i,GS) rec[recs++]=G[i];
        rep(i,BS) rec[recs++]=B[i];
        solve(S,C,S2);
        rgb=S;

        type rAg=r+g-rg,rAb=r+b-rb,gAb=g+b-gb,rAgAb=rgb+rAg+rAb+gAb-r-g-b;
        // R, G, B, RG, RB, GB, RGB).
        static int t;
        printf("Case %d:\n%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n",
        ++t,
        r-rAg-rAb+rAgAb,
        g-rAg-gAb+rAgAb,
        b-gAb-rAb+rAgAb,
        rAg-rAgAb,
        rAb-rAgAb,
        gAb-rAgAb,
        rAgAb);
    }
}
