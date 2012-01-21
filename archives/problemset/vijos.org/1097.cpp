#include <stdio.h>

void qsort(int* l,int* r)
{
     int* i=l;
     int* j=r;
     int mid=*((j-i)/2+i);
     while (i<=j)
     {
           while (*i<mid) i++;
           while (*j>mid) j--;
           if (i<=j)
           {
              int swap=*i;
              *i=*j;
              *j=swap;
              i++;
              j--;
           }
     }
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
}

void sort(int* l,int* r)
{
     int mv=*l;
     int* cg=l+1;
     while ((*cg<mv)&&(cg<=r)) cg++;
     if (cg!=r) cg--;
     for (int* i=l;i<cg;i++)
         *i=*(i+1);
     *cg=mv;
     /*for (int* i=l;i<=r;i++)
     {
         printf("%d ",*i);
     }printf("\n");*/
}

int main()
{
    int n;
    int p[10000+2];
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    qsort(&p[1],&p[n]);
    int answer=0;
    for (int i=1;i<n;i++)
    {
        p[i+1]=p[i]+p[i+1];
        answer+=p[i+1];
        //printf("%d %d\n",i,answer);
        sort(&p[i+1],&p[n]);
    }
    printf("%d\n",answer);
    //scanf("%%");
    return 0;
}
