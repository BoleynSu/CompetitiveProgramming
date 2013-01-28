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

const int MS=300;
int n,m,y,x,d;
db p[MS];
int matrixs;
int row[MS];
db matrix[MS][MS];
db solution[MS];

int main()
{
    int T;
    scanf("%d",&T);
    whl(T--)
    {
        scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
        if (d==0) d=+1;
        else if (d==1) d=-1;
        else if (x==0) d=+1;
        else d=-1;
        rep(i,m) scanf("%lf",p+i),p[i]/=1e2;
        int S;
        vi seq,T;
        rep(i,n) seq.pb(i);
        rep(i,n-2) seq.pb(n-2-i);
        rep(i,sz(seq))
        {
            if (seq[i]==x)
            {
                if (x==n-1) S=i;
                else if (x==0) S=i;
                else if (d==+1&&i<n) S=i;
                else if (d==-1&&i>=n) S=i;
            }
            if (seq[i]==y) T.pb(i);
        }

        vb inq(sz(seq));
        que<int> q;
        q.push(T.front()),q.push(T.back());
        inq[T.front()]=inq[T.back()]=true;
        while (!q.empty())
        {
            int u=q.front();
            q.pop();
            rep(k,m)
            {
                int v=((u-(k+1))%sz(seq)+sz(seq))%sz(seq);
                if (sgn(p[k])&&!inq[v])
                    q.push(v),inq[v]=true;
            }
        }
        if (!inq[S]) puts("Impossible !");
        else
        {
            vi id(sz(seq)),rid;
            rep(i,sz(id)) if (inq[i]) id[i]=sz(rid),rid.pb(i);
            vec<vec<pr<int,pr<db,db> > > > adj(sz(rid));
            rep(i,sz(rid))
            {
                int u=rid[i];
                rep(k,m)
                {
                    int v=(u+(k+1))%sz(seq);
                    if (inq[v]) adj[i].pb(mp(id[v],mp(p[k],p[k]*(k+1))));
                }
            }
            clr(matrix),clr(solution),matrixs=sz(rid);
            rep(i,matrixs)
            {
                row[i]=i;
                matrix[row[i]][i]=-1.0;
                rep(j,sz(adj[i])) matrix[row[i]][adj[i][j].x]+=adj[i][j].y.x,matrix[row[i]][matrixs]+=adj[i][j].y.y;
            }
            rep(i,sz(T)) ft(j,0,matrixs) matrix[row[id[T[i]]]][j]=(id[T[i]]==j?-1.0:0.0);
            rep(i,matrixs)
            {
                ft(j,i+1,matrixs-1)
                    if (abs(matrix[row[j]][i])>abs(matrix[row[i]][i]))
                        swap(row[i],row[j]);
                ft(j,i+1,matrixs-1)
                    fdt(k,matrixs,i)
                        matrix[row[j]][k]-=matrix[row[i]][k]*matrix[row[j]][i]/matrix[row[i]][i];
            }
            fdt(i,matrixs-1,0)
            {
                solution[i]=matrix[row[i]][matrixs];
                ft(j,i+1,matrixs-1) solution[i]+=matrix[row[i]][j]*solution[j];
                solution[i]/=-matrix[row[i]][i];
            }
            printf("%.2f\n",solution[id[S]]);
        }
    }
}

