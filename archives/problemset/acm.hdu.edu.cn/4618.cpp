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

//#define eps 1e-8
//#define inf 1e12
//
//struct point3 {
//
//    double x,y,z;
//    point3(double xx,double yy,double zz){
//        x=xx;y=yy;z=zz;
//    }
//    point3(){x=0;y=0;z=0;}
//    point3 operator- (const point3 p) {return point3(x-p.x,y-p.y,z-p.z);}
//    point3 operator* (const point3 p)
//    {
//        return point3(
//        y*p.z-p.y*z,
//        z*p.x-p.z*x,
//        x*p.y-p.y*x
//                );
//    }
//
//    point3 operator+ (const point3 p){return point3(x+p.x,y+p.y,z+p.z);}
//
//    double operator^ (const point3 p){
//        return (x*p.x+y*p.y+z*p.z);
//    }
//};
//
//struct line3{point3 a,b;};
//
//struct plane3{point3 a,b,c,n;};
//
//plane3 pl[333];
//
//
//double len(point3 p){
//    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
//}
//
//double dis(point3 u,point3 v){
//    return sqrt(len(u-v));
//}
//
//point3 pvec(point3 p1,point3 p2,point3 p3){
//    point3 n=(p2-p1)*(p3-p1);
//    return n;
//}
//
//double ptoline(point3 p,point3 l1,point3 l2){
//    return fabs( len((l1-p)*(l2-p))/dis(l1,l2) ) ;
//}
//
//double linetoline(point3 u1,point3 u2,point3 v1,point3 v2){
//    point3 n=(u1-u2)*(v1-v2);
//    if(len(n)<eps)
//        return ptoline(u1,v1,v2);
//    return fabs( (u1-v1)^n)  / len(n);
//}
////0.000000 0.000000 0.000000 0.000000 3.000000 0.000000
////112.000000 115.000000 109.000000 107.000000 108.000000 109.000000
////-110.000000 -121.000000 -130.000000 -121.584312 -130.009805 -130.000000
////185.516527
//int main()
//{
//    int cas;
//    scanf("%d",&cas);
//    int n;
//    while(cas--){
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%lf%lf%lf",&pl[i].a.x,&pl[i].a.y,&pl[i].a.z);
//            scanf("%lf%lf%lf",&pl[i].b.x,&pl[i].b.y,&pl[i].b.z);
//            scanf("%lf%lf%lf",&pl[i].c.x,&pl[i].c.y,&pl[i].c.z);
//            pl[i].n=pvec(pl[i].a,pl[i].b,pl[i].c);
//        }
//
//        double ans=inf;
//        for(int i=1;i<=n;i++)
//        {
//            point3 b=pl[i].a+pl[i].n;
//            printf("%f %f %f %f %f %f\n",pl[i].a.x,pl[i].a.y,pl[i].a.z,b.x,b.y,b.z);
//            for(int j=1;j<=n;j++)
//            if(i!=j)
//            {
//                double d=linetoline(pl[i].a+pl[i].n,pl[i].a,pl[j].a+pl[j].n,pl[j].a );
//                d-=dis(pl[i].a,pl[i].b);
//                d-=dis(pl[j].a,pl[j].b);
//                if(d<0)
//                    d=0;
//                if(d<ans)
//                    ans=d;
//            }
//        }
//        if(ans>eps)
//            printf("%.6f\n",ans);
//        else
//
//            printf("Lucky\n");
//    }
//}

typedef unsigned int big;

const int N=304;
big H1[N][N],H2[N][N];
big h1[N][N],h2[N][N],h3[N][N],h4[N][N];
int a[N][N];
const int s1=99999973,s2=1000000007;
int n,m;
bool ck1(int r)
{
    int i,j,k;
    big s=0;
    big pw1=1,pw2=1;
    for(i=1;i<r;i++)pw1*=s1;
    for(i=1;i<r;i++)pw2*=s2;
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=1;j<=r;j++)
            s=s*s1+a[i][j];
        H1[i][r]=s;
        for(j=r+1;j<=m;j++)
        {
            s-=pw1*a[i][j-r];
            s*=s1;
            s+=a[i][j];
            H1[i][j]=s;
        }
    }
    for(j=r;j+r-1<=m;j++)
    {
        s=0;
        for(i=1;i<=r;i++)
            s=s*s2+H1[i][j];
        h1[r][j]=s;
        for(i=r+1;i<=n;i++)
        {
            s-=pw2*H1[i-r][j];
            s*=s2;
            s+=H1[i][j];
            h1[i][j]=s;
        }
    }
    for(j=r;j+r-1<=m;j++)
    {
        s=0;
        for(i=n;i>=n-r+1;i--)
            s=s*s2+H1[i][j];
        h2[n-r+1][j]=s;
        for(i=n-r;i>=1;i--)
        {
            s-=pw2*H1[i+r][j];
            s*=s2;
            s+=H1[i][j];
            h2[i][j]=s;
        }
    }


    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=m;j>=m-r+1;j--)
            s=s*s1+a[i][j];
        H2[i][m-r+1]=s;
        for(j=m-r;j>=1;j--)
        {
            s-=pw1*a[i][j+r];
            s*=s1;
            s+=a[i][j];
            H2[i][j]=s;
        }
    }
    for(j=r;j<=m;j++)
    {
        s=0;
        for(i=1;i<=r;i++)
            s=s*s2+H2[i][j];
        h3[r][j]=s;
        for(i=r+1;i<=n;i++)
        {
            s-=pw2*H2[i-r][j];
            s*=s2;
            s+=H2[i][j];
            h3[i][j]=s;
        }
    }
    for(j=r;j<=m;j++)
    {
        s=0;
        for(i=n;i>=n-r+1;i--)
            s=s*s2+H2[i][j];
        h4[n-r+1][j]=s;
        for(i=n-r;i>=1;i--)
        {
            s-=pw2*H2[i+r][j];
            s*=s2;
            s+=H2[i][j];
            h4[i][j]=s;
        }
    }


    big t;
    for(i=r;i+r<=n;i++)
        for(j=r;j+r<=m;j++)
        {
            t=h1[i][j];
            if(t==h2[i+1][j]&&t==h3[i][j+1]&&t==h4[i+1][j+1])return true;
        }
    return false;
}


bool ck2(int r)
{
    int i,j,k;
    big s=0;
    big pw1=1,pw2=1;
    for(i=1;i<r;i++)pw1*=s1;
    for(i=1;i<r;i++)pw2*=s2;
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=1;j<=r;j++)
            s=s*s1+a[i][j];
        H1[i][r]=s;
        for(j=r+1;j<=m;j++)
        {
            s-=pw1*a[i][j-r];
            s*=s1;
            s+=a[i][j];
            H1[i][j]=s;
        }
    }
    for(j=r;j+r-1<=m;j++)
    {
        s=0;
        for(i=1;i<=r;i++)
            s=s*s2+H1[i][j];
        h1[r][j]=s;
        for(i=r+1;i<=n;i++)
        {
            s-=pw2*H1[i-r][j];
            s*=s2;
            s+=H1[i][j];
            h1[i][j]=s;
        }
    }
    for(j=r;j+r-1<=m;j++)
    {
        s=0;
        for(i=n;i>=n-r+1;i--)
            s=s*s2+H1[i][j];
        h2[n-r+1][j]=s;
        for(i=n-r;i>=1;i--)
        {
            s-=pw2*H1[i+r][j];
            s*=s2;
            s+=H1[i][j];
            h2[i][j]=s;
        }
    }


    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=m;j>=m-r+1;j--)
            s=s*s1+a[i][j];
        H2[i][m-r+1]=s;
        for(j=m-r;j>=1;j--)
        {
            s-=pw1*a[i][j+r];
            s*=s1;
            s+=a[i][j];
            H2[i][j]=s;
        }
    }
    for(j=r;j<=m;j++)
    {
        s=0;
        for(i=1;i<=r;i++)
            s=s*s2+H2[i][j];
        h3[r][j]=s;
        for(i=r+1;i<=n;i++)
        {
            s-=pw2*H2[i-r][j];
            s*=s2;
            s+=H2[i][j];
            h3[i][j]=s;
        }
    }
    for(j=r;j<=m;j++)
    {
        s=0;
        for(i=n;i>=n-r+1;i--)
            s=s*s2+H2[i][j];
        h4[n-r+1][j]=s;
        for(i=n-r;i>=1;i--)
        {
            s-=pw2*H2[i+r][j];
            s*=s2;
            s+=H2[i][j];
            h4[i][j]=s;
        }
    }

    big t;
    for(i=r;i+r-1<=n;i++)
        for(j=r;j+r-1<=m;j++)
        {
            t=h1[i][j];
            if(t==h2[i][j]&&t==h3[i][j]&&t==h4[i][j])return true;
        }
    return false;
}
void pri(big A[N][N])
{
    int i,j;
    for(i=1;i<=n;i++,puts(""))
        for(j=1;j<=m;j++)
            printf("%u ",A[i][j]);
    puts("\n");
}
int main()
{
    int s,e,ans,cas,i,j,mid;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        s=1;e=min(n/2,m/2);
        while(s<=e)
        {
            mid=s+e>>1;
            if(ck1(mid))s=mid+1;
            else e=mid-1;
        }
        ans=-1;
        ans=max(ans,2*e);
        s=1;e=min((n+1)/2,(m+1)/2);
        while(s<=e)
        {
            mid=s+e>>1;
            if(ck2(mid))s=mid+1;
            else e=mid-1;
        }

//        ck2(2);
//        pri(H1);
//        pri(H2);
//        pri(h1);pri(h2),pri(h3),pri(h4);
        ans=max(ans,2*e-1);
        printf("%d\n",ans);
    }
}

