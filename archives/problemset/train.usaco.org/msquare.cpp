/*
ID: sujiao1
PROG: msquare
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

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXSTATE=8*7*6*5*4*3*2*1;
      static const int MAXN=8;
      typedef unsigned int state;
      state target,start;
      state answer;
      public:
      Application() :cin("msquare.in"),cout("msquare.out"),start(12348765),target(0)
      {
                    int get;
                    for (int i=10000000;i>=10000;i/=10)
                    {
                        cin>>get;
                        target+=get*i;
                    }
                    for (int i=1;i<=1000;i*=10)
                    {
                        cin>>get;
                        target+=get*i;
                    }
                    //cout<<target<<endl;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int A(int f)
      {
          int t;
          t=(f/10000)+(f%10000)*10000;
          return t;
      }
      int B(int f)
      {
          int t;
          t=((f/10000)%10)*10000000+((f/100000)%1000)*10000+((f/1)%10)*1000+((f/10)%1000)*1;
          return t;
      }
      int C(int f)
      {
          int t;
          t=((f/10000000)%10)*10000000
            +((f/100)%10)    *1000000
            +((f/1000000)%10)*100000
            +((f/1000)%100)  *1000
            +((f/10)%10)     *100
            +((f/100000)%10) *10
            +((f/1)%10)      *1;
          return t;
      }
      int h(int key)
      {
          char f[MAXN+2];
          memset(f,0,sizeof(f));
          int value=0;
          for (int k=1,j=1;k<=10000000;k*=10,j++)
          {
              int get=(key/k)%10;
              //cout<<get<<"g"<<endl;
              
              int c=1;
              for (int i=1;i<j;i++)
                  c*=i;
              if (j==1) c=0;
              //cout<<c<<"c"<<endl;
              
              value+=f[get]*c;
              //cout<<value<<"v"<<endl;
              
              for (int i=get;i<=MAXN;i++)
                  f[i]++;
              
              //for (int i=1;i<=MAXN;i++)
              //    cout<<int(f[i])<<" ";
              //cout<<"f"<<endl;
          }
          return value;
      }
      int run()
      {
          bool hash[MAXSTATE+2];
          memset(hash,false,sizeof(hash));
          
          state q[MAXSTATE+2];
          int link[MAXSTATE+2];
          char opt[MAXSTATE+2];
          int open,close;
          
          close=1;
          open=1;
          q[close]=start;
          link[close]=0;
          hash[h(close)]=true;
          
          while (close<=open)
          {
                state now=q[close];
                //cout<<close<<"close"<<endl;
                
                if (now==target)
                {
                   answer=close;
                   //cout<<answer<<"ans"<<endl;
                   break;
                }
                
                int getA=A(now);
                if (!hash[h(getA)])
                {
                   hash[h(getA)]=true;
                   open++;
                   q[open]=getA;
                   link[open]=close;
                   opt[open]='A';
                }
                int getB=B(now);
                if (!hash[h(getB)])
                {
                   hash[h(getB)]=true;
                   open++;
                   q[open]=getB;
                   link[open]=close;
                   opt[open]='B';
                }
                int getC=C(now);
                if (!hash[h(getC)])
                {
                   hash[h(getC)]=true;
                   open++;
                   q[open]=getC;
                   link[open]=close;
                   opt[open]='C';
                }
                //cout<<open<<"open"<<endl;
                close++;
          }
          int c=0;
          for (int i=answer;link[i]!=0;i=link[i])
          {
              c++;
          }
          cout<<c<<endl;
          char stack[MAXSTATE+2];
          int len=c-1;
          for (int i=answer;link[i]!=0;i=link[i])
          {
              stack[len--]=opt[i];
          }
          stack[c]='\0';
          cout<<stack<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
