#include <cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        n/=10;
        static int t;
        printf("Case #%d:\n",++t);
        puts("*------------*");
        for (int i=0;i<10-n;i++) puts("|............|");
        for (int i=0;i<n;i++) puts("|------------|");
        puts("*------------*");
    }
}
