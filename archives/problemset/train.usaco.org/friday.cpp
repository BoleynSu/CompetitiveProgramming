/*
ID: sujiao1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("friday.in");
std::ofstream cout("friday.out");

struct Date
{
       int y,m,d;
       int toDay()//0 Saturday 1 Sunday ...
       {
           const int dayInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
           int total=0;
           for (int year=1900;year<y;year++)
           {
               if (year%100==0)
               {
                  if (year%400==0) total+=366;
                  else total+=365;
               }
               else
               {
                   if (year%4==0) total+=366;
                   else total+=365;
               }
           }
           //cout<<"y"<<total<<endl;
           for (int month=1;month<m;month++)
           {
               total+=dayInMonth[month];
           }
           bool isLeap;
           if (y%100==0)
           {
              if (y%400==0) isLeap=true;
              else isLeap=false;
           }
           else
           {
               if (y%4==0) isLeap=true;
               else isLeap=false;
           }
           if ((m>2)&&isLeap) total++;
           //cout<<"m"<<total<<endl;
           total+=d;
           //cout<<"d"<<total<<endl;
           return (total+1)%7;
       }
};
struct Program
{
       int f[7];
       int N;
       int run()
       {
           cin>>N;
           for (int i=0;i<7;i++) f[i]=0;
           Date date;
           date.d=13;
           for (date.y=1900;date.y<1900+N;date.y++)
               for (date.m=1;date.m<=12;date.m++)
                   f[date.toDay()]++;
           for (int i=0;i<6;i++)
               cout<<f[i]<<" ";
           cout<<f[6];
           cout<<endl;
           /*
           Date a;
           a.d=1;a.m=1;a.y=1900;
           cout<<a.toDay()<<endl;
           */
           //while (cin.get()!='q');
           return 0;
       }
};

int main()
{
    Program app;
    return app.run();
}
