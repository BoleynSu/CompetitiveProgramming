/*
ID: sujiao1
PROG: clocks
LANG: C++
*/
#include <stdio.h>

int opt[10][10]=
{
{/*A B C D E F G H I*/},//0
{0,1,1,0,1,1,0,0,0,0},//1
{0,1,1,1,0,0,0,0,0,0},//2
{0,0,1,1,0,1,1,0,0,0},//3
{0,1,0,0,1,0,0,1,0,0},//4
{0,0,1,0,1,1,1,0,1,0},//5
{0,0,0,1,0,0,1,0,0,1},//6
{0,0,0,0,1,1,0,1,1,0},//7
{0,0,0,0,0,0,0,1,1,1},//8
{0,0,0,0,0,1,1,0,1,1}//9
};
int clock[10];
int com[10];
inline
void as(int f[10],int t[10])
{
     for (int i=1;i<=9;i++)
         t[i]=f[i];
}
inline
void change(int t[10],int f[10],int by,int k)
{
     for (int i=1;i<=9;i++)
         t[i]=(f[i]+opt[by][i]*k)%4;
}
inline
bool getDis(int now[10])
{
     for (int i=1;i<=9;i++)
         if (now[i]%4!=0)
            return false;
     return true;
}
bool notfirst=false;
inline
void write(int n)
{
     if (notfirst)
        printf(" %d",n);
     else
     {
         printf("%d",n);
         notfirst=true;
     }
}
bool get(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
     as(clock,com);
     change(com,com,1,a);
     change(com,com,2,b);
     change(com,com,3,c);
     change(com,com,4,d);
     change(com,com,5,e);
     change(com,com,6,f);
     change(com,com,7,g);
     change(com,com,8,h);
     change(com,com,9,i);
     if (getDis(com)) return true;
     else return false;
}
void print(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
     for (int j=1;j<=a;j++)
         write(1);
     for (int j=1;j<=b;j++)
         write(2);
     for (int j=1;j<=c;j++)
         write(3);
     for (int j=1;j<=d;j++)
         write(4);
     for (int j=1;j<=e;j++)
         write(5);
     for (int j=1;j<=f;j++)
         write(6);
     for (int j=1;j<=g;j++)
         write(7);
     for (int j=1;j<=h;j++)
         write(8);
     for (int j=1;j<=i;j++)
         write(9);
}
int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    for (int i=1;i<=9;i++)
    {
        scanf("%d",&clock[i]);
        clock[i]=(clock[i]/3)%4;
    }
    for (int a=0;a<=3;a++)
        for (int b=0;b<=3;b++)
            for (int c=0;c<=3;c++)
                for (int d=0;d<=3;d++)
                    for (int e=0;e<=3;e++)
                        for (int f=0;f<=3;f++)
                            for (int g=0;g<=3;g++)
                                for (int h=0;h<=3;h++)
                                    for (int i=0;i<=3;i++)
                                        if (get(a,b,c,d,e,f,g,h,i))
                                           print(a,b,c,d,e,f,g,h,i);
    printf("\n");
    return 0;
}
