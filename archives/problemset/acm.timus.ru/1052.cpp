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
      vector<pair<int,int> > rabbit;
      public:
      Application() 
      {
                    cin>>N;
                    rabbit.resize(N);
                    for (int i=0;i<N;i++)
                        cin>>rabbit[i].first>>rabbit[i].second;
      }
      int run()
      {
          #define can(a,b,c) (rabbit[a].first-rabbit[b].first)\
                             *(rabbit[a].second-rabbit[c].second)\
                             ==(rabbit[a].first-rabbit[c].first)\
                             *(rabbit[a].second-rabbit[b].second)
          int K=0;
          for (int a=0;a<N;a++)
              for (int b=a+1;b<N;b++)
              {
                  int counter=2;
                  for (int c=b+1;c<N;c++)
                      if (can(a,b,c)) counter++;
                  if (counter>K) K=counter; 
              }
          cout<<K<<endl;
          #undef can
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
