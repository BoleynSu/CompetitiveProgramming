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
      vector<int> database;
      int K;
      vector<int> query;
      public:
      Application() 
      {
                    cin>>N;
                    database.resize(N);
                    for (int i=0;i<N;i++) cin>>database[i];
                    string s;
                    cin>>s;
                    cin>>K;
                    query.resize(K);
                    for (int i=0;i<K;i++) cin>>query[i];
      }
      int run()
      {
          sort(database.begin(),database.end());
          
          for (int i=0;i<K;i++) cout<<database[query[i]-1]<<endl;
          
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
