#include <stdio.h>

const int MAXR=1000+2;
const int MAXC=1000+2;

int R,C;
double m1[MAXR][MAXC];
double m2[MAXR][MAXC];
double m3[MAXR][MAXC];
double f[MAXR][MAXC];

int main()
{
    while (scanf("%d%d",&R,&C)!=EOF)
    {
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            scanf("%lf%lf%lf",&m1[i][j],&m2[i][j],&m3[i][j]);
    
    for (int i=R-1;i>=0;i--)
        for (int j=C-1;j>=0;j--)
        {
            //f[i][j]=(f[i][j]+2)*m1[i][j]+(f[i][j+1]+2)*m2[i][j]+(f[i+1][j]+2)*m3[i][j];
            if (m1[i][j]!=1.0)
               f[i][j]=(2*m1[i][j]+(f[i][j+1]+2)*m2[i][j]+(f[i+1][j]+2)*m3[i][j])/(1.0-m1[i][j]);
            else f[i][j]=0.0;
        }
        printf("%.3f\n",f[0][0]);
    }
    return 0;
}

