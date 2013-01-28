#include <cstdio>
using namespace std;

const int MAXN=10000+2;
const int BASE=100000000;

int get_first_digit(int n)
{
    for (;;)
    {
        if (n/10) n/=10;
        else return n;
    }
}

int main()
{
    int b[MAXN];
    int c[MAXN];
    int cl;
    c[0]=1;
    cl=1;
    for (int i=0;i<MAXN;i++)
    {
        b[i]=get_first_digit(c[cl-1]);
        int t[MAXN];
        int tl;
        for (int i=0;i<cl;i++)
            t[i]=c[i]+c[i];
        t[tl=cl]=0;
        for (int i=0;i<cl;i++)
            t[i+1]+=t[i]/BASE,
            t[i]%=BASE;
        if (t[tl]) tl++;
        cl=tl;
        for (int i=0;i<tl;i++)
            c[i]=t[i];
    }
    int n;
    for (;;)
    {
        scanf("%d",&n);
        if (n==-1) break;
        int a[10];
        for (int i=1;i<=9;i++) a[i]=0;
        for (int i=0;i<=n;i++) a[b[i]]++;
        for (int i=1;i<=9;i++)
            printf("%d%c",a[i],i==9?'\n':' ');
    }
}

