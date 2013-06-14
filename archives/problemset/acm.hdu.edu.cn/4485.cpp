#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define sf scanf
#define pf printf

char s[10000000+2];

int main()
{
    int p;
    sf("%d",&p);
    for (int i=1;i<=p;i++)
    {
        int n;
        sf("%d%d%s",&n,&n,s);
        int ans=0;
        for (int j=0;s[j];j++)
        {
            ans*=n;
            ans+=(s[j]-'0');
            ans%=n-1;
        }
        pf("%d %d\n",i,ans);
    }
}
