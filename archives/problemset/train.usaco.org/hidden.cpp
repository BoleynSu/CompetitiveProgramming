/*
ID: sujiao1
PROG: hidden
LANG: C++
*/
/*
PROGRAM: hidden
AUTHOR: Su Jiao
DATE: 2010-1-22
DESCRIPTION:
有时候程序员有很奇怪的方法来隐藏他们的口令。Billy"Hacker"Geits会选择一个字符串S
（由L个小写字母组成，5<=L<=100,000），然后他把S顺时针绕成一个圈，每次取一个做开
头字母并顺时针依次取字母而组成一个字符串。这样将得到一些字符串，他把它们排序后取
出第一个字符串。把这个字符串的第一个字母在原字符串中的位置做为口令。
第一个字母所在的位置是0
如字符串alabala，按操作得到7个字符串，排序后得：
aalabal abalaal alaalab alabala balaala laalaba labalaa
第一个字符串为aalabal，这个a在原字符串位置为6，则6为口令。当字符串相同时，输出编
号最小的（即对于aaaa输出0）
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXL=100000;
      static const int oo=256-1;
      typedef unsigned char string[MAXL+2];
      int L;
      string s;
      #define gc(i,j) (s[(i+j)%L])
      //gc(i,j)=偏移了第i个字符新串的第j个字符 
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        cin>>L;
                        for (int i=0;i<L;i++)
                            cin>>s[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int run()
      {
          int i=0,j=1;
          for (;j<=L;)
          {
              int k=0;
              for (;k<L-1;k++)
              {
                  if (gc(i,k)<gc(j,k))
                  {
                     j+=k+1;
                     if (j==i) j++;
                     break;
                  }
                  if (gc(i,k)>gc(j,k))
                  {
                     i+=k+1;
                     if (i==j) i++;
                     break;
                  }
              }
              if (k==L-1) j+=k+1;
              if (i>j)
              {
                 int swap=i;
                 i=j;
                 j=swap;
              }
          }
          cout<<i<<endl;
          return 0;
      }
      //force version
      /*
      bool impossible[MAXL+2];
      int run()
      {
          memset(impossible,false,sizeof(impossible));
          for (int j=0;j<L-1;j++)
          {
              int min=oo;
              int counter=0;
              int mins[MAXL+2];
              for (int i=1;i<=L;i++)
                  if (!impossible[i]) 
                  {
                     if (gc(i,j)<min)
                     {
                        for (int k=1;k<=counter;k++)
                            impossible[mins[k]]=true;
                        min=gc(i,j);
                        counter=1;
                        mins[counter]=i;
                     }
                     else if (gc(i,j)==min)
                     {
                        counter++;
                        mins[counter]=i;
                     }
                     else
                     {
                         impossible[i]=true;
                     }
                  }
              if (counter==1)
              {
                 cout<<mins[counter]<<endl;
                 break;
              }
          }
          return 0;
      }
      */
};

int main()
{
    Application app("hidden.in","hidden.out");
    return app.run();
}
