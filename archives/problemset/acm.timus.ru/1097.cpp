/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-16 
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define MAXM 100
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int L,A;
int M; 
struct Record
{
       int p;
       int a;
       int x,y;
};
Record record[MAXM];

inline
void check(int left,int bottom,int& get_min)
{
     int right=left+A;
     int top=bottom+A;
     if (left<1||right>L+1||bottom<1||top>L+1) return;
     int get_max=1;
     for (int i=0;i<M;i++)
     {
         int cleft=max(record[i].x,left);
         int cright=min(record[i].x+record[i].a,right);
         int cbottom=max(record[i].y,bottom);
         int ctop=min(record[i].y+record[i].a,top);
         if (cleft<cright&&cbottom<ctop)
            get_max=max(get_max,record[i].p);
     }
     get_min=min(get_min,get_max);
}

int main()
{
    scanf("%d %d\n%d\n",&L,&A,&M);
    for (int i=0;i<M;i++)
        scanf("%d %d %d %d\n",&record[i].p,
                              &record[i].a,
                              &record[i].x,
                              &record[i].y);
    record[M].p=1;
    record[M].a=L;
    record[M].x=1;
    record[M].y=1;
    M++;
    int get_min=255;
    int left,bottom;
    for (int i=0;i<M;i++)
    {
        left=record[i].x;
        for (int j=0;j<M;j++)
        {
            bottom=record[j].y;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a;
            check(left,bottom,get_min);
            bottom=record[j].y-A;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a-A;
            check(left,bottom,get_min);
        }
        left=record[i].x+record[i].a;
        for (int j=0;j<M;j++)
        {
            bottom=record[j].y;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a;
            check(left,bottom,get_min);
            bottom=record[j].y-A;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a-A;
            check(left,bottom,get_min);
        }
        left=record[i].x+record[i].a-A;
        for (int j=0;j<M;j++)
        {
            bottom=record[j].y;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a;
            check(left,bottom,get_min);
            bottom=record[j].y-A;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a-A;
            check(left,bottom,get_min);
        }
        left=record[i].x-A;
        for (int j=0;j<M;j++)
        {
            bottom=record[j].y;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a;
            check(left,bottom,get_min);
            bottom=record[j].y-A;
            check(left,bottom,get_min);
            bottom=record[j].y+record[j].a-A;
            check(left,bottom,get_min);
        }
    }
    if (get_min<=100) printf("%d\n",get_min);
    else printf("IMPOSSIBLE\n");
    return 0;
}
