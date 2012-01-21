#include <stdio.h>

int main()
{
    int n;
    int a[1024];
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int f1[1024];
    int f2[1024];
    for (int i=1;i<=n;i++)
    {
        f1[i]=1;
        for (int j=1;j<i;j++)
            if ((a[j]<a[i])&&(f1[j]+1>f1[i])) f1[i]=f1[j]+1;
    }
    for (int i=n;i>=1;i--)
    {
        f2[i]=1;
        for (int j=n;j>i;j--)
            if ((a[j]<a[i])&&(f2[j]+1>f2[i])) f2[i]=f2[j]+1;
    }
    int answer=0;
    for (int i=1;i<=n;i++)
    {
        //printf("f1[%d]=%d f2[%d]=%d\n",i,f1[i],i,f2[i]);
        if (f1[i]+f2[i]-1>answer) answer=f1[i]+f2[i]-1;
    }
    answer=n-answer;
    printf("%d\n",answer);
    scanf("%%");
}
