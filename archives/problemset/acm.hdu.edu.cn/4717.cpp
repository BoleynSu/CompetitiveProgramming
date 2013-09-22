#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
const double eps=1e-5;
const int oo=(~0u)>>1;
//
//int sa[30],sb[30];
//int n;
//char str[1002000];
//
//struct P
//{
//    int x,y;
//    P(){}
//    P(int _x,int _y):x(_x),y(_y){}
//    bool operator<(const P &b)const
//    {
//        return (x+y)%10>(b.x+b.y)%10;
//    }
//}a[120];
//char ans[1001000];
//int main()
//{
//    int cas,k,i,j,t,n,v,x,y,g;
//    scanf("%d",&cas);
//    for(k=1;k<=cas;k++)
//    {
//        memset(sa,0,sizeof(sa));
//        memset(sb,0,sizeof(sb));
//        scanf("%s",str);
//        for(i=0;str[i];i++)
//            sa[str[i]-'0']++;
//        scanf("%s",str);
//        for(i=0;str[i];i++)
//            sb[str[i]-'0']++;
//        t=0;
//        for(i=1;i<10;i++)
//            for(j=1;j<10;j++)
//                if(sa[i]&&sb[j])
//                    a[++t]=P(i,j);
//        sort(a+1,a+1+t);
//        ans[1]=(a[1].x+a[1].y)%10+'0';
//        sa[a[1].x]--;
//        sb[a[1].y]--;
//        n=1;
//        while(1)
//        {
//            t=0;
//            for(i=0;i<10;i++)
//                for(j=0;j<10;j++)
//                    if(sa[i]&&sb[j])
//                        a[++t]=P(i,j);
//            if(!t)break;
//            sort(a+1,a+1+t);
//            x=a[1].x;y=a[1].y;
//            v=min(sa[x],sb[y]);
//            sa[x]-=v;sb[y]-=v;
//            g=(x+y)%10+'0';
//            while(v--)ans[++n]=g;
//        }
//        printf("Case #%d: ",k);
//        for(i=1;ans[i]=='0'&&i<=n;i++);
//        if(i==n+1)putchar('0');
//        for(;i<=n;i++)
//            putchar(ans[i]);
//        puts("");
//    }
//}

const int MAXN=400;
int n;
double x[MAXN],y[MAXN];
double vx[MAXN],vy[MAXN];

double get(double t)
{
    double ans=0;
    for (int i=0;i<n;i++)
    {
        double ix=x[i]+vx[i]*t;
        double iy=y[i]+vy[i]*t;
        for (int j=i+1;j<n;j++)
        {
            double jx=x[j]+vx[j]*t;
            double jy=y[j]+vy[j]*t;
            double get=(jx-ix)*(jx-ix)+(jy-iy)*(jy-iy);
            if (get>ans) ans=get;
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&vx[i],&vy[i]);
        }
        double l=0,r=1e9;
        while (r-l>=eps)
        {
            double lm=(l*2+r)/3;
            double rm=(l+r*2)/3;
            if (get(lm)<get(rm)) r=rm;
            else l=lm;
        }
        printf("Case #%d: %.2f %.2f\n",t,(l+r)/2,sqrt(get((l+r)/2)));
    }
}
