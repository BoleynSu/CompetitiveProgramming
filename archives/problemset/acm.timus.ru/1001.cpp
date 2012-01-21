/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-8 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
using std::memset;
#include <stack>
using std::stack; 
#include <cmath>
using std::sqrt;
#include <iomanip>
using std::setiosflags;
using std::setprecision;

class Application
{
      stack<long long int> A;
      public:
      Application() 
      {
                    long long int input;
                    while (cin>>input)
                          A.push(input);
      }
      int run()
      {
          long long int pop;
          cout<<setiosflags(std::ios::fixed)<<setprecision(4);
          while (!A.empty())
          {
                pop=A.top();
                A.pop();
                cout<<sqrt(double(pop))<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
