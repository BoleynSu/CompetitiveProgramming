/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-13
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
      static const int BASE=10;
      int N;
      vector<int> counter;
      public:
      Application()
                   :counter(BASE,0)
      {
                    cin>>N;
      }
      int run()
      {
          if (N==0) cout<<10<<endl;
          else if (N==1) cout<<1<<endl;
          else
          {
              for (int i=BASE-1;i>1;i--)
                  while (N%i==0)
                  {
                        N/=i;
                        counter[i]++;
                  }
              if (N!=1) cout<<-1<<endl;
              else
              {
                  for (int i=0;i<BASE;i++)
                      for (int j=0;j<counter[i];j++)
                          cout<<i;
                  cout<<endl;
              }
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
