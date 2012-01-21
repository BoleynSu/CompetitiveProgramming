/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-20
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
      vector<int> a;
      public:
      Application() 
      {
                    cin>>N;
                    a.resize(N);
                    for (int i=0;i<N;i++) cin>>a[i];
      }
      int run()
      {
          static const int NOTIN=-1;
          vector<int> sum(N+1);
          sum[0]=0;
          for (int i=0;i<N;i++)
              sum[i+1]=sum[i]+a[i];
          vector<int> counter(N,NOTIN);
          for (int i=0;i<=N;i++)
          {
              if (counter[sum[i]%N]!=NOTIN)
              {
                 cout<<i-counter[sum[i]%N]<<endl;
                 for (int j=counter[sum[i]%N];j<i;j++)
                     cout<<a[j]<<endl;
                 break;
              }
              else counter[sum[i]%N]=i;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
