/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-25
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
      public:
      Application() 
      {
                    cin>>N;
      }
      int run()
      {
          int forward=N/2;
          int backward=N-forward;
          const int MAX=N*9+1;
          vector<vector<int> > f(N+1,vector<int>(MAX,0));
          //f[i][j]表示不超过i位和为j一共有几种可能
          //f[i][j]=sum{f[i-1][k],0<=j-k<=9}
          //边界f[0][0]=1
          //answer=sum{f[forward][i]*f[backward][i]}
          f[0][0]=1;
          for (int i=1;i<=N;i++)
              for (int j=0;j<MAX;j++)
                  for (int k=0;k<MAX;k++)
                      if (j-k>=0 && j-k<=9)
                         f[i][j]+=f[i-1][k];
          int answer=0;
          for (int i=0;i<MAX;i++)
              answer+=f[forward][i]*f[backward][i];
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
