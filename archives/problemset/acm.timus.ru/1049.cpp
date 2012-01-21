/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-26
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
      static const int NUMBER=10;
      static const int oo=10000;
      vector<int> a;
      int last_digit_of_N;
      vector<int> counter;
      public:
      Application()
                   :a(NUMBER)
      {
                   for (int i=0;i<NUMBER;i++) cin>>a[i];
      }
      int run()
      {
          counter.resize(oo+1,1);
          for (int i=0;i<NUMBER;i++)
              for (int j=2;j<=oo;j++)
                  while (a[i]%j==0) counter[j]++,a[i]/=j;
          last_digit_of_N=1;
          for (int i=0;i<=oo;i++)
              last_digit_of_N=last_digit_of_N*counter[i]%10;
          cout<<last_digit_of_N<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
