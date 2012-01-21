/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-11
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
      int n,k;
      unsigned long long int answer;
      public:
      Application()
      {
                   cin>>n;
                   k=0;
                   char mark;
                   while (cin>>mark) if (mark=='!') k++;
      }
      int run()
      {
          answer=1;
          for (int i=n;i>0;i-=k)
              answer*=i;
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
