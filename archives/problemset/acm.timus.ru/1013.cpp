/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-13
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <iomanip>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;

class BigNumber
{
      static const int BASE=10000;
      vector<int> d;
      public:
      BigNumber(int value=0)
                    :d(1,value)
      {
                    //assert(value<BASE);
      }
      friend BigNumber operator+(const BigNumber& a,const BigNumber& b)
      {
             BigNumber c;
             c.d.resize(a.d.size()>b.d.size()?a.d.size():b.d.size());
             int over=0;
             for (int i=0;i<c.d.size();i++)
                 if (i<a.d.size()&&i<b.d.size())
                 {
                    c.d[i]=(a.d[i]+b.d[i]+over)%BASE;
                    over=(a.d[i]+b.d[i]+over)/BASE;
                 }
                 else if (i<a.d.size())
                 {
                    c.d[i]=(a.d[i]+over)%BASE;
                    over=(a.d[i]+over)/BASE;
                 }
                 else if (i<b.d.size())
                 {
                    c.d[i]=(b.d[i]+over)%BASE;
                    over=(b.d[i]+over)/BASE;
                 }
             if (over) c.d.push_back(over);
             return c;
      }
      BigNumber& operator*=(int mul)
      {
                 int over=0;
                 for (int i=0;i<d.size();i++)
                 {
                     int old=d[i];
                     d[i]=(old*mul+over)%BASE;
                     over=(old*mul+over)/BASE;
                 }
                 if (over) d.push_back(over);
                 return *this;
      }
      BigNumber& operator/=(int div)
      {
                 int rest=0;
                 for (int i=d.size()-1;i>=0;i--)
                 {
                     int old=d[i];
                     d[i]=(rest*BASE+old)/div;
                     rest=(rest*BASE+old)%div;
                 }
                 if (d[d.size()-1]==0) d.resize(d.size()-1);
                 return *this;
      }
      void print()
      {
           cout<<d[d.size()-1];
           for (int i=d.size()-1-1;i>=0;i--)
               cout<<std::setfill('0')<<std::setw(4)<<d[i]<<std::setw(1)<<std::setfill(' ');
           cout<<endl;
      }
};

class Application
{
      int N,K; 
      public:
      Application() 
      {
                    cin>>N>>K;
      }
      int run()
      {
          //sum{(N-i)!/(((N-i*2)!)*(i!))*((K-1)^(N-i)), 0<=i<=N/2}
          //f[i]=C(N-i,i)*(K-1)^(N-i)
          //f[i-1]=C(N-i+1,i-1)*(K-1)^(N-i+1)
          
          //f[i]/f[i-1]=C(N-i,i)/C(N-i+1,i-1)/(K-1)
          //           =((N-i)!/(N-i+1)!) * ((N-i*2+2)!/(N-i*2)!) * ((i-1)!/i!) / (K-1)
          //           =1/(N-i+1)         * (N-i*2+2)*(N+i*2+1)   * 1/i           / (K-1)
          //           =((N-i*2+2)*(N+i*2+1))/((N-i+1)*i*(K-1))
          //f[i]=f[i-1]*((N-i*2+2)*(N+i*2+1))/((N-i+1)*i*(K-1))
          BigNumber answer(0);
          BigNumber get(1);
          for (int i=0;i*2<=N;i++)
          {
              if (i==0)
                 for (int j=1;j<=N;j++)
                     get*=K-1;
              else
              {
                  get*=(N-i*2+2);
                  get*=(N-i*2+1);
                  get/=(N-i+1);
                  get/=(i);
                  get/=K-1;
              }
              answer=answer+get;
          }
          answer.print();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
