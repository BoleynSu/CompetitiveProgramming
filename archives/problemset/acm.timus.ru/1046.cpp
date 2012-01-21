/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-26
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
using std::cin;
using std::cos;
//using std::M_PI;
#define M_PI 3.141592653589793238462643383279f
#include <iomanip>

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
      typedef double Type;
      struct Data
      {
             typedef double Type;
             Type x,y,C;
             void set(Type _x,Type _y,Type _C)
             {
                  x=(_x),y=(_y),C=(_C);
             } 
             void print()
             {
                  cout<<floor(x+0.5)<<" "<<floor(y+0.5)<<" "<<floor(C+0.5)<<endl;
             }
      };
      int N;
      vector<pair<Type,Type> > M;
      vector<Type> a;
      public:
      Application() 
      {
                    cin>>N;
                    M.resize(N);
                    for (int i=0;i<N;i++)
                        cin>>M[i].first>>M[i].second;
                    a.resize(N);
                    for (int i=0;i<N;i++)
                    {
                        cin>>a[i];
                        a[i]=a[i]/180.0*M_PI;
                    }
      }
      int run()
      {
          /*
          O为原点 旋转均为顺时针 
          O->Ai+1= Mi->Ai 转ai度后 + O->Mi
          Ai+1=(Ai-Mi)转ai度 + Mi
          
          然后，关于旋转：
          若(x,y)旋转a度成为了(x',y')
          可以用极坐标
          令x'=R*cos(A),y'=R*sin(A)
            x=R*cos(B),y=R*cos(B)
          则A-B=a
          所以cos(A)=cos(B+a)
              sin(A)=sin(B+a)
          那么cos(A)=cos(B)cos(a)-sin(B)sin(a)
              sin(A)=sin(B)cos(a)+cos(B)sin(a) 
          所以x'=x*cos(a)-y*sin(a)
              y'=y*cos(a)+x*sin(a)
          
          所以x(Ai+1)=(x(Ai)-x(Mi))*cos(a)-(y(Ai)-y(Mi))*sin(a)+x(Mi)
              y(Ai+1)=(y(Ai)-y(Mi))*cos(a)+(x(Ai)-x(Mi))*sin(a)+y(Mi)
          所以x(Ai+1)=x(Ai)*cos(a)-y(Ai)*sin(a)-x(Mi)*cos(a)+y(Mi)*sin(a)+x(Mi)
              y(Ai+1)=y(Ai)*cos(a)+x(Ai)*sin(a)-y(Mi)*cos(a)-x(Mi)*sin(a)+y(Mi)
          */
          vector<pair<Data,Data> > A(N+1);
          A[0].first.set(1.0,0,0);
          A[0].second.set(0,1.0,0);
          for (int i=0;i<N;i++)
          {
              double x,y,C;
              
              //x(Ai+1)=x(Ai)*cos(a)  -y(Ai)*sin(a)
              x=A[i].first.x*cos(a[i])-A[i].second.x*sin(a[i]);
              y=A[i].first.y*cos(a[i])-A[i].second.y*sin(a[i]);
              C=A[i].first.C*cos(a[i])-A[i].second.C*sin(a[i])
              //-x(Mi)*cos(a)        +y(Mi)*sin(a)         +x(Mi)
                -M[i].first*cos(a[i])+M[i].second*sin(a[i])+M[i].first;
              
              A[i+1].first.set(x,y,C);
              
              //y(Ai)*cos(a)          +x(Ai)*sin(a)
              x=A[i].second.x*cos(a[i])+A[i].first.x*sin(a[i]);
              y=A[i].second.y*cos(a[i])+A[i].first.y*sin(a[i]);
              C=A[i].second.C*cos(a[i])+A[i].first.C*sin(a[i])
              //-y(Mi)*cos(a)         -x(Mi)*sin(a)        +y(Mi)
                -M[i].second*cos(a[i])-M[i].first*sin(a[i])+M[i].second;
              
              A[i+1].second.set(x,y,C);
          }
          Function<Type> f;
          vector<vector<double> > matrix(2,vector<double>(3));
          vector<double> answer(2);
          //x=A[N].first.x*x+A[N].first.y*y+A[N].first.C
          //y=A[N].second.x*x+A[N].second.y*y+A[N].first.C
          
          //  x               y               C
          //  1-A[N].first.x  -A[N].first.y    A[N].first.C
          //  -A[N].second.x  1-A[N].second.y  A[N].second.C
          matrix[0][0]=1-A[N].first.x;
          matrix[0][1]=-A[N].first.y;
          matrix[0][2]=A[N].first.C;
          matrix[1][0]=-A[N].second.x;
          matrix[1][1]=1-A[N].second.y;
          matrix[1][2]=A[N].second.C;
          f.read(matrix);
          f.solve();
          f.write(answer);
          double X=answer[0];
          double Y=answer[1];
          cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
          for (int i=0;i<N;i++)
          {
              cout<<A[i].first.x*X+A[i].first.y*Y+A[i].first.C<<" "
                  <<A[i].second.x*X+A[i].second.y*Y+A[i].second.C<<endl;
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
