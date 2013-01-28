#include <iostream>
using namespace std;

const long long MODER=40007;
long long n;
long long a[4];
long long A[8][8]={
        {0,1,1,0,1,0,0,0},
        {1,0,0,1,0,1,0,0},
        {1,0,0,1,0,0,1,0},
        {0,1,1,0,0,0,0,1},
        {1,0,0,0,0,1,1,0},
        {0,1,0,0,1,0,0,1},
        {0,0,1,0,1,0,0,1},
        {0,0,0,1,0,1,1,0}
};
long long B[8][8];
long long x[8]={1,0,0,0,0,0,0,0};
long long y[8];
void pow()
{
    long long M[8][8],N[8][8];
    for (long long i=0;i<8;i++)
        for (long long j=0;j<8;j++)
            M[i][j]=A[i][j],B[i][j]=(i==j);
    while (n)
    {
        if (n&1)
        {
            for (long long i=0;i<8;i++)
                for (long long k=0;k<8;k++)
                {
                    N[i][k]=0;
                    for (long long j=0;j<8;j++)
                        N[i][k]+=B[i][j]*M[j][k];
                    N[i][k]%=MODER;
                }
            for (long long i=0;i<8;i++)
                for (long long j=0;j<8;j++)
                    B[i][j]=N[i][j];
        }
        for (long long i=0;i<8;i++)
            for (long long k=0;k<8;k++)
            {
                N[i][k]=0;
                for (long long j=0;j<8;j++)
                    N[i][k]+=M[i][j]*M[j][k];
                N[i][k]%=MODER;
            }
        for (long long i=0;i<8;i++)
            for (long long j=0;j<8;j++)
                M[i][j]=N[i][j];
        n>>=1;
    }
}
void mul()
{
    for (long long i=0;i<8;i++)
    {
        y[i]=0;
        for (long long j=0;j<8;j++)
            y[i]+=B[i][j]*x[j];
        y[i]%=MODER;
    }
}

int main()
{
    long long T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        pow();
        mul();
        for (long long i=0;i<4;i++) a[i]=0;
        for (long long i=0;i<8;i++)
        {
            long long c=0;
            for (long long j=0;j<8;j++)
                if (i&(1<<j))
                    c++;
            a[c]+=y[i];
        }
        for (long long i=0;i<4;i++) a[i]%=MODER;
        cout<<a[0]<<" "<<a[2]<<" "<<a[1]<<" "<<a[3]<<endl;
    }
}

