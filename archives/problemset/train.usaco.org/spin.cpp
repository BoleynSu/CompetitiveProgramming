/*
ID: sujiao1
PROG: spin
LANG: C++
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <ctime>
using std::clock;
#include <cstring>
using std::memset;
struct Wheel
{
       static const int MAXDEGREE=360;
       int speed;
       int circle[MAXDEGREE];
       Wheel()
       {
              memset(circle,false,sizeof(circle));
       }
};
class Application
{
      ifstream cin;
      ofstream cout;
      static const int WHEELNUMBER=5;
      Wheel wheel[WHEELNUMBER+2];
      int answer;
      public:
      Application() :cin("spin.in"),cout("spin.out")
      {
                    for (int i=1;i<=WHEELNUMBER;i++)
                    {
                        int W;
                        cin>>wheel[i].speed>>W;
                        for (int j=1;j<=W;j++)
                        {
                            int start,length,end;
                            cin>>start>>length;
                            end=start+length;
                            for (int k=start;k<=end;k++)
                                wheel[i].circle[k%Wheel::MAXDEGREE]=true;
                        }
                    }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      /*
      int gcd(int a,int b)
      {
          return b?gcd(b,a%b):a;
      }
      */
      int run()
      {
          bool getIntoACircle;
          int degree[WHEELNUMBER+2];
          memset(degree,0,sizeof(degree));
          for (int t=0;;t++)
          {
              /*
              cout<<"t:"<<t<<endl;
              for (int i=1;i<=WHEELNUMBER;i++)
                  cout<<degree[i]<<" ";
              cout<<endl;
              for (int i=1;i<=WHEELNUMBER;i++)
              {
                  for (int k=0;k<Wheel::MAXDEGREE;k++)
                      cout<<wheel[i].circle[(k+degree[i])%Wheel::MAXDEGREE];
                  cout<<endl;
              }
              cout<<endl;
              */
              getIntoACircle=true;
              for (int i=1;i<WHEELNUMBER;i++)
                  if (degree[i]!=degree[i+1]) getIntoACircle=false;
              if (t==0) getIntoACircle=false;
              if (getIntoACircle) break;
              
              bool get;
              for (int d=0;d<Wheel::MAXDEGREE;d++)
              {
                  get=true;
                  for (int i=1;i<=WHEELNUMBER;i++)
                      if (!wheel[i].circle[(d-degree[i]+Wheel::MAXDEGREE)%Wheel::MAXDEGREE])
                         get=false;
                  if (get)
                  {
                     answer=t;
                     break;
                  }
              }
              if (get) break;
              for (int i=1;i<=WHEELNUMBER;i++)
                  degree[i]=(degree[i]+wheel[i].speed)%Wheel::MAXDEGREE;
          }
          if (getIntoACircle)
             cout<<"none"<<endl;
          else
              cout<<answer<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
