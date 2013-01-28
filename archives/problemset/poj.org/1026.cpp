#include <stdio.h>
#include <string.h>

#define MAXN 200+5
#define LOG2MAXK 30

int n,k;
int a[MAXN];
int f[LOG2MAXK][MAXN];

void get_kth(int b[MAXN],int k)
{
     int i,j;
     for (i=1;i<=n;i++) b[i]=i;
     for (i=0;i<LOG2MAXK;i++)
     {
         if (k&(1<<i))
         {
            int t[MAXN];
            for (j=1;j<=n;j++)
                t[j]=f[i][b[j]];
            for (j=1;j<=n;j++) b[j]=t[j];
         }
     }
}

int main()
{
    int i,j;
    for (;;)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        for (i=0;i<LOG2MAXK;i++)
        {
            if (i==0)
               for (k=1;k<=n;k++) f[i][k]=a[k];
            else
            {
                int i_=i-1;
                for (k=1;k<=n;k++)
                    f[i][k]=f[i_][f[i_][k]];
            }
        }
        for (;;)
        {
            int k,sl;
            char s[MAXN];
            char decode[MAXN];
            int b[MAXN];
            scanf("%d",&k);
            if (k==0) break;
            scanf("%c%[^\n]",s,s);
            sl=strlen(s);
            if (sl!=n)
            {
               for (i=sl;i<n;i++) s[i]=' ';
               s[n]='\0';
            }
            get_kth(b,k);
            for (i=1;i<=n;i++) decode[b[i]-1]=s[i-1];
            for (i=1;i<=n;i++) printf("%c",decode[i-1]);
            printf("\n");
        }
        printf("\n");
    }
}
