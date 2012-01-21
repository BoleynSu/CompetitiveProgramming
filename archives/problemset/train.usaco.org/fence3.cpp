/*
ID: sujiao1
PROG: fence3
LANG: C++
*/
/*
PROGRAM: fence3
AUTHOR: Su Jiao
DATE: 2009-12-27
DESCRIPTION:
农夫约翰已经决定建造电网。他已经把他的农田围成一些奇怪的形状，现在必须找出安放
电源的最佳位置。 
对于段电网都必须从电源拉出一条电线。电线可以穿过其他电网或者跨过其他电线。电线能
够以任意角度铺设，从电源连接到一段电网的任意一点上（也就是，这段电网的端点上或者
在其之间的任意一点上）。这里所说的“一段电网”指的是呈一条线段状的电网，并不是连
在一起的几段电网。若几段电网连在一起，那么也要分别给这些电网提供电力。 
已知所有的 F（1 <= F <= 150）段电网的位置（电网总是和坐标轴平行，并且端点的坐标
总是整数，0 <= X,Y <= 100）。你的程序要计算连接电源和每段电网所需的电线的最小总
长度，还有电源的最佳坐标。 
电源的最佳坐标可能在农夫约翰的农田中的任何一个位置，并不一是整数。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
//TODO FINISH IT!
//Geometry Lib
#include <cmath>
#include <iostream>
using std::abs;
using std::sqrt;
using std::cout;
namespace Geometry
{
          template<class type>
          struct Point;
          template<class type>
          struct Segment;
          template<class type>
          struct Point
          {
                 type x,y,z;
                 Point(const type& _x=0,const type& _y=0,const type& _z=0):x(_x),y(_y),z(_z){}
                 Point<type>& set_by1segment(const Segment<type>& seg)
                 {
                              this->x=seg.b.x-seg.a.x;
                              this->y=seg.b.y-seg.a.y;
                              this->z=seg.b.z-seg.a.z;
                              return *this;                            
                 }
          };
          template<class type>
          struct Segment
          {
                 Point<type> a,b;
                 Segment(){}
                 Segment(const Point<type>& _a,const Point<type>& _b):a(_a),b(_b){}
                 Segment<type>& set_by2point(const Point<type>& _a,const Point<type>& _b)
                 {
                          a=_a;
                          b=_b;
                          return *this;
                 }
                 Point<type> to_point() const
                 {
                             Point<type> p;
                             p.set_by1segment(*this);
                             return p;
                 }
          };
          //BEGIN MIN / MAX
          template<class type>
          type min(const type& a,const type& b)
          {
               return a<b?a:b;
          }
          template<class type>
          type max(const type& a,const type& b)
          {
               return a>b?a:b;
          }
          //END MIN / MAX
          
          template<class type>
          inline
          double distance(const Point<type>& a,const Segment<type>& bc)
          {
               double ret;
               if (bc.a.y==bc.b.y)
               {
                  type _min=min(bc.a.x,bc.b.x);
                  type _max=max(bc.a.x,bc.b.x);
                  if (a.x<=_min)
                     /*return */ret=sqrt((a.x-_min)*(a.x-_min)+(a.y-bc.a.y)*(a.y-bc.a.y));
                  else if (a.x>=_max)
                     /*return */ret=sqrt((a.x-_max)*(a.x-_max)+(a.y-bc.a.y)*(a.y-bc.a.y));
                  else
                      /*return */ret=abs(bc.a.y-a.y);
               }
               else
               {
                  type _min=min(bc.a.y,bc.b.y);
                  type _max=max(bc.a.y,bc.b.y);
                  if (a.y<=_min)
                     /*return */ret=sqrt((a.y-_min)*(a.y-_min)+(a.x-bc.a.x)*(a.x-bc.a.x));
                  else if (a.y>=_max)
                     /*return */ret=sqrt((a.y-_max)*(a.y-_max)+(a.x-bc.a.x)*(a.x-bc.a.x));
                  else
                      /*return */ret=abs(bc.a.x-a.x);
               }
               return ret;
          }
          //END DISTANCE
}
using namespace Geometry;

#include <ctime>
using std::clock;
class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXF=150;
      static const int oo=1024*1024*1024;
      typedef int datatype;
      typedef float answertype;
      typedef Segment<datatype> segment;
      typedef Point<datatype> point;
      int F;
      segment f[MAXF+2];
      point answerp;
      answertype answer;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),answer(oo)
      {
                              cin>>F;
                              for (int i=1;i<=F;i++)
                              {
                                  cin
                                  >>f[i].a.x>>f[i].a.y
                                  >>f[i].b.x>>f[i].b.y;
                                  f[i].a.x*=10;
                                  f[i].a.y*=10;
                                  f[i].b.x*=10;
                                  f[i].b.y*=10;
                              }
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
          point p;
          answertype outanswer=oo;
          for (p.x=0;p.x<=1000;p.x+=10)
              for (p.y=0;p.y<=1000;p.y+=10)
              {
                  answertype nanswer=0;
                  for (int i=1;(i<=F)&&(nanswer<=outanswer);i++)
                      nanswer+=distance(p,f[i]);
                  
                  if (nanswer<=outanswer)
                  {
                     outanswer=nanswer;
                                          
                     point q;
                     for (q.x=p.x;q.x<=p.x+10;q.x++)
                         for (q.y=p.y;q.y<=p.y+10;q.y++)
                         {
                             answertype nanswer=0;
                             for (int i=1;(i<=F)&&(nanswer<answer);i++)
                                 nanswer+=distance(q,f[i]);
                             if (nanswer<answer)
                             {
                                answer=nanswer;
                                answerp.x=q.x;
                                answerp.y=q.y;
                             }
                         }
                  }
                  //cout<<answerp.x<<" "<<answerp.y<<" "<<answer<<endl;
              }
          if (int(answer*10)%10>=5)
             answer+=1;
          
          cout
          <<int(answerp.x/10)<<"."<<int(answerp.x)%10<<" "
          <<int(answerp.y/10)<<"."<<int(answerp.y)%10<<" "
          <<int(answer/10)<<"."<<(int(answer)%10)<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app("fence3.in","fence3.out");
    return app.run();
}
