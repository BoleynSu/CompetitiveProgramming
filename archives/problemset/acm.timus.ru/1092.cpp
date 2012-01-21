/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-14
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <assert.h>

#define MAXN 20

int N;
char map[MAXN*2+1][MAXN*2+1];

void print()
{
     /*
     for (int i=0;i<N*2+1;i++)
     {
         for (int j=0;j<N*2+1;j++)
             printf("%c",map[i][j]);
         printf("\n");
     }
     */
}
inline
void change(char& who)
{
     if (who=='+') who='-';
     else who='+';
}

void shift(int a,int b,int c,int d)
{
     change(map[a][d]);
     change(map[a][b]);
     change(map[c][b]);
     change(map[c][d]);
     for (int i=0;i<N*2+1;i++)
     {
         if (i==a) printf("%d",b+1);
         else if (i==c) printf("%d",d+1);
         else if (i==b) printf("%d",a+1);
         else if (i==d) printf("%d",c+1);
         else printf("%d",i+1);
         if (i+1==N*2+1) printf("\n");
         else printf(" ");
     }
     for (int i=0;i<N*2+1;i++)
     {
         if (i==a) printf("%d",d+1);
         else if (i==c) printf("%d",b+1);
         else if (i==b) printf("%d",a+1);
         else if (i==d) printf("%d",c+1);
         else printf("%d",i+1);
         if (i+1==N*2+1) printf("\n");
         else printf(" ");
     }
     print();
}

int main()
{
    scanf("%d\n",&N);
    for (int i=0;i<N*2+1;i++)
    {
        for (int j=0;j<N*2+1;j++)
            scanf("%c",&map[i][j]);
        scanf("\n");
    }
    printf("There is solution:\n");
    int counter=0;
    for (int i=0;i<N*2+1;i++)
        for (int j=0;j<N*2+1;j++)
            if (map[i][j]=='+')
               counter++;
    if (counter%2)
       for (int i=0;i<N*2+1;i++)
       {
           change(map[i][i]);
           printf("%d",i+1);
           if (i+1==N*2+1) printf("\n");
           else printf(" ");
       }
    print();
    for (int i=0;i<N*2+1;i++)
    {
        int j=N*2+1-1,_j,k=N*2+1-1,_k;
        while (j>i)
        {
              while ((j>i)&&(map[i][j]!='+')) j--;
              _j=j;
              j--;
              while ((j>i)&&(map[i][j]!='+')) j--;
              if (j>i) shift(i,j,N*2+1-1,_j);
              else break;
              _j=-1;
        }
        if (_j>i) shift(i,i,N*2+1-1,_j);
        while (k>i)
        {
              while ((k>i)&&(map[k][i]!='+')) k--;
              _k=k;
              k--;
              while ((k>i)&&(map[k][i]!='+')) k--;
              if (k>i) shift(k,i,_k,N*2+1-1);
              else break;
              _k=-1;
        }
        if (_k>i&&map[i][i]=='+') shift(i,i,_k,N*2+1-1);
    }
    return 0;
}
