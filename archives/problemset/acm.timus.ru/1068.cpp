/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-3
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

class Application
{
      int N;
      static int abs(int a)
      {
             return a>0?a:-a;
      }
      public:
      Application()
      {
                   cin>>N;
      }
      int run()
      {
          cout<<(N+1)*(abs(N-1)+1)/2<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
