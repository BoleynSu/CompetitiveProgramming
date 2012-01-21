/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-16 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
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
      static const int NOTLINKED=~(1<<31);
      int N,Q;
      vector<vector<int> > length;
      public:
      Application() 
      {
                    cin>>N>>Q;
                    length=vector<vector<int> >(N,vector<int>(N,NOTLINKED));
                    int a,b,c;
                    for (int i=0;i<N-1;i++)
                    {
                        cin>>a>>b>>c;
                        length[a-1][b-1]=length[b-1][a-1]=c;
                    }
                    if (Q>N-1) Q=N-1;
      }
      /*
      f for father
      l for left child
      r for right child
      f.f[n]=max{
           l.f[i-1]+lenght[f][l]+r.f[n-i-1]+length[f][r],//if have two children
           l.f[n-1]+lenght[f][l],//if have left child
           r.f[n-1]+lenght[f][r],//if have right child
           0//if no child
           }
      */
      vector<vector<int> > get;
      int dp(int f,int have,int ff)
      {
          if (get[f][have]==NOTLINKED)
          {
             int l=NOTLINKED,r=NOTLINKED;
             for (int i=0;i<N;i++)
                 if ((i!=ff)&&(length[f][i]!=NOTLINKED))
                 {
                    if (l==NOTLINKED)
                    {
                       l=i;
                       continue;
                    }
                    if (r==NOTLINKED)
                    {
                       r=i;
                       continue;
                    }
                 }
             get[f][have]=0;
             int dpl,dpr;
             if (l!=NOTLINKED&&r!=NOTLINKED)
             {
                for (int i=1;i<have;i++)
                {
                    dpl=dp(l,i-1,f)+length[f][l];
                    dpr=dp(r,have-i-1,f)+length[f][r];
                    if (dpl+dpr>get[f][have])
                       get[f][have]=dpl+dpr;
                }
             }
             if (l!=NOTLINKED)
                if (have>0)
                {
                   dpl=length[f][l]+dp(l,have-1,f);
                   if (dpl>get[f][have])
                      get[f][have]=dpl;
                }
             if (r!=NOTLINKED)
                if (have>0)
                {
                   dpr=length[f][r]+dp(r,have-1,f);
                   if (dpr>get[f][have])
                      get[f][have]=dpr;
                }
          }
          return get[f][have];
      }
      int run()
      {
          get=vector<vector<int> >(N,vector<int>(Q+1,NOTLINKED));
          cout<<dp(1-1,Q,NOTLINKED)<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
