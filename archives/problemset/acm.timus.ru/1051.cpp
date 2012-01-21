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
      int M,N;
      public:
      Application() 
      {
                    cin>>M>>N; 
      }
      int run()
      {
          if (M==1||N==1) cout<<(M+N)/2<<endl;
          else cout<<((M*N)%3?1:2)<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
