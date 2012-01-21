#include <stdio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void qsort(__int64* l,__int64* r)
{
     __int64*i =l;
     __int64*j =r;
     __int64 mid=*((j-i)/2+i);
     while (i<=j)
     {
           while (*i<mid) i++;
           while (*j>mid) j--;
           if (i<=j)
           {
              __int64 swap=*i;
              *i=*j;
              *j=swap;
              i++;
              j--;
           }
     }
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
}

inline __int64 abs(__int64 n)
{
       return n>0?n:-n;
}


int main()
{
    __int64 a[100000];
    __int64 b[100000];
    __int64 n,k;
    scanf("%I64d%I64d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for (int i=1;i<=n;i++)
        scanf("%I64d",&b[i]);
    qsort(&a[1],&a[n]);
    qsort(&b[1],&b[n]);
    __int64 total=0;
    int ao=1,ac=n,bo=1,bc=n;
    for (int i=0;i<k;i++)
    {
        if (abs(a[ao]-b[bc])>abs(a[ac]-b[bo]))
        {
           total+=abs(a[ao]-b[bc]);
           ao++;
           bc--;
        }
        else
        {
           total+=abs(a[ac]-b[bo]);
           ac--;
           bo++;
        }
    }
    printf("%I64d\n",total);
    //while (cin.get());
}
