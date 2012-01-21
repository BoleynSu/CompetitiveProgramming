/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-12
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
      static const int oo=200000;
      int n;
      vector<int> prime;
      void get_prime()
      {
           prime.push_back(2);
           for (int i=3;i<oo;i++)
           {
               bool can=true;
               for (int j=0;prime[j]*prime[j]<=i;j++)
                   if (i%prime[j]==0)
                   {
                      can=false;
                      break;
                   }
               if (can) prime.push_back(i);
           }
      }
      public:
      Application()
      {
                   cin>>n; 
      }
      int run()
      {
          get_prime();
          for (int i=0;i<n;i++)
          {
              int order;
              cin>>order;
              cout<<prime[order-1]<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
