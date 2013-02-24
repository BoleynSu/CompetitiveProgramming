#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long int lli;

void mul(lli a[3][3],lli b[3][3],lli c[3][3])
{
     lli tmp[3][3];
     for (int i=0;i<3;i++)
         for (int j=0;j<3;j++)
         {
             tmp[i][j]=0;
             for (int k=0;k<3;k++) tmp[i][j]+=b[i][k]*c[k][j];
         }
     memcpy(a,tmp,sizeof(tmp));
}
void pow(lli a[3][3],lli b[3][3],int c)
{
     lli tmp1[3][3],tmp2[3][3];
     memcpy(tmp1,b,sizeof(tmp1));
     memset(tmp2,0,sizeof(tmp2));
     for (int i=0;i<3;i++) tmp2[i][i]=1;
     while (c)
     {
           if (c&1) mul(tmp2,tmp2,tmp1);
           mul(tmp1,tmp1,tmp1);
           c>>=1;
     }
     memcpy(a,tmp2,sizeof(tmp2));
}
lli turn[3][3]={{0,-1,0},{1,0,0},{0,0,1}};
lli move[3][3]={{1,0,0},{0,1,0},{0,0,1}};

struct RobotHerb
{
       static long long getdist(int T, vector <int> a)
       {
              lli ans[3][3];
              memset(ans,0,sizeof(ans));
              for (int i=0;i<3;i++) ans[i][i]=1;
              for (int i=0;i<a.size();i++)
              {
                  int ai=a[i];

                  move[1][2]=ai;
                  mul(ans,move,ans);

                  switch (ai%4)
                  {
                         case 3:
                              mul(ans,turn,ans);
                         case 2:
                              mul(ans,turn,ans);
                         case 1:
                              mul(ans,turn,ans);
                  }
              }
              pow(ans,ans,T);
              return abs(ans[0][2])+abs(ans[1][2]);
       }
};
