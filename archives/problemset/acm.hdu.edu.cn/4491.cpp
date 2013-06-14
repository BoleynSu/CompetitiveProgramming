#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
#define sf scanf
#define pf printf
const double eps=1e-8,PI=acos(-1.0);
const int N=1020;
struct P
{
    double x,y;
    P(){}
    P(const double _x,const double _y):x(_x),y(_y){}
};
P a[N],now[N];
int n,m,S;
P O;
double ang;
int sgn(double x)
{
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
P operator-(const P&a,const P&b)
{
    return P(a.x-b.x,a.y-b.y);
}
P rot(const P&a,const double A)
{
    return P(a.x*cos(A)-a.y*sin(A),a.x*sin(A)+a.y*cos(A));
}
int main()
{
    int cas,cass,i,t,tmp,j;
    double minx,beta;
    scanf("%d",&cas);
    for(cass=1;cass<=cas;cass++)
    {
        scanf("%d",&t);
        scanf("%d%d%d%lf",&n,&m,&S,&ang);
        ang=ang/180.0*PI;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        printf("%d ",cass);
        for(i=1;i<=m;i++)
        {
            minx=2e9;
            for(j=1;j<=n;j++)
            if(j!=S)
            {
                now[j]=rot(a[j]-a[S],-ang);
                beta=atan2(now[j].y,now[j].x);
                if(sgn(beta)>0)
                {
                    if(minx>beta)
                    {
                        minx=beta;
                        tmp=j;
                    }
                }
                else if(sgn(PI+beta))
                {
                    beta=PI+beta;
                    if(minx>beta)
                    {
                        minx=beta;
                        tmp=j;
                    }
                }
            }
            //printf("%f ",minx);
            printf("%d",tmp);
            if(i<m)putchar(' ');
            O=a[tmp]-a[S];
            ang=atan2(O.y,O.x);
            if(ang<0)ang+=PI;
            //printf("%f# ",ang);
            S=tmp;
        }
        puts("");
    }
}

