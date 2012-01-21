/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-18
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
      vector<vector<bool> > isChild;
      public:
      Application() 
      {
                    cin>>N;
                    isChild=vector<vector<bool> >(N,vector<bool>(N,false));
                    for (int i=0;i<N;i++)
                    {
                        int child;
                        for (;;)
                        {
                            cin>>child;
                            if (child) isChild[i][child-1]=true;
                            else break;
                        }
                    }
      }
      int run()
      {
          vector<bool> printed(N);
          for (int i=0;i<N;i++)
          {
              for (int c=0;c<N;c++)
                  if (!printed[c])
                  {
                     bool haveFather=false;
                     for (int f=0;f<N;f++)
                         if ((!printed[f])&&(isChild[f][c]))
                            haveFather=true;
                     if (!haveFather)
                     {
                        cout<<c+1<<char(i+1==N?'\n':' ');
                        printed[c]=true;
                        break;
                     }
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
