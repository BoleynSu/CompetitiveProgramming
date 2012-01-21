#include <iostream>
using namespace std;

const int MAXN=200;

int n;
int A[MAXN+2];
int B[MAXN+2];
#define K(_k_) ((_k_)%2)
int f[2][(MAXN+2)*(MAXN+2)];

void read()
{
     cin>>n;
     for (int i=1;i<=n;i++)
         cin>>A[i]>>B[i];
}
void sort()
{
     for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
             if (B[i]<B[j])
             {
                int swap;
                swap=A[i];
                A[i]=A[j];
                A[j]=swap;
                swap=B[i];
                B[i]=B[j];
                B[j]=swap;
             }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void DP()
{
     int sum=0;
     f[0][0]=0;
     for (int i=1;i<=MAXN*n;i++)
         f[0][i]=MAXN*n;
     for (int k=1;k<=n;k++)
     {
         sum+=A[k];
         for (int sk=0;sk<A[k];sk++)
         {
             f[K(k)][sk]/*[sum-sk]*/=
                     //min(max(f[K(k-1)][sk-A[k]]/*[sum-sk]*/,sk+B[k]),
                         max(f[K(k-1)][sk]/*[sum-sk-A[k]]*/,sum-sk+B[k]);//);
         }
         for (int sk=A[k];sk<=MAXN*n;sk++)
         {
             f[K(k)][sk]/*[sum-sk]*/=
                     min(max(f[K(k-1)][sk-A[k]]/*[sum-sk]*/,sk+B[k]),
                         max(f[K(k-1)][sk]/*[sum-sk-A[k]]*/,sum-sk+B[k]));
         }
     }
     int m=0;
     for (int i=1;i<MAXN*n;i++)
     {
         if (f[K(n)][i]<f[K(n)][m]) m=i;
     }
     cout<<f[K(n)][m]<<endl;
}

int main()
{
    read();
    sort();
    DP();
    return 0;
}
