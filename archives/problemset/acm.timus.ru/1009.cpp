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
      int N,K; 
      public:
      Application() 
      {
                    cin>>N>>K;
      }
      int run()
      {
          /*
          N位中有i个取0，且不连续，不前导
          i个0:
                0一共有(N-i)!/(((N-i*2)!)*(i!))种插法(明显N-i>=i，即N>=i*2)
          N-i个非0:
                   他们一共有(K-1)^(N-i)种可能 
          要求的就是sum{(N-i)!/(((N-i*2)!)*(i!))*((K-1)^(N-i)), 0<=i<=N/2}
          */
          long long int answer=0;
          for (int i=0;i*2<=N;i++)
          {
              long long int a=1,b=1,c=1,d=1;
              for (int j=1;j<=N-i;j++)
                  a*=j;
              for (int j=1;j<=N-i*2;j++)
                  b*=j;
              for (int j=1;j<=i;j++)
                  c*=j;
              for (int j=1;j<=N-i;j++)
                  d*=K-1;
              answer+=a/(b*c)*d;
          }
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
