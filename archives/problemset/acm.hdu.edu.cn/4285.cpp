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
#define feach(e,s,t) for (t::iterator e=(s).begin();e!=(s).end();++e)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
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
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e8;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type lb(type x){rtn x&(-x);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x+=lb(x);}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;while (x>0)s+=st[x],x-=lb(x);rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}
/*
int main()
{
}
*/
/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-25
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=12;
const int MAXSTATE=1000001;
int N,M,K;
char m[MAXN][MAXN];
int sc,SC;
pii s_[MAXSTATE],S_[MAXSTATE];
int f_[MAXSTATE],F_[MAXSTATE];
pii* s=s_;
pii* S=S_;
int* f=f_;
int* F=F_;
void qsort(int l,int r)
{
     int i=l,j=r;
     pii mid=S[(l+r)>>1];
     while (i<=j)
     {
           while (S[i]<mid) i++;
           while (S[j]>mid) j--;
           if (i<=j)
           {
              pii SS;
              int SF;
              SS=S[i],S[i]=S[j],S[j]=SS,SF=F[i],F[i]=F[j],F[j]=SF;
              i++,j--;
           }
     }
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
}

void run()
{
    cin>>N>>M>>K;
    int lasti=-1,lastj=-1;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
        {
            cin>>m[i][j];
            if (m[i][j]!='*') lasti=i,lastj=j;
        }

    int answer=0;

    SC=0;
    S[SC]=mp(0,0);
    F[SC]=1;
    SC++;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            pii* ss;
            int* sf;
            ss=s,s=S,S=ss,sf=f,f=F,F=sf;
            sc=SC,SC=0;

            #define getp(state,p) (((state)>>((p)<<1))&3)
            #define replace(state,p,n) (((state)&(~(3<<((p)<<1))))|n<<((p)<<1))
            #define getl(state) getp(state,j)
            #define getu(state) getp(state,j+1)
            #define replacedr(state,d,r) replace(replace(state,j,d),j+1,r)
            #define getcl(state,p,ns)\
            do\
            {\
              ns=replacedr(state,0,0);\
              int get=2;\
              for (int i=p+2;i<=M;i++)\
              {\
                  if (getp(ns,i)==1) get++;\
                  else if (getp(ns,i)==2) get--;\
                  if (get==1)\
                  {\
                     ns=replace(ns,i,1);\
                     break;\
                  }\
              }\
            }\
            while (false)
            #define getcr(state,p,ns)\
            do\
            {\
              ns=replacedr(state,0,0);\
              int get=2;\
              for (int i=p-1;i>=0;i--)\
              {\
                  if (getp(ns,i)==2) get++;\
                  else if (getp(ns,i)==1) get--;\
                  if (get==1)\
                  {\
                     ns=replace(ns,i,2);\
                     break;\
                  }\
              }\
            }\
            while (false)
            if (m[i][j]=='*')
            {
               for (int si=0;si<sc;si++)
               {
                   int l=getl(s[si].x),u=getu(s[si].x);
                   if (!(l|u))
                   {
                      int ns;
                      ns=replacedr(s[si].x,0,0);
                      S[SC]=mp(ns,s[si].y);
                      F[SC]=f[si];
                      SC++;
                   }
               }
            }
            else
            {
                for (int si=0;si<sc;si++)
                {
                    int l=getl(s[si].x),u=getu(s[si].x);
                    if (l&&u)
                    {
                       bool odd=false;
                       rep(k,j) if (getp(s[si].x,k)) odd=!odd;

                       int ns;
                       if (l==2&&u==1)
                       {
                           ns=replacedr(s[si].x,0,0);
                           S[SC]=mp(ns,s[si].y);
                           F[SC]=f[si];
                           SC++;
                       }
                       else if (l==1&&u==1)
                       {
                           getcl(s[si].x,j,ns);
                           S[SC]=mp(ns,s[si].y);
                           F[SC]=f[si];
                           SC++;
                       }
                       else if (l==2&&u==2)
                       {
                           getcr(s[si].x,j,ns);
                           S[SC]=mp(ns,s[si].y);
                           F[SC]=f[si];
                           SC++;
                       }
                       else if (!odd)
                       {
                            ns=replacedr(s[si].x,0,0);
                            if ((!ns)&&i==lasti&&j==lastj&&s[si].y+1==K) (answer+=f[si])%=1000000007;
                            if (s[si].y+1<K)
                            {
                                S[SC]=mp(ns,s[si].y+1);
                                F[SC]=f[si];
                                SC++;
                            }
                       }
                    }
                    else if (l||u)
                    {
                         int ns;
                         ns=replacedr(s[si].x,l,u);
                         S[SC]=mp(ns,s[si].y);
                         F[SC]=f[si];
                         SC++;
                         ns=replacedr(s[si].x,u,l);
                         S[SC]=mp(ns,s[si].y);
                         F[SC]=f[si];
                         SC++;
                    }
                    else
                    {
                         int ns;
                         ns=replacedr(s[si].x,1,2);
                         S[SC]=mp(ns,s[si].y);
                         F[SC]=f[si];
                         SC++;
                    }
                }
            }
            {
                qsort(0,SC-1);
                int RSC=0;
                int i=0;
                while (i<SC)
                {
                      int j=i+1;
                      while (j<SC&&S[i]==S[j]) (F[i]+=F[j])%=1000000007,j++;
                      S[RSC]=S[i];
                      F[RSC++]=F[i];
                      i=j;
                }
                SC=RSC;
            }
        }
        {
            int RSC=0;
            int i=0;
            while (i<SC)
            {
                  while (i<SC&&getp(S[i].x,M)) i++;
                  if (i<SC) S[RSC]=mp(S[i].x<<(1<<1),S[i].y),F[RSC++]=F[i++];
            }
            SC=RSC;
        }
    }
    cout<<answer<<endl;
}
/*
#include <iostream>
#include <cstring>
#include <ext/hash_map>
using namespace std;

typedef long long int lli;
const int MAXN=12;
const int MAXSTATE=300001;
int N,M,K;
char m[MAXN][MAXN];
typedef __gnu_cxx::hash_map<pii,int> ftype;
namespace __gnu_cxx
{
template<>
struct hash<pii>
{
    size_t operator()(const pii& x) const
    {
        return x.x*36+x.y;
    }
};
}
const int MOD=1000000007;

void run()
{
    scanf("%d%d%d\n",&N,&M,&K);
    int lasti=-1,lastj=-1;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            m[i][j]=getchar();
            if (m[i][j]!='*') lasti=i,lastj=j;
        }
        getchar();
    }

    lli answer=0;

    ftype f(1000000);
    f[mp(0,0)]=1;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            #define getp(state,p) (((state)>>((p)<<1))&3)
            #define replace(state,p,n) (((state)&(~(3<<((p)<<1))))|n<<((p)<<1))
            #define getl(state) getp(state,j)
            #define getu(state) getp(state,j+1)
            #define replacedr(state,d,r) replace(replace(state,j,d),j+1,r)
            #define getcl(state,p,ns)\
            do\
            {\
            ns=replacedr(state,0,0);\
            int get=2;\
            for (int i=p+2;i<=M;i++)\
            {\
                if (getp(ns,i)==1) get++;\
                else if (getp(ns,i)==2) get--;\
                if (get==1)\
                {\
                    ns=replace(ns,i,1);\
                    break;\
                }\
            }\
            }\
            while (false)
            #define getcr(state,p,ns)\
            do\
            {\
            ns=replacedr(state,0,0);\
            int get=2;\
            for (int i=p-1;i>=0;i--)\
            {\
                if (getp(ns,i)==2) get++;\
                else if (getp(ns,i)==1) get--;\
                if (get==1)\
                {\
                    ns=replace(ns,i,2);\
                    break;\
                }\
            }\
            }\
            while (false)
            ftype F(1000000);
            if (m[i][j]=='*')
            {
                feach(fi,f,ftype)
                {
                    int l=getl(fi->first.first),u=getu(fi->first.first);
                    if (!(l|u))
                    {
                        int ns;
                        ns=replacedr(fi->first.first,0,0);
                        {
                            int& FF=F[mp(ns,fi->first.second)];
                            FF+=fi->second;
                            FF%=MOD;
                        }
                    }
                }
            }
            else
            {
                feach(fi,f,ftype)
                {
                    int l=getl(fi->first.first),u=getu(fi->first.first);
                    if (l&&u)
                    {
                        bool odd=false;
                        rep(k,j) if (getp(fi->first.first,k)) odd=!odd;

                        int ns;
                        if (l==2&&u==1)
                        {
                            ns=replacedr(fi->first.first,0,0);
                            {
                                int& FF=F[mp(ns,fi->first.second)];
                                FF+=fi->second;
                                FF%=MOD;
                            }
                        }
                        else if (!odd&&l==1&&u==1)
                        {
                            getcl(fi->first.first,j,ns);
                            {
                                int& FF=F[mp(ns,fi->first.second)];
                                FF+=fi->second;
                                FF%=MOD;
                            }
                        }
                        else if (!odd&&l==2&&u==2)
                        {
                            getcr(fi->first.first,j,ns);
                            {
                                int& FF=F[mp(ns,fi->first.second)];
                                FF+=fi->second;
                                FF%=MOD;
                            }
                        }
                        else if (!odd)
                        {

                                if ((!replacedr(fi->first.first,0,0))&&i==lasti&&j==lastj&&fi->first.second+1==K)
                                {
                                    answer+=fi->second;
                                    answer%=MOD;
                                }
                                ns=replacedr(fi->first.first,0,0);
                                {
                                    int& FF=F[mp(ns,fi->first.second+1)];
                                    FF+=fi->second;
                                    FF%=MOD;
                                }
                        }
                    }
                    else if (l||u)
                    {
                        int ns;
                        ns=replacedr(fi->first.first,l,u);
                        {
                            int& FF=F[mp(ns,fi->first.second)];
                            FF+=fi->second;
                            FF%=MOD;
                        }
                        ns=replacedr(fi->first.first,u,l);
                        {
                            int& FF=F[mp(ns,fi->first.second)];
                            FF+=fi->second;
                            FF%=MOD;
                        }
                    }
                    else
                    {
                        int ns;
                        ns=replacedr(fi->first.first,1,2);
                        {
                            int& FF=F[mp(ns,fi->first.second)];
                            FF+=fi->second;
                            FF%=MOD;
                        }
                    }
                }
            }
            f=F;
        }
        ftype F=f;
        f.clear();
        feach(i,F,ftype)
            if (i->first.first<(1<<(M<<1)))
                f[mp(i->first.first<<(1<<1),i->first.second)]=i->second;
    }
    printf("%d\n",int(answer));
}
*/
int main()
{
    int T;
    for (scanf("%d\n",&T);T;T--) run();
}

