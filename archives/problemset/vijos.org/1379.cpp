#include <iostream>
#include <cstring>
using namespace std;

char str[1024];
int p[4];

bool isNumber(char n)
{
     if ((n>='0')&&(n<='9')) return true;
     else return false;
}
bool isChar(char n)
{
     if ((n>='a')&&(n<='z')) return true;
     else return false;
}
void output(char a,char b)
{
     int upper=0;
     char fill=0;
     int k;
     int change=1;
     if ((p[1]==2)&&isChar(a)&&isChar(b)) upper='A'-'a';
     if (p[1]==3) fill='*';
     k=p[2];
     if (p[3]==2)
     {
        char tmp=a;
        a=b;
        b=tmp;
        change=-1;
     }
     for (char i=a+change;i!=b;i+=change)
     {
         for (int j=0;j<k;j++)
         {
             if (fill!=0) cout<<fill;
             else cout<<char(i+upper);
         }
     }
}

void get()
{
     int length=strlen(str);
     for (int i=0;i<length;i++)
     {
         if (str[i]!='-') cout<<str[i];
         else
         {
             if ((i-1>=0)&&(i+1<length))
             {
                if (isNumber(str[i-1])&&isNumber(str[i+1])&&(str[i+1]>str[i-1])) output(str[i-1],str[i+1]);
                else if (isChar(str[i-1])&&isChar(str[i+1])&&(str[i+1]>str[i-1])) output(str[i-1],str[i+1]);
                else cout<<'-';
             }
             else cout<<str[i];
         }
     }
}

int main()
{
    cin>>p[1]>>p[2]>>p[3]>>str;
    get();
    while (cin.get()!='q');
    return 0;
}
