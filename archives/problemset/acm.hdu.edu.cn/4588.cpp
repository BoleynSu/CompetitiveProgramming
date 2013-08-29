#include <cstdio>
#include <iostream>
using namespace std;

typedef double db;
#define rep(i,n) for (int i=0;i<(n);i++)

typedef long long int lli;

#include <cstdio>
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
//
//const int N=30;
//int n;
//int a[N];
//int main()
//{
//    int cas,i,k;
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        scanf("%d",&n);
//        for(i=1;i<=n;i++)
//            scanf("%d",&a[i]);
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                if()
//        }
//    }
//}

lli get(lli x,lli d)
{
    if (x<0) return  0;
    else
    {
        lli mod=1<<d;
        lli rmd=x%mod;
        x>>=d;
        lli ans=0;
        if (x&1) ans+=rmd+1;
        x>>=1;
        ans+=x*mod;
        return ans;
    }
}

int main()
{
    lli a,b;
    while (~scanf("%I64d%I64d",&a,&b))
    {
        lli cnt=0,ans=0;
        for (int i=0;i<60;i++)
        {
            cnt+=get(b,i)-get(a-1,i);
            cnt/=2;
            ans+=cnt;
        }
        cout<<ans<<endl;
    }
}
