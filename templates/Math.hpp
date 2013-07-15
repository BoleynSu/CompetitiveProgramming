/*
 * Package: StandardCodeLibrary.Math
 * Description:
 * Simpson's rule实现数值积分计算
 * */
#include <Core>
#include <Math.BigInteger>
#include <Math.NumberTheory>

//Simpson's rule实现数值积分计算
//integrate(a,b)=f(x)在[a,b]上的定积分
template<typename func>
db simpson(db a,db b,func f)
{
	rtn (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6;
}
template<typename func>
db integrate(db a,db b,func f)
{
	db c=(a+b)/2;
	db l=simpson(a,c,f);
	db r=simpson(c,b,f);
	db t=simpson(a,b,f);
	rtn sgn(l+r-t)?integrate(a,c,f)+integrate(c,b,f):t;
}
