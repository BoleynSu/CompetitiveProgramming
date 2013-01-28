#include <stdio.h>

int n;
int a[2000],b[2000];
int h;
void sort(int l,int r)
{
    int i=l,j=r;
    int mid=a[(l+r)>>1]+b[(l+r)>>1];
    while (i<=j)
    {
        while (a[i]+b[i]<mid) ++i;
        while (a[j]+b[j]>mid) --j;
        if (i<=j)
        {
            int swap;
            swap=a[i],a[i]=a[j],a[j]=swap;
            swap=b[i],b[i]=b[j],b[j]=swap;
            ++i;
            --j;
        }
    }
    if (l<j) sort(l,j);
    if (i<r) sort(i,r);
}
typedef long long int lli;
const lli oo=(~0ull)>>1;

int main()
{
    while (~scanf("%d",&n))
    {
        int i,j;
        for (i=0;i<n;i++)
            scanf("%d%d",a+i,b+i);
        scanf("%d",&h);
        sort(0,n-1);
        int answer=0;
        lli maxf=0;
        for (i=0;i<n;i++) maxf+=a[i];
        lli f_1[2000],f_2[2000];
        lli* f=f_1;
        for (j=0;j<n;j++)
        {
            f[j]=maxf+b[j];
            if (f[j]>=h) answer=0+1;
        }
        lli* g=f_2;
        for (i=1;i<n;i++)
        {
            lli* swap=f;
            f=g;
            g=swap;
            maxf=-oo;
            for (j=i;j<n;j++)
            {
                int tj=j-1;
                if (g[tj]>=h)
                {
                    lli lf=g[tj]-a[tj]-b[tj];
                    if (lf>maxf) maxf=lf;
                }
                f[j]=maxf+b[j];
                if (f[j]>=h) answer=i+1;
            }
            if (answer<=i) break;
        }
        printf("%d\n",answer);
    }
}

