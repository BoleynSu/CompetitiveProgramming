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
      int N,M;
      vector<int> k;
      public:
      Application()
      {
                   cin>>N>>M;
                   k.resize(M);
                   for (int i=0;i<M;i++) cin>>k[i];
      }
      int run()
      {
          vector<bool> f(N+1);
          f[0]=true;
          for (int i=1;i<=N;i++)
          {
              f[i]=false;
              for (int j=0;j<M;j++)
                  if ((i-k[j]>=0)&&(not f[i-k[j]]))
                     f[i]=true;
          }
          cout<<(f[N]?1:2)<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
