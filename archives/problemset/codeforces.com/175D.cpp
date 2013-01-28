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

struct Tank
{
    int hp,dt,l,r;
    db p,q;
    Tank()
    {
        cin>>hp>>dt>>l>>r>>p;
        p/=100.0;
        q=(1.0-p)/(r-l+1);
    }
};
Tank tank[2];
pdd f[300+4][300+4][60+2];
db ff[300+4][300+4][60+2];
int attack[60+2];
int attacks;
inline pdd& F(int hp0,int hp1,int t)
{
    return f[hp0+102][hp1+102][t];
}
inline db& FF(int hp0,int hp1,int t)
{
    return ff[hp0+102][hp1+102][t];
}
pdd operator*(pdd a,db b)
{
    return mp(a.x*b,a.y*b);
}
pdd operator+(pdd a,pdd b)
{
    return mp(a.x+b.x,a.y+b.y);
}

int main()
{
    //f[hp0][hp1][t]=sum{f[hp0'][hp1'][t+1]}*q+f[hp0][hp1][t+1]*p
    //f[hp0][hp1][0]=f[hp0][hp1][T]
    int T=lcm(tank[0].dt,tank[1].dt);
    rep(t,T) rep(i,2) if (!(t%tank[i].dt)) attack[attacks++]=i;
    attack[attacks]=0;
    ft(hp0,-tank[1].r,tank[0].hp)
        ft(hp1,-tank[0].r,tank[1].hp)
        {
            if (hp1<=0) ft(t,0,attacks) F(hp0,hp1,t)=mp(0.0,1.0);
            else if (hp0<=0) ft(t,0,attacks) F(hp0,hp1,t)=mp(0.0,0.0);
            else
            {
                F(hp0,hp1,attacks)=mp(1.0,0);
                fdt(t,attacks-1,0)
                {
                    F(hp0,hp1,t)=F(hp0,hp1,t+1)*tank[attack[t]].p;
                    if (attack[t]) F(hp0,hp1,t).y+=(FF(hp0-tank[attack[t]].l,hp1,t+1)-FF(hp0-(tank[attack[t]].r+1),hp1,t+1))*tank[attack[t]].q;
                    else F(hp0,hp1,t).y+=(FF(hp0,hp1-tank[attack[t]].l,t+1)-FF(hp0,hp1-(tank[attack[t]].r+1),t+1))*tank[attack[t]].q;
                }
                db x=0;
                if (sgn(F(hp0,hp1,0).y)>0) x=F(hp0,hp1,0).y/(1.0-F(hp0,hp1,0).x);
                ft(t,0,attacks) F(hp0,hp1,t)=mp(0.0,F(hp0,hp1,t).x*x+F(hp0,hp1,t).y);
            }
            ft(t,1,attacks)
            {
                if (attack[t-1]) FF(hp0,hp1,t)=FF(hp0-1,hp1,t)+F(hp0,hp1,t).y;
                else FF(hp0,hp1,t)+=FF(hp0,hp1-1,t)+F(hp0,hp1,t).y;
            }
        }
    printf("%.50f\n",F(tank[0].hp,tank[1].hp,0).y);
}

