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
      static const int SUM=10000;
      int aN,bN;
      vector<int> a,b;
      public:
      Application()
      {
                   cin>>aN;
                   a.resize(aN);
                   for (int i=0;i<aN;i++) cin>>a[i];
                   cin>>bN;
                   b.resize(bN);
                   for (int i=0;i<bN;i++) cin>>b[i];
      }
      int run()
      {
          bool have=false;
          for (int i=0,j=0;i<aN;i++)
          {
              while (a[i]+b[j]>SUM) j++;
              if (a[i]+b[j]==SUM) have=true; 
          }
          cout<<(char*)(have?"YES":"NO")<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
