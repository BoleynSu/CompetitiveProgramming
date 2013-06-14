#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
#define sf scanf
#define pf printf
typedef long long lli;

//
//char str[5000];
//int main()
//{
//    int i,cass,cas,n,x,len,s;
//    scanf("%d",&cas);
//    for(cass=1;cass<=cas;cass++)
//    {
//        scanf("%d\n",&i);
//        //pf("%d\n",i);
//        gets(str);len=strlen(str);
//        //pf("%s",str);puts("!");
//    //printf("%d###\n",str[len-1]);
//        scanf("%d",&n);
//        printf("%d ",cass);s=0;
//        for(int j=1;j<=n;j++)
//        {
//            scanf("%d",&x);
//            s=(s+x+len)%len;
//            printf("%c",str[s]);
//        }
//        puts("");
//    }
//}

int main()
{
    int p;
    sf("%d",&p);
    for (int i=1;i<=p;i++)
    {
        lli n;
        int in;
        sf("%d%d",&in,&in);n=in;
        lli ans=0;
        for (lli c=1;c<=n;c++)
        {
            //1<=a<=b<=c
            //a+b>c
            lli apb=n-c;
            //1<=apb-b<=b<=c
            //a+b>c
            //max((apb+1)/2,1)<=b<=min(c,apb-1)
            if (apb<=c) continue;
            if (max((apb+1)/2,1ll)>min(c,apb-1)) continue;
            ans+=2*(min(c,apb-1)-max((apb+1)/2,1ll)+1);
            //pf("%d:%d\n",int(c),int(ans));
            if (c+c+c==n) ans--;
            else
            {
                if (1<=n-c-c&&n-c-c<=c) ans--;//,puts("here");
                if ((n-c)%2==0&&(n-c)/2<=c&&(n-c)/2>=1) ans--;
            }
            //pf("%d:%d\n",int(c),int(ans));
        }
        pf("%d %d\n",i,int(ans));
    }
}
