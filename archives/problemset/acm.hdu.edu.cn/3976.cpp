#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

enum{MAXM=2000};
int a[MAXM],b[MAXM];
double c[MAXM];

double matrix[MAXM][MAXM+1];

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(matrix,0,sizeof matrix);
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%lf",a+i,b+i,c+i);
            a[i]--;
            b[i]--;
            matrix[a[i]][a[i]]+=+1.0/c[i];
            matrix[a[i]][b[i]]+=-1.0/c[i];
            matrix[b[i]][a[i]]+=-1.0/c[i];
            matrix[b[i]][b[i]]+=+1.0/c[i];
        }
        for (int i=0;i<=n;i++)
            matrix[0][i]=matrix[n-1][i]=0;
        matrix[0][0]=1.0;
        matrix[0][n]=0.0;
        matrix[n-1][n-1]=1.0;
        matrix[n-1][n]=1993.0309;
        for (int i=0;i<n;i++)
        {
            int max=i;
            for (int j=i;j<n;j++)
                if (fabs(matrix[j][i])>fabs(matrix[max][i]))
                    max=j;
            for (int j=i;j<=n;j++)
            {
                double swap=matrix[i][j];
                matrix[i][j]=matrix[max][j];
                matrix[max][j]=swap;
            }
            for (int j=i+1;j<n;j++)
                for (int k=n;k>=i;k--)
                    matrix[j][k]-=matrix[j][i]/matrix[i][i]*matrix[i][k];
        }
        double x[MAXM];
        for (int i=n-1;i>=0;i--)
        {
            x[i]=matrix[i][n];
            for (int j=i+1;j<n;j++)
                x[i]-=matrix[i][j]*x[j];
            x[i]/=matrix[i][i];
        }
        double U=x[n-1]-x[0],I=0;
        for (int i=0;i<m;i++)
        {
            if (a[i]==0) I+=(x[a[i]]-x[b[i]])/c[i];
            if (b[i]==0) I-=(x[a[i]]-x[b[i]])/c[i];
        }
        printf("Case #%d: %.2f\n",t,fabs(U/I));
    }
}

