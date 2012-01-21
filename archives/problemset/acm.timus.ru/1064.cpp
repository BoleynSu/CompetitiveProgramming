/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-7
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
      static const int MAXN=10000;
      int i,L;
      int BinarySearch(int x,int N)
      {
          int p, q, i, L;          
          p = 0;   /* Left border of the search  */
          q = N-1; /* Right border of the search */
          L = 0;   /* Comparison counter         */
          while (p <= q)
          {
                i = (p + q) / 2;
                ++L;
                if (i == x)
                   return L;
                if (x < i)
                   q = i - 1;
                else
                    p = i + 1;
          }
          return -1;
      }
      public:
      Application()
      {
                   cin>>i>>L;
      }
      int run()
      {
          int counter=0;
          stringstream sout;
          for (int j=0;j<=MAXN;j++)
          {
              if (BinarySearch(i,j)==L)
              {
                 sout<<j<<" ";
                 while ((j+1<=MAXN)&&(BinarySearch(i,j+1)==L)) j++;
                 sout<<j<<endl;
                 counter++;
              }
          }
          cout<<counter<<endl;
          cout<<sout.str();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
