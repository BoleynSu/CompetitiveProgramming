/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-11 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
//using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <cassert>
//using std::assert;

class Application
{
      typedef unsigned char uc;
      static const int W=50,H=20;
      static const uc LU=218,//Left upper corner
                      RU=191,//Right upper corner
                      LB=192,//Left bottom corner
                      RB=217,//Right bottom corner
                      VE=179,//Vertical (left and right) border line
                      HO=196,//Horizontal (top and bottom) border line
                      DO=46,//Dot
                      CO=0;//Cover
      uc pic[H][W];
      public:
      Application() 
      {
                    for (int i=0;i<H;i++)
                        for (int j=0;j<W;j++)
                            cin>>pic[i][j];
      }
      int run()
      {
          bool update=true;
          stack<pair<pair<int,int>,int> > answer;
          while (update)
          {
                /*
                cout<<"updating..."<<endl;
                for (int x=0;x<H;x++)
                {
                    for (int y=0;y<W;y++)
                    {
                        switch(pic[x][y])
                        {
                                         case LU:cout<<'/';break;
                                         case RU:cout<<'\\';break;
                                         case LB:cout<<'\\';break;
                                         case RB:cout<<'/';break;
                                         case VE:cout<<'|';break;
                                         case HO:cout<<'-';break;
                                         case DO:cout<<'.';break;
                                         case CO:cout<<' ';break;
                        }
                    }
                    cout<<endl;
                }
                */
                update=false;
                for (int x=0;x<H;x++)
                    for (int y=0;y<W;y++)
                        if (pic[x][y]==CO||pic[x][y]==LU)
                           for (int a=2;a<=H;a++)
                               if ((pic[x+a-1][y]==CO||pic[x+a-1][y]==LB)
                                  &&(pic[x][y+a-1]==CO||pic[x][y+a-1]==RU)
                                  &&(pic[x+a-1][y+a-1]==CO||pic[x+a-1][y+a-1]==RB))
                               {
                                  #define impossibleHO(x,y) ((x>=H)or(y>=W)or((pic[x][y]!=CO)&&(pic[x][y]!=HO)))
                                  #define impossibleVE(x,y) ((x>=H)or(y>=W)or((pic[x][y]!=CO)&&(pic[x][y]!=VE)))
                                  bool ispossible=true;
                                  bool L=false,R=false,U=false,B=false;
                                  
                                  if (pic[x][y]==LU) L=U=true;
                                  if (pic[x+a-1][y]==LB) L=B=true;
                                  if (pic[x][y+a-1]==RU) R=U=true;
                                  if (pic[x+a-1][y+a-1]==RB) R=B=true;
                                  
                                  for (int i=1;i<a-1;i++)
                                  {
                                      if (impossibleHO(x,y+i) 
                                         ||impossibleHO(x+a-1,y+i)
                                         ||impossibleVE(x+i,y)
                                         ||impossibleVE(x+i,y+a-1))
                                      {
                                         ispossible=false;
                                         break;
                                      }
                                      if (pic[x][y+i]==HO) U=true;
                                      if (pic[x+a-1][y+i]==HO) B=true;
                                      if (pic[x+i][y]==VE) L=true;
                                      if (pic[x+i][y+a-1]==VE) R=true;
                                  }
                                  #define cover(x,y) pic[x][y]=CO;
                                  if (ispossible&&(L||R||U||B))
                                  {
                                     for (int i=0;i<a;i++)
                                     {
                                         cover(x,y+i);
                                         cover(x+a-1,y+i);
                                         cover(x+i,y);
                                         cover(x+i,y+a-1);
                                     }
                                     update=true;
                                     answer.push(make_pair(make_pair(y,x),a));
                                     //cout<<y<<" "<<x<<" "<<a<<endl;
                                  }
                                  #undef impossibleHO
                                  #undef impossibleVE
                                  #undef cover
                               }
          }
          cout<<answer.size()<<endl;
          while (!answer.empty())
          {
                cout<<answer.top().first.first<<" "
                    <<answer.top().first.second<<" "
                    <<answer.top().second<<endl;
                answer.pop();
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
