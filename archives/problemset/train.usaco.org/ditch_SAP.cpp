/*
ID: sujiao1
PROG: ditch
LANG: C++
*/
#include <stdio.h>
#define SIZE 1000+2
#define oo (~(1<<31))
//以USACO的ditch为例 
int c[SIZE][SIZE];//邻接矩阵
int h[SIZE],vh[SIZE];
int n,augc,rd1,rd2,m,i;//augc为增广路容量
int flow;
bool found;//记录是否已达汇点
void aug(int m)
{
     int i,augco,minh;
     minh=n-1;
     augco=augc;
     if (m==n)
     {
        found=true;
        flow+=augc;
        return;
     }
     for (i=1;i<=n;i++)
         if (c[m][i]>0)
         {
            if (h[m]==h[i]+1)
            {
               if (c[m][i]<augc) augc=c[m][i];
               aug(i);
               if (h[1]>n) return;//GAP
               if (found) break;
               augc=augco;
            }
            if (h[i]<minh) minh=h[i];
         }
     if (!found)//重标号 
     {
        vh[h[m]]--;//GAP
        if (vh[h[m]]==0) h[1]=n;//GAP
        h[m]=minh+1;
        vh[h[m]]++;//GAP
     }
     else
     {
         c[m][i]-=augc;
         c[i][m]+=augc;
     }     
}

int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&rd1,&rd2,&augc);
        c[rd1][rd2]+=augc;
    }
    vh[0]=n;
    while (h[1]<n)
    {
          augc=oo;
          found=false;
          aug(1);
    }
    printf("%d\n",flow);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
