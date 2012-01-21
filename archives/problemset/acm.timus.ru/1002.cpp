/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-8 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
using std::memset;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <stack>
using std::stack;

class Question
{
      int get_num[256];
      string number;
      vector<string> dictionary;
      bool match(int f,int t,int id)
      {
           if (t-f!=dictionary[id].length()) return false;
           else
           {
               for (int i=f;i<t;i++)
                   if (get_num[dictionary[id][i-f]]!=(number[i]-'0')) return false;
               return true;
           }
      }
      public:
      Question()
      {
                get_num['a']=2; 
                get_num['b']=2; 
                get_num['c']=2; 
                get_num['d']=3; 
                get_num['e']=3; 
                get_num['f']=3;  
                get_num['g']=4; 
                get_num['h']=4; 
                get_num['i']=1; 
                get_num['j']=1;
                get_num['k']=5; 
                get_num['l']=5;
                get_num['m']=6; 
                get_num['n']=6;
                get_num['o']=0;
                get_num['p']=7;
                get_num['q']=0;
                get_num['r']=7;
                get_num['s']=7;
                get_num['t']=8;
                get_num['u']=8;
                get_num['v']=8;
                get_num['w']=9;
                get_num['x']=9;
                get_num['y']=9;
                get_num['z']=0;
      }
      bool read()
      {
           dictionary.clear(); 
           cin>>number;
           if (number=="-1") return false;
           
           int n;
           cin>>n;
           while (n--)
           {
                 string get;
                 cin>>get;
                 dictionary.push_back(get);
           }
           return true;
      }
      void solve()
      {
           int* f=new int[number.length()+1];
           int* pre=new int[number.length()+1];
           int* use=new int[number.length()+1];
           memset(f,0x7f,sizeof(int)*(number.length()+1));
           f[0]=0;
           for (int k=1;k<=number.length();k++)
               for (int i=0;i<k;i++)
                   for (int j=0;j<dictionary.size();j++)
                       if (match(i,k,j))
                          if (f[k]>f[i]+1)
                          {
                             f[k]=f[i]+1;
                             pre[k]=i;
                             use[k]=j;
                          }
           if (f[number.length()]>number.length()) cout<<"No solution."<<endl;
           else
           {
               stack<int> s;
               
               s.push(number.length());
               while (pre[s.top()])
                     s.push(pre[s.top()]);
               
               for (;!s.empty();)
               {
                   cout<<dictionary[use[s.top()]]<<char(s.size()>1?' ':'\n');
                   s.pop();
               }
           }
           delete[] f;
      }
};
class Application
{
      public:
      Application() 
      {
      }
      int run()
      {
          Question q;
          while(q.read()) q.solve();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
