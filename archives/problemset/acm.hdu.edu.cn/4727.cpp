#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
//const double eps=1e-8;
//struct P
//{
//    double x,y;
//    void in(){scanf("%lf%lf",&x,&y);}
//};
//double dis(P a,P b)
//{
//    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
//}
//int sgn(double x)
//{
//    return (x>eps)-(x<-eps);
//}
//P a,b,c,T,p[6];
//int main()
//{
//    int cas,i,j;
//    scanf("%d",&cas);
//    P cp;
//    bool flag;
//    pair<int,int>t;
//    for(int k=1;k<=cas;k++)
//    {
//        a.in();
//        b.in();
//        c.in();
//        T.in();
//        double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
//        double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
//        double d=a1*b2-a2*b1;
//        if(fabs(d)<1e-8)
//        {
//            p[0]=a;p[1]=b;p[2]=c;
//            t=make_pair(0,1);
//            for(i=0;i<3;i++)
//                for(j=i+1;j<3;j++)
//                    if(dis(p[i],p[j])>dis(p[t.first],p[t.second]))
//                        t=make_pair(i,j);
//            cp.x=(p[t.first].x+p[t.second].x)/2;
//            cp.y=(p[t.first].y+p[t.second].y)/2;
//            if(sgn(dis(T,cp)-dis(cp,a))<=0)flag=true;
//            else flag=false;
//        }
//        else
//        {
//            cp.x=a.x+(c1*b2-c2*b1)/d;
//            cp.y=a.y+(a1*c2-a2*c1)/d;
//            printf("%f %f\n",dis(T,cp),dis(cp,a));
//            if(sgn(dis(T,cp)-dis(cp,a))<=0)flag=true;
//            else flag=false;
//        }
//        printf("Case #%d: ",k);
//        if(flag)puts("Danger");
//        else puts("Safe");
//
//    }
//}
int a[129299],n;
int main()
{
    int cas;
    scanf("%d",&cas);
    int k,i,ans;
    for(k=1;k<=cas;k++)
    {
        scanf("%d",&n);
        ans=-1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i>1&&a[i]!=a[i-1]+1)ans=i;
        }
        if(ans==-1)ans=1;
        printf("Case #%d: %d\n",k,ans);
    }
}

//int main()
//{
//    int T;
//    scanf("%d",&T);
//    for (int t=1;t<=T;t++)
//    {
//        int ans=0;
//        printf("Case #%d: %d\n",t,ans);
//    }
//}
