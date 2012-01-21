/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-27
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
      static int gcd(int a,int b)
      {
             return b?gcd(b,a%b):a;
      }
      public:
      Application()
      {
                   cin>>N;
                   a.resize(N);
                   for (int i=0;i<N;i++) cin>>a[i];
      }
      int run()
      {
          int answer=a[0];
          for (int i=1;i<N;i++) answer=gcd(answer,a[i]);
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
