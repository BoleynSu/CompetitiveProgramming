/*
ID: sujiao1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::endl;
using std::string;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("ttwo.in");
std::ofstream cout("ttwo.out");

struct Program
{
       static const int MAXD=4;//1 to 4
       static const int MAXN=10;//1 to 10
       char map[MAXN+2][MAXN+2];
       struct Point{int x,y;};
       Point farmer;
       Point cow;
       Point d[MAXD+2];
       bool got[MAXN+2][MAXN+2][MAXN+2][MAXN+2][MAXD+2][MAXD+2];
       Program()
       {
                for (int i=1;i<=MAXN;i++)
                    for (int j=1;j<=MAXN;j++)
                    {
                        cin>>map[i][j];
                        if (map[i][j]=='F')
                        {
                           farmer.x=i;
                           farmer.y=j;
                        }
                        if (map[i][j]=='C')
                        {
                           cow.x=i;
                           cow.y=j;
                        }
                    }
                //up
                d[0].y=0;
                d[0].x=-1;
                //right
                d[1].y=1;
                d[1].x=0;
                //down
                d[2].y=0;
                d[2].x=1;
                //left
                d[3].y=-1;
                d[3].x=0;
                for (int i=1;i<=MAXN;i++)
                    for (int j=1;j<=MAXN;j++)
                        for (int k=1;k<=MAXN;k++)
                            for (int l=1;l<=MAXN;l++)
                                for (int m=0;m<MAXD;m++)
                                    for (int n=0;n<MAXD;n++)
                                        got[i][j][k][l][m][n]=false;
       }
       inline
       void move(Point& who,int& how)
       {
            int x=who.x+d[how].x;
            int y=who.y+d[how].y;
            if ((x<1)||(x>MAXN)||(y<1)||(y>MAXN)||map[x][y]=='*')
               how=(how+1)%MAXD;
            else
            {
                who.x=x;
                who.y=y;
            }
       }
       inline
       bool get(Point& F,Point& C)
       {
            return ((F.x==C.x)&&(F.y==C.y));
       }
       inline
       bool cannot(Point& F,Point& C,int howf,int howc)
       {
            return got[F.x][F.y][C.x][C.y][howf][howc];
       }
       int run()
       {
           /*
           for (int i=1;i<=MAXN;i++)
           {
               for (int j=1;j<=MAXN;j++)
                   cout<<map[i][j];
               cout<<endl;
           }
           cout<<"F:"<<farmer.x<<" "<<farmer.y<<endl;
           cout<<"C:"<<cow.x<<" "<<cow.y<<endl;
           */
           Point F=farmer,C=cow;
           int howf=0;
           int howc=0;
           int counter=0;
           for (;;)
           {
               move(F,howf);
               move(C,howc);
               //cout<<"F:"<<F.x<<" "<<F.y<<endl;
               //cout<<"C:"<<C.x<<" "<<C.y<<endl;
               counter++;
               if (get(F,C)) 
               {
                  cout<<counter<<endl;
                  break;
               }
               if (cannot(F,C,howf,howc))
               {
                  cout<<0<<endl;
                  break;
               }
               got[F.x][F.y][C.x][C.y][howf][howc]=true;
           }
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
