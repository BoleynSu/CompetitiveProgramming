#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define x first
#define y second
typedef long long big;
const int P=1000000007;
typedef map<int,int> mii;


struct mat
{
    big s[2][2];
};
void operator*=(mat &a,const mat &b)
{
    int i,j,k;
    static mat c;
    memset(c.s,0,sizeof(c.s));
    for(k=0;k<2;k++)
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                c.s[i][j]+=a.s[i][k]*b.s[k][j],c.s[i][j]%=P;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            a.s[i][j]=c.s[i][j];
}
mat operator^(const mat &a,const mat &b)
{
    int i,k;
    static mat c;
    memset(c.s,0,sizeof(c.s));
    for(k=0;k<2;k++)
        for(i=0;i<2;i++)
                c.s[i][0]+=a.s[i][k]*b.s[k][0],c.s[i][0]%=P;
    return c;
}
int n,k;
mat ans,g;
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&k);
        if(n<k)puts("0");
        else
        {
            memset(g.s,0,sizeof(g.s));
            memset(ans.s,0,sizeof(ans.s));
            g.s[0][0]=2;
            g.s[0][1]=2;
            g.s[1][0]=0;
            g.s[1][1]=2;
            ans.s[0][0]=12;
            ans.s[1][0]=2;
            n-=k;
            if(!n)puts("1");
            else if(n==1)puts("2");
            else if(n==2)puts("5");
            else
            {
                n-=3;
                for(;n;n>>=1,g*=g)
                    if(n&1)ans=g^ans;
                cout<<ans.s[0][0]<<endl;
            }
        }
    }
}
