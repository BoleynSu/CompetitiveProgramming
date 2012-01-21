/*
ID: sujiao1
PROG: ratios
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
      static const int MAXN=100;
      static const int TYPE=3;
      static const int NUMBER=3;
      static const int oo=1<<30;
      int a[NUMBER+2][TYPE+2];
      int b[NUMBER+2];
      int nb[NUMBER+2];
      int total;
      int ab[NUMBER+2];
      public:
      Application() :cin("ratios.in"),cout("ratios.out")
      {
                    for (int i=0;i<=NUMBER;i++)
                        for (int j=1;j<=TYPE;j++)
                            cin>>a[i][j];
                    //todo:
                    //find b[] that
                    // i= 1 to NUMBER
                    //b[0]*a[0][j]=sum{b[i]*a[i][j]} (j=1 to TYPE)
                    //and that
                    //sum{b[i]} is the smallest (i= 1 to NUMBER)
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
                    total=oo;
                    for (b[1]=0;(b[1]<=100)&&(b[1]<=total);b[1]++)
                        for (b[2]=0;(b[2]<=100)&&(b[2]<=total-b[1]);b[2]++)
                            for (b[3]=0;(b[3]<=100)&&(b[3]<=total-b[1]-b[2]);b[3]++)
                            {
                                nb[1]=b[1]*a[1][1]+b[2]*a[2][1]+b[3]*a[3][1];
                                nb[2]=b[1]*a[1][2]+b[2]*a[2][2]+b[3]*a[3][2];
                                nb[3]=b[1]*a[1][3]+b[2]*a[2][3]+b[3]*a[3][3];
                                //cout<<nb[1]<<" "<<nb[2]<<" "<<nb[3]<<endl;
                                
                                bool get=true;
                                for (int i=1;i<=TYPE;i++)
                                {
                                    if ((a[0][i]==0)&&(nb[i]==0)) ;//do nothing
                                    else if ((a[0][i]!=0)&&(nb[i]==0)) get=false;
                                    else if ((a[0][i]==0)&&(nb[i]!=0)) get=false;
                                    else if(nb[i]%a[0][i]!=0) get=false;
                                }
                                if (get)
                                {
                                   for (int i=1;i<TYPE;i++)
                                   {
                                       if ((a[0][i]==0)||(a[0][i+1]==0)) ;//do nothing
                                       else if (nb[i]/a[0][i]!=nb[i+1]/a[0][i+1]) get=false;
                                   }
                                }
                                if (get&&(total>nb[1]+nb[2]+nb[3]))
                                {
                                   for (int i=1;i<=TYPE;i++)
                                       if (a[0][i]!=0)
                                          ab[0]=nb[i]/a[0][i];
                                   for (int i=1;i<=NUMBER;i++)
                                       ab[i]=b[i];
                                   total=nb[1]+nb[2]+nb[3];
                                }
                            }
                    if (total==oo)
                       cout<<"NONE"<<endl;
                    else
                    {
                        for (int i=1;i<=NUMBER;i++)
                            cout<<ab[i]<<" ";
                        cout<<ab[0]<<endl;
                    }
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
