#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long big;

struct P
{
    double x,y;
    P(){}
    P(double _x,double _y):x(_x),y(_y){}
}a[2000];
const double eps=1e-9;
int n;
int sgn(double x){return (x>eps)-(x<-eps);}
double det(const P &a,const P &b)
{
    return a.x*b.y-a.y*b.x;
}
double det(const P &s,const P &a,const P &b)
{
    return det(P(a.x-s.x,a.y-s.y),P(b.x-s.x,b.y-s.y));
}
int main()
{
    int i,j,k;
    int cas;
    double t;
    scanf("%d",&cas);
    while(cas--)
    {
        bool flag=false;
        double ans=2e9;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                for(k=j+1;k<=n;k++)
                {
                    t=fabs(det(a[i],a[j],a[k]));
                    if(sgn(t))ans=min(ans,t),flag=true;
                }
        if(!flag)puts("Impossible");
        else printf("%.2f\n",ans/2.0);
    }
}
