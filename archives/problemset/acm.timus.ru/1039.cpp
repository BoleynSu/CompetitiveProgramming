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

class Application
{
      static const int oo=~(1<<31);
      int N;
      vector<int> happy;
      vector<vector<int> > children;
      vector<vector<int> > f;
      int dp(int parent,bool join)
      {
          if (f[parent][join]!=-oo) return f[parent][join];
          int max=-oo;
          //CASE 1 MY PARENT WANNA JOIN THE PARTY
          if (join)
          {
             int get=happy[parent];
             for (int i=0;i<children[parent].size();i++)
                 get+=dp(children[parent][i],false);
             if (get>max) max=get;
          }
          //CASE 2 MY PARENT HATE PARTIES
          else
          {
             int get=0;
             for (int i=0;i<children[parent].size();i++)
             {
                 int joinit=dp(children[parent][i],true);
                 int hateit=dp(children[parent][i],false);
                 if (joinit>hateit) get+=joinit;
                 else get+=hateit;
             }
             if (get>max) max=get;         
          }
          return f[parent][join]=max;
      }
      public:
      Application() 
      {
                    //WE WANNA A ROOT, SO WE ADD A NODE 0.
                    cin>>N;
                    happy.resize(N+1);
                    happy[0]=0;
                    for (int i=1;i<=N;i++)
                        cin>>happy[i];
                    children.resize(N+1);
                    vector<bool> haveParent(N+1,false);
                    for (;;)
                    {
                        int L,K;
                        cin>>L>>K;
                        if (L==0&&K==0) break;
                        children[K].push_back(L);
                        haveParent[L]=true;
                    }
                    for (int i=1;i<=N;i++)
                        if (!haveParent[i])
                           children[0].push_back(i);
      }
      int run()
      {
          f.resize(N+1,vector<int>(2,-oo));
          cout<<dp(0,false)<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
