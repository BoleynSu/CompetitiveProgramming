/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-11
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
using std::priority_queue;
#include <set>
using std::set;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <iomanip>
#include <cassert>
//using std::assert;
#include <cmath>
//using std::M_PI;
#define M_PI 3.141592653589793238462643383279f
using std::sqrt;

class Application
{
      double A,R;
      public:
      Application()
      {
                   cin>>A>>R; 
      }
      int run()
      {
          cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(3);
          if (R*2<=A)
             cout<<M_PI*R*R<<endl;
          else if (R*sqrt(2.0)>=A) cout<<A*A<<endl;
          else
          {
              double a=A/2;
              double c=R;
              double b=sqrt(c*c-a*a);
              cout<<(b*a+M_PI*R*R*((M_PI/2)-acos(a/c)*2)/(M_PI*2))*4<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
