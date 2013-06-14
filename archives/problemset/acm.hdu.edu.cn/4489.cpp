#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;
#define sf scanf
#define pf printf
typedef long long lli;
const int N=20;
int n;
lli f[1<<N][N][2];
lli ans[]={0,1,2,4,10,32,122,544,2770,15872,101042,707584,5405530,44736512,398721962ll,3807514624ll,38783024290ll,419730685952ll,4809759350882ll,58177770225664ll,740742376475050ll};
int main()
{
    int p;
    sf("%d",&p);
    for (int i=1;i<=p;i++)
    {
        int n;
        sf("%d%d",&n,&n);
        cout<<i<<" "<<ans[n]<<endl;
    }
//    int i,j,k,p,q;
//    for(n=1;n<=20;n++)
//    {
//        memset(f,0,sizeof(f));
//        for(i=0;i<n;i++)
//        {
//            f[1<<i][i][0]=1;
//            f[1<<i][i][1]=1;
//        }
//            for(j=0;j<(1<<n);j++)
//                for(k=0;k<n;k++)
//                    if((j>>k&1))
//                    {
//                        for(p=0;p<2;p++)
//                        if(f[j][k][p])
//                        {
//                            if(p==0)
//                            {
//                                for(q=k+1;q<n;q++)
//                                    if(!(j>>q&1))
//                                        f[j|(1<<q)][q][1]+=f[j][k][0];
//                            }
//                            else
//                            {
//                                for(q=0;q<k;q++)
//                                    if(!(j>>q&1))
//                                        f[j|(1<<q)][q][0]+=f[j][k][1];
//                            }
//                        }
//                    }
//        lli ans=0;
//        for(i=0;i<n;i++)
//        ans+=f[(1<<n)-1][i][0]+f[(1<<n)-1][i][1];
//        printf("%I64d,",ans);fflush(stdout);
//    }
//    puts("!");
}


