/*
ID: sujiao1
PROG: fence9
LANG: C++
*/
/*
PROGRAM: fence9
AUTHOR: Su Jiao
DATE: 2009-12-28
DESCRIPTION:
在本题中，格点是指横纵坐标皆为整数的点。 
为了圈养他的牛，农夫约翰建造了一个三角形的电网。他从原点（0,0）牵出一根通电的电
线，连接格点[n,m]（0<=n<32000,0<m<32000），再连接格点[p,0]（p>0），最后回到原点。 
牛可以在不碰到电网的情况下被放到电网内部的每一个格点上（十分苗条的牛）。如果一个
格点碰到了电网，牛绝对不可以被放到该格点之上。那么有多少头牛可以被放到农夫约翰的
电网中去呢？ 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;

class Application
{
      ifstream cin;
      ofstream cout;
      int n,m,p;
      int answer;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>n>>m>>p;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int gcd(int a,int b)
      {
          return b?gcd(b,a%b):a;
      }
      int abs(int n)
      {
          return n>0?n:-n;
      }
      int online()
      {
          return gcd(n,m)+gcd(abs(p-n),m)+p;
      }
      int run()
      {
          answer=(m*p/2+1-online()/2);
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app("fence9.in","fence9.out");
    return app.run();
}
