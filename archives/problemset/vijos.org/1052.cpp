/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-23 
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

template<typename Type>
class Function
{
      int n;
      vector<vector<Type> > matrix;
      vector<Type> answer;
      static Type abs(Type a)
      {
             return a>=0?a:-a;
      }
      void smaller(int step)
      {
           for (int i=step+1;i<n;i++)
               if (abs(matrix[i][step])>abs(matrix[step][step]))
                  matrix[step].swap(matrix[i]);
           for (int i=step+1;i<n;i++)
           {
               Type mul=matrix[i][step];
               Type div=matrix[step][step];
               for (int j=step;j<=n;j++)
                   matrix[i][j]-=matrix[step][j]*mul/div;
           }
      }
      void back(int step)
      {
           if (step==n-1)
              answer[step]=matrix[step][n]/matrix[step][step];
           else
           {
               answer[step]=matrix[step][n];
               for (int i=step+1;i<n;i++)
                   answer[step]-=matrix[step][i]*answer[i];
               answer[step]/=matrix[step][step];
           }
      }
      public:
      bool read()
      {
           cin>>n;
           matrix.resize(n,vector<Type>(n+1));
           answer.resize(n);
           for (int i=0;i<n;i++)
               for (int j=0;j<=n;j++)
                   cin>>matrix[i][j];
           return true;
      }
      void solve()
      {
           for (int i=0;i<n-1;i++) smaller(i);
           for (int i=n-1;i>=0;i--) back(i);
      }
      template<typename Print_Type>
      void print()
      {
           for (int i=0;i<n;i++)
               cout<<Print_Type(answer[i])<<char((i+1==n)?'\n':' ');
      }
};
struct Integer
{
       long long int data;
       Integer(double get)
                      :data((long long int)(get+0.5))
       {
       }
       operator long long int()
       {
                return data;
       }
};
class Application
{
      public:
      Application() 
      {
      }
      int run()
      {
          Function<double> f;
          f.read();
          f.solve();
          f.print<Integer>();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
