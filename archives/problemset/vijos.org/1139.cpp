#include <iostream>
using namespace std;

int F[1024];
int room[1024][1024];
int level[1024][1024];
int out[1024*1024];
int m,n;

int main()
{
    cin>>m>>n;
    
    for (int i=m;i>=1;i--)
    {
            int p[1024];
            for (int j=1;j<=n;j++)
            {
                cin>>p[j];
                F[j]+=p[j];
                room[i][j]=j;
                level[i][j]=i+1;
            }
            for (int j=2;j<=n;j++)
                if (F[j]>F[j-1]+p[j])
                {
                   F[j]=F[j-1]+p[j];
                   room[i][j]=j-1;
                   level[i][j]=i;
                }
            for (int j=n-1;j>=1;j--)
                if (F[j]>F[j+1]+p[j])
                {
                   F[j]=F[j+1]+p[j];
                   room[i][j]=j+1;
                   level[i][j]=i;
                }
    }
    
    int n1=1;
    for (int i=n;i>1;i--)
        if (F[i]<F[n1])
           n1=i;
    int k=0;
    for (int m1=1;m1!=m+1;)
    {
        out[k++]=n1;
        int m2=level[m1][n1];
        int n2=room[m1][n1];
        m1=m2;
        n1=n2;
    }
    for (int i=k-1;i>=0;i--)
        cout<<out[i]<<endl;
    //while (cin.get());
    return 0;
}

