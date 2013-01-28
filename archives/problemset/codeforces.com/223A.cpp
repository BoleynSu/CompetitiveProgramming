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
typedef set<str> ss;
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

lli gcd(lli a,lli b,lli& x,lli& y)
{
    //ax+by=gcd(a,b)
    if (b==0)
    {
       x=1,y=0;
       return a;
    }
    else
    {
        lli g=gcd(b,a%b,y,x);
        //b*y+a%b*x=gcd(b,a%b)=gcd(a,b)
        // b*y+a%b*x
        //=b*y+(a-a/b*b)*x
        //=b*y-a/b*b*x+a*x
        //=a*x+b*(y-a/b*x)
        y-=a/b*x;
        return g;
    }
}

const lli MOD=1000000007;
int n;
lli inv[2002];
lli f[2002];

int main2()
{
    cin>>n;
    ft(i,1,n)
    {
        lli x;
        gcd(i,MOD,inv[i],x);
        prt(i*inv[i]%MOD);
    }
    f[1]=1;
    ft(i,2,n)
    {
        f[i]=f[i-1]*(n+i-1-1)%MOD*inv[i-1]%MOD;
    }
    ft(i,1,n)
    {

    }
}

int main()
{
    str s;
    cin>>s;
    stack<pr<char,int> > stk;
    vec<pii> pp;
    rep(i,sz(s))
    {
        if (s[i]==')')
        {
            if (!stk.empty()&&stk.top().x=='(')
            {
                pp.pb(mp(stk.top().y,i));
                stk.pop();
            }
            else stk=stack<pr<char,int> >();
        }
        else if (s[i]==']')
        {
            if (!stk.empty()&&stk.top().x=='[')
            {
                pp.pb(mp(stk.top().y,i));
                stk.pop();
            }
            else stk=stack<pr<char,int> >();
        }
        else stk.push(mp(s[i],i));
    }
    int ans=0,b,e;
    mii end;
    rep(i,sz(pp)) end[pp[i].x]=pp[i].y;
    for (mii::itr i=end.begin();i!=end.end();)
    {
        mii::itr j=end.find(i->y+1);
        if (j!=end.end()) i->y=j->y,end.erase(j);
        else
        {
            int c=0;
            ft(j,i->x,i->y) if (s[j]=='[') c++;
            if (cmax(ans,c)) b=i->x,e=i->y;
            i=end.upper_bound(i->y);
        }
    }
    cout<<ans<<endl;
    if (ans) cout<<s.substr(b,e-b+1)<<endl;
    else cout<<endl;
}
