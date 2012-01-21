/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-18
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
using std::deque;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;
#include <cmath>
//using std::M_PI;
#define M_PI (3.141592653589793238462643383279f) //哈哈 我会背PI小数点后30位 
using std::sqrt;
#include <iomanip>

class Application
{
      typedef vector<pair<double,double> > vpdd;
      typedef vector<pair<double,double> >::iterator vpddi;
      int N;
      double R;
      vpdd point;
      public:
      Application() 
      {
                    cin>>N>>R;
                    point.resize(N);
                    for (vpddi it=point.begin();
                         it!=point.end();
                         it++)
                        cin>>it->first>>it->second;
      }
      int run()
      {
          double answer=M_PI*R*2.0f;
          for (vpddi it=point.begin();;)
          {
               vpddi to=it++;
               if (it==point.end()) it=point.begin();
               answer+=sqrt((to->first-it->first)
                             *(to->first-it->first)
                            +(to->second-it->second)
                             *(to->second-it->second));
               if (it==point.begin()) break;
          }
          cout<<std::setiosflags(std::ios::fixed)
              <<std::setprecision(2)
              <<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
