/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: $DATE
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
using std::min;
using std::max;
#include <cassert>
//using std::assert;

class Application
{
      pair<long long int,long long int> p1,p2,p3,p4;
      long long int answer;
      public:
      Application()
      {
                   cin>>p1.first>>p1.second
                      >>p2.first>>p2.second
                      >>p3.first>>p3.second
                      >>p4.first>>p4.second;
      }
      int run()
      {
          long long int ax1,ay1,ax2,ay2;
          ax1=min(p1.first,p2.first);
          ax2=max(p1.first,p2.first);
          ay1=min(p1.second,p2.second);
          ay2=max(p1.second,p2.second);
          long long int bx1,by1,bx2,by2;
          bx1=min(p3.first,p4.first);
          bx2=max(p3.first,p4.first);
          by1=min(p3.second,p4.second);
          by2=max(p3.second,p4.second);
          long long int cx1,cy1,cx2,cy2;
          cx1=max(ax1,bx1);
          cx2=min(ax2,bx2);
          cy1=max(ay1,by1);
          cy2=min(ay2,by2);
          if (cx1<=cx2&&cy1<=cy2)
          {
             if (((p1.first<=cx1&&p3.first<=cx1)or(p1.first>=cx2&&p3.first>=cx2))
                 xor((p1.second<=cy1&&p3.second<=cy1)or(p1.second>=cy2&&p3.second>=cy2)))
                answer=max(cx2-cx1,cy2-cy1);
             else answer=cx2-cx1+cy2-cy1;
          }
          else answer=0;
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
