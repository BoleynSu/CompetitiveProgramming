/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-30
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
      static const long long int oo=1000000000;
      int N,K,L;
      vector<long long int> data;
      vector<long long int> sum;
      public:
      Application()
      {
                   cin>>N>>K;
                   data.resize(N);
                   for (int i=0;i<N;i++)
                   {
                       char c;
                       cin>>c;
                       if (c=='*') data[i]=oo;
                       else data[i]=c-'0';
                   }
      }
      int run()
      {
          sum.resize(N+1);
          sum[0]=0;
          for (int i=0;i<N;i++)
              sum[i+1]=sum[i]+data[i];
          
          long long int min=oo;
          L=0;
          for (int i=0;i<=N-K;i++)
              if (sum[i+K]-sum[i]<min)
              {
                 L=i+1;
                 min=sum[i+K]-sum[i];
              }
          cout<<L<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
