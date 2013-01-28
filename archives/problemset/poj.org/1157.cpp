#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAXN=100;
int F,V;
int A[MAXN+2][MAXN+2];

/*
k: 1..F
s[k]: position where (k)th F put{some of 1..V}
x[k]: position where (k-1)th F put{some of 1..s[k]-1}
v[k]=A[k][s[k]]
s[k-1]=x[k]
f[k][s[k]]=max{f[k-1][s[k-1]]+v[k]}
f[0]={0,0,...,0}
*/

int f[MAXN+2][MAXN+2];
int g[MAXN+2][MAXN+2];
int _sort[MAXN+2];

int main()
{
    cin>>F>>V;
    for (int i=1;i<=F;i++)
        for (int j=1;j<=V;j++)
            cin>>A[i][j];
    for (int k=1;k<=F;k++) //for each k
    {
        if (k==1)
        {
           for (int sk=1;sk<=V;sk++)
               f[k][sk]=A[k][sk];
        }
        else
        {
            for (int sk=1;sk<=V;sk++)//for each sk
            {
                int vk=A[k][sk];
                int max=-100000000;
                int maxid;
                for (int xk=1;xk<sk;xk++)//for each xk
                {
                    int sk_1=xk;
                    if (f[k-1][sk_1]>max)
                    {
                       max=f[k-1][sk_1];
                       maxid=sk_1;
                    }
                }
                f[k][sk]=vk+max;
                g[k][sk]=maxid;
            }
        }
    }
    int answer=1;
    for (int i=1;i<=V;i++)
        if (f[F][i]>f[F][answer])
           answer=i;
    cout<<f[F][answer]<<endl;/*
    for (int i=F;i>=1;i--)
    {
        _sort[i]=answer;
        answer=g[i][answer];
    }
    for (int i=1;i<=F;i++)
        cout<<_sort[i]<<" ";*/
    //while(cin.get());
    return 0;
}
