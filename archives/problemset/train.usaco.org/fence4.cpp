/*
ID: sujiao1
PROG: fence4
LANG: C++
*/
/*
PROGRAM: fence4
AUTHOR: Su Jiao
DATE: 2009-12-24
DESCRIPTION:
ÂÔ 
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
using std::abs;
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
          
          //BEGIN BASIC 
          template<class type>
          Point<type> cross(const Point<type>& a,const Point<type>& b)
          {
                      //i   j   k
                      //a.x a.y a.z
                      //b.x b.y b.z
                      Point<type> c;
                      c.x=a.y*b.z-a.z*b.y;
                      c.y=a.z*b.x-a.x*b.z;
                      c.z=a.x*b.y-a.y*b.x;
                      return c;
          }
          
          template<class type>
          type dot(const Point<type>& a,const Point<type>& b)
          {
               type c=a.x*b.x+a.y*b.y+a.z*b.z;
               return c;
          }
          
          template<class type>
          int sign(type n)
          {
              static const double o=0.000001;
              if (abs(n)<=o) return 0;
              return n>0?1:-1;
          }
          //END BASIC
          
          //BEGIN INTERSECT
          template<class type>
          int _intersect(const Segment<type>& a,const Segment<type>& b)
          {
              const Point<type>& A(a.a);
              const Point<type>& B(a.b);
              const Point<type>& C(b.a);
              const Point<type>& D(b.b);
              Segment<type> AB(A,B),AC(A,C),AD(A,D),BC(B,C),BD(B,D),CD(C,D);
              type c1,c2,c3,c4;
              c1=cross(AB.to_point(),AC.to_point()).z;
              c2=cross(AB.to_point(),AD.to_point()).z;
              c3=cross(CD.to_point(),AD.to_point()).z;
              c4=cross(CD.to_point(),BD.to_point()).z;
              type d1,d2,d3,d4;
              int counter=0;
              d1=dot(AC.to_point(),BC.to_point());
              d2=dot(AD.to_point(),BD.to_point());
              d3=dot(AC.to_point(),AD.to_point());
              d4=dot(BC.to_point(),BD.to_point());
              //CASE 1 
              // AB AND CD = E
              // E!=A|B|C|D
              if ((sign(c1)*sign(c2)<0)&&(sign(c3)*sign(c4)<0))
                 return 1;              
              
              if ((sign(c1)==0)&&(sign(d1)<=0)) counter++;
              if ((sign(c2)==0)&&(sign(d2)<=0)) counter++;
              if ((sign(c3)==0)&&(sign(d3)<=0)) counter++;
              if ((sign(c4)==0)&&(sign(d4)<=0)) counter++;
              
              //CASE 2
              // AB AND CD = E
              // E=A|B|C|D 
              if (counter==1)
                    return 2;
              //CASE 3
              // AB AND CD = EF
              // {E,F} IS A SUBSET OF {A,B,C,D}
              if (counter>1)
                 return 3;
              
              //CASE 0
              // AN AND CD =EMPTY
              return 0;
          }
          template<class type>
          bool intersect(const Segment<type>& a,const Segment<type>& b)
          {
               return (_intersect(a,b)==1);
          }
          
          template<class type>
          Point<type> intersectionPoint(const Segment<type>& a,const Segment<type>& b)
          {
                //E = AB AND CD
                const Point<type>& A(a.a);
                const Point<type>& B(a.b);
                const Point<type>& C(b.a);
                const Point<type>& D(b.b);
                Segment<type> AB(A,B),AC(A,C),AD(A,D),BC(B,C),BD(B,D),CD(C,D);
                type c1,c2;
                c1=cross(AB.to_point(),AC.to_point()).z;
                c2=cross(AB.to_point(),AD.to_point()).z;
                Point<type> E;
                E.x=(-C.x*c2+D.x*c1)/(c1-c2);
                E.y=(-C.y*c2+D.y*c1)/(c1-c2);
                return E;
          }
          //END INTERSECTION
          
          //BEGIN SAMESIDE / BETWEEN
          template<class type>
          int _sameside(const Segment<type>& ab,const Point<type>& c,const Point<type>& d)
          {
             Segment<type> AC(ab.a,c),AD(ab.b,d);
             type c1,c2;
             c1=cross(ab.to_point(),AC.to_point()).z;
             c2=cross(ab.to_point(),AD.to_point()).z;
             return (sign(c1)*sign(c2));
          }
          template<class type>
          bool sameside(const Segment<type>& ab,const Point<type>& c,const Point<type>& d)
          {
              return (_sameside(ab,c,d)>=0);
          }
          template<class type>
          int _between(const Segment<type>& ab,const Point<type>& c)
          {
             Segment<type> AC(ab.a,c),BC(ab.b,c);
             return sign(dot(AC,BC));
          }
          template<class type>
          bool between(const Segment<type>& ab,const Point<type>& c)
          {
              return (_between(ab,c)<=0);
          }
          //END SAMESIDE / BETWEEN
          
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
}
using namespace Geometry;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=200;//3 to 200
      int N;
      typedef double datatype;
      typedef Point<datatype> point;
      typedef Segment<datatype> segment;
      point me;
      point p[MAXN+2];
      segment seg[MAXN+2];
      int counter;
      segment output[MAXN+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),counter(0)
      {
                              cin>>N;
                              cin>>me.x>>me.y;
                              for (int i=1;i<=N;i++)
                                  cin>>p[i].x>>p[i].y;
                              /*
                              cout<<N<<endl;
                              cout<<me.x<<" "<<me.y<<endl;
                              for (int i=1;i<=N;i++)
                                  cout<<p[i].x<<" "<<p[i].y<<endl;
                              */
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      bool check()
      {
           for (int i=1;i<=N;i++)
           {
               if (i!=N)
                  seg[i].set_by2point(p[i],p[i+1]);
               else
                   seg[i].set_by2point(p[1],p[i]);
               for (int j=1;j<i;j++)
                   if (intersect(seg[j],seg[i])) return false;
           }
           if (N>1)
           {
              segment swap=seg[N];
              seg[N]=seg[N-1];
              seg[N-1]=swap;
           }
           return true;
      }
      
      void pp(const point& p,const char* s="\0")
      {
           cout<<s
           <<"("<<p.x<<","<<p.y<<")"<<endl;
      }
      void ps(const segment& now,const char* s="\0")
      {
           cout<<s
           <<"a("<<now.a.x<<","<<now.a.y<<")"
           <<"b("<<now.b.x<<","<<now.b.y<<")"
           <<endl;
      }
      
      void ps2(const segment& now)
      {
           output[++counter]=now;
      }
      int run()
      {
          if (check())
          {
                      for (int i=1;i<=N;i++)
                      {
                          segment now=seg[i];
                          if (now.a.x>now.b.x)
                          {
                             point swap=now.a;
                             now.a=now.b;
                             now.b=swap;
                          }
                          segment cuts[MAXN];
                          int cuts_len=0;
                          bool canBeSeen=true;
                          for (int j=1;j<=N;j++)
                              if (i!=j)
                              {
                                       const segment AB(me,now.a),AC(me,now.b);
                                       //ps(seg[j],"seg[j]:");
                                       //ps(AB,"AB:");
                                       //ps(AC,"AC:");
                                       //pp(intersectionPoint(seg[j],AC),"P");
                                       if (_intersect(seg[j],AB)&&_intersect(seg[j],AC))
                                       {
                                          canBeSeen=false;
                                          break;
                                       }
                                       else if (intersect(seg[j],AB))
                                       {
                                            segment cut;
                                            if (sameside(AB,seg[j].a,now.b))
                                            {
                                               cut.set_by2point(me,seg[j].a);
                                            }
                                            if (sameside(AB,seg[j].b,now.b))
                                            {
                                               cut.set_by2point(me,seg[j].b);
                                            }
                                            now.a=intersectionPoint(cut,now);
                                       }
                                       else if (intersect(seg[j],AC))
                                       {
                                            segment cut;
                                            if (sameside(AC,seg[j].a,now.a))
                                            {
                                               cut.set_by2point(me,seg[j].a);
                                            }
                                            if (sameside(AC,seg[j].b,now.a))
                                            {
                                               cut.set_by2point(me,seg[j].b);
                                            }
                                            //ps(cut,"CUT:");
                                            now.b=intersectionPoint(cut,now);
                                            //cout
                                            //<<i<<" "<<j<<" intersectionPoint:";
                                            //pp(now.b);
                                       }
                                       else
                                       {
                                           //cout<<"before:"<<endl;
                                           //ps(AB);ps(AC);
                                           if (sameside(AB,seg[j].a,now.b)
                                               &&sameside(AB,seg[j].b,now.b)
                                               &&sameside(AC,seg[j].a,now.a)
                                               &&sameside(AC,seg[j].b,now.a)
                                               &&sameside(now,me,seg[j].a)
                                               &&sameside(now,me,seg[j].b))
                                           {
                                               
                                               //cout<<j;
                                               //cout<<"CUT    :"<<endl;
                                               //ps(AB,"AB:");
                                               //ps(AC,"AC:");
                                               //ps(seg[j],"seg[j]:");
                                               
                                               segment cut;
                                               point a,b;
                                               cut.set_by2point(me,seg[j].a);
                                               a=intersectionPoint(cut,now);
                                               cut.set_by2point(me,seg[j].b);
                                               b=intersectionPoint(cut,now);
                                               cuts[++cuts_len].set_by2point(a,b);
                                           }
                                       }
                                       if ((now.a.x>=now.b.x)&&(now.a.y==now.b.y))
                                       {
                                          ps(now);
                                          canBeSeen=false;
                                          break;
                                       }
                              }
                              if (canBeSeen)
                              {
                                 //cout<<i<<"TH:"<<endl;
                                 //ps(now);
                                 //cout<<cuts_len<<endl;
                                 //for (int k=1;k<=cuts_len;k++)
                                 //    ps(cuts[k],"CUT:");
                                 //ps(seg[i],"seg[i]:");
                                 
                                 if (now.a.x!=now.b.x)
                                 {
                                    for (int k=1;k<=cuts_len;k++)
                                        if (cuts[k].a.x>cuts[k].b.x)
                                        {
                                           point swap=cuts[k].a;
                                           cuts[k].a=cuts[k].b;
                                           cuts[k].b=swap;
                                        }
                                    for (int c=1;(c<=cuts_len)&&canBeSeen;c++)
                                        for (int k=1;k<=cuts_len;k++)
                                        {
                                            if ((cuts[k].a.x<=now.a.x)&&(cuts[k].b.x>now.a.x))
                                               now.a.x=cuts[k].b.x;
                                            if ((cuts[k].b.x>=now.b.x)&&(cuts[k].a.x<now.b.x))
                                               now.b.x=cuts[k].a.x;
                                            if (now.a.x>=now.b.x)
                                            {
                                               canBeSeen=false;
                                               break;
                                            }
                                        }
                                 }
                                 else if (now.a.y!=now.b.y)
                                 {
                                     if (now.a.y>now.b.y)
                                     {
                                        point swap=now.a;
                                        now.a=now.b;
                                        now.b=swap;
                                     }
                                     
                                     for (int k=1;k<=cuts_len;k++)
                                         if (cuts[k].a.y>cuts[k].b.y)
                                         {
                                            point swap=cuts[k].a;
                                            cuts[k].a=cuts[k].b;
                                            cuts[k].b=swap;
                                         }
                                     for (int c=1;(c<=cuts_len)&&canBeSeen;c++)
                                         for (int k=1;k<=cuts_len;k++)
                                         {
                                             if ((cuts[k].a.y<=now.a.y)&&(cuts[k].b.y>now.a.y))
                                                now.a.y=cuts[k].b.y;
                                             if ((cuts[k].b.y>=now.b.y)&&(cuts[k].a.y<now.b.y))
                                                now.b.y=cuts[k].a.y;
                                             if (now.a.y>now.b.y)
                                             {
                                                canBeSeen=false;
                                                break;
                                             }
                                         }
                                 }
                                 else canBeSeen=false;
                                 
                                 if ((sign(now.a.x-now.b.x)==0)
                                    &&(sign(now.a.y-now.b.y)==0))
                                    canBeSeen=false;
                                 //ps(now);
                                 if (canBeSeen) ps2(seg[i]);
                              }
                      }
                      cout<<counter<<endl;
                      for (int i=1;i<=counter;i++)
                      {
                          cout
                          <<output[i].a.x<<" "<<output[i].a.y<<" "
                          <<output[i].b.x<<" "<<output[i].b.y<<endl;
                      }
          }
          else cout<<"NOFENCE"<<endl;
          return 0;
      }
};

int main()
{
    Application app("fence4.in","fence4.out");
    return app.run();
}
