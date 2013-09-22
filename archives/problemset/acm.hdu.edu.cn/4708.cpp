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


int n;
int a[20][20];
int ansa,ansb;
vector<int>b;
void get(int d)
{
    int i,j,t=n-d+1,t1,t2;
    b.clear();
    t1=-0x3f3f3f3f;t2=0x3f3f3f3f;
    for(i=d;i+d-1<=n;i++)
        b.pb(a[d][i]);
    for(i=d+1;i+d-1<=n;i++)
        b.pb(a[i][t]);
    for(i=t-1;i>=d;i--)
        b.pb(a[t][i]);
    for(i=t-1;i>d;i--)
        b.pb(a[i][d]);
//    for(i=0;i<b.size();i++)
//        printf("%d ",b[i]);
//    puts("");
    t=b.size();
    int now,tt;
    for(i=0;i<b.size();i++)
    {
        now=b[i]+b[(i+n-d*2+1)%t]+b[(i+(n-d*2+1)*2)%t]+b[(i+(n-d*2+1)*3)%t];
        tt=min(i,(int)b.size()-i);
        if(now>t1||(now==t1&&t2>tt))
            t1=now,t2=tt;
    }
//    printf("%d %d\n",t1,t2);
    ansa+=t1;ansb+=t2;
}
void sol()
{
    int i;
    ansa=ansb=0;
    ansa+=a[(n+1)/2][(n+1)/2];
    for(i=1;i<=n/2;i++)
        get(i);
    printf("%d %d\n",ansa,ansb);
}
int main()
{
    int i,j;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        ansa=ansb=0;
        sol();
    }
}
