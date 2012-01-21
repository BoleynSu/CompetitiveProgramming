/*
ID: sujiao1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("cowtour.in");
std::ofstream cout("cowtour.out");

struct Program
{
       static const int MAXN=150;//1 to 150
       static const int MAXXY=100000;//0 to 100000
       static const double oo=MAXXY*2*MAXN;
       struct Point{int x,y;};
       int N;
       Point f[MAXN+2];
       double map[MAXN+2][MAXN+2];
       int block;
       int mark[MAXN+2];//mark[i]=j means i belongs to block j
       double maxDistanceToCore[MAXN+2];//maxDistanceToCore[i]=map[i][j]
                                        //that mark[j]=mark[i]
                                        //and not exist k!=j that mark[k]=mark[i]
                                        //and map[i][k]>map[i][j]
       double diameter[MAXN+2];//diameter[b]=map[i][j]
                               //that mark[i]=mark[j]=b
                               //and not exist n,m that n,m is not same as i,j
                               //and mark[n]=mark[m]=b
                               //and map[n][m]>map[i][j]
       double answer;
       Program()//debuged
       {
                cin>>N;
                for (int i=1;i<=N;i++)
                {
                    cin>>f[i].x>>f[i].y;
                    //cout<<f[i].x<<" "<<f[i].y<<endl;
                }
                for (int i=1;i<=N;i++)
                {
                    cin.get();
                    for (int j=1;j<=N;j++)
                    {
                        bool connect;
                        connect=(cin.get()=='1');
                        //cout<<connect;
                        if (i==j)
                           map[i][j]=0;
                        else if (connect==1)
                           map[i][j]=distance(i,j);
                        else
                            map[i][j]=oo;
                        //cout<<map[i][j]<<"\t";
                    }
                    //cout<<endl;
                }
                /*
                cout<<"BEGIN INIT:\n";
                for (int i=1;i<=N;i++)
                {
                    for (int j=1;j<=N;j++)
                    {
                        cout<<map[i][j]<<"\t";
                        if (map[i][j]!=map[j][i]) cout<<"alert!\n";
                    }
                    cout<<endl;
                }
                cout<<"END INIT;\n";
                */
       }
       inline
       double distance(int a,int b)
       {
              //cout<<f[a].x<<" "<<f[a].y<<","<<f[b].x<<" "<<f[b].y<<"="<<sqrt((double)((f[a].x-f[b].x)*(f[a].x-f[b].x)+(f[a].y-f[b].y)*(f[a].y-f[b].y)))<<endl;
              return sqrt((double)((f[a].x-f[b].x)*(f[a].x-f[b].x)+(f[a].y-f[b].y)*(f[a].y-f[b].y)));
       }
       int floyd()
       {
           for (int j=1;j<=N;j++)
               for (int i=1;i<=N;i++)// if (j!=i)
                   for (int k=1;k<=N;k++)// if (k!=i&&k!=j)
                       if (map[i][j]+map[j][k]<map[i][k])
                          map[i][k]=map[i][j]+map[j][k];
           /*
           cout<<"BEGIN Floyd:\n";
           for (int i=1;i<=N;i++)
           {
               for (int j=1;j<=N;j++)
               {
                   cout<<int(map[i][j]/100)<<"\t";
                   //if (map[i][j]!=map[j][i]) cout<<"alert!\n";
               }
               cout<<endl;
           }
           cout<<"END Floyd;\n";
           */
           return 0;
       }
       int findBlock()
       {
           block=0;
           for (int i=1;i<=N;i++)
               mark[i]=0;
           for (int i=1;i<=N;i++)
           {
               if (mark[i]==0)
               {
                  //cout<<i<<" "<<mark[i]<<"mark\n";
                  block++;
                  mark[i]=block;
                  int j=i+1;
                  //for (int k=1;k<=N;k++) cout<<map[i][k]<<" ";cout<<endl;
                  while (j<=N)
                  {
                        //if (mark[j]!=0) cout<<j<<" "<<map[i][j]<<"alert!\n";
                        if ((map[i][j]<oo)&&(mark[j]==0))
                           mark[j]=block;
                        j++;
                  }
               }
           }
           /*
           cout<<"BEGIN findBlock():\n";
           for (int i=1;i<=N;i++)
               cout<<i<<" "<<mark[i]<<endl;
           cout<<"END findBlock();\n";
           */
           return 0;
       }
       inline
       double max(double a,double b)
       {
              return a>b?a:b;
       }
       int findCore()
       {
           for (int i=1;i<=block;i++)
               diameter[i]=0;
           for (int i=1;i<=N;i++)
               maxDistanceToCore[i]=0;
           for (int i=1;i<=N;i++)
               for (int j=i+1;j<=N;j++)
                   if (mark[i]==mark[j])
                   {
                      if (map[i][j]>diameter[mark[i]])
                         diameter[mark[i]]=map[i][j];
                      if (map[i][j]>maxDistanceToCore[i])
                         maxDistanceToCore[i]=map[i][j];
                      if (map[i][j]>maxDistanceToCore[j])
                         maxDistanceToCore[j]=map[i][j];
                   }
           /*
           cout<<"BEGIN findCore():\n";
           for (int i=1;i<=block;i++)
               cout<<diameter[i]<<"\t";
           cout<<"\n=================\n";
           for (int i=1;i<=N;i++)
           {
               //if (mark[i]==1) cout<<i<<"alert!\n";
               cout<<maxDistanceToCore[i]<<"\t";
           }
           cout<<"\nEND findCore();\n";
           */
           return 0;
       }
       double max(double a,double b,double c)
       {
              if (b>a) a=b;
              if (c>a) a=c;
              return a;
       }
       int findMinNewDiameter()
       {
           answer=oo;
           //mark[1] must be 1
           for (int i=1;i<=N;i++)
               for (int j=i+1;j<=N;j++)
                   if (mark[j]>mark[i])
                   {
                      double got= max(
                                  maxDistanceToCore[i]
                                  +distance(i,j)
                                  +maxDistanceToCore[j],
                                  diameter[mark[i]],
                                  diameter[mark[j]]);
                      if (got<answer)
                      {
                         answer=got;
                         //cout<<got<<" "<<mark[i]<<" "<<mark[j]<<"d:"<<distance(i,j)<<endl;
                      }
                   }
           long long int answerInt=(long long int)(answer*10000000);
           cout<<answerInt/10000000<<".";
           long long int answerInt2=(answerInt/10)%1000000+(answerInt%10>=5);
           for (int k=100000;k>=1;k/=10)
               cout<<(answerInt2/k)%10;
           cout<<endl;
           return 0;
       }
       int run()
       {
           floyd();
           findBlock();
           findCore();
           findMinNewDiameter();
           //cout<<clock()<<endl;
           return 0;
       }
};

#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
