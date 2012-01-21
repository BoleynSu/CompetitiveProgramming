/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-18
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
      vector<int> P;
      int gcd(int a,int b)
      {
          return b?gcd(b,a%b):a;
      }
      int lmc(int a,int b)
      {
          return a/gcd(a,b)*b;
      }
      public:
      Application() 
      {
                    cin>>N;
                    P.resize(N);
                    for (int i=0;i<N;i++)
                    {
                        cin>>P[i];
                        P[i]--;
                    }
      }
      int run()
      {
          vector<bool> visited(N,false);
          int answer=1;
          for (int i=0;i<N;i++)
              if (!visited[i])
              {
                 int j=i;
                 int counter=0;
                 while (!visited[j])
                 {
                       counter++;
                       visited[j]=true;
                       j=P[j];
                 }
                 answer=lmc(answer,counter);
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
