#include <iostream>
using namespace std;

int main()
{
    __int64 a,b,c;
    while (cin>>a>>b>>c)
    {
          if ((!(a+b>c))||(!(a+c>b))||(!(b+c>a)))
             cout<<-1<<endl;
          else
          {
              int i;
              for (i=-1;i<=9999;i++)
              {
                  if ((!(a+b>c))||(!(a+c>b))||(!(b+c>a)))
                  {
                     cout<<i<<endl;
                     break;
                  }
                  __int64 na=(b+c)-a;
                  __int64 nb=(a+c)-b;
                  __int64 nc=(a+b)-c;
                  a=na;
                  b=nb;
                  c=nc;
              }
              if (i>9999)
                 cout<<"The voyage seemed endless..."<<endl;
          }
    }
    return 0;
}
