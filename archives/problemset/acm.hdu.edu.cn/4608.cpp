#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=102000;
char a[N];
int n;
void f()
{
    int i;
    a[1]++;
    for(i=1;i<=n;i++)
        if(a[i]>=10)
        {
            a[i]-=10;
            a[i+1]++;
        }
    if(a[n+1])n++;

}
bool ck()
{
    int res=0,i;
    for(i=n;i;i--)
    {
        res+=a[i];
        res%=10;
    }
    return !res;
}
void pri()
{
    int i;
    for(i=n;i;i--)
        printf("%d",a[i]);
    puts("");
}
int main()
{
    int cas;
    int i;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",a+1);
        n=strlen(a+1);
        reverse(a+1,a+1+n);
        for(i=1;i<=n;i++)
            a[i]-='0';
        f();
        while(!ck())f();
        pri();
    }
}
