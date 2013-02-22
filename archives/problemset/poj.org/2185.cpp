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
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.insert(*b.begin()),b.erase(b.begin());}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

/*
 * Package: StandardCodeLibrary.StringAlgorithms
 * Description:
 * KMP算法;
 * 扩展KMP算法;
 * 最长回文子串 Manacher's Algorithm;
 * AC自动机;
 * 后缀数组DC3;
 * */

namespace StandardCodeLibrary
{
namespace StringAlorithm
{

typedef char Char;
typedef vec<Char> String;

//KMP算法
void get_pi(const String t,vi& pi)
{
	pi.resize(sz(t)),pi[0]=-1;
	int j=-1;
	repf(i,1,sz(t))
	{
		whl(j!=-1&&t[j+1]!=t[i]) j=pi[j];
		if (t[j+1]==t[i]) j++;
		pi[i]=j;
	}
}
void get_match(const String& t,const vi& pi,const String& s,vi& match)
{
	int j=-1;
	rep(i,sz(s))
	{
		whl(j!=-1&&t[j+1]!=s[i]) j=pi[j];
		if (t[j+1]==s[i]) j++;
		if (j==sz(t)-1)
		{
			match.pb(i-j);
			j=pi[j];
		}
	}
}
int KMP(const String& t,const String& s)
{
	vi pi;
	get_pi(t,pi);
	vi match;
	get_match(t,pi,s,match);
	if (sz(match)) rtn match.front();
	else rtn -1;
}

//扩展KMP算法
void get_ext(const String& t,vi& ext)
{
	ext.resize(sz(t)),ext[0]=sz(t);
	if (sz(t)==1) rtn;
	int j=0,a=1;
	whl(1+j<sz(t)&&t[1+j]==t[j]) j++;
	ext[1]=j;
	repf(i,2,sz(t))
	{
		if (i+ext[i-a]<a+ext[a]) ext[i]=ext[i-a];
		else
		{
			j=max(a+ext[a]-i,0);
			whl(i+j<sz(t)&&t[i+j]==t[j]) j++;
			ext[a=i]=j;
		}
	}
}
void get_extend(const String& t,const vi& ext,const String& s,vi& extend)
{
	extend.resize(sz(s));
	int j=0,a=0;
	whl(j<sz(s)&&j<sz(t)&&s[j]==t[j]) j++;
	extend[0]=j;
	repf(i,1,sz(s))
	{
		if (i+ext[i-a]<a+extend[a]) extend[i]=ext[i-a];
		else
		{
			j=max(a+extend[a]-i,0);
			whl(i+j<sz(s)&&j<sz(t)&&s[i+j]==t[j]) j++;
			extend[a=i]=j;
		}
	}
}

//最长回文子串 Manacher's Algorithm
void longest_palindromic_substring(const String& str,String& ans_str,Char split='#')
{
	String S;
	rep(i,sz(str)) S.pb(split),S.pb(str[i]);
	S.pb(split);
	vi p(sz(S));
	int ans,ansi,mid;
	ans=(p[mid=0]=1)-1;
	repf(i,1,sz(S))
	{
	    p[i]=p[mid]+mid>i?min(p[mid]+mid-i,p[mid*2-i]):1;
	    whl(i>=p[i]&&i+p[i]<sz(S)&&S[i-p[i]]==S[i+p[i]]) p[i]++;
	    if (cmax(ans,p[i]-1)) ansi=i;
	    if (p[i]+i>p[mid]+mid) mid=i;
	}
	ans_str.clear();
	ft(i,ansi-ans,ansi+ans)
		if (S[i]!=split) ans_str.pb(S[i]);
}

}
}

using namespace StandardCodeLibrary::StringAlorithm;

int get(const vec<vec<char> >& m)
{
	lli ans=1;
	rep(i,sz(m))
	{
		vi ext,extend;
		get_ext(m[i],ext);
		get_extend(m[i],ext,m[i],extend);
		lli t=sz(m[i]);
		repf(j,1,sz(m[i])) if (j+extend[j]==sz(m[i]))
		{
			t=j;
			break;
		}
		ans=lcm(ans,t);
		if (ans>=sz(m[i])) rtn sz(m[i]);
	}
	rtn ans;
}

int main()
{
	int R,C;
	cin>>R>>C;
	vec<vec<char> > m(R,vec<char>(C));
	rep(i,R) rep(j,C) cin>>m[i][j];
	vec<vec<char> > mm(C,vec<char>(R));
	rep(i,R) rep(j,C) mm[j][i]=m[i][j];
	cout<<get(m)*get(mm)<<endl;
}
