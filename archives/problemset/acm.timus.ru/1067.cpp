/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-3
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

struct FileTree
{
       string node;
       map<string,FileTree> child;
       void add(const string& path)
       {
            int end=path.find('\\');
            if (end!=-1)
               child[path.substr(0,end)]
               .add(path.substr(end+1,path.length()));
            else
               child[path.substr(0,end)];
       }
       void print(const string& pre="")
       {
            for (map<string,FileTree>::iterator it=child.begin();
                 it!=child.end();it++)
            {
                cout<<pre<<it->first<<endl;
                it->second.print(" "+pre);
            }
       }
};

class Application
{
      int N;
      FileTree ft;
      public:
      Application()
      {
      }
      int run()
      {
          cin>>N;
          for (int i=0;i<N;i++)
          {
              string path;
              cin>>path;
              ft.add(path);
          }
          ft.print();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
