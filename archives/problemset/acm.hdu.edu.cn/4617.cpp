#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long long int lli;
#define mp make_pair
#define sz(x) (int((x).size()))

#define eps 1e-8
#define inf 1e12

struct point3 {

    double x,y,z;
    point3(double xx,double yy,double zz){
        x=xx;y=yy;z=zz;
    }
    point3(){x=0;y=0;z=0;}
    point3 operator- (const point3 p) {return point3(x-p.x,y-p.y,z-p.z);}
    point3 operator* (const point3 p)
    {
        return point3(
        y*p.z-p.y*z,
        z*p.x-p.z*x,
        x*p.y-p.x*y
                );
    }

    point3 operator+ (const point3 p){return point3(x+p.x,y+p.y,z+p.z);}

    double operator^ (const point3 p){
        return (x*p.x+y*p.y+z*p.z);
    }
};

struct line3{point3 a,b;};

struct plane3{point3 a,b,c,n;};

plane3 pl[333];


double len(point3 p){
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

double dis(point3 u,point3 v){
    return len(u-v);
}

point3 pvec(point3 p1,point3 p2,point3 p3){
    point3 n=(p2-p1)*(p3-p1);
    return n;
}

double ptoline(point3 p,point3 l1,point3 l2){
    //printf("%f %f %f %f %f %f %f %f %f\n",p.x,p.y,p.z,l1.x,l1.y,l1.z,l2.x,l2.y,l2.z);
    return fabs( len((l1-p)*(l2-p))/dis(l1,l2) ) ;
}

double linetoline(point3 u1,point3 u2,point3 v1,point3 v2){
    point3 p=u1-u2,l1=v1-v2;
//    printf("%f %f %f %f %f %f \n",p.x,p.y,p.z,l1.x,l1.y,l1.z);
    point3 n;
    n=p*l1;//(u1-u2)*(v1-v2);
//    printf("%f %f %f \n",n.x,n.y,n.z);
    //printf("%f\n",len(n));
    if(len(n)<eps)
    {
        return ptoline(u1,v1,v2);
    }
    return fabs( (u1-v1)^n)  / len(n);
}
/*
1
2
0 0 0
1 0 1.5
1 0 -1.5
-110 -121 -130
-115 -129 -140
-104 -114 -119.801961
 */
int main()
{
    point3 p1(0,0,1),p2(0,1,1),p3(0,0,0),p4(1,0,0);
    linetoline(p1,p2,p3,p4);
    int cas;
    scanf("%d",&cas);
    int n;
    while(cas--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&pl[i].a.x,&pl[i].a.y,&pl[i].a.z);
            scanf("%lf%lf%lf",&pl[i].b.x,&pl[i].b.y,&pl[i].b.z);
            scanf("%lf%lf%lf",&pl[i].c.x,&pl[i].c.y,&pl[i].c.z);
            pl[i].n=pvec(pl[i].a,pl[i].b,pl[i].c);
        }

        double ans=inf;
        for(int i=1;i<=n;i++)
        {
            //point3 b=pl[i].a+pl[i].n;
            //printf("%f %f %f %f %f %f\n",pl[i].a.x,pl[i].a.y,pl[i].a.z,b.x,b.y,b.z);
            for(int j=1;j<=n;j++)
            if(i!=j)
            {
                double d=linetoline(pl[i].a+pl[i].n,pl[i].a,pl[j].a+pl[j].n,pl[j].a );
                d-=dis(pl[i].a,pl[i].b);
                d-=dis(pl[j].a,pl[j].b);
                if(d<0)
                    d=0;
            //    printf("%d %d:%f\n",i,j,d);
                if(d<ans)
                    ans=d;
            }
        }
        if(ans>eps)
            printf("%.2f\n",ans);
        else

            printf("Lucky\n");
    }
}
