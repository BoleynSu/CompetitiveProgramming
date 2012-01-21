/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-12
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
      typedef int bit;
      bit D,E,F,Dp,Ep,H;
      static bit abs(bit a)
      {
             return a>=0?a:-a;
      }
      public:
      Application()
      {
                   cin>>D>>E>>F>>Dp>>Ep>>H;
      }
      int run()
      {
          bit cut=(~0);
          bit need=0;
          for (;;cut<<=1,need++)
              if (((Dp-1)&cut)==((Ep-1)&cut))
              {
                 if (D>=need&&E>=need) need=abs(D-E);
                 else need=abs(D-need)+abs(E-need);
                 if (need<=H) cout<<"YES"<<endl;
                 else cout<<"NO"<<endl;
                 break;
              }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
