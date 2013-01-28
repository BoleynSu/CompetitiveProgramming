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
      vector<int> k;
      public:
      Application()
      {
                   std::ios::sync_with_stdio(false);
      }
      int run()
      {
          for (cin>>n;n;cin>>n)
          {
              k.resize(n);
              int SG=0,answer=0;
              for (int i=0;i<n;i++)
              {
                  cin>>k[i];
                  SG^=k[i];
              }
              if (SG)
                 for (int i=0;i<n;i++)
                     if ((SG^k[i])<k[i]) answer++;
              cout<<answer<<endl;
              k.clear();
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
