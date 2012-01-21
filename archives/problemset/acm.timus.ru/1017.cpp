/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-16 
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
      int N; 
      public:
      Application() 
      {
                    cin>>N;
      }
      int run()
      {
          //把N分堆，每堆不同，一共有多少分法？
          //f[n][i]=N分堆后最大的为i一共有几种分法
          //f[n][n]=1
          //f[n][i]=sum{f[n-i][j],1<=j<i<n}
          //answer=sum{f[n][i],1<=i<=n}-1
          
          vector<vector<long long int> > f(N+1,vector<long long int>(N+1,0));
          for (int i=1;i<=N;i++) f[i][i]=1;
          for (int n=1;n<=N;n++)
              for (int i=1;i<n;i++)
                  for (int j=1;j<i;j++)
                      f[n][i]+=f[n-i][j];
          long long int answer=-1;
          for (int i=1;i<=N;i++)
              answer+=f[N][i];
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
