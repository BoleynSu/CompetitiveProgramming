/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间
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
using namespace std;

//用于减少代码量的宏
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rrepf(i,a,b) for (int i=(a)-1;i>=(b);--i)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))

//调试相关的宏
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型
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

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
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
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化
struct Initializer
{
#ifndef DEBUG
	Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
	~Initializer(){runtime();}
#endif
}initializer;

////非标准
//#define feach(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//using __gnu_cxx::rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount

/*
 * Package: StandardCodeLibrary.ComputationalGeometry
 * Description:
 * Ray Casting Algorithm 射线法判断点是否在简单多边形内
 * Andrew's Monotone Chain算法 求凸包
 * 半品面交 O(nlogn)算法
 * */

namespace StandardCodeLibrary
{
namespace ComputationalGeometry2D
{

//数据类型定义
typedef db Number;//数值类型
typedef pr<Number,Number> Point;//点
typedef Point Vector;//向量
typedef pr<Point,Point> Segment;//线段
typedef Segment Line;//直线
typedef Segment Halfplane;//半平面
typedef vec<Point> Polygon;//多边形

//基本运算
//符号函数 正数返回1 负数返回-1 0返回0
using ::sgn;
//比较函数 大于返回1 小于返回-1 等于返回0
using ::dbcmp;
//点积
using ::dot;
inline
Number dot(const Vector& a,const Vector& b,const Vector& c)
{
	rtn dot(b-a,c-a);
}
//叉积
using ::cross;
inline
Number cross(const Vector& a,const Vector& b,const Vector& c)
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

//判断点是否在直线上
//如果点在直线上返回1 不在直线上返回0
int point_on_line(const Point& p,const Line& l)
{
	if (sgn(cross(p,l.x,l.y))) rtn 0;
	else rtn 1;
}
//判断点是否在线段上
//如果点在线段上返回1 不在线段上但在直线上 返回-1 不在直线上返回0
int point_on_segment(const Point& p,const Segment& s)
{
	if (point_on_line(p,s)) rtn sgn(dot(p,s.x,s.y))<=0?1:-1;
	else rtn 0;
}

//Ray Casting Algorithm 射线法判断点是否在简单多边形内
//在内部返回1 在外部返回0 在边上返回-1
int point_in_polygon(const Point& p,const vec<Segment>& e)
{
	rep(i,sz(e)) if (point_on_segment(p,e[i])==1) rtn -1;
	bool in=false;
	rep(i,sz(e))
		if ((dbcmp(e[i].x.y,p.y)>0)!=(dbcmp(e[i].y.y,p.y)>0)
			&&dbcmp(p.x,(e[i].y.x-e[i].x.x)/(e[i].y.y-e[i].x.y)*(p.y-e[i].x.y)+e[i].x.x)<0)
			in=!in;
	return in?1:0;
}

//判断直线是否相交
//1表示相交 -1表示重合 0表示平行
int line_intersect(const Line& a,const Line& b)
{
	Vector va=a.y-a.x,vb=b.y-b.x;
	if (sgn(cross(va,vb))) rtn 1;
	else
	{
		if (sgn(cross(a.x,a.y,b.x))) rtn 0;
		else rtn -1;
	}
}

//判断线段是否相交
//1表示有一个交点
//-1表示有无穷多个交点(两线段平行但实际只有一个交点也算入了这种情况)
//0表示不相交
int segment_intersect(const Segment& a,const Segment& b)
{
	int ab=sgn(cross(a.x,a.y,b.x))*sgn(cross(a.x,a.y,b.y)),
		ba=sgn(cross(b.x,b.y,a.x))*sgn(cross(b.x,b.y,a.y));
	if (ab>0||ba>0) rtn 0;
	else
	{
		Vector va=a.y-a.x,vb=b.y-b.x;
		if (sgn(cross(va,vb))) rtn 1;
		else
		{
			if (sgn(dot(b.x,a.x,a.y))<=0
				||sgn(dot(b.y,a.x,a.y))<=0
				||sgn(dot(a.x,b.x,b.y))<=0
				||sgn(dot(a.y,b.x,b.y))<=0)
				rtn -1;
			else rtn 0;
		}
	}
}

//求直线交点
//需保证直线不平行 返回直线交点
Point line_intersection(const Line& a,const Line& b)
{
	Vector va=a.y-a.x,vb=b.y-b.x;
	rtn a.x+va*(cross(b.x-a.x,vb)/cross(va,vb));
}

//Andrew's Monotone Chain算法  求凸包
void convex_hull(Polygon& CH,Polygon& PO)
{
	CH.clear();
	srt(PO);
	rep(i,sz(PO))
	{
		whl(sz(CH)>=2&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();//如果要将在凸包上的非顶点也放入凸包内 <=变<
		CH.pb(PO[i]);
	}
	for (int i=sz(PO)-2,t=sz(CH)+1;i>=0;--i)
	{
		whl(sz(CH)>=t&&sgn(cross(CH[sz(CH)-2],CH[sz(CH)-1],PO[i]))<=0) CH.pop_back();//如果要将在凸包上的非顶点也放入凸包内 <=变<
		CH.pb(PO[i]);
	}
	CH.pop_back();
}

//半平面交 返回false表示交集为空 返回true时 CH为交集对应的凸包 AHP为HP中有效的部分
bool halfplane_intersection_compare(const Halfplane& a,const Halfplane& b)
{
	Vector u=a.y-a.x,v=b.y-b.x;
	db du=atan2(u.y,u.x),dv=atan2(v.y,v.x);
	if (dbcmp(du,dv)) return dbcmp(du,dv)<0;
	else return sgn(cross(a.x,a.y,b.x))<0;
}
bool halfplane_intersection_judge(const Halfplane& a,const Halfplane& b,const Halfplane& c)
{
	Vector u=a.y-a.x,v=b.y-b.x;
	db du=atan2(u.y,u.x),dv=atan2(v.y,v.x);
	if (dbcmp(du,dv))
	{
		if (sgn(cross(a.y-a.x,b.y-b.x)))
		{
			Point ab=line_intersection(a,b);
			return sgn(cross(c.x,c.y,ab))<=0;//如果交集可以退化成线或者点 <=变<
		}
		else return false;
	}
	else return true;
}
bool halfplane_intersection(Polygon& CH,vec<Halfplane>& AHP,vec<Halfplane> HP)
{
	HP.pb(Halfplane(Point(-inf,-inf),Point(+inf,-inf))),
	HP.pb(Halfplane(Point(+inf,-inf),Point(+inf,+inf))),
	HP.pb(Halfplane(Point(+inf,+inf),Point(-inf,+inf))),
	HP.pb(Halfplane(Point(-inf,+inf),Point(-inf,-inf)));
	sort(all(HP),halfplane_intersection_compare);
	deque<Halfplane> q;
	q.pb(HP.front());
	repf(i,1,sz(HP))
	{
		Halfplane t;
		do t=q.back(),q.pop_back();
		whl(sz(q)&&halfplane_intersection_judge(q.back(),t,HP[i]));
		q.pb(t);
		do t=q.front(),q.pop_front();
		whl(sz(q)&&halfplane_intersection_judge(q.front(),t,HP[i]));
		q.push_front(t);
		q.pb(HP[i]);
	}
	Halfplane t;
	do t=q.back(),q.pop_back();
	whl(sz(q)&&halfplane_intersection_judge(q.back(),t,q.front()));
	q.pb(t);
	if (sz(q)<3) return false;
	else
	{
		CH.resize(sz(q)),AHP.resize(sz(q));
		rep(i,sz(q)) AHP[i]=q[i];
		for (int i=0,j=sz(AHP)-1;i<sz(AHP);j=i++)
			CH[i]=line_intersection(AHP[i],AHP[j]);
		return true;
	}
}

}
}

namespace StandardCodeLibrary
{
namespace ComputationalGeometry2D
{

const int MAXN=500000;

typedef Point Vertex;
typedef int Face;
struct Edge
{
	int idx;
	Edge* n;
	union
	{
		Vertex* v;
		Face* f;
	};
	inline Edge* Rot(){return idx<3?this+1:this-3;}
	inline Edge* InvRot(){return idx>0?this-1:this+3;}
	inline Edge* Sym(){rtn idx<2?this+2:this-2;}
	inline Edge* Onext(){rtn n;}
	inline Edge* Oprev(){rtn Rot()->Onext()->Rot();}
	inline Edge* Dnext(){rtn Sym()->Onext()->Sym();}
	inline Edge* Dprev(){rtn InvRot()->Onext()->InvRot();}
	inline Edge* Lnext(){rtn InvRot()->Onext()->Rot();}
	inline Edge* Lprev(){rtn Onext()->Sym();}
	inline Edge* Rnext(){rtn Rot()->Onext()->InvRot();}
	inline Edge* Rprev(){rtn Sym()->Onext();}
	inline Vertex*& Org(){rtn v;}
	inline Vertex*& Dest(){rtn Sym()->v;}
	inline Face*& Left(){rtn Rot()->f;}
	inline Face*& Right(){rtn InvRot()->f;}
}pool[MAXN];
Edge* top;
int n;
Vertex v[MAXN];

Edge* MakeEdge()
{
	Edge* e=top;
	rep(i,4) e[i].idx=i,e[i].n=e+(4-i)%4;
	top+=4;
	rtn e;
}
void Splice(Edge *a, Edge *b)
{
	Edge* alpha=a->Onext()->Rot();
	Edge* beta=b->Onext()->Rot();
	Edge* t1=b->Onext();
	Edge* t2=a->Onext();
	Edge* t3=beta->Onext();
	Edge* t4=alpha->Onext();
	a->n=t1;
	b->n=t2;
	alpha->n=t3;
	beta->n=t4;
}
Edge* Connect(Edge* a,Edge* b)
{
	Edge* e=MakeEdge();
	e->Org()=a->Dest();
	e->Dest()=b->Org();
	Splice(e,a->Lnext());
	Splice(e->Sym(),b);
	rtn e;
}
void DeleteEdge(Edge* e)
{
	Splice(e,e->Oprev());
	Splice(e->Sym(),e->Sym()->Oprev());
}

bool CCW(Vertex* a,Vertex* b,Vertex* c)
{
	rtn sgn(cross(*a,*b,*c))>0;
}
bool InCircle(Vertex* a,Vertex* b,Vertex* c,Vertex* d)
{
	rtn sgn(dot(*a,*a)*cross(*b,*c,*d)-
			dot(*b,*b)*cross(*a,*c,*d)+
			dot(*c,*c)*cross(*a,*b,*d)-
			dot(*d,*d)*cross(*a,*b,*c))>0;
}
bool RightOf(Vertex* x,Edge* e)
{
	rtn CCW(x,e->Dest(),e->Org());
}
bool LeftOf(Vertex* x,Edge* e)
{
	rtn CCW(x,e->Org(),e->Dest());
}
bool Valid(Edge* e,Edge* basel)
{
	rtn RightOf(e->Dest(),basel);
}

pr<Edge*,Edge*> Delaunay(int l,int r)
{
	if (r-l==2)
	{
		Vertex *s1=v+l,*s2=v+l+1;
		Edge* a=MakeEdge();
		a->Org()=s1,a->Dest()=s2;
		rtn mp(a,a->Sym());
	}
	else if (r-l==3)
	{
		Vertex *s1=v+l,*s2=v+l+1,*s3=v+l+2;
		Edge *a=MakeEdge(),*b=MakeEdge();
		Splice(a->Sym(),b),a->Org()=s1,a->Dest()=b->Org()=s2,b->Dest()=s3;
		if (CCW(s1,s2,s3))
		{
			Connect(b,a);
			rtn mp(a,b->Sym());
		}
		else if (CCW(s1,s3,s2))
		{
			Edge* c=Connect(b,a);
			rtn mp(c->Sym(),c);
		}
		else rtn mp(a,b->Sym());
	}
	else
	{
		pr<Edge*,Edge*> ld=Delaunay(l,(l+r)/2),rd=Delaunay((l+r)/2,r);
		Edge* ldo=ld.x;
		Edge* ldi=ld.y;
		Edge* rdi=rd.x;
		Edge* rdo=rd.y;
		lp
		{
			if (LeftOf(rdi->Org(),ldi)) ldi=ldi->Lnext();
			else if (RightOf(ldi->Org(),rdi)) rdi=rdi->Rprev();
			else break;
		}
		Edge* basel=Connect(rdi->Sym(),ldi);
		if (ldi->Org()==ldo->Org()) ldo=basel->Sym();
		if (rdi->Org()==rdo->Org()) rdo=basel;
		lp
		{
			Edge* lcand=basel->Sym()->Onext();
			if (Valid(lcand,basel))
				whl(InCircle(basel->Dest(),basel->Org(),lcand->Dest(),lcand->Onext()->Dest()))
				{
					Edge* t=lcand->Onext();
					DeleteEdge(lcand),lcand=t;
				}
			Edge* rcand=basel->Oprev();
			if (Valid(rcand,basel))
				whl(InCircle(basel->Dest(),basel->Org(),rcand->Dest(),rcand->Oprev()->Dest()))
				{
					Edge* t=rcand->Oprev();
					DeleteEdge(rcand),rcand=t;
				}
			if (!Valid(lcand,basel)&&!Valid(rcand,basel)) break;
			if (!Valid(lcand,basel)||(Valid(rcand,basel)&&InCircle(lcand->Dest(),lcand->Org(),rcand->Org(),rcand->Dest())))
				basel=Connect(rcand,basel->Sym());
			else
				basel=Connect(basel->Sym(),lcand->Sym());
		}
		rtn mp(ldo,rdo);
	}
}
//Delaunay Triangulation
Edge* delaunay_triangulation()
{
	top=pool;
	sort(v,v+n);
	rtn Delaunay(0,n).x;
}

}
}
using namespace StandardCodeLibrary::ComputationalGeometry2D;

int main()
{
		cin>>n;
		map<Point,int> id;
		rep(i,n) cin>>v[i],id[v[i]]=i;

		Edge* v=delaunay_triangulation();
		vb inq(top-pool);
		que<Edge*> q;
		vec<pr<Number,pii> > edg;
		if (!inq[v-pool])
		{
			edg.pb(mp(dis(*v->Org(),*v->Dest()),mp(id[*v->Org()],id[*v->Dest()])));
			//cerr<<v->Org()<<" "<<v->Dest()<<endl;
			inq[v-pool]=true;
			q.push(v);
		}
		whl(sz(q))
		{
			Edge* u=q.front();
			q.pop();
			v=u->Onext();
			if (!inq[v-pool])
			{
				edg.pb(mp(dis(*v->Org(),*v->Dest()),mp(id[*v->Org()],id[*v->Dest()])));
				//cerr<<v->Org()<<" "<<v->Dest()<<endl;
				inq[v-pool]=true;
				q.push(v);
			}
			v=u->Lnext();
			if (!inq[v-pool])
			{
				edg.pb(mp(dis(*v->Org(),*v->Dest()),mp(id[*v->Org()],id[*v->Dest()])));
				//cerr<<v->Org()<<" "<<v->Dest()<<endl;
				inq[v-pool]=true;
				q.push(v);
			}
		}
		srt(edg);
		vi st(n);
		vvi adj(n);
		vec<vec<Number> > len(n);
		make_set(st);
		rep(i,sz(edg))
			if (union_set(st,edg[i].y.x,edg[i].y.y))
			{
				adj[edg[i].y.x].pb(edg[i].y.y),
				adj[edg[i].y.y].pb(edg[i].y.x),
				len[edg[i].y.x].pb(edg[i].x),
				len[edg[i].y.y].pb(edg[i].x);
			}
		//rep(i,sz(edg)) prt(edg[i]);
		vvi p(n,vi(20));
		vec<vec<Number> > f(n,vec<Number>(20));
		vi d(n,+oo);
		que<int> lst;
		d[0]=0,lst.push(0),p[0][0]=0,f[0][0]=0;
		whl(sz(lst))
		{
			int u=lst.front();
			lst.pop();
			rep(i,sz(adj[u]))
			{
				int v=adj[u][i];
				if (cmin(d[v],d[u]+1)) lst.push(v),p[v][0]=u,f[v][0]=len[u][i];
			}
		}
		repf(i,1,20)
			rep(j,n)
				p[j][i]=p[p[j][i-1]][i-1],
				f[j][i]=max(f[j][i-1],f[p[j][i-1]][i-1]);
		int m;
		cin>>m;
		rep(i,m)
		{
			int a,b;
			cin>>a>>b,--a,--b;
			Number ans=0;
			rrep(i,20) if (d[a]<=d[p[b][i]]) cmax(ans,f[b][i]),b=p[b][i];
			rrep(i,20) if (d[b]<=d[p[a][i]]) cmax(ans,f[a][i]),a=p[a][i];
			rrep(i,20) if (p[a][i]!=p[b][i]) cmax(ans,max(f[a][i],f[b][i])),a=p[a][i],b=p[b][i];
			//prt(a),prt(b);
			//prt(ans);
			if (a!=b)
			{
				int i=0;
				cmax(ans,max(f[a][i],f[b][i])),a=p[a][i],b=p[b][i];
			}
			//prt(a),prt(b);
			pdb(10,ans)<<endl;
		}
}
