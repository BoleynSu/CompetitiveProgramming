/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-22
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
      int mistake;
      public:
      Application()
                   :mistake(0) 
      {
                    char get;
                    while ((get=cin.get())!=EOF) file.push_back(get);
      }
      int run()
      {
          vector<bool> upper(256,false),
                       lower(256,false),
                       letter(256,false),
                       endofsentence(256,false);
          for (char i='A';i<='Z';i++) upper[i]=true;
          for (char i='a';i<='z';i++) lower[i]=true;
          for (char* i="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "abcdefghijklmnopqrstuvwxyz";*i;i++)
              letter[*i]=true;
          for (char* i=".?!";*i;i++)
              endofsentence[*i]=true;
          
          //CASE 1
          for (int i=1;i<file.length();i++)
              if (upper[file[i]]&&letter[file[i-1]])
                 mistake++;
          //CASE 2
          for (int i=0,j;i<file.length();i=j+1)
          {
              for (j=i;j<file.length()&&(!endofsentence[file[j]]);j++) ;
              for (int k=i;k<=j;k++)
              {
                  if (lower[file[k]])
                     mistake++;
                  if (letter[file[k]])
                     break;
              }
              //cout<<"sentence:"<<i<<","<<j<<endl;
              //for (int k=i;k<=j;k++) cout<<file[k];
              //cout<<endl;
          }
          
          cout<<mistake<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
