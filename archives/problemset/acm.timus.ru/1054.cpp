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
      vector<int> pos;
      static void swap(int& a,int& b)
      {
             static int s;
             s=a;
             a=b;
             b=s;
      }
      public:
      Application()
      {
                   cin>>N;
                   pos.resize(N);
                   for (int i=0;i<N;i++) cin>>pos[i];
      }
      int run()
      {
          int step=0;
          bool can=true;
          int a=1,b=2,c=3; 
          for (int i=N-1;i>=0;i--)
          {
              if (pos[i]==a)  
                 swap(b,c);
              else if (pos[i]==b)
                   swap(a,c),step+=1<<i;
              else can=false;
          }
          if (can) cout<<step<<endl;
          else cout<<-1<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
