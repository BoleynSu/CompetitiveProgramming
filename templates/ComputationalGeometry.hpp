/*
 * Package: StandardCodeLibrary.ComputationalGeometry
 * Description:
 * Ray Casting Algorithm 射线法判断点是否在简单多边形内
 * Andrew's Monotone Chain算法 求凸包
 * 半品面交 O(nlogn)算法
 * Delaunay三角剖分 O(nlogn)分治法(离线)和O(n^2)增量法(在线) MAXV为最大点数 使用在线算法时要额外增加3个点
 * */
#include <Core>

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
	rtn in?1:0;
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
	if (dbcmp(du,dv)) rtn dbcmp(du,dv)<0;
	else rtn sgn(cross(a.x,a.y,b.x))<0;
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
			rtn sgn(cross(c.x,c.y,ab))<=0;//如果交集可以退化成线或者点 <=变<
		}
		else rtn false;
	}
	else rtn true;
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
	if (sz(q)<3) rtn false;
	else
	{
		CH.resize(sz(q)),AHP.resize(sz(q));
		rep(i,sz(q)) AHP[i]=q[i];
		for (int i=0,j=sz(AHP)-1;i<sz(AHP);j=i++)
			CH[i]=line_intersection(AHP[i],AHP[j]);
		rtn true;
	}
}

//Delaunay三角剖分 O(nlogn)分治法(离线)和O(n^2)增量法(在线)
const int MAXV=3;
const int MAXE=3*MAXV-6;
struct Vertex:Point
{
	int id;
	Vertex(){}
	Vertex(Number x,Number y):Point(x,y){}
};
//struct Face:Polygon
//{
//	int id;
//	Face(int n=0):Polygon(0){}
//};
typedef struct QuadEdge* Edge;
struct QuadEdge
{
	int idx;
	Edge n;
	Vertex v;
//	Face f;
	inline Edge Rot(){rtn idx<3?this+1:this-3;}
	inline Edge InvRot(){rtn idx>0?this-1:this+3;}
	inline Edge Sym(){rtn idx<2?this+2:this-2;}
	inline Edge Onext(){rtn n;}
	inline Edge Oprev(){rtn Rot()->Onext()->Rot();}
	inline Edge Dnext(){rtn Sym()->Onext()->Sym();}
	inline Edge Dprev(){rtn InvRot()->Onext()->InvRot();}
	inline Edge Lnext(){rtn InvRot()->Onext()->Rot();}
	inline Edge Lprev(){rtn Onext()->Sym();}
	inline Edge Rnext(){rtn Rot()->Onext()->InvRot();}
	inline Edge Rprev(){rtn Sym()->Onext();}
	inline Vertex& Org(){rtn v;}
	inline Vertex& Dest(){rtn Sym()->v;}
//	inline Face& Left(){rtn Rot()->f;}
//	inline Face& Right(){rtn InvRot()->f;}
}pool[MAXE][4];
Edge stk[MAXE];
int stks;
int n;
Vertex v[MAXV];

inline bool Equal(const Vertex& A,const Vertex& B){rtn sgn(dis(A,B))==0;}
inline bool CCW(const Vertex& A,const Vertex& B,const Vertex& C){rtn sgn(cross(A,B,C))>0;}
inline bool RightOf(const Vertex& X,Edge e){rtn CCW(X,e->Dest(),e->Org());}
inline bool LeftOf(const Vertex& X,Edge e){rtn CCW(X,e->Org(),e->Dest());}
inline bool Valid(Edge e,Edge basel){rtn RightOf(e->Dest(),basel);}
inline bool InCircle(const Vertex& A,const Vertex& B,const Vertex& C,const Vertex& D)
{
	rtn sgn(dot(A,A)*cross(B,C,D)-
			dot(B,B)*cross(A,C,D)+
			dot(C,C)*cross(A,B,D)-
			dot(D,D)*cross(A,B,C))>0;
}
inline bool On(const Vertex& X,Edge e){rtn point_on_segment(X,mp(e->Org(),e->Dest()))==1;}

Edge MakeEdge()
{
	Edge e=stk[stks++];
	rep(i,4) e[i].idx=i,e[i].n=e+(i?4-i:0);
	rtn e;
}
void Splice(Edge a, Edge b)
{
	Edge alpha=a->Onext()->Rot(),beta=b->Onext()->Rot();
	Edge t1=b->Onext(),t2=a->Onext();
	Edge t3=beta->Onext(),t4=alpha->Onext();
	a->n=t1,b->n=t2;
	alpha->n=t3,beta->n=t4;
}
Edge Connect(Edge a,Edge b)
{
	Edge e=MakeEdge();
	e->Org()=a->Dest(),e->Dest()=b->Org();
	Splice(e,a->Lnext()),Splice(e->Sym(),b);
	rtn e;
}
void DeleteEdge(Edge e)
{
	Splice(e,e->Oprev());
	Splice(e->Sym(),e->Sym()->Oprev());
	stk[--stks]=e-e->idx;
}
void Swap(Edge e)
{
	Edge a=e->Oprev(),b=e->Sym()->Oprev();
	Splice(e,a),Splice(e->Sym(),b);
	Splice(e,a->Lnext()),Splice(e->Sym(),b->Lnext());
	e->Org()=a->Dest(),e->Dest()=b->Dest();
}
Edge Locate(Vertex X)
{
	Edge e=stk[rand()%stks];
	lp
	{
		if (Equal(X,e->Org())||Equal(X,e->Dest())) rtn e;
		else if (RightOf(X,e)) e=e->Sym();
		else if (!RightOf(X,e->Onext())) e=e->Onext();
		else if (!RightOf(X,e->Dprev())) e=e->Dprev();
		else rtn e;
	}
}

void InitializeDelaunay()
{
	stks=0;
	rep(i,MAXE) stk[i]=pool[i];
	sort(v,v+n);
}
pr<Edge,Edge> Delaunay(int l,int r)
{
	if (r-l==2)
	{
		Vertex s1=v[l],s2=v[l+1];
		Edge a=MakeEdge();
		a->Org()=s1,a->Dest()=s2;
		rtn mp(a,a->Sym());
	}
	else if (r-l==3)
	{
		Vertex s1=v[l],s2=v[l+1],s3=v[l+2];
		Edge a=MakeEdge(),b=MakeEdge();
		Splice(a->Sym(),b),a->Org()=s1,a->Dest()=b->Org()=s2,b->Dest()=s3;
		if (CCW(s1,s2,s3))
		{
			Edge c=Connect(b,a);
			rtn mp(a,b->Sym());
		}
		else if (CCW(s1,s3,s2))
		{
			Edge c=Connect(b,a);
			rtn mp(c->Sym(),c);
		}
		else rtn mp(a,b->Sym());
	}
	else
	{
		pr<Edge,Edge> ld=Delaunay(l,(l+r)/2),rd=Delaunay((l+r)/2,r);
		Edge ldo=ld.x,ldi=ld.y,rdi=rd.x,rdo=rd.y;
		lp
		{
			if (LeftOf(rdi->Org(),ldi)) ldi=ldi->Lnext();
			else if (RightOf(ldi->Org(),rdi)) rdi=rdi->Rprev();
			else break;
		}
		Edge basel=Connect(rdi->Sym(),ldi);
		if (Equal(ldi->Org(),ldo->Org())) ldo=basel->Sym();
		if (Equal(rdi->Org(),rdo->Org())) rdo=basel;
		lp
		{
			Edge lcand=basel->Sym()->Onext();
			if (Valid(lcand,basel))
				whl(InCircle(basel->Dest(),basel->Org(),lcand->Dest(),lcand->Onext()->Dest()))
				{
					Edge t=lcand->Onext();
					DeleteEdge(lcand),lcand=t;
				}
			Edge rcand=basel->Oprev();
			if (Valid(rcand,basel))
				whl(InCircle(basel->Dest(),basel->Org(),rcand->Dest(),rcand->Oprev()->Dest()))
				{
					Edge t=rcand->Oprev();
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
void InitializeInsertSite()
{
	stks=0;
	rep(i,MAXE) stk[i]=pool[i];
	Vertex s1(-inf,-inf),s2(0,+inf),s3(+inf,0);
	s1.id=s2.id=s3.id=-1;
	Edge a=MakeEdge(),b=MakeEdge();
	Splice(a->Sym(),b),a->Org()=s1,a->Dest()=b->Org()=s2,b->Dest()=s3;
	Connect(b,a);
}
void InsertSite(const Vertex& X)
{
	Edge e=Locate(X);
	if (Equal(X,e->Org())||Equal(X,e->Dest())) rtn;
	else if (On(X,e))
	{
		Edge t=e->Oprev();
		DeleteEdge(e),e=t;
	}
	Edge base=MakeEdge();
	Vertex first=e->Org();
	base->Org()=first,base->Dest()=X,Splice(base,e);
	do base=Connect(e,base->Sym()),e=base->Oprev();
	whl(!Equal(e->Dest(),first));
	e=base->Oprev();
	lp
	{
		Edge t=e->Oprev();
		if (RightOf(t->Dest(),e)&&InCircle(e->Org(),t->Dest(),e->Dest(),X))
			Swap(e),e=e->Oprev();
		else if (Equal(e->Org(),first)) rtn;
		else e=e->Onext()->Lprev();
	}
}

}
}
