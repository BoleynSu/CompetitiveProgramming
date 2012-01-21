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
      int K,L;
      public:
      Application()
      {
                   cin>>K;
      }
      int run()
      {
          //K%(L+1)=0
          for (L=2;L<K;L++)
              if (!(K%(L+1))) break;
          cout<<L%K<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
