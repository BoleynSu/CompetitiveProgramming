/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-8 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
using std::memset;

class Application
{
      int a,b;
      public:
      Application() 
      {
                    cin>>a>>b;
      }
      int run()
      {
          cout<<(a+b)<<endl; 
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
