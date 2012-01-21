/*
ID: sujiao1
PROG: picture
LANG: C++
*/
/*
PROGRAM: picture
AUTHOR: Su Jiao
DATE: 2010-1-21
DESCRIPTION:
N 张矩形的海报，照片和其他同样形状的图片贴在墙上。它们的边都是垂直的或水平的。每
个矩形可以部分或者全部覆盖其他矩形。所有的矩形组成的集合的轮廓称为周长。写一个程
序计算周长。 
所有矩形的顶点坐标均为整数。所有的坐标都在 [-10000，10000] 的范围内，并且任何一
个矩形面积都为正数。结果的值可能需要 32 位有符号整数表示。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <algorithm>
using std::sort;
#include <ctime>
using std::clock;
#include <stdlib.h>

struct Line
{
       int s,e,dir;
       int mark;
       void set(int _s,int _e,int _dir,int _mark)
       {
            s=_s;
            e=_e;
            dir=_dir; 
            mark=_mark;
       }
};
/*
bool operator <(const Line& a,const Line& b)
{
     return (a.dir<b.dir)||((a.dir==b.dir)&&(a.mark>b.mark));
}
*/
int compare(const void* _a,const void* _b)
{
    Line a=*(Line*)_a;
    Line b=*(Line*)_b;
    if ((a.dir<b.dir)||((a.dir==b.dir)&&(a.mark>b.mark))) return -1;
    return 1;
}

struct LineTree
{
       LineTree* lc;
       LineTree* rc;
       int l,r;
       int counter;
       int len;
       LineTree(int _l,int _r)
                    :l(_l),r(_r),lc(0),rc(0),counter(0),len(0)
       {
                    if (r-l>1)
                    {
                       lc=new LineTree(_l,(_l+_r)/2);
                       rc=new LineTree((_l+_r)/2,_r);
                    }
       }
       ~LineTree()
       {
                  if (r-l>1)
                  {
                     delete lc;
                     delete rc;
                  }
       }
       inline
       void update()
       {
            if (counter) len=r-l;
            else if (r-l>1)
                 len=lc->len+rc->len;
            else len=0;
       }
       void add(int _l,int _r)
       {
            if (_l<=l&&r<=_r)
               counter++;
            else if (r-l>1)
            {
                if (_l<=(l+r)/2)
                   lc->add(_l,_r);
                if (_r>=(l+r)/2)
                   rc->add(_l,_r);
            }
            update();
       }
       void del(int _l,int _r)
       {
            if (_l<=l&&r<=_r)
               counter--;
            else if (r-l>1)
            {
                if (_l<=(l+r)/2)
                   lc->del(_l,_r);
                if (_r>=(l+r)/2)
                   rc->del(_l,_r);
            }
            update();
       }
       int length()
       {
           return len;
       }
};

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=5000*2; 
      static const int oo=10000;
      int N;
      Line x[MAXN+2];
      Line y[MAXN+2];
      int answer;
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        cin>>N;
                        for (int i=1;i<=N;i++)
                        {
                            int x1,y1,x2,y2;
                            cin>>x1>>y1>>x2>>y2;
                            y[i*2-1].set(x1,x2,y1,1);
                            y[i*2].set(x1,x2,y2,-1);
                            x[i*2-1].set(y1,y2,x1,1);
                            x[i*2].set(y1,y2,x2,-1);
                        }
                        N*=2;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      int next(int n)
      {
          return n+N;
      }
      inline
      int abs(int n)
      {
          return n>0?n:-n;
      }
      int run()
      {
          //sort(&x[1],&x[N]);
          //sort(&y[1],&y[N]);
          qsort(&x[1],N,sizeof(Line),compare);
          qsort(&y[1],N,sizeof(Line),compare);
          answer=0;
          LineTree _x(-oo,+oo);
          for (int i=1;i<=N;i++)
          {
              int l1=_x.length();
              if (x[i].mark>0) _x.add(x[i].s,x[i].e);
              else _x.del(x[i].s,x[i].e);
              int l2=_x.length();
              answer+=abs(l1-l2);
              /*
              cout<<x[i].s<<" "<<x[i].e<<" "<<x[i].dir<<" "<<x[i].mark<<"s e";
              cout<<l1<<" ";
              cout<<l2<<":";
              cout<<answer<<endl;*/
          }
          LineTree _y(-oo,+oo);
          for (int i=1;i<=N;i++)
          {
              int l1=_y.length();
              if (y[i].mark>0) _y.add(y[i].s,y[i].e);
              else _y.del(y[i].s,y[i].e);
              int l2=_y.length();
              answer+=abs(l1-l2);
              /*
              cout<<y[i].s<<" "<<y[i].e<<" "<<y[i].dir<<" "<<y[i].mark<<"s e";
              cout<<l1<<" ";
              cout<<l2<<":";
              cout<<answer<<endl;*/
          }
          cout<<answer<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app("picture.in","picture.out");
    return app.run();
}
