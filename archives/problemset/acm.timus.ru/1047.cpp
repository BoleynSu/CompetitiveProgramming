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
#include <cmath>
#include <iomanip>

class Application
{
      typedef double Type;
      struct Data
      {
             typedef double Type;
             Type x,C;
             void set(Type _x,Type _C)
             {
                  x=(_x),C=(_C);
             } 
             void print()
             {
                  cout<<floor(x+0.5)<<" "<<floor(C+0.5)<<endl;
             }
      };
      int N;
      Type Astart,Aend;
      vector<Type> c;
      public:
      Application() 
      {
                    cin>>N;
                    cin>>Astart>>Aend;
                    c.resize(N);
                    for (int i=0;i<N;i++) cin>>c[i];
      }
      int run()
      {
          //a[i]=(a[i-1]+a[i+1])/2-c[i]
          //a[i+1]=(a[i]+c[i])*2-a[i-1]
          //a[i]=(a[i-1]+c[i-1])*2-a[i-2]
          vector<Data> a(N+2);
          a[0].set(0,Astart);
          a[1].set(1,0);
          for (int i=2;i<=N+1;i++)
          {
              a[i].x=a[i-1].x*2-a[i-2].x;
              a[i].C=(a[i-1].C+c[i-1-1])*2-a[i-2].C;
          }
          cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
          cout<<(Aend-a[N+1].C)/a[N+1].x<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
