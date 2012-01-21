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
      int N;
      vector<vector<bool> > v;
      vector<bool> answer;
      public:
      Application() 
      {
                    cin>>N;
                    v.resize(N,vector<bool>(N+1,false));
                    for (int i=0;i<N;i++)
                    {
                        int get;
                        for (cin>>get;get!=-1;cin>>get)
                            v[get-1][i]=true;
                    }
                    for (int i=0;i<N;i++)
                        v[i][N]=true;
      }
      int run()
      {
          bool nosolution=false;
          for (int i=0;i<N-1;i++)
          {
              for (int j=i+1;j<N;j++)
                  if (v[j][i]>v[i][i])
                     v[i].swap(v[j]);
              if (v[i][i]==false)
              {
                 nosolution=true;
                 break;
              }
              for (int j=i+1;j<N;j++)
              {
                  bool mulj=v[i][i];
                  bool muli=v[j][i];
                  for (int k=i;k<=N;k++)
                      v[j][k]=((v[j][k] and mulj) xor (v[i][k] and muli));
              }
          }
          answer.resize(N);
          for (int i=N-1;i>=0;i--)
          {
              bool total=v[i][N];
              for (int j=i+1;j<N;j++)
                  total=total xor (answer[j] and v[i][j]);
              answer[i]=total and v[i][i];
          }
          if (nosolution) cout<<"No solution"<<endl;
          else
          {
              vector<int> print;
              for (int i=0;i<N;i++)
                  if (answer[i])
                     print.push_back(i+1);
              for (int i=0;i<print.size();i++)
                  cout<<print[i]<<char(i+1==print.size()?'\n':' ');
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
