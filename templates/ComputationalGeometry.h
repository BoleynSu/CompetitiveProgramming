/*
 * Package: StandardCodeLibrary.ComputationalGeometry
 * Description:
 * Ray Casting Algorithm 射线法判断点是否在简单多边形内
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
typedef vec<Point> Polygon;//多边形

//基本运算
//符号函数 正数返回1 负数返回-1 0返回0
using ::sgn;
//比较函数 大于返回1 小于返回-1 等于返回0
using ::dbcmp;
//点积
using ::dot;
Number dot(const Point& a,const Point& b,const Point& c)
{
	rtn dot(b-a,c-a);
}
//叉积
using ::cross;
Number cross(const Point& a,const Point& b,const Point& c)
{
	rtn cross(b-a,c-a);
}
//长度
Number len(const Vector& v)
{
	rtn sqrt(dot(v,v));
}
Number len(const Segment& s)
{
	rtn len(s.x-s.y);
}
//距离
Number dis(const Point& a,const Point& b)
{
	rtn len(b-a);
}

//判断点是否在线段上
//如果点在线段上返回1 不在线段上但在直线上 返回-1 不在直线上返回0
int point_on_segment(const Point& p,const Segment& s)
{
	if (sgn(cross(p,s.x,s.y))) rtn 0;
	else rtn dbcmp(dis(s.x,p)+dis(s.y,p),len(s))==0?1:-1;
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

}
}

