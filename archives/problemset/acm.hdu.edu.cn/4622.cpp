#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define rep(i,n) for (int i=0;i<(n);i++)
#define sz(x) (int((x).size()))

typedef long long int lli;

const int MAXN=2013;
char s[MAXN];
int Q;
int n;
int f[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%d",s,&Q);
        n=strlen(s);
        for (int i=n-1;i>=0;i--)
        {
            int j=-1,max=-1;
            int pi[MAXN];
            pi[i]=-1;
            f[i][i]=1;
            for (int k=i+1;k<n;k++)
            {
                while (j!=-1&&s[k]!=s[i+j+1]) j=pi[i+j];
                if (s[k]==s[i+j+1]) j++;
                pi[k]=j;
                if (max<pi[k]) max=pi[k];
                f[i][k]=(i+1==n?0:f[i+1][k])+k-i-max;
            }
        }
        for (int i=0;i<Q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r),--l,--r;
            printf("%d\n",f[l][r]);
        }
    }
}
//
//
//
//const int N=1010;
//const double eps=1e-8;
//const double pi=acos(-1.0);
//double area[N];
//
//int n;
//
//int dcmp(double x){
//    return (x>eps)-(x<-eps);
//}
//
//struct point p{
//    double x,y;
//};
//
//struct cp{
//    point p[6];
//    double angle;
//    int d;
//    cp(){}
//    cp(point aa,point bb,point cc,double ang=0.0,int t=0){
//        p[0]=aa;p[1]=bb;p[2]=cc;angle=ang;d=t;
//        p[3]=aa;
//    }
//    void get(){
//        scanf("%lf%lf",&p[0].x,&p[0].y);
//        scanf("%lf%lf",&p[1].x,&p[1].y);
//        scanf("%lf%lf",&p[2].x,&p[2].y);
//        p[3]=p[0];
//        d=1;
//    }
//}cir[N],tp[N*2];
//
//
//double cross(point p0,point p1,point p2){
//    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
//}
//
//point intersect_ss(point p1,point p2,point p3 point p4){
//
//}
//
//bool cmp(const cp &u, const cp& v){
//    if(dcmp(u.angle-v.angle )) return u.angle<v.angle;
//    return u.d>v.d;
//}
//
//bool intersect_ss(point p1,point p2,point p3,point p4,point &p5){
//
//}
//
//
//double dis(point a,point b){
//    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
//}
//
//
//double calc(cp cp1,cp cp2){
//    point tmp;
//    tmp.x=0;tmp.y=0;
//    return cross(tmp,cp1.a,cp2.a);
//}
//
//void triunion(cp cir[],int n){
//    cp cp1,cp2;
//    for(int i=0;i<n;i++)
//    for(int j=0;j<n;j++)
//    if(i!=j)
//    {
//        if(tri_in(cir[i],cir[j]) )
//            cir[i].d++;
//    }
//
//    for(int i=0;i<n;i++){
//        int tn=0,cnt=0;
//        for(int j=0;j<n;j++){
//            if(i==j) continue;
//
//            for(int k1=0;k1<3;k1++)
//            for(int k2=0;k2<3;k2++)
//            {
//                point inter;
//                if(intersect_ss(
//                cir[i].p[k2],cir[i].p[k1+1],
//                cir[j].p[k2],cir[j].p[k2+1],inter))
//                {
//
//                }
//            }
//
//
//        }
//
//    }
//
//
//}

