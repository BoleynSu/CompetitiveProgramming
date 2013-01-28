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

#include <cstring>
using namespace std;
const int MAXV=400;
const int MAXE=80000;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
typedef void function(int block,int node);
int V;
struct_edge pool[MAXE];
edge top;
edge adj[MAXV];
void build_graph()
{
     top=pool;
     memset(adj,0,sizeof(adj));
     //V;
     //add_edge(u,v);
}
void add_edge(int u,int v)
{
     top->v=v,top->n=adj[u],adj[u]=top++;
}
int stamp;
int DFN[MAXV];
int LOW[MAXV];
int st;
int s[MAXV];
bool ins[MAXV];
bool visited[MAXV];
int depth;
edge e[MAXV];
int root[MAXV];
int block;
void tarjan(function f)
{
     memset(visited,0,sizeof(visited));
     memset(ins,0,sizeof(ins));
     st=0;
     block=0;
     for (int start=0;start<V;start++)
         if (!visited[start])
         {
            depth=0;
            root[depth]=start;
            e[depth]=adj[root[depth]];
            DFN[root[depth]]=LOW[root[depth]]=++stamp;
            ins[s[st++]=root[depth]]=true;
            visited[root[depth]]=true;
            do
            {
              if (e[depth])
              {
                 if (!visited[e[depth]->v])
                 {
                    int depth_=depth+1;
                    e[depth_]=adj[root[depth_]=e[depth]->v];
                    DFN[root[depth_]]=LOW[root[depth_]]=++stamp;
                    ins[s[st++]=root[depth_]]=true;
                    visited[root[depth_]]=true;
                    e[depth]=e[depth]->n;
                    depth++;
                 }
                 else if (ins[e[depth]->v])
                 {
                     if (LOW[root[depth]]>DFN[e[depth]->v])
                        LOW[root[depth]]=DFN[e[depth]->v];
                     e[depth]=e[depth]->n;
                 }
                 else e[depth]=e[depth]->n;
              }
              else
              {
                  if (LOW[root[depth]]==DFN[root[depth]])
                  {
                     do
                     {
                       ins[s[--st]]=false;
                       f(block,s[st]);
                     }
                     while (s[st]!=root[depth]);
                     block++;
                  }
                  if (depth>0)
                  {
                     int depth_=depth-1;
                     if (LOW[root[depth_]]>LOW[root[depth]])
                        LOW[root[depth_]]=LOW[root[depth]];
                  }
                  depth--;
              }
            }
            while (depth>=0);
         }
}
typedef struct_edge struct_list;
typedef edge list;
int block_id[MAXV];
struct_list spool[MAXV];
list stop;
list set[MAXV];
#define T(x) (((x)<<1)|1)
#define F(x) ((x)<<1)
void build_2sat()
{
     stop=spool;
     memset(set,0,sizeof(set));
     build_graph();
     //add_edge(u,v);
     /*
     A[x]                  =add_edge(F(x),T(x));
     NOT A[x]              =add_edge(T(x),F(x));
     A[x] AND A[y]         =add_edge(F(x),T(x)),add_edge(F(y),T(y));
     A[x] AND NOT A[y]     =add_edge(F(x),T(x)),add_edge(T(y),F(y));
     A[x] OR A[y]          =add_edge(F(x),T(y)),add_edge(F(y),T(x));
     A[x] OR NOT A[y]      =add_edge(F(x),F(y)),add_edge(T(y),T(x));
     NOT (A[x] AND A[y])   =add_edge(T(x),F(y)),add_edge(T(y),F(x));
     NOT (A[x] OR A[y])    =add_edge(T(x),F(x)),add_edge(T(y),F(y));
     A[x] XOR A[y]         =add_edge(F(x),T(y)),add_edge(F(y),T(x)),add_edge(T(x),F(y)),add_edge(T(y),F(x));
     NOT (A[x] XOR A[y])   =add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
     A[x] XOR NOT A[y]     =add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
     u到v有边表示选u必选v,如果要输出一个可行解,
     */
}
void function_2sat(int block,int node)
{
     block_id[node]=block;
     stop->v=node,stop->n=set[node],set[node]=stop++;
}

#include <iostream>
using namespace std;
bool possible_2sat()
{
     tarjan(function_2sat);
     for (int i=0;i<(V>>1);i++)
         if (block_id[T(i)]==block_id[F(i)])
            return false;
     return true;
}

int a[100000],b[100000],c[100000];
bool possible(int n,int x)
{
    build_2sat();
    V=n<<1;
    ft(i,0,x)
    {
        if (c[i]==0)
        {
            //x[a]||x[b]
            add_edge(F(a[i]),T(b[i]));
            add_edge(F(b[i]),T(a[i]));
        }
        else if (c[i]==1)
        {
            //!(x[a]^x[b])
            add_edge(F(a[i]),F(b[i]));
            add_edge(T(b[i]),T(a[i]));
            add_edge(T(a[i]),T(b[i]));
            add_edge(F(b[i]),F(a[i]));
        }
        else
        {
            //!x[a]||!x[b]
            add_edge(T(a[i]),F(b[i]));
            add_edge(T(b[i]),F(a[i]));
        }
    }
    return possible_2sat();
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int T;
    cin>>T;
    whl(T--)
    {
        int n,m;
        cin>>n>>m;
        rep(i,m) cin>>a[i]>>b[i]>>c[i];
        int l=0,r=m;
        whl(l+1!=r)
        {
            int mid=(l+r)>>1;
            if (possible(n,mid)) l=mid;
            else r=mid;
        }
        cout<<r<<endl;
    }
}

