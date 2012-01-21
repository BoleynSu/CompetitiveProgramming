/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-10
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
      static const int MAXN=100000;
      public:
      Application()
      {
      }
      int run()
      {
          vector<int> a(MAXN+1);
          vector<int> max(MAXN+1);
          a[0]=0;
          a[1]=1;
          for (int i=2;i<MAXN;i++)
              if (i%2==0) a[i]=a[i/2];
              else a[i]=a[i/2]+a[i/2+1];
          max[0]=0;
          max[1]=1;
          for (int i=2;i<MAXN;i++)
              if (a[i]>max[i-1]) max[i]=a[i];
              else max[i]=max[i-1];
          
          int get;
          for (;;)
          {
              cin>>get;
              if (get) cout<<max[get]<<endl;
              else break;
          }
          
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
