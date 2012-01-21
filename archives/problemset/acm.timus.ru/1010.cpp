/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-13
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
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
      static const int oo=~(1<<31);
      int N;
      vector<double> f; 
      public:
      Application()
      {
                   cin>>N;
                   f.resize(N);
                   for (int i=0;i<N;i++)
                       cin>>f[i];
      }
      int run()
      {
          //max{abs(f[i-1]-f[i]) ,2<=i<=N} 
          double max=-oo;
          int max_i;
          for (int i=1;i<N;i++)
          {
              double abs_k=f[i-1]>f[i]?f[i-1]-f[i]:f[i]-f[i-1];
              if (abs_k>max)
              {
                 max=abs_k;
                 max_i=i;
              }
          }
          cout<<max_i+1-1<<" "<<max_i+1<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
