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
      static const int oo=~(1<<31);
      double P,Q; 
      public:
      Application() 
      {
                    cin>>P>>Q;
      }
      int run()
      {
          int Pi=int(P*double(100)+0.5);
          int Qi=int(Q*double(100)+0.5);
          
          int answer;
          for (answer=1;;answer++)
          {
              int min=answer*Pi;
              int max=answer*Qi;
              int l=min/10000-1;
              int r=max/10000+1;
              int counter=0;
              for (int i=l;i<=r;i++)
                  if ((i*10000>min)&&(i*10000<max))
                     counter++;
              if (counter)
                 break;
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
