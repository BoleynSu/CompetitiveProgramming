/*
AUTHOR: Su Jiao
DATE: 2010-8-24
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

const int MAXF=100+2,MAXV=100+2;
const int oo=19930309;
int F,V;
int A[MAXF][MAXV];
int f[MAXF][MAXV];

void print(int v,int i)
{
     if (i)
     {
        int j;
        for (j=1;j<=V;j++)
            if (f[i][j]==v)
               break;
        print(v-A[i][j],i-1);
        cout<<j<<char(i==F?'\n':' ');
     }
}

int main()
{
    cin>>F>>V;
    for (int i=1;i<=F;i++)
        for (int j=1;j<=V;j++)
            cin>>A[i][j];
    #define max(a,b) ((a)>(b)?(a):(b))
    for (int i=1;i<=F;i++)
        for (int j=0;j<=V;j++)
        {
            f[i][j]=-oo;
            for (int k=0;k<j;k++)
                f[i][j]=max(f[i][j],f[i-1][k]+A[i][j]);
        }
    int answer=-oo;
    for (int i=0;i<=V;i++)
        answer=max(answer,f[F][i]);
    cout<<answer<<endl;
    print(answer,F);
}
