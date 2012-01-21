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
      int N;
      public:
      Application()
      {
                   cin>>N;
      }
      int run()
      {
          vector<int> f(N+1,N);
          f[0]=0;
          for (int i=1;i<=N;i++)
          {
              for (int j=1;j*j<=i;j++)
                  if (f[i-j*j]+1<f[i]) f[i]=f[i-j*j]+1;
          }
          cout<<f[N]<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
