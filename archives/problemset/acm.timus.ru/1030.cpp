/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-20
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
using std::getline; 
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
#include <cmath>
using std::cos;
using std::acos;
//using std::M_PI;
#define M_PI (3.141592653589793238462643383279f)
#include <cassert>
//using std::assert;
#include <iomanip>

class Application
{
      double sx,sy,ix,iy;
      void get(string& s,double& d)
      {
           if (s.substr(0,4)=="and ") s.erase(0,4);
           stringstream cin(s);
           d=0;
           double get;
           cin>>get;
           cin.ignore();
           d+=get;
           cin>>get;
           cin.ignore();
           d+=get/60.0;
           cin>>get;
           cin.ignore();
           d+=get/3600.0;
           char flag;
           cin>>flag;
           if (flag=='N'||flag=='E')
           {
              d=-d;
           }
      }
      double d(double get)
      {
             if (get>0) get=-get;
             if (get>180.0) get=360.0-get;
             return get;
      }
      public:
      Application() 
      {
      }
      int run()
      {
          string s;
          getline(cin,s);//Message #<n>.
          getline(cin,s);//Received at <HH>:<MM>:<SS>. 
          getline(cin,s);//Current ship's coordinates are 
          getline(cin,s);//<X1>^<X2>'<X3>" <NL/SL>
          get(s,sx);
          getline(cin,s);//and <Y1>^<Y2>'<Y3>" <EL/WL>.
          get(s,sy);
          getline(cin,s);//An iceberg was noticed at 
          getline(cin,s);//<A1>^<A2>'<A3>" <NL/SL> 
          get(s,ix);
          getline(cin,s);//and <B1>^<B2>'<B3>" <EL/WL>. 
          get(s,iy);
          getline(cin,s);//===
          
          sx=sx/180.0*M_PI;
          sy=sy/180.0*M_PI;
          ix=ix/180.0*M_PI;
          iy=iy/180.0*M_PI;
          
          const double R=(6875*0.5); 
          double d=R*acos(sin(sx)*sin(ix)+cos(sx)*cos(ix)*cos(sy-iy));
          cout<<"The distance to the iceberg: "
              <<std::setiosflags(std::ios::fixed)
              <<std::setprecision(2)
              <<d
              <<" miles."<<endl;
          string stream;
          int get;
          stringstream scout(stream);
          scout<<std::setiosflags(std::ios::fixed)
               <<std::setprecision(2)
               <<d;
          stringstream scin(scout.str());
          scin>>get;
          if (get<100) cout<<"DANGER!"<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
