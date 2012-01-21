/*
ID: sujiao1
PROG: fence6
LANG: C++
*/
/*
PROGRAM: fence6
AUTHOR: Su Jiao
DATE: 2010-1-2
DESCRIPTION:
农夫布朗的牧场上的篱笆已经失去控制了。它们分成了1~200英尺长的线段。只有在线段的
端点处才能连接两个线段，有时给定的一个端点上会有两个以上的篱笆。结果篱笆形成了一
张网分割了布朗的牧场。布朗想将牧场恢复原样，出于这个考虑，他首先得知道牧场上哪一
块区域的周长最小。布朗将他的每段篱笆从1到N进行了标号（N=线段的总数）。他知道每段
篱笆的有如下属性： 
该段篱笆的长度 
该段篱笆的一端所连接的另一段篱笆的标号 
该段篱笆的另一端所连接的另一段篱笆的标号 
幸运的是，没有篱笆连接它自身。对于一组有关篱笆如何分割牧场的数据，写一个程序来计
算出所有分割出的区域中最小的周长。 
例如，标号1~10的篱笆由下图的形式组成（下面的数字是篱笆的标号）： 
          1
  +---------------+
  |\             /|
 2| \7          / |
  |  \         /  |
  +---+       /   |6
  | 8  \     /10  |
 3|     \9  /     |
  |      \ /      |
  +-------+-------+
      4       5
上图中周长最小的区域是由2，7，8号篱笆形成的。 
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
      static const int MAXN=100;
      static const int MAXNEXT=8;
      static const int oo=512*1024*1024;
      int N;
      int map[MAXN+2][MAXN+2];
      int dist[MAXN+2][MAXN+2];
      bool cross[MAXN+2][MAXN+2][MAXN+2];
      int answer;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>N;
                              
                              for (int i=1;i<=N;i++)
                                  for (int j=1;j<=N;j++)
                                      map[i][j]=(i==j)?0:oo;
                              
                              memset(cross,false,sizeof(cross));
                              for (int i=1;i<=N;i++)
                              {
                                  int id,length,s1,s2;
                                  cin>>id>>length>>s1>>s2;
                                  int next;
                                  int n1[MAXNEXT+2];
                                  int n2[MAXNEXT+2];
                                  for (int j=1;j<=s1;j++)
                                  {
                                      cin>>next;
                                      n1[j]=next;
                                      if (map[id][next]==oo)
                                         map[id][next]=length;
                                      else
                                          map[id][next]+=length;
                                      if (map[next][id]==oo)
                                         map[next][id]=length;
                                      else
                                          map[next][id]+=length;
                                  }
                                  for (int j=1;j<=s1;j++)
                                      for (int k=1;k<=s1;k++)
                                          cross[id][n1[j]][n1[k]]=true;
                                  for (int j=1;j<=s2;j++)
                                  {
                                      cin>>next;
                                      n2[j]=next;
                                      if (map[id][next]==oo)
                                         map[id][next]=length;
                                      else
                                          map[id][next]+=length;
                                      if (map[next][id]==oo)
                                         map[next][id]=length;
                                      else
                                          map[next][id]+=length;
                                  }
                                  for (int j=1;j<=s2;j++)
                                      for (int k=1;k<=s2;k++)
                                          cross[id][n2[j]][n2[k]]=true;
                              }
                              //for (int i=1;i<=N;i++)
                              //{
                              //    for (int j=1;j<=N;j++)
                              //        cout<<map[i][j]<<" ";
                              //    cout<<endl;
                              //}
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int min(int a,int b)
      {
          return a<b?a:b;
      }
      int run()
      {
          for (int i=1;i<=N;i++)
              for (int j=1;j<=N;j++)
                  //cout<<"f["<<i<<","<<j<<"]="<<(
                  dist[i][j]=map[i][j];
                  //)<<endl;
          
          answer=oo;
          for (int k=1;k<=N;k++)
          {
              for (int i=1;i<k;i++)
                  for (int j=i+1;j<k;j++)
                  if (!cross[i][j][k])
                  {
                      //cout<<i<<" "<<j<<" "<<k<<" "<<map[i][k]+map[k][j]+dist[j][i]<<endl;
                      answer=min(answer,map[i][k]+map[k][j]+dist[j][i]);
                  }
              for (int i=1;i<=N;i++)
                  for (int j=1;j<=N;j++)
                      dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
          }
          answer=answer/2;
          cout<<answer<<endl;
          return 0;
      }
};

int main()
{
    Application app("fence6.in","fence6.out");
    return app.run();
}
