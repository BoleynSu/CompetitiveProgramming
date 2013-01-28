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
#define repf(i,a,b) for (int i=a;i<(b);++i)
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
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}

int type(char t)
{
    if (t=='L') rtn 0;
    else if (t=='O') rtn 1;
    else if (t=='V') rtn 2;
    else rtn 3;
}
pll operator+(const pll& a,const pll& b)
{
    rtn mp(a.x+b.x,a.y+b.y);
}
bool operator<(const pll& a,const pll& b)
{
    if (a.x!=b.x) rtn a.x<b.x;
    else rtn a.y>b.y;
}

enum{MAXE=200000,MAXV=200000};
struct struct_edge{int v;pll d;struct_edge* n;};
typedef struct_edge* edge;
edge top;
struct_edge pool[MAXE];
edge adj[MAXV];
void add_edge(int u,int v,pll d)
{
    top->v=v,top->d=d,top->n=adj[u],adj[u]=top++;
}
int qh,qt;
bool inq[MAXV];
int q[MAXV];
pll d[MAXV];
#define oo 0x7f7f7f7f7f7f7f7fll
pll spfa(int S,int T)
{
    fl(d,oo);
    d[S]=mp(0,0);
    inq[q[qh=qt]=S]=true;
    whl(qh<=qt)
    {
        int u=q[(qh++)%MAXV];
        inq[u]=false;
        for (edge e=adj[u];e;e=e->n)
            if ((((e->v==1*4+(type('E')+1)%4&&d[e->v].y==0)?d[e->v]=d[u]+e->d,true:false)||cmin(d[e->v],d[u]+e->d))&&!inq[e->v])
                inq[q[(++qt)%MAXV]=e->v]=true;
    }
    rtn d[T];
}

int main()
{
    int T;
    cin>>T;
    whl(T--)
    {
        top=pool,clr(adj);
        int N,M;
        cin>>N>>M;
        rep(i,M)
        {
            int u,v,d;
            char t;
            cin>>u>>v>>d>>t;
            t=type(t);
            add_edge(u*4+t,v*4+(t+1)%4,mp(d,1));
            add_edge(v*4+t,u*4+(t+1)%4,mp(d,1));
        }
        add_edge(0,1*4+(type('E')+1)%4,mp(0,0));
        pll ans=spfa(0,N*4+(type('E')+1)%4);
        static int tc;
        if (ans.x==oo||ans.y==0) cout<<"Case "<<++tc<<": Binbin you disappoint Sangsang again, damn it!"<<endl;
        else cout<<"Case "<<++tc<<": Cute Sangsang, Binbin will come with a donkey after travelling "<<ans.x<<" meters and finding "<<ans.y/4<<" LOVE strings at last."<<endl;
    }
}

