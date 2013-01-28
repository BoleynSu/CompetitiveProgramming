/*
 * main.cpp
 *
 *  Created on: 2012-12-2
 *      Author: sujiao
 */
#include <cstdio>
#include <cmath>
using namespace std;

double calc(int n,double p)
{
//    long double ans=0;
//    long double t=pow(p,n),c=1;
//    for (int i=0;i<=n;i++)
//    {
//        ans+=t*c*(n-i);
//        t*=1-p;
//        c*=double(n+i+1)/double(i+1);
//        //printf("%f %f %f\n",t,c,c);
//    }
//    ans*=p;
//    return ans;
    long double ans=0;
    long double t=log(p)*n,c=log(1);
    for (int i=0;i<=n;i++)
    {
        if (fabs(t+c)<100) ans+=exp(t+c)*(n-i);
        t+=log(1-p);
        c+=log(double(n+i+1)/double(i+1));
    }
    ans*=p;
    return ans;
}

int main()
{
    int n;
    double p;
    while (~scanf("%d%lf",&n,&p))
    {
        double ans=calc(n,p)+calc(n,1.0-p);
        static int t;
        printf("Case %d: %.6f\n",++t,ans);
    }
}


