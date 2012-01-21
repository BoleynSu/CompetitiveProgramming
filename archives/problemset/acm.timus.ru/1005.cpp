/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-10 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
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
#include <cassert>
//using std::assert;

class Application
{
      static const int oo=~(1<<31);
      int N;
      vector<int> W; 
      int total;
      public:
      Application() 
                    :total(0)
      {
                    cin>>N;
                    W.resize(N);
                    for (int i=0;i<N;i++)
                    {
                        cin>>W[i];
                        total+=W[i];
                    }
      }
      int run()
      {
          vector<bool> f(total+1,false);
          f[0]=true;
          for (int k=0;k<N;k++)
              for (int i=total;i>=W[k];i--)
                  f[i]=f[i] or f[i-W[k]];
          
          int answer=oo;
          for (int i=(total+1)/2;i<=total;i++)
          {
              if (f[i])
              {
                 answer=i*2-total;
                 break;
              }
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
