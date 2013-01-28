#include <iostream>
using namespace std;

enum{MAXDIGITS=19,MAXSUM=9*MAXDIGITS+1,MAXWEIGHEDSUM=(MAXDIGITS-1)*MAXDIGITS/2*9+1};
long long f[MAXDIGITS][MAXSUM][MAXWEIGHEDSUM];
//f[i][j][k]=sum{f[i-1][j-t][k-t*i],0<=t<=9,j-t>=0,k-t*i>=0}
//f[0][*][*]=0
//f[0][j][0]=1 0<=1<=9
void init_F()
{
    for (int j=0;j<=9;j++)
        f[0][j][0]=1;
    for (int i=1;i<MAXDIGITS;i++)
        for (int j=0;j<MAXSUM;j++)
            for (int k=0;k<MAXWEIGHEDSUM;k++)
                for (int t=0;t<=9;t++)
                {
                    int i_=i-1,j_=j-t,k_=k-t*i;
                    if (j_>=0&&k_>=0)
                        f[i][j][k]+=f[i_][j_][k_];
                }
}
long long F(long long x)
{
    if (x<0) return 0;
    int string[MAXDIGITS];
    int length=0;
    do
    {
        string[length++]=x%10;
        x/=10;
    }
    while (x);
    long long answer=1;
    int ms=0,mws=0;
    for (int i=length-1;i>=0;i--)
    {
        if (i==0)
        {
            for (int digit=0;digit<=string[i];digit++)
                for (int sum=1;sum<MAXSUM;sum++)
                    for (int times=0;times<length&&times*sum<MAXWEIGHEDSUM;times++)
                        if (sum-ms-digit==0&&times*sum-mws-digit*i==0)
                            answer++;
        }
        else
        {
            for (int digit=0;digit<string[i];digit++)
                for (int sum=1;sum<MAXSUM;sum++)
                    for (int times=0;times<length&&times*sum<MAXWEIGHEDSUM;times++)
                        if (sum-ms-digit>=0&&times*sum-mws-digit*i>=0)
                            answer+=f[i-1][sum-ms-digit][times*sum-mws-digit*i];
        }
        ms+=string[i];
        mws+=string[i]*i;
    }
    return answer;
}

int main()
{
    int T;
    init_F();
    for (cin>>T;T;T--)
    {
        long long x,y;
        cin>>x>>y;
        cout<<F(y)-F(x-1)<<endl;
    }
}

