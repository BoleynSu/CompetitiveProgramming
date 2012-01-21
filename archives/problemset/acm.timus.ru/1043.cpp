/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-25
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::stringstream;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <set>
using std::set;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;
#include <cmath>
using std::sqrt;
using std::floor;
using std::ceil;

template<typename Type>
class Function
{
      int n;
      vector<vector<Type> > matrix;
      vector<Type> answer;
      static Type abs(Type a)
      {
             return a>=0?a:-a;
      }
      void smaller(int step)
      {
           for (int i=step+1;i<n;i++)
               if (abs(matrix[i][step])>abs(matrix[step][step]))
                  matrix[step].swap(matrix[i]);
           for (int i=step+1;i<n;i++)
           {
               Type mul=matrix[i][step];
               Type div=matrix[step][step];
               for (int j=step;j<=n;j++)
                   matrix[i][j]-=matrix[step][j]*mul/div;
           }
      }
      void back(int step)
      {
           if (step==n-1)
              answer[step]=matrix[step][n]/matrix[step][step];
           else
           {
               answer[step]=matrix[step][n];
               for (int i=step+1;i<n;i++)
                   answer[step]-=matrix[step][i]*answer[i];
               answer[step]/=matrix[step][step];
           }
      }
      public:
      void read(vector<vector<Type> >& get)
      {
           n=get.size();
           matrix=get;
           answer.resize(get.size());
      }
      void solve()
      {
           for (int i=0;i<n-1;i++) smaller(i);
           for (int i=n-1;i>=0;i--) back(i);
      }
      void write(vector<Type>& put)
      {
           put=answer;
      }
};

class Application
{
      static const int POINTNUMBER=3;
      static const int oo=1000;
      vector<pair<int,int> > p;
      double cross(double x1,double y1,double x2,double y2,double x3,double y3)
      {
             /*
                  1-----------2
                 /
                /
               /
              3
              return 1->2 X 1->3
             */
             double dx12=x2-x1,dy12=y2-y1,
                    dx13=x3-x1,dy13=y3-y1;
             return dx12*dy13-dx13*dy12;
      }
      bool sameside(double x1,double y1,double x2,double y2,
                    double px1,double py1,double px2,double py2)
      {
           return cross(x1,y1,x2,y2,px1,py1)*cross(x1,y1,x2,y2,px2,py2)>0;
      }
      public:
      Application()
                   :p(POINTNUMBER)
      {
                   for (int i=0;i<POINTNUMBER;i++)
                       cin>>p[i].first>>p[i].second;
      }
      int run()
      {
          vector<vector<double> > v(POINTNUMBER,vector<double>(POINTNUMBER+1));
          Function<double> f;
          vector<double> answer;
          for (int i=0;i<POINTNUMBER;i++)
          {
              //x^2+y^2+Cx+Dy+E=0
              //x y 1 (-x^2-y^2) 
              v[i][0]=p[i].first;
              v[i][1]=p[i].second;
              v[i][2]=1;
              v[i][3]=-(p[i].first*p[i].first+p[i].second*p[i].second);
          }
          f.read(v);
          f.solve();
          f.write(answer);
          //C=answer[0]
          //D=answer[1]
          //E=answer[2]
          //(x+C/2)^2+(y+D/2)^2=(C^2+D^2)/4-E
          //O(-C/2,-D/2) R=sqrt((C^2+D^2)/4-E) 
          double C=answer[0],
                 D=answer[1],
                 E=answer[2];
          double Ox=-C/2,
                 Oy=-D/2,
                 R=sqrt((C*C+D*D)/4-E);
          /*
          圆心O; 起点S; 终点E; 中间过M 
                          O-----------S
                         / \
                        /   \
                       /     \
                      /       \
                     /         \
                    E           M
          */
          double Sx=p[0].first,Sy=p[0].second,
                 Ex=p[1].first,Ey=p[1].second,
                 Mx=p[2].first,My=p[2].second;
          int t=-oo,b=oo,l=oo,r=-oo;
          #define line(x1,y1,x2,y2) x1,y1,x2,y2
          #define point(x,y) x,y
          #define ZERO 0.0000001
          #define update(x,y)\
          {\
                  double X=x,Y=y;\
                  if (floor(X+ZERO)<l) l=floor(X+ZERO);\
                  if (ceil(X-ZERO)>r) r=ceil(X-ZERO);\
                  if (floor(Y+ZERO)<b) b=floor(Y+ZERO);\
                  if (ceil(Y-ZERO)>t) t=ceil(Y-ZERO);\
          }
          #define check_and_update(X,Y)\
          if (sameside(line(Sx,Sy,Ex,Ey),point(Mx,My),point(X,Y)))\
             update(X,Y);
          update(Sx,Sy);
          update(Ex,Ey);
          update(Mx,My);
          check_and_update(Ox+R,Oy);
          check_and_update(Ox-R,Oy);
          check_and_update(Ox,Oy+R);
          check_and_update(Ox,Oy-R);
          #undef check_and_update
          #undef update
          #undef ZERO
          #undef point
          #undef line
          if (r>oo) r=oo;
          if (l<-oo) l=-oo;
          if (t>oo) t=oo;
          if (b<-oo) b=-oo;
          cout<<(r-l)*(t-b)<<endl; 
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
