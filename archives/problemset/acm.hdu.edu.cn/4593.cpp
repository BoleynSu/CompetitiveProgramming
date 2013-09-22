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
//
//int main()
//{
//    int a,b;
//    while (cin>>a>>b)
//    {
//        lli cnt=0;
//        lli ans=0;
//        for (int i=0;i<30;i++)
//        {
//            cnt+=(b+1)/2-a/2;
//            cout<<i<<":"<<cnt<<":"<<(b+1)/2-a/2<<endl;
//            ans+=cnt/2;
//            cnt=cnt/2;
//            a++;
//            a>>=1,b>>=1;
//        }
//        cout<<ans<<endl;
//    }
//}

int main()
{
    int n,ans,x,i;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=1;i<=n+1;i++)
        {
            scanf("%d",&x);
            ans=ans^i;
            ans=ans^x;
        }
        ans=ans^(n+1);
        printf("%d\n",ans);
    }
}
