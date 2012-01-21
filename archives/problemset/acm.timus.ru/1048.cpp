/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-25
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
      public:
      Application() 
      {
      }
      int run()
      {
          int N;
          cin>>N;
          vector<pair<int,int> > data;
          data.resize(N);
          for (int i=0;i<N;i++)
              cin>>data[i].first>>data[i].second;
          
          string answer;
          answer.resize(N);
          int over=0;
          for (int i=N-1;i>=0;i--)
          {
              answer[i]='0'+((data[i].first+data[i].second+over)%10);
              over=(data[i].first+data[i].second+over)/10;
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
