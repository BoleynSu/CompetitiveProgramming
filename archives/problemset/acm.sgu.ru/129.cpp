//begin #include <Core>
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
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;
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
int dx[]={-1,1,0,0,-1,-1,1,1,0};
int dy[]={0,0,-1,1,-1,1,-1,1,0};
int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
inline int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
inline int sgn(const db& x){rtn dbcmp(x,0);}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<"("<<x.x<<","<<x.y<<")";}
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
template<typename type>inline void merge(prq<type>& a,prq<type>& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.push(b.top()),b.pop();}

struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;
//end #include <Core>

/*
 * Package: StandardCodeLibrary.ComputationalGeometry
 * Description:
 * Ray Casting Algorithm 射线法判断点是否在简单多边形内
 * */
//#include <Core>

namespace StandardCodeLibrary
{
namespace ComputationalGeometry2D
{

//数据类型定义
typedef db Number;//数值类型
typedef pr<Number,Number> Point;//点
typedef Point Vector;//向量
typedef pr<Point,Point> Segment;//线段
typedef vec<Point> Polygon;//多边形

//基本运算
//符号函数 正数返回1 负数返回-1 0返回0
using ::sgn;
//比较函数 大于返回1 小于返回-1 等于返回0
using ::dbcmp;
//点积
using ::dot;
inline
Number dot(const Point& a,const Point& b,const Point& c)
{
	rtn dot(b-a,c-a);
}
//叉积
using ::cross;
inline
Number cross(const Point& a,const Point& b,const Point& c)
{
	rtn cross(b-a,c-a);
}
//长度
inline
Number len(const Vector& v)
{
	rtn sqrt(dot(v,v));
}
inline
Number len(const Segment& s)
{
	rtn len(s.x-s.y);
}
//距离
inline
Number dis(const Point& a,const Point& b)
{
	rtn len(b-a);
}

//判断点是否在线段上
//如果点在线段上返回1 不在线段上但在直线上 返回-1 不在直线上返回0
int point_on_segment(const Point& p,const Segment& s)
{
	if (sgn(cross(p,s.x,s.y))) rtn 0;
	else rtn sgn(dot(p,s.x,s.y))<=0?1:-1;
}

//Ray Casting Algorithm 射线法判断点是否在简单多边形内
//在内部返回1 在外部返回-1 在边上返回0
int point_in_polygon(const Point& p,const vec<Segment>& e)
{
	rep(i,sz(e)) if (point_on_segment(p,e[i])==1) rtn 0;
	bool in=false;
	rep(i,sz(e))
		if ((dbcmp(e[i].x.y,p.y)>0)!=(dbcmp(e[i].y.y,p.y)>0)
			&&dbcmp(p.x,(e[i].y.x-e[i].x.x)/(e[i].y.y-e[i].x.y)*(p.y-e[i].x.y)+e[i].x.x)<0)
			in=!in;
	return in?1:-1;
}

//求线段交点
//如果平行则返回(+inf,+inf) 否则返回交点 交点为线段所在直线的交点
Point intersection(const Segment a,const Segment& b)
{
	Vector va=a.y-a.x,vb=b.y-b.x;
	if (!sgn(cross(va,vb))) rtn Point(+inf,+inf);
	else rtn a.x+va*(cross(b.x-a.x,vb)/cross(va,vb));
}

//Andrew's Monotone Chain算法  求凸包
void get_convex_hull(Polygon& PO)
{
	srt(PO);
	Polygon CH;
    rep(i,sz(PO))
    {
        while (sz(CH)>=2&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();
        CH.pb(PO[i]);
    }
    for (int i=sz(PO)-1,t=sz(CH)+1;i>=0;--i)
    {
        while (sz(CH)>=t&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();
        CH.pb(PO[i]);
    }
    CH.pop_back();
    PO.swap(CH);
}

}
}

using namespace StandardCodeLibrary::ComputationalGeometry2D;

int main()
{
	eps=1e-3;
	int n;
	cin>>n;
	Polygon PO(n);
	rep(i,n) cin>>PO[i];

	get_convex_hull(PO);

	vec<Segment> edges;
	for (int i=0,j=sz(PO)-1;i<sz(PO);j=i++) edges.pb(mp(PO[j],PO[i]));

	int m;
	cin>>m;
	rep(i,m)
	{
		Segment seg;
		cin>>seg;
		vec<Point> ps;
		if (point_in_polygon(seg.x,edges)==1) ps.pb(seg.x);
		if (point_in_polygon(seg.y,edges)==1) ps.pb(seg.y);
		bool online=false;
		rep(i,sz(edges))
		{
			Point p=intersection(edges[i],seg);
			if (point_on_segment(p,seg)==1&&point_on_segment(p,edges[i])==1)
			{
				bool fnd=false;
				rep(i,sz(ps)) if (sgn(dis(p,ps[i]))==0) fnd=true;
				if (!fnd) ps.pb(p);
			}
			if (sgn(cross(seg.x,edges[i].x,edges[i].y))==0
				&&sgn(cross(seg.y,edges[i].x,edges[i].y))==0)
				online=true;
		}
		if (online||!sz(ps)) pdb(2,0.0)<<endl;
		else pdb(2,dis(ps.front(),ps.back()))<<endl;
	}
}
