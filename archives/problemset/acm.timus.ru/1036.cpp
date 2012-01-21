/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-21
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::stringstream;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <set>
using std::set;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;
#include <iomanip>

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
      friend BigNumber operator*(const BigNumber& a,const BigNumber& b)
      {
             BigNumber c;
             c.d.resize(a.d.size()+b.d.size(),0);
             for (int i=0;i<a.d.size();i++)
                 for (int j=0;j<b.d.size();j++)
                 {
                     c.d[i+j]+=a.d[i]*b.d[j];
                     if (c.d[i+j]>=BASE)
                     {
                        c.d[i+j+1]+=c.d[i+j]/BASE;
                        c.d[i+j]=c.d[i+j]%BASE;
                     }
                 }
             if (!c.d.back()) c.d.pop_back();
             return c;
      }
      BigNumber& operator+=(BigNumber& add)
      {
                 *this=operator+(*this,add);
                 return *this;
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
      int N,S; 
      public:
      Application() 
      {
                    cin>>N>>S; 
      }
      int run()
      {
          //答案为将S/2个苹果分到N个果盘里（最多分9个，最少不分）的方案数的平方
          //用生成函数 (1+x^2+x^3+...+x^9)^N
          //然后x^(s/2)的系数的平方
          //然后生成函数的程序我不想写了
          if (S%2)
          {
             cout<<0<<endl;
             return 0;
          }
          
          vector<vector<BigNumber> > f(N,vector<BigNumber>(S/2+1));
          for (int i=0;i<N;i++)
          {
              if (i)
                 for (int j=0;j<=S/2;j++)
                 {
                     f[i][j]=0;
                     for (int k=0;k<=j;k++)
                         if (j-k<=9)
                            f[i][j]+=f[i-1][k];
                 }
              else
                  for (int j=0;j<=S/2;j++)
                      if (j<=9)
                         f[i][j]=1;
          }
          BigNumber answer=f[N-1][S/2]*f[N-1][S/2];
          answer.print();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
