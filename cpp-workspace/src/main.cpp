#include <stdio.h>
#include <math.h>

const double pi=3.141592653589793238462643383279;
double x,y,theta;

int main()
{
	scanf("%lf",&x);
	y=sqrt(1.0*1.0-x*x);
	//tan(y/x)=theta
	theta=atan2(y,x);
	printf("%.4f\n",(1.0*1.0*pi-2.0*(1.0*1.0*theta/2.0-x*y/2.0))/(1.0*1.0*pi)*5.0);
}
