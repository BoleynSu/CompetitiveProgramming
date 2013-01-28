/*
 * main.cpp
 *
 *  Created on: 2012-12-2
 *      Author: sujiao
 */
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int f[1024];
    f[0]=1;
    for (int i=1;i<=1000;i++)
    {
        int t=i-1;
        f[i]=f[t];
        for (int j=1;j<t;j++)
            if (t%j==0)
                f[i]=(f[i]+f[j])%1000000007;
    }
    while (~scanf("%d",&n))
    {
        static int t;
        printf("Case %d: %d\n",++t,f[n]);
    }
}


