/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-8
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
#include <cassert>
//using std::assert;

class Application
{
      int x,y;
      int answer;
      public:
      Application()
      {
                   cin>>x>>y;
      }
      int run()
      {
          answer=0;
          for (int base=2;base<=x+1;base++)
          {
              int Y=y;
              int X=x;
              bool match=true;
              while (Y)
              {
                    while (X%base!=Y%base)
                    {
                          X/=base;
                          if (X==0)
                          {
                             match=false;
                             break;
                          }
                    }
                    if (!match) break;
                    match=true;
                    X/=base;
                    Y/=base;
              }
              if (match)
              {
                 answer=base;
                 break;
              }
          }
          if (answer) cout<<answer<<endl;
          else cout<<"No solution"<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
