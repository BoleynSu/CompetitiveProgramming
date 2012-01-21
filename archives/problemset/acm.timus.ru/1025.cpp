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
      int K;
      vector<int> vote;
      public:
      Application() 
      {
                    cin>>K;
                    vote.resize(K);
                    for (int i=0;i<K;i++) cin>>vote[i];
      }
      int run()
      {
          sort(vote.begin(),vote.end());
          int answer=0;
          for (int i=0;i<(K+1)/2;i++)
              answer+=(vote[i]+1)/2;
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
