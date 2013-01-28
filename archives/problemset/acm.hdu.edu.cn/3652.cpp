#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lli;
typedef int state[13][10][2];

lli get(lli N)
{
    static int digits;
    static int digit[10+2];
    static state f[10+2];
    digits=0;
    do digit[digits++]=N%10;
    while (N/=10);
    for (int i=0;i*2<=digits;i++) swap(digit[i],digit[digits-i]);
    digit[0]=0;
    int answer=0;
    for (int i=digits+1;i>=1;i--)
    {
        memset(f,0,sizeof(f));
        f[0][0][0][0]=1;
        for (int j=0;j<i-1;j++)
            for (int r=0;r<13;r++)
                for (int l=0;l<10;l++)
                    for (int g=0;g<2;g++)
                    {
                        int j_=j+1,r_=(r*10+digit[j_])%13,l_=digit[j_],g_=g|(l==1&&l_==3);
                        f[j_][r_][l_][g_]+=f[j][r][l][g];
                    }
        for (int j=i-1;j<i;j++)
            for (int r=0;r<13;r++)
                for (int l=0;l<10;l++)
                    for (int g=0;g<2;g++)
                        for (int digit_j_=0;digit_j_<digit[j+1];digit_j_++)
                        {
                            int j_=j+1,r_=(r*10+digit_j_)%13,l_=digit_j_,g_=g|(l==1&&l_==3);
                            f[j_][r_][l_][g_]+=f[j][r][l][g];
                        }
        for (int j=i;j<digits;j++)
            for (int r=0;r<13;r++)
                for (int l=0;l<10;l++)
                    for (int g=0;g<2;g++)
                        for (int digit_j_=0;digit_j_<10;digit_j_++)
                        {
                            int j_=j+1,r_=(r*10+digit_j_)%13,l_=digit_j_,g_=g|(l==1&&l_==3);
                            f[j_][r_][l_][g_]+=f[j][r][l][g];
                        }
        for (int l=0;l<10;l++)
            answer+=f[digits][0][l][1];
    }
    return answer;
}

int main()
{
    int N;
    while (scanf("%d",&N)!=EOF)
          printf("%d\n",int(get(N)));
}

