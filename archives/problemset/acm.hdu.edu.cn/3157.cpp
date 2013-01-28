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
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define itr iterator
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
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
//typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+8;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}
/*
Package:
图论.网络流.最大流

Description:
ISAP实现的最大流

Interface:
MAXV:{
需要为点分配多少空间
Warning:
点不一定要从0到V-1，即MAXV应该等于实际最大的标号+1
}
MAXE:{
需要为边分配多少空间
Warning:
一条边对应一条正向边和一条反向边，即注意MAXE要等于实际最大边数*2
}
add_edge:{
输入int u,v,c
add_edge(u,v,c) 加一条u到v的容量为c的有向边
}
build_network:{
构图
详细见函数内的注释
}
sap:{
输出int
sap()=最大流
}

Include:
#include <cstring>
using std::memset;

Test:
已经测过许多数据，可信任

References:
ZKW's Lab(http://www.artofproblemsolving.com/blog/54266)

Latest Update:
2011-10-27
*/
enum{MAXV=1000000+2,MAXE=1000000+2};
typedef struct struct_edge* edge;
struct struct_edge{int v,c;edge n,b;};
struct_edge pool[MAXE];
edge top;
int S,T,V;
edge adj[MAXV];
void add_edge(int u,int v,int c)
{
     top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}
void build_network()
{
     fl(adj,0),top=pool;
     //S,T,V;//源，汇，点数
     //Warning:
     //V必须严格等于图中的点的数目
     //add_edge(u,v,c);
}
edge cur[MAXV];
int pre[MAXV],d[MAXV],dn[MAXV+1],q[MAXV],qh,qt;
int sap()
{
    fl(d,-1),fl(dn,0),cpy(cur,adj);
    d[q[qh=qt=0]=T]=0;
    whl(qh<=qt)
    {
        int u=q[qh++];
        dn[d[u]]++;
        for (edge i=adj[u];i;i=i->n)
            if ((d[i->v]==-1)&&i->b->c)
                d[q[++qt]=i->v]=d[u]+1;
    }
    int f=0,u=S;
    whl(d[S]<V)
    {
        if (u==T)
        {
            int aug=+oo,v;
            v=T;
            whl(v!=S) cmin(aug,cur[v=pre[v]]->c);
            v=T;
            whl(v!=S) v=pre[v],cur[v]->c-=aug,cur[v]->b->c+=aug,u=cur[v]->c?u:v;
            f+=aug;
        }
        whl(cur[u]&&!(cur[u]->c&&d[u]==d[cur[u]->v]+1)) cur[u]=cur[u]->n;
        if (cur[u]) pre[cur[u]->v]=u,u=cur[u]->v;
        else
        {
            int mind=V;
            for (edge i=adj[u];i;i=i->n)
                if (i->c&&cmin(mind,d[i->v])) cur[u]=i;
            if (!(--dn[d[u]])) break;
            dn[d[u]=mind+1]++;
            if (u!=S) u=pre[u];
        }
    }
    return f;
}
int N,M;
int ss,tt;
int total;
edge tt_to_ss;
bool read()
{
     total=0;
     top=pool;
     memset(adj,0,sizeof(adj));
     scanf("%d%d",&N,&M);
     if (N==0&&M==0) return false;
     ss=0,tt=N+1;
     S=N+2,T=N+3,V=N+4;
     for (int i=0;i<M;i++)
     {
         static const int MAXLENGTH=1024;
         char s[MAXLENGTH];
         int a,b,c;
         scanf("%s",s);
         if (sscanf(s,"%d",&a)==EOF)
         {
            if (*s=='+') a=ss;
            else if (*s=='-')  a=tt;
         }
         scanf("%s",s);
         if (sscanf(s,"%d",&b)==EOF)
         {
            if (*s=='+') b=ss;
            else if (*s=='-') b=tt;
         }
         scanf("%d",&c);
         add_edge(a,b,oo);
         add_edge(S,b,c);
         add_edge(a,T,c);
         total+=c;
     }
     add_edge(tt,ss,oo);
     tt_to_ss=top-2;
     return true;
}
void write()
{
     total-=sap();
     if (total) printf("impossible\n");
     else
     {
         S=N+1,T=0,V-=2;
         int answer=tt_to_ss->b->c-sap();
         printf("%d\n",answer);
     }
}

int main()
{
    while (read()) write();
}
