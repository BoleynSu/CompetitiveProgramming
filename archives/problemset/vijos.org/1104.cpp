#include <stdio.h>
int t,m;
int p[1024];
int q[1024];
int f[100000];
//f[k][t]=min(f[k-1][t-p[k]]+q[k],f[k-1][t]);
int main()
{
    scanf("%d%d",&t,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d",&p[i],&q[i]);
    for (int i=1;i<=m;i++)
        for (int j=m*100+1;j>=p[i];j--)
            if (f[j-p[i]]+q[i]>f[j]) f[j]=f[j-p[i]]+q[i];
    printf("%d\n",f[t]);//scanf("%%");
    return 0;
}
