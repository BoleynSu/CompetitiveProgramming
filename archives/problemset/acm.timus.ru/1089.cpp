/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-12
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
using std::priority_queue;
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
      static const int my_EOF=-1;
      vector<string> vocabulary;
      string content;
      int mistakes;
      public:
      Application()
      {
                   {
                       string get;
                       while (cin>>get)
                             if (get=="#")
                             {
                                while (cin.get()!='\n');
                                break;
                             }
                             else vocabulary.push_back(get);
                   }
                   {
                       char get;
                       while ((get=cin.get())!=my_EOF) content.push_back(get);
                   }
      }
      int run()
      {
          mistakes=0;
          for (int i=0,j;;i=j)
          {
              while ((i<content.length())
                     &&(!('a'<=content[i]&&content[i]<='z'))) i++;
              if (i>=content.length()) break;
              j=i;
              while ('a'<=content[j]&&content[j]<='z') j++;
              string word=content.substr(i,j-i);
              for (int j=0;j<vocabulary.size();j++)
                  if (vocabulary[j].length()==word.length())
                  {
                     int difference=0;
                     for (int k=0;k<word.length();k++)
                         if (vocabulary[j][k]!=word[k]) difference++;
                     if (difference==1)
                     {
                        mistakes++;
                        for (int k=0;k<word.length();k++)
                            content[i+k]=vocabulary[j][k];
                        break;
                     }
                  }
          }
          cout<<content<<mistakes<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
