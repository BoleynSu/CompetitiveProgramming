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
#include <cstdio>
#include <cstring>
using namespace std;

namespace sujiaos_lab
{
const int LOG2_MAXLENGTH=19;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
const int MAXALPHABET=256;
typedef char string[MAXLENGTH];
typedef int* int_pointer;
int_pointer sort;
int _SA[MAXLENGTH],_rank[MAXLENGTH],_TSA[MAXLENGTH],_Trank[MAXLENGTH];
int_pointer SA=_SA,rank=_rank,TSA=_TSA,Trank=_Trank;
void get_SA(string s,int length)
{
     sort=Trank;
     for (int i=0;i<MAXALPHABET;i++) sort[i]=0;
     for (int i=1;i<=length;i++) sort[s[i]]++;
     for (int i=1;i<MAXALPHABET;i++) sort[i]+=sort[i-1];
     for (int i=1;i<=length;i++) SA[sort[s[i]]--]=i;
     rank[SA[1]]=1;
     for (int i=2;i<=length;i++)
         if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
         else rank[SA[i]]=rank[SA[i-1]]+1;
     for (int block=1;rank[SA[length]]!=length;block<<=1)
     {
         sort=Trank;
         for (int i=1;i<=length;i++) sort[rank[SA[i]]]=i;
         for (int i=length;i>=1;i--)
             if (SA[i]-block>=1)
                TSA[sort[rank[SA[i]-block]]--]=SA[i]-block;
         for (int i=length-block+1;i<=length;i++)
             TSA[sort[rank[i]]--]=i;
         int_pointer swap;
         swap=SA,SA=TSA,TSA=swap;
         swap=rank,rank=Trank,Trank=swap;
         rank[SA[1]]=1;
         for (int i=2;i<=length;i++)
             if (Trank[SA[i]]==Trank[SA[i-1]]
                &&Trank[SA[i]+block]==Trank[SA[i-1]+block])
                rank[SA[i]]=rank[SA[i-1]];
             else rank[SA[i]]=rank[SA[i-1]]+1;
     }
}
int_pointer height;
void get_height(string s,int length)
{
     height=TSA;
     for (int i=1,h=0;i<=length;i++)
     {
         if (h) h--;
         if (rank[i]!=1)
         {
            int j=SA[rank[i]-1];
            while (s[i+h]==s[j+h]) h++;
         }
         height[rank[i]]=h;
     }
}
int_pointer log2;
int rmq[LOG2_MAXLENGTH][MAXLENGTH];
void get_RMQ(int length)
{
     log2=Trank;
     log2[1]=0;
     for (int i=2;i<=length;i++) log2[i]=log2[i-1]+(i==(i&(-i)));
     for (int i=1;i<=length;i++) rmq[0][i]=i;
     for (int log=1;log<=log2[length];log++)
     {
         int exp=1<<log,exp_div_2=exp>>1;
         for (int i=1;i<=length-exp+1;i++)
         {
             int a=rmq[log-1][i];
             int b=rmq[log-1][i+exp_div_2];
             rmq[log][i]=height[a]<height[b]?a:b;
         }
     }
}
int RMQ(int a,int b)
{
    int log=log2[b-a+1];
    int exp=1<<log;
    a=rmq[log][a],b=rmq[log][b-exp+1];
    return height[a]<height[b]?a:b;
}
int LCP(int a,int b)
{
    a=rank[a],b=rank[b];
    if (a>b) return height[RMQ(b+1,a)];
    else return height[RMQ(a+1,b)];
}
}
using namespace sujiaos_lab;
/*
const int MAXN=20003;
sujiaos_lab::string s;
int W[MAXN];
int p[MAXN];
int len[MAXN];

const int MAXNODE=MAXLENGTH*4+1;
int st[MAXNODE];
void insert(int p,int value,int L,int R,int root=1)
{
     if (p<L||R<p) return;
     else
     {
         if (value>st[root])
            st[root]=value;
         if (L==R) return;
         int LL=L,LR=(L+R)>>1,Lroot=root<<1,
             RL=LR+1,RR=R,Rroot=Lroot|1;
         insert(p,value,LL,LR,Lroot);
         insert(p,value,RL,RR,Rroot);
     }
}
int query(int l,int r,int L,int R,int root=1)
{
    if (r<L||R<l||L>R) return 0;
    else if (l<=L&&R<=r) return st[root];
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1,
            RL=LR+1,RR=R,Rroot=Lroot|1;
        int LV=query(l,r,LL,LR,Lroot);
        int RV=query(l,r,RL,RR,Rroot);
        return LV>RV?LV:RV;
    }
}
int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        int N;
        scanf("%d",&N);
        for (int i=1;i<=N;i++)
        {
            p[i]=p[i-1]+len[i-1];
            s[p[i]++]='#';
            scanf("%s%d",s+p[i],&W[i]);
            len[i]=strlen(s+p[i]);
        }

        int length=strlen(s);
        get_SA(s,length);
        get_height(s,length);
        get_RMQ(length);

        int answer=0;
        memset(st,0,sizeof(st));
        for (int i=N;i>=1;i--)
        {
            int L,R,l,r;
            L=0,R=rank[p[i]];
            while (L+1!=R)
            {
                  int mid=(L+R)>>1;
                  if (height[RMQ(mid+1,rank[p[i]])]>=len[i]) R=mid;
                  else L=mid;
            }
            l=R;
            L=rank[p[i]],R=length+1;
            while (L+1!=R)
            {
                  int mid=(L+R)>>1;
                  if (height[RMQ(rank[p[i]]+1,mid)]>=len[i]) L=mid;
                  else R=mid;
            }
            r=L;
            int get=query(l,r,1,length)+W[i];
            if (get>answer) answer=get;
            for (int j=0;j<len[i];j++)
                insert(rank[p[i]+j],get,1,length);
        }
        printf("Case #%d: %d\n",tc,answer);
    }
}
*/
sujiaos_lab::string s;
int f[MAXLENGTH],g[MAXLENGTH];
int main()
{
    int T;
    scanf("%d\n",&T);
    ft(t,1,T)
    {
        int n;
        scanf("%d\n",&n);
        int Alength;
        cstr si=s;
        gets(si);
        whl(*si) si++;
        *si++='$';
        Alength=si-s;
        rep(i,n)
        {
            gets(si);
            whl(*si) si++;
            *si++='#';
        }
        *si='\0';
        int length=si-s;
        cstr S=s-1;
        get_SA(S,length);
        get_height(S,length);
        get_RMQ(length);
        clr(f),clr(g);
        int lastB;
        lastB=-1;
        ft(i,1,length)
        {
            if (lastB!=-1) f[SA[i]]=LCP(lastB,SA[i]);
            else f[SA[i]]=0;
            if (S[SA[i]]!='#'&&SA[i]>Alength) lastB=SA[i];
        }
        lastB=-1;
        fdt(i,length,1)
        {
            if (lastB!=-1) g[SA[i]]=LCP(lastB,SA[i]);
            else g[SA[i]]=0;
            if (S[SA[i]]!='#'&&S[SA[i]]!='$') lastB=SA[i];
        }
        lli ans=0;
        ft(i,1,Alength-1)
        {
            int lcp=LCP(i,i+1),match=max(f[i],g[i]);//prt(match);
            //if (lcp>=match) match=lcp;
            ans+=(Alength-i)-match;
            //prt(ans),prt(lcp);
        }
        printf("Case %d: %I64d\n",t,ans);
    }
}
