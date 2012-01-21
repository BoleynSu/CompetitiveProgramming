/*
ID: sujiao1
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
#include <cassert>
#include <stdio.h>

//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);

std::ifstream cin("rect1.in");
std::ofstream cout("rect1.out");

struct Point
{
       int x,y;
       Point():x(0),y(0){}
       Point& read()
       {
              cin>>x>>y;
              return *this;
       }
       Point& print()
       {
              cout<<"Point("<<x<<","<<y<<")"<<endl;
       }
       Point& operator ()(int nx,int ny)
       {
              x=nx;
              y=nx;
              return *this;
       }
};
struct Rectangle
{
       Point a,b;
       int color;
       Rectangle():color(1){}
       Rectangle& read()
       {
                  a.read();
                  b.read();
                  cin>>color;
       }
       Rectangle& print()
       {
                  cout<<"Rectangle:"<<endl;
                  a.print();
                  b.print();
                  cout<<"color:"<<color<<endl;
       }
       Rectangle& operator ()(Point& na,Point& nb)
       {
                  a=na;
                  b=nb;
                  return *this;
       }
};
struct Program
{
       static const int MAXN=1000;//1 to 1000
       static const int MAXA=10000;//1 to 10000
       static const int MAXCOLOR=2500;//1 to 2500
       int A,B;
       int N;
       Rectangle rec[MAXN+2];
       int x[MAXN*2+2];
       int y[MAXN*2+2];
       int bx[MAXA*2+2];
       int by[MAXA*2+2];
       int xlen,ylen;
       bool** box;
       short** next;
       int answer[MAXN+2];
       Program()
       {
                rec[0].b.read();
                cin>>N;
                for (int i=1;i<=N;i++)
                    rec[i].read();
                init();
       }
       int init()
       {
           for (int i=0;i<=MAXN;i++) answer[i]=0;
           for (int i=0;i<=rec[0].b.x;i++) bx[i]=false;
           for (int i=0;i<=rec[0].b.y;i++) by[i]=false;
           
           for (int i=0;i<=N;i++)
           {
               bx[rec[i].a.x]
               =bx[rec[i].b.x]
               =by[rec[i].a.y]
               =by[rec[i].b.y]
               =true;
           }
           
           xlen=0;
           ylen=0;
           for (int i=0;i<=rec[0].b.x;i++)
               if (bx[i])
               {
                  x[++xlen]=i;
                  bx[i]=xlen;
               }
           for (int i=0;i<=rec[0].b.y;i++)
               if (by[i])
               {
                  y[++ylen]=i;
                  by[i]=ylen;
               }
           
           box=new bool*[xlen+2];
           for (int i=1;i<=xlen;i++)
               box[i]=new bool[ylen+2];
           next=new short*[xlen+2];
           for (int i=1;i<=xlen;i++)
               next[i]=new short[ylen+2];
           
           for (int i=1;i<xlen;i++)
               for (int j=1;j<ylen;j++)
               {
                   box[i][j]=true;
                   next[i][j]=j+1;
               }
       }
       int run()
       {
           //for (int i=0;i<=N;i++) rec[i].print();
                      
           for (int k=N;k>=0;k--)
           {
               for (int i=bx[rec[k].a.x],ex=bx[rec[k].b.x];i<ex;i++)
               {
                   int j=by[rec[k].a.y],ey=by[rec[k].b.y];
                   for (;j<ey;)
                   {
                       if (box[i][j])
                       {
                          answer[rec[k].color]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                          box[i][j]=false;
                       }
                   int backupj=j;
                   j=next[i][j];
                   next[i][backupj]=ey;
                   }
               }
           }
           
           for (int i=0;i<=MAXN;i++)
               if (answer[i]) cout<<i<<" "<<answer[i]<<endl;
           
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
//force version
/*
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
#include <cassert>
#include <stdio.h>

//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);

std::ifstream cin("rect1.in");
std::ofstream cout("rect1.out");

struct Point
{
       int x,y;
       Point():x(0),y(0){}
       Point& read()
       {
              cin>>x>>y;
              return *this;
       }
       Point& print()
       {
              cout<<"Point("<<x<<","<<y<<")"<<endl;
       }
       Point& operator ()(int nx,int ny)
       {
              x=nx;
              y=nx;
              return *this;
       }
};
struct Rectangle
{
       Point a,b;
       int color;
       Rectangle():color(1){}
       Rectangle& read()
       {
                  a.read();
                  b.read();
                  cin>>color;
       }
       Rectangle& print()
       {
                  cout<<"Rectangle:"<<endl;
                  a.print();
                  b.print();
                  cout<<"color:"<<color<<endl;
       }
       Rectangle& operator ()(Point& na,Point& nb)
       {
                  a=na;
                  b=nb;
                  return *this;
       }
};
struct Program
{
       static const int MAXN=1000;//1 to 1000
       static const int MAXA=10000;//1 to 10000
       static const int MAXCOLOR=2500;//1 to 2500
       int A,B;
       int N;
       Rectangle rec[MAXN+2];
       int x[MAXN*2+2];
       int y[MAXN*2+2];
       int bx[MAXA*2+2];
       int by[MAXA*2+2];
       int xlen,ylen;
       int** box;
       int answer[MAXN+2];
       Program()
       {
                rec[0].b.read();
                cin>>N;
                for (int i=1;i<=N;i++)
                    rec[i].read();
                init();
       }
       int init()
       {
           for (int i=0;i<=MAXN;i++) answer[i]=0;
           for (int i=0;i<=rec[0].b.x;i++) bx[i]=false;
           for (int i=0;i<=rec[0].b.y;i++) by[i]=false;
           
           for (int i=0;i<=N;i++)
           {
               bx[rec[i].a.x]
               =bx[rec[i].b.x]
               =by[rec[i].a.y]
               =by[rec[i].b.y]
               =true;
           }
           
           xlen=0;
           ylen=0;
           for (int i=0;i<=rec[0].b.x;i++)
               if (bx[i])
               {
                  x[++xlen]=i;
                  bx[i]=xlen;
               }
           for (int i=0;i<=rec[0].b.y;i++)
               if (by[i])
               {
                  y[++ylen]=i;
                  by[i]=ylen;
               }
           
           box=new int*[xlen+2];
           for (int i=1;i<=xlen;i++)
               box[i]=new int[ylen+2];
           //for (int i=1;i<=xlen;i++) cout<<x[i]<<" ";cout<<endl;
           //for (int i=1;i<=ylen;i++) cout<<y[i]<<" ";cout<<endl;
           for (int i=1;i<xlen;i++)
           {
               for (int j=1;j<ylen;j++)
               {
                   box[i][j]=(x[i+1]-x[i])*(y[j+1]-y[j]);
                   //cout<<box[i][j]<<"\t";
               }
               //cout<<endl;
           }
       }
       int run()
       {
           //for (int i=0;i<=N;i++) rec[i].print();
           
           //cout<<clock()<<endl;
           
           for (int k=N;k>=0;k--)
           {
               for (int i=bx[rec[k].a.x],ex=bx[rec[k].b.x];i<ex;i++)
                   for (int j=by[rec[k].a.y],ey=by[rec[k].b.y];j<ey;j++)
                       if (box[i][j])
                       {
                          answer[rec[k].color]+=box[i][j];
                          box[i][j]=false;
                       }
           }
           
           for (int i=0;i<=MAXN;i++)
               if (answer[i]) cout<<i<<" "<<answer[i]<<endl;
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
*/
