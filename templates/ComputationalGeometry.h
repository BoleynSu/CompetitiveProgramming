/*
 * Package: StandardCodeLibrary.ComputationalGeometry
 * Description:
 * Ray Casting Algorithm 射线法判断点是否在简单多边形内
 * Andrew's Monotone Chain算法  求凸包
 * 半品面交 O(nlogn)算法
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
typedef Segment Line;
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
Point intersection(const Line& a,const Line& b)
{
	Vector va=a.y-a.x,vb=b.y-b.x;
	if (!sgn(cross(va,vb))) rtn Point(+inf,+inf);
	else rtn a.x+va*(cross(b.x-a.x,vb)/cross(va,vb));
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
			Point ab=intersection(a,b);
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
			CH[i]=intersection(AHP[i],AHP[j]);
		return true;
	}
}

}
}

