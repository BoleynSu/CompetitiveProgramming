#include <stdio.h>

const int MAXN=1024;
typedef int array[MAXN][MAXN];
#define S(s) (((s)%k==0)?k:(s)%k)
inline int min(int a,int b){return a<b?a:b;}
int n;
array map;
array F;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            scanf("%d",&map[i][j]);
    
    for (int k=n;k>=1;k--)
    {
        if (k==n)
        {
           F[n][1]=map[n][1];
           for (int i=2;i<=n;i++)
               F[n][i]=F[n][i-1]+map[n][i];
               
           F[n][n]=min(F[n][n],F[n][1]+map[n][n]);
           for (int i=n-1;i>=1;i--)
               F[n][i]=min(F[n][i],F[n][i+1]+map[n][i]);
        }
        else
        {
            for (int s=1;s<=k;s++)
                F[k][s]=min(F[k+1][s+1],F[k+1][s])+map[k][s];
            F[k][1]=min(F[k][1],F[k+1][k+1]+map[k][1]);
            F[k][k]=min(F[k][k],F[k+1][1]+map[k][k]);
        
            int min=1;
            for (int s=2;s<=k;s++)
                if (F[k][s]<F[k][min]) min=s;
        
            for (int i=min;i<=min+k;i++)
                if (F[k][S(i-1)]+map[k][S(i)]<F[k][S(i)])
                   F[k][S(i)]=F[k][S(i-1)]+map[k][S(i)];
            for (int i=min+k;i>=min;i--)
                if (F[k][S(i+1)]+map[k][S(i)]<F[k][S(i)])
                   F[k][S(i)]=F[k][S(i+1)]+map[k][S(i)];
        }
        //for (int i=1;i<=k;i++)
            //printf("F[%d][%d]=%d\n",k,i,F[k][i]);
    }
    printf("%d",F[1][1]);
    //scanf("%%");
}
