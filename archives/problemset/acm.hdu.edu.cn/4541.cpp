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
#define rev(x) reverse(all(x))
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
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE"));whl(0)
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
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
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
    vec<pr<int,str> > lst;
    lst.pb(mp(4,"0"));
    lst.pb(mp(3,"1"));
    lst.pb(mp(3,"2"));
    lst.pb(mp(5,"3"));
    lst.pb(mp(4,"4"));
    lst.pb(mp(4,"5"));
    lst.pb(mp(3,"6"));
    lst.pb(mp(5,"7"));
    lst.pb(mp(5,"8"));
    lst.pb(mp(4,"9"));
    lst.pb(mp(3,"10"));
    lst.pb(mp(6,"11"));
    lst.pb(mp(6,"12"));
    lst.pb(mp(8,"13"));
    lst.pb(mp(8,"14"));
    lst.pb(mp(7,"15"));
    lst.pb(mp(7,"16"));
    lst.pb(mp(9,"17"));
    lst.pb(mp(8,"18"));
    lst.pb(mp(8,"19"));
    lst.pb(mp(6,"20"));
    lst.pb(mp(9,"21"));
    lst.pb(mp(9,"22"));
    lst.pb(mp(11,"23"));
    lst.pb(mp(10,"24"));
    lst.pb(mp(10,"25"));
    lst.pb(mp(9,"26"));
    lst.pb(mp(11,"27"));
    lst.pb(mp(11,"28"));
    lst.pb(mp(10,"29"));
    lst.pb(mp(6,"30"));
    lst.pb(mp(9,"31"));
    lst.pb(mp(9,"32"));
    lst.pb(mp(11,"33"));
    lst.pb(mp(10,"34"));
    lst.pb(mp(10,"35"));
    lst.pb(mp(9,"36"));
    lst.pb(mp(11,"37"));
    lst.pb(mp(11,"38"));
    lst.pb(mp(10,"39"));
    lst.pb(mp(5,"40"));
    lst.pb(mp(8,"41"));
    lst.pb(mp(8,"42"));
    lst.pb(mp(10,"43"));
    lst.pb(mp(9,"44"));
    lst.pb(mp(9,"45"));
    lst.pb(mp(8,"46"));
    lst.pb(mp(10,"47"));
    lst.pb(mp(10,"48"));
    lst.pb(mp(9,"49"));
    lst.pb(mp(5,"50"));
    lst.pb(mp(8,"51"));
    lst.pb(mp(8,"52"));
    lst.pb(mp(10,"53"));
    lst.pb(mp(9,"54"));
    lst.pb(mp(9,"55"));
    lst.pb(mp(8,"56"));
    lst.pb(mp(10,"57"));
    lst.pb(mp(10,"58"));
    lst.pb(mp(9,"59"));
    lst.pb(mp(5,"60"));
    lst.pb(mp(8,"61"));
    lst.pb(mp(8,"62"));
    lst.pb(mp(10,"63"));
    lst.pb(mp(9,"64"));
    lst.pb(mp(9,"65"));
    lst.pb(mp(8,"66"));
    lst.pb(mp(10,"67"));
    lst.pb(mp(10,"68"));
    lst.pb(mp(9,"69"));
    lst.pb(mp(7,"70"));
    lst.pb(mp(10,"71"));
    lst.pb(mp(10,"72"));
    lst.pb(mp(12,"73"));
    lst.pb(mp(11,"74"));
    lst.pb(mp(11,"75"));
    lst.pb(mp(10,"76"));
    lst.pb(mp(12,"77"));
    lst.pb(mp(12,"78"));
    lst.pb(mp(11,"79"));
    lst.pb(mp(6,"80"));
    lst.pb(mp(9,"81"));
    lst.pb(mp(9,"82"));
    lst.pb(mp(11,"83"));
    lst.pb(mp(10,"84"));
    lst.pb(mp(10,"85"));
    lst.pb(mp(9,"86"));
    lst.pb(mp(11,"87"));
    lst.pb(mp(11,"88"));
    lst.pb(mp(10,"89"));
    lst.pb(mp(6,"90"));
    lst.pb(mp(9,"91"));
    lst.pb(mp(9,"92"));
    lst.pb(mp(11,"93"));
    lst.pb(mp(10,"94"));
    lst.pb(mp(10,"95"));
    lst.pb(mp(9,"96"));
    lst.pb(mp(11,"97"));
    lst.pb(mp(11,"98"));
    lst.pb(mp(10,"99"));
    str googol="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    prt(sz(lst));
    repf(i,1,100)
        lst.pb(mp(lst[i].x+6,lst[i].y+googol));
    vec<vs> tab(10);
    rep(i,sz(lst)) if (lst[i].x<10) tab[lst[i].x].pb(lst[i].y);
    int T;
    cin>>T;
    ft(cs,1,T)
    {
        int n,m;
        cin>>n>>m,m--;
        cout<<"Case #"<<cs<<": ";
        if (m<sz(tab[n])) cout<<tab[n][m]<<endl;
        else cout<<-1<<endl;
    }
}
