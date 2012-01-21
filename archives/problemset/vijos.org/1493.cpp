#include <iostream>
using namespace std;

int m,n;
int map[100][100];
unsigned F[100][100][100];
int K;

void get()
{
     cin>>m>>n;
     for (int i=1;i<=m;i++)
         for (int j=1;j<=n;j++)
             cin>>map[i][j];
     K=m+n-1;
     for (int k=2;k<K;k++)
         for (int i=1;i<=m;i++)
             for (int j=i+1;j<=m;j++)
             {
                 int newF;
                 unsigned min=F[k-1][i][j];
                 if (i>1)
                 {
                    newF=F[k-1][i-1][j];
                    min=newF>min?newF:min;
                 }
                 if (j>1)
                 {
                    newF=F[k-1][i][j-1];
                    min=newF>min?newF:min;
                 }
                 if ((i>1)&&(j>1))
                 {
                    newF=F[k-1][i-1][j-1];
                    min=newF>min?newF:min;
                 }
                 F[k][i][j]=min+map[i][k+1-i]+map[j][k+1-j];
             }
     cout<<F[K-1][m-1][m]<<endl;
}

int main()
{
    get();
    //while (cin.get()!='q');
    return 0;
}
