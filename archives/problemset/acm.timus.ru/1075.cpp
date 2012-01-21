/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-9
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
using std::sqrt;
using std::acos;

struct Point{double x,y,z;};
double d(const Point& A,const Point& B)
{
       return sqrt((A.x-B.x)*(A.x-B.x)
                  +(A.y-B.y)*(A.y-B.y)
                  +(A.z-B.z)*(A.z-B.z));
}
double s(double a,double b,double c)
{
       double p=(a+b+c)/2;
       return sqrt(p*(p-a)*(p-b)*(p-c));
}

class Application
{
      Point A,B,C;
      double R;
      public:
      Application()
      {
                   cin>>A.x>>A.y>>A.z
                      >>B.x>>B.y>>B.z
                      >>C.x>>C.y>>C.z
                      >>R;
      }
      int run()
      {
          double AB=d(A,B);
          double AC=d(A,C);
          double BC=d(B,C);
          
          cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
          if (acos((AC*AC+BC*BC-AB*AB)/(2*AC*BC))-acos(R/AC)-acos(R/BC)<0)
             cout<<AB<<endl;
          else
          {
              double answer=0;
              answer=
              sqrt(AC*AC-R*R)
              +sqrt(BC*BC-R*R)
              +R*(acos((AC*AC+BC*BC-AB*AB)/(2*AC*BC))-acos(R/AC)-acos(R/BC));
              cout<<answer<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
