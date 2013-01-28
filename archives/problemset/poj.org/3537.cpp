/*
AUTHOR: Su Jiao
DATE: $DATA
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

class Application
{
      int n;
      vector<int> _sg;
      int SG(int x)
      {
          if (x<0) return 0;
          if (_sg[x]!=-1) return _sg[x];
          else
          {
              vector<bool> found(n+1,false);
              for (int i=1;i<=x;i++)
                  found[SG(i-2-1)^SG(x-i-2)]=true;
              for (int i=0;i<=n;i++)
                  if (!found[i]) return _sg[x]=i;
          }
      }
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
      }
      int run()
      {
          cin>>n;
          _sg.resize(n+1,-1);
          if (SG(n)) cout<<1<<endl;
          else cout<<2<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
