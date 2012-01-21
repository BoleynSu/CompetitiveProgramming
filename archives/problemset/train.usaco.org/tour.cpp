/*
ID: sujiao1
PROG: tour
LANG: C++
*/
/*
PROGRAM: tour
AUTHOR: Su Jiao
DATE: 2010-1-18
DESCRIPTION:
你赢得了一场航空公司举办的比赛，奖品是一张加拿大环游机票。旅行在这家航空公司开放
的最西边的城市开始，然后一直自西向东旅行，直到你到达最东边的城市，再由东向西返
回，直到你回到开始的城市。除了旅行开始的城市之外，每个城市只能访问一次，因为开始
的城市必定要被访问两次（在旅行的开始和结束）。 
当然不允许使用其他公司的航线或者用其他的交通工具。 
给出这个航空公司开放的城市的列表，和两两城市之间的直达航线列表。找出能够访问尽可
能多的城市的路线，这条路线必须满足上述条件，也就是从列表中的第一个城市开始旅行，
访问到列表中最后一个城市之后再返回第一个城市。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <string>
using std::string;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=100;
      static const int oo=MAXN;
      int N,V;
      string city[MAXN+2];
      bool map[MAXN+2][MAXN+2];
      int f[MAXN+2][MAXN+2];
      int answer;
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        memset(map,false,sizeof(map));
                        cin>>N>>V;
                        for (int i=1;i<=N;i++)
                            cin>>city[i];
                        for (int i=1;i<=V;i++)
                        {
                            string a,b;
                            int ida,idb;
                            cin>>a>>b;
                            for (int i=1;i<=N;i++)
                            {
                                if (city[i]==a) ida=i;
                                if (city[i]==b) idb=i;
                            }
                            map[ida][idb]=map[idb][ida]=true;
                        }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int max(int a,int b)
      {
          return a>b?a:b;
      }
      int run()
      {
          f[1][1]=1;
          for (int i=1;i<=N;i++)
              for (int j=i+1;j<=N;j++)
              {
                  f[i][j]=-oo;
                  for (int k=1;k<j;k++)
                      if (map[k][j]&&f[i][k]>0)
                         f[i][j]=max(f[i][j],f[i][k]+1);
                  f[j][i]=f[i][j];
                  //cout<<"f["<<i<<","<<j<<"]="<<f[i][j]<<endl;
              }
          answer=-oo;
          for (int i=1;i<N;i++)
              if (map[i][N])
                 answer=max(answer,f[i][N]);
          if (answer<2) answer=1;
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app("tour.in","tour.out");
    return app.run();
}
