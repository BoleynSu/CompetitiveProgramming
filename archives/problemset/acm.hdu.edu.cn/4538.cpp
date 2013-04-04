/*
 * Package: StandardCodeLibrary.Core
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
#if __GNUC__>=4 and __GNUC_MINOR__>=6
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#endif
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
#define typeof decltype
#endif
using namespace std;

#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s) for (typeof((s).begin()) e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=(set)&((set)-1);subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) (cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0))
#ifdef DEBUG
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#else
#define endl (char('\n'))
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
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
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef vec<pii> vpii;
typedef vec<pdd> vpdd;
#if __GNUC__>=4 and __GNUC_MINOR__>=6
using __gnu_cxx::rope;
#endif
#if __GNUC__>=4 and __GNUC_MINOR__>=7
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#elif __GNUC__>=4 and __GNUC_MINOR__>=6
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
template<typename key>class ext_set:public __gnu_pbds::tree<key,__gnu_pbds::null_mapped_type,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#endif

int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

int main()
{
    int type[256];
    fl(type,-1);
    ft(i,'0','9') type[i]=1;
    ft(i,'a','z') type[i]=1;
    ft(i,'A','Z') type[i]=1;
    type['_']=1;
    type[' ']=type['\n']=0;

    int T;
    cin>>T;
    whl(T--)
    {
        int n,m;
        pr<pii,bool> s,t;
        cin>>n>>m>>s.x>>t.x,cin.get();
        vs ch(n),rc(n);
        rep(i,n) getline(cin,ch[i]);
        rep(i,n) getline(cin,rc[i]);

        vpii wbegin,wend;
        vpii Wbegin,Wend;
        rep(i,n) rep(j,m)
        {
            if ((j==0||type[ch[i][j-1]]==0)&&type[ch[i][j]])
            {
                Wbegin.pb(mp(i,j));
            }
            if ((j==0||type[ch[i][j-1]]!=type[ch[i][j]])&&type[ch[i][j]])
            {
                wbegin.pb(mp(i,j));
            }
            if ((j==m-1||type[ch[i][j+1]]==0)&&type[ch[i][j]])
            {
                Wend.pb(mp(i,j));
            }
            if ((j==m-1||type[ch[i][j+1]]!=type[ch[i][j]])&&type[ch[i][j]])
            {
                wend.pb(mp(i,j));
            }
        }

        prq<pr<int,pr<pii,bool> > > q;
        vec<vvi> d(n,vvi(m,vi(2,19930309)));
#define dis(u) (d[(u).x.x][(u).x.y][(u).y])
#define chk(u) (!((u).x.x<0||(u).x.x>=n||(u).x.y<0||(u).x.y>=m||rc[(u).x.x][(u).x.y]=='1'))
#define psh \
    do\
    {\
        if (chk(v))\
        {\
            if (cmin(dis(v),dis(u)+delta))\
                q.push(mp(-dis(v),v));\
        }\
    }\
    whl(0);

        s.y=false;
        dis(s)=0;
        q.push(mp(0,s));
        whl(sz(q))
        {
            pr<pii,bool> u=q.top().y;
            if (dis(u)==-q.top().x)
            {
                pr<pii,bool> v;
                int delta;
                vpii::iterator it;

                //Caps Lock
                v=mp(mp(u.x.x,u.x.y),!u.y);
                delta=1;
                psh;

                if (!u.y)
                {
                    //h
                    v=mp(mp(u.x.x,u.x.y-1),u.y);
                    delta=1;
                    psh;
                    //j
                    v=mp(mp(u.x.x+1,u.x.y),u.y);
                    delta=1;
                    psh;
                    //k
                    v=mp(mp(u.x.x-1,u.x.y),u.y);
                    delta=1;
                    psh;
                    //l
                    v=mp(mp(u.x.x,u.x.y+1),u.y);
                    delta=1;
                    psh;

                    //w
                    it=ub(all(wbegin),u.x);
                    if (it!=wbegin.end())
                    {
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //e
                    it=ub(all(wend),u.x);
                    if (it!=wend.end())
                    {
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //b
                    it=lb(all(wbegin),u.x);
                    if (it!=wbegin.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //ge
                    it=lb(all(wend),u.x);
                    if (it!=wend.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }

                    //W
                    it=ub(all(Wbegin),u.x);
                    if (it!=Wbegin.end())
                    {
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //E
                    it=ub(all(Wend),u.x);
                    if (it!=Wend.end())
                    {
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //B
                    it=lb(all(Wbegin),u.x);
                    if (it!=Wbegin.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //gE
                    it=lb(all(Wend),u.x);
                    if (it!=Wend.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=3;
                        psh;
                        v=mp(*it,!u.y);
                        delta=3;
                        psh;
                    }
                }
                else
                {
                    //h
                    v=mp(mp(u.x.x,u.x.y-1),u.y);
                    delta=2;
                    psh;
                    //j
                    v=mp(mp(u.x.x+1,u.x.y),u.y);
                    delta=2;
                    psh;
                    //k
                    v=mp(mp(u.x.x-1,u.x.y),u.y);
                    delta=2;
                    psh;
                    //l
                    v=mp(mp(u.x.x,u.x.y+1),u.y);
                    delta=2;
                    psh;

                    //w
                    it=ub(all(wbegin),u.x);
                    if (it!=wbegin.end())
                    {
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //e
                    it=ub(all(wend),u.x);
                    if (it!=wend.end())
                    {
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //b
                    it=lb(all(wbegin),u.x);
                    if (it!=wbegin.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=2;
                        psh;
                    }
                    //ge
                    it=lb(all(wend),u.x);
                    if (it!=wend.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=4;
                        psh;
                    }

                    //W
                    it=ub(all(Wbegin),u.x);
                    if (it!=Wbegin.end())
                    {
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //E
                    it=ub(all(Wend),u.x);
                    if (it!=Wend.end())
                    {
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //B
                    it=lb(all(Wbegin),u.x);
                    if (it!=Wbegin.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=1;
                        psh;
                    }
                    //gE
                    it=lb(all(Wend),u.x);
                    if (it!=Wend.begin())
                    {
                        it--;
                        v=mp(*it,u.y);
                        delta=3;
                        psh;
                    }
                }
            }
            q.pop();
        }

        int ans=19930309;
        rep(i,2) cmin(ans,d[t.x.x][t.x.y][i]);
        if (ans==19930309) ans=-1;

        static int cs;
        cout<<"Case #"<<++cs<<": ";
        cout<<ans<<endl;
    }
}









