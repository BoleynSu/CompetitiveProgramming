/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-19
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
#include <cstdio>
//using std::EOF;

class Application
{
      string file;
      public:
      Application() 
      {
                    char rc;
                    while ((rc=cin.get())!=EOF) file.push_back(rc);
      }
      int run()
      {
          bool comment=false;
          int counter=0;
          int last=~(1<<31);
          bool answer=true;
          for (int i=0;i<file.size();i++)
          {
              if (comment)
              {
                   if (file[i]=='*') last=i;
                   else if (file[i]==')'&&last+1==i) comment=false;
              }
              else if (counter)
              {
                 if (file[i]=='*'&&last+1==i)
                 {
                      counter--;
                      last=~(1<<31);
                      comment=true;
                 }
                 else if (file[i]==')')
                 {
                    counter--;
                 }
                 else if (file[i]=='(')
                 {
                      counter++;
                      last=i;
                 }
                 else
                 {
                     bool valid=false;
                     for (char* j="=+-*/0123456789)(\n";*j;j++)
                         if (file[i]==*j) valid=true;
                     if (!valid) answer=false;
                 }
              }
              else
              {
                  if (file[i]=='(')
                  {
                     counter++;
                     last=i;
                  }
                  else if (file[i]==')')
                  {
                       answer=false;
                  }
              }
          }
          if (comment||counter) answer=false;
          cout<<(char*)(answer?"YES":"NO")<<endl; 
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
