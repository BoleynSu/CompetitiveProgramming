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
#include <cstdio>
//using std::EOF;

class Application
{
      string file;
      public:
      Application() 
      {
                    char c;
                    while ((c=cin.get())!=EOF) file.push_back(c);
      }
      int run()
      {
          for (int i=0,j;i<file.length();i=j)
          {
              bool endinput=false;
              for (int k=i;;k++)
              {
                  if (file.substr(k,4)=="\\par")
                  {
                     j=k+4;
                     break;
                  }
                  if (file.substr(k,9)=="\\endinput")
                  {
                     endinput=true;
                     j=file.length();
                     break;
                  }
                  if (file.substr(k,2)=="\n\n")
                  {
                     j=k+2;
                     break;
                  }
              }
              
              int total=0;
              bool printed;
              int counter=0;
              
              for (int k=i;k<j;k++)
                  if (k==0||file[k-1]!='\\')
                     if (file[k]=='"')
                        total++;
              
              for (int k=i;k<j;k++)
              {
                  printed=false;
                  if (k==0||file[k-1]!='\\')
                  {
                     if (file[k]=='"')
                     {
                        if (counter%2)
                        {
                           counter++;
                           cout<<"''";
                           printed=true;
                        }
                        else
                        {
                            counter++;
                            if (total!=counter) cout<<"``";
                            printed=true; 
                        }
                     }
                  }
                  if (!printed) cout<<file[k];
              }
              
              if (endinput) break;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
