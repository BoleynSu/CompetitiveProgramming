/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: $DATE
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
      int N,K;
      public:
      Application()
      {
                   cin>>N>>K;
      }
      int run()
      {
          vector<vector<long long int> > f(N+1,vector<long long int>(2));
          f[0][0]=1;
          f[0][1]=0;
          for (int i=1;i<=N;i++)
          {
              f[i][0]=f[i-1][0]+f[i-1][1];
              f[i][1]=f[i-1][0];
          }
          bool noanswer=false;
          string output;
          output.resize(N);
          for (int i=N;i>=1;i--)
          {
              if (K>f[i][1]+f[i][0])
              {
                 noanswer=true;
                 break;
              }
              if (K>f[i][0])
              {
                 K-=f[i][0];
                 output[N-i]='1';
              }
              else
              {
                 output[N-i]='0';
              }
          }
          if (noanswer) cout<<-1<<endl;
          else cout<<output<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
