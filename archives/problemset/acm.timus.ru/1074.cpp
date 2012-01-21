/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-9
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
using std::priority_queue;
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
using std::floor;

class Application
{
      bool read(string& s,int& N)
      {
           s.clear();
           char c;
           while ((c=cin.get())!='\n') s.push_back(c);
           if (s=="#") return false;
           cin>>N;
           while ((c=cin.get())!='\n');
           return true;
      }
      //<simple unsigned real number> ::= 
      //                  <unsigned integer number>
      //                 |.<unsigned integer number>
      //                 |<unsigned integer number>.<unsigned integer number>
      bool simple_unsigned_real_number(const string& s)
      {
           if (unsigned_integer_number(s)) return true;
           if (s.substr(0,1)=="."
               &&unsigned_integer_number(s.substr(1,s.length()-1)))
              return true;
           for (int i=1;i<s.length();i++)
               if (unsigned_integer_number(s.substr(0,i))
                   &&s.substr(i,1)=="."
                   &&unsigned_integer_number(s.substr(i+1,s.length()-i-1)))
               return true;
           return false;           
      }
      //<simple real number> ::= <simple unsigned real number>
      //                        |<sign><simple unsigned real number> 
      bool simple_real_number(const string& s)
      {
           if (simple_unsigned_real_number(s)) return true;
           for (int i=1;i<s.length();i++)
               if (sign(s.substr(0,i))
                   &&simple_unsigned_real_number(s.substr(i,s.length()-i)))
               return true;
           return false;
      }
      //<digit> ::= 0|1|2|3|4|5|6|7|8|9
      bool digit(const string& s)
      {
           return s=="0"
                  ||s=="1"
                  ||s=="2"
                  ||s=="3"
                  ||s=="4"
                  ||s=="5"
                  ||s=="6"
                  ||s=="7"
                  ||s=="8"
                  ||s=="9";
      }
      //<unsigned integer number> ::= <digit>
      //                             |<digit><unsigned integer number>
      bool unsigned_integer_number(const string& s)
      {
           if (digit(s)) return true;
           for (int i=1;i<s.length();i++)
               if (digit(s.substr(0,i))
                   &&unsigned_integer_number(s.substr(i,s.length()-i)))
               return true;
           return false;
      }
      //<sign> ::= +|-
      bool sign(const string& s)
      {
           return s=="+"||s=="-";
      }
      //<integer number> ::= <unsigned integer number>
      //                    |<sign><unsigned integer number>
      bool integer_number(const string& s)
      {
           if (unsigned_integer_number(s)) return true;
           for (int i=1;i<s.length();i++)
               if (sign(s.substr(0,i))
                   &&unsigned_integer_number(s.substr(i,s.length()-i)))
               return true;
           return false;
      }
      //<exponent symbol> ::= e|E
      bool exponent_symbol(const string& s)
      {
           return s=="e"||s=="E";
      }
      //<exponent> ::= <exponent symbol><integer number>
      bool exponent(const string& s)
      {
           for (int i=1;i<s.length();i++)
               if (exponent_symbol(s.substr(0,i))
                   &&integer_number(s.substr(i,s.length()-i)))
               return true;
           return false;
      }
      //<real number> ::= <simple real number>
      //                 |<simple real number><exponent>
      bool real_number(const string& s)
      {
           if (simple_real_number(s)) return true;
           for (int i=1;i<s.length();i++)
               if (simple_real_number(s.substr(0,i))
                   &&exponent(s.substr(i,s.length()-i)))
               return true;
           return false;
      }
      void print_real_number(const string& s,int N)
      {
           static const int MAXLENGTH=200;
           static const int MAXN=100;
           int position_of_e=std::string::npos;
           if (s.find("e")!=std::string::npos) position_of_e=s.find("e");
           if (s.find("E")!=std::string::npos) position_of_e=s.find("E");
           
           string simple_real_number_part;
           int value_of_e;
           if (position_of_e!=std::string::npos)
           {
              simple_real_number_part=s.substr(0,position_of_e);
              stringstream
              in(s.substr(position_of_e+1,s.length()-(position_of_e+1)));
              double get;
              in>>get;
              if (get>MAXLENGTH) value_of_e=MAXLENGTH;
              else if (get<-MAXLENGTH) value_of_e=-MAXLENGTH;
              else value_of_e=floor(get+0.5);
           }
           else
           {
               simple_real_number_part=s;
               value_of_e=0;
           }
           
           string integral_part;
           string fractional_part;
           int position_of_dot=simple_real_number_part.find(".");
           if (position_of_dot!=std::string::npos)
           {
              integral_part=simple_real_number_part.substr(0,position_of_dot);
              fractional_part=
              simple_real_number_part
                  .substr(position_of_dot+1,
                          simple_real_number_part.length()-(position_of_dot+1));
           }
           else
              integral_part=simple_real_number_part;
           string flag;
           if (integral_part[0]=='-')
           {
              flag="-";
              integral_part.erase(0,1);
           }
           else if (integral_part[0]=='+')
                integral_part.erase(0,1);
           
           do integral_part="0"+integral_part;
           while (int(integral_part.length())+value_of_e-1<=0);
           do fractional_part=fractional_part+"0";
           while (int(fractional_part.length())-value_of_e-1<=0);
           if (value_of_e<0)
           {
              fractional_part=
              integral_part.substr(integral_part.length()+value_of_e,
                                   -value_of_e)
              +fractional_part;
              integral_part.erase(integral_part.length()+value_of_e,
                                  -value_of_e);
           }
           if (value_of_e>0)
           {
              integral_part=
              integral_part
              +fractional_part.substr(0,value_of_e);
              fractional_part.erase(0,value_of_e);
           }
                      
           bool equal_to_zero=true;
           for (int i=0;i<integral_part.length();i++)
               if (integral_part[i]!='0') equal_to_zero=false;
           for (int i=0;i<fractional_part.length()&&i<N;i++)
               if (fractional_part[i]!='0') equal_to_zero=false;
           if (equal_to_zero) flag.clear();
           
           while (integral_part[0]=='0'&&integral_part.length()>1)
                 integral_part.erase(0,1);
           while (fractional_part.length()<MAXN)
                 fractional_part=fractional_part+"0";
           
           cout<<flag<<integral_part;
           if (N)
           {
                 cout<<".";
                 for (int i=0;i<N;i++)
                     cout<<fractional_part[i];
           }
      }
      public:
      Application()
      {
      }
      int run()
      {
          string s;
          int N;
          while (read(s,N))
                if (real_number(s))
                {
                   print_real_number(s,N);
                   cout<<endl;
                }
                else cout<<"Not a floating point number"<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
