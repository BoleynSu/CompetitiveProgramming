/*
 * Package: StandardCodeLibrary.Core
 * Last Update: 2012-12-08
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s) for (typeof((s).begin()) e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define forin(i,charset) for (cstr i=charset;*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),sizeof(x),char(y))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memset(x,sizeof(x),y)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) printf("%."#prcs"f",(abs(x)<1e-##prcs)?0.0:x)
#ifdef ONLINE_JUDGE
#define endl '\n'
#define prt(x) cerr
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() cerr
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"asrtWA"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"asrtTLE"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"asrtMLE"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"asrtOLE"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"asrtRE"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#define DEBUG
#endif

typedef long long int lli;
typedef double db;
typedef const char* cstr;
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
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b,const pr<type,type>& c){rtn (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& set){rep(i,sz(set))set[i]=i;}
inline int find_set(vi& set,int x){int y=x,z;whl(y!=set[y])y=set[y];whl(x!=set[x])z=set[x],set[x]=y,x=z;rtn y;}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a!=b?set[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

int main()
{
    input("input.txt");
    output("output.txt");
    int n,v;
    cin>>n>>v;
    vi a(n+2);
    ft(i,1,n) cin>>a[i];
    int m;
    cin>>m;
    vec<vec<pii> > needs(n+2);
    ft(i,1,m)
    {
        int l,r,f;
        cin>>l>>r>>f;
        ft(j,l,r) needs[j].pb(mp(f,i));
    }
    ft(i,1,n) srt(needs[i]);
    const int MAXREST=*max_element(all(a));
    vvi f(n+2,vi(MAXREST+2,-oo));
    vvi pre(n+2,vi(MAXREST+2));
    f[0][0]=0;
    ft(i,1,n)
        ft(j,0,a[i])
        {
            int nd=0;
            int jj=max(nd+v+j-a[i],0);
            if (jj<=a[i-1]&&cmax(f[i][j],f[i-1][jj])) pre[i][j]=0;
            rep(k,sz(needs[i]))
            {
                nd+=needs[i][k].x;
                int jj=max(nd+v+j-a[i],0);
                if (jj<=a[i-1]&&cmax(f[i][j],f[i-1][jj]+k+1)) pre[i][j]=k+1;
            }
        }
    int ans=-oo,ansi;
    ft(i,0,MAXREST) if (cmax(ans,f[n][i])) ansi=i;
    vvi anslst(n+2);
    fdt(i,n,1)
    {
        int nd=0;
        rep(j,pre[i][ansi]) anslst[i].pb(needs[i][j].y),nd+=needs[i][j].x;
        ansi=max(nd+v+ansi-a[i],0);
    }
    cout<<ans<<endl;
    ft(i,1,n)
    {
        cout<<sz(anslst[i]);
        rep(j,sz(anslst[i])) cout<<" "<<anslst[i][j];
        cout<<endl;
    }
}
