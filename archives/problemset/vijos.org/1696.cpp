#include <iostream>
using namespace std;

int a[1024*1024];
char _fz[1024];

void gcd(int a,int b)
{
     while ((a%b)!=0)
     {
           cout<<(a/b)<<",";
           int tmp=a%b;
           a=b;
           b=tmp;
     }
     cout<<a;
}
int getGcd(int a,int b)
{
    while ((a%b)!=0)
    {
          int tmp=a%b;
          a=b;
          b=tmp;
    }
    return b;
}
void gtf()
{
     cin>>a[0];
     int len=0;
     while (cin.get()!=']')
     {
         len++;
         cin>>a[len];
     }
     a[len+1]=1;
     for (int i=len;i>0;i--)
         a[i-1]=a[i-1]*a[i]+a[i+1];
     int _gcd=getGcd(a[0],a[1]);
     a[0]/=_gcd;
     a[1]/=_gcd;
     if (a[1]==1) cout<<a[0]<<endl;
     else cout<<a[0]<<'/'<<a[1]<<endl;
}
void ftg(char in)
{
     _fz[0]=in;
     int len=1;
     while ((_fz[len]=cin.get())!='/') len++;
     int fz=0;
     for (int i=0;i<len;i++)
         fz=fz*10+_fz[i]-'0';
     int fm;
     cin>>fm;
     int _gcd=getGcd(fz,fm);
     fz/=_gcd;
     fm/=_gcd;
     cout<<'['<<int(fz/fm);
     if ((fz%fm)!=0)
     {
        cout<<';';
        gcd(fm,fz%fm);
     }
     cout<<']'<<endl;
}
int main()
{
    char flag;
    while (cin>>flag)
    {
          if (flag=='[')
             gtf();
          else
              ftg(flag);
    }
    return 0;
}
