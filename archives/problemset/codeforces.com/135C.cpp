#include <iostream>
#include <cstdio>
using namespace std;

char c[100000+1];
int c0=0,c1=0,cx=0,t;
char last;
bool get[2][2];
int abs(int x)
{
    return x<0?-x:x;
}
int main()
{
    gets(c);
    for (char* i=c;*i;i++)
    {
        last=*i;
        if (*i=='0') c0++;
        else if (*i=='1') c1++;
        else cx++;
    }
    if (last=='?')
    {
       cx--;
       c1++;
       last='1';
       if (c0+cx>=c1+1) get[0][0]=true;
       if (c1+cx>=c0+2) get[1][1]=true;
       if ((c0+cx-c1)%2==0) t=(c0+cx-c1)/2;
       else t=(c0+cx+1-c1)/2;
       if (0<=t&&t<=cx)
          if (last=='1') get[0][1]=true;
          else get[1][0]=true;       
       last='?';
       c1--;
       cx++;
       
       cx--;
       c0++;
       last='0';
       if (c0+cx>=c1+1) get[0][0]=true;
       if (c1+cx>=c0+2) get[1][1]=true;
       if ((c0+cx-c1)%2==0) t=(c0+cx-c1)/2;
       else t=(c0+cx+1-c1)/2;
       if (0<=t&&t<=cx)
          if (last=='1') get[0][1]=true;
          else get[1][0]=true; 
       last='?';
       c0--;
       cx++;
    }
    else
    {
        if (c0+cx>=c1+1) get[0][0]=true;
        if (c1+cx>=c0+2) get[1][1]=true;
        if ((c0+cx-c1)%2==0) t=(c0+cx-c1)/2;
        else t=(c0+cx+1-c1)/2;
        if (0<=t&&t<=cx)
           if (last=='1') get[0][1]=true;
           else get[1][0]=true; 
    }
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if (get[i][j])
               cout<<i<<j<<endl;
}

