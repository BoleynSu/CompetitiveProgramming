/*
ID: sujiao1
PROG: fc
LANG: C++
*/
/*
PROGRAM: fc
AUTHOR: Su Jiao
DATE: 2010-1-13
DESCRIPTION:
农夫约翰想要建造一个围栏用来围住他的奶牛，可是他资金匮乏。他建造的围栏必须包括他
的奶牛喜欢吃草的所有地点。对于给出的这些地点的坐标，计算最短的能够围住这些点的围
栏的长度。
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <algorithm>
using std::sort;
#include <cmath>
using std::sqrt;

ifstream* in;
ofstream* out;
void setInput(ifstream& cin)
{
     in=&cin;
}
void setOutput(ofstream& cout)
{
     out=&cout;
}

template<class type>
struct Point
{
       type x,y;
       Point(type _x=0,type _y=0)
       :x(_x),y(_y)
       {
       }
       Point& read()
       {
              (*in)>>x>>y;
              return *this;
       }
       const Point& print(char* message="") const
       {
              (*out)<<message<<"("<<x<<","<<y<<")"<<endl;
              return *this;
       }
};

Point<double> point_compare;
double cross(const Point<double>& a,const Point<double>& b)
{
       /*
       a.print("A");
       b.print("B");
       point_compare.print("O");
       (*out)<<(a.x-point_compare.x)*(b.y-point_compare.y)
               -(a.y-point_compare.y)*(b.x-point_compare.x)<<endl;
       */
       return (a.x-point_compare.x)*(b.y-point_compare.y)
              -(a.y-point_compare.y)*(b.x-point_compare.x);
}
double cross(const Point<double>& a,const Point<double>& b,Point<double> point_compare)
{
       
       //a.print("A");
       //b.print("B");
       //point_compare.print("O");
       //(*out)<<(a.x-point_compare.x)*(b.y-point_compare.y)
       //        -(a.y-point_compare.y)*(b.x-point_compare.x)<<endl;
       
       return (a.x-point_compare.x)*(b.y-point_compare.y)
              -(a.y-point_compare.y)*(b.x-point_compare.x);
}
bool operator<(const Point<double>& a,const Point<double>& b)
{
     double c=cross(a,b);
     //a.print("sA");
     //b.print("sB");
     //*out<<c<<endl;
     if (c>0) return true;
     else if (c==0)
     {
          return
          (((a.x-point_compare.x)*(a.x-point_compare.x)+(a.y-point_compare.y)*(a.y-point_compare.y)))
          <
          (((b.x-point_compare.x)*(b.x-point_compare.x)+(b.y-point_compare.y)*(b.y-point_compare.y)));
     }
     else return false;
}

class Application
{
      ifstream cin;
      ofstream cout;
      typedef double type;
      static const int MAXN=10000;
      static const type oo=1000000;
      int N;
      Point<type> p[MAXN+2];
      int oId;
      Point<type> list[MAXN+2];
      int list_len;
      type answer;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output),oId(0)
      {
                                       setInput(cin);
                                       setOutput(cout);
                                       cin>>N;
                                       for (int i=1;i<=N;i++)
                                       {
                                           p[i].read();
                                           //p[i].print();
                                           if (!oId)
                                           {
                                              oId=i;
                                           }
                                           else if (p[i].y<p[oId].y)
                                           {
                                                oId=i;
                                           }
                                           else if (p[i].y==p[oId].y)
                                           {
                                                if (p[i].x<p[oId].x)
                                                   oId=i;
                                           }
                                       }
                                       //p[oId].print("O");
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
          point_compare=p[oId];
          //cout<<"p:"<<endl;
          //for (int i=1;i<=N;i++) p[i].print();
          sort(&p[1],&p[N+1]);
          //cout<<"p:"<<endl;
          //for (int i=1;i<=N;i++) p[i].print();
          answer=0;
          if (N>1)
          {
             list_len=0;
             list[++list_len]=p[1];
             list[++list_len]=p[2];
             for (int i=3;i<=N;i++)
             {
                 if (cross(p[i],list[list_len-1],list[list_len])<0)
                    list[list_len--]=p[i--];
                 else
                     list[++list_len]=p[i];
             }
             //cout<<"list:"<<endl;
             //for (int i=1;i<=list_len;i++) list[i].print();
             for (int i=1;i<list_len;i++) answer+=sqrt(type(
                                                       (list[i].x-list[i+1].x)
                                                       *(list[i].x-list[i+1].x)
                                                      +(list[i].y-list[i+1].y)
                                                       *(list[i].y-list[i+1].y)));
             answer+=sqrt(type(
                                (list[1].x-list[list_len].x)
                               *(list[1].x-list[list_len].x)
                              +(list[1].y-list[list_len].y)
                               *(list[1].y-list[list_len].y)));
          }
          if ((long long int)(answer*10000000)%100000>=49999) answer+=0.01;
          cout
          <<(long long int)(answer)<<"."
          <<(long long int)((long long int)(answer*10)%10)
          <<(long long int)((long long int)(answer*100)%10)<<endl;
          return 0;
      }
};


int main()
{
    Application app("fc.in","fc.out");
    return app.run();
}
