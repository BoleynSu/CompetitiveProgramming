/*
ID: sujiao1
PROG: twofive
LANG: C++
*/
/*
PROGRAM: twofive
AUTHOR: Su Jiao
DATE: 2010-1-22
DESCRIPTION:
Two Five
二五语言 
IOI 2001
有一种奇怪的语言叫做“二五语言”。它的每个单词都由A～Y这25个字母各一个组成。但
是，并不是任何一种排列都是一个合法的二五语言单词。二五语言的单词必须满足这样一个
条件：把它的25个字母排成一个5*5的矩阵，它的每一行和每一列都必须是递增的。比如单
词ACEPTBDHQUFJMRWGKNSXILOVY，它排成的矩阵如下所示： 
A C E P T
B D H Q U
F J M R W
G K N S X
I L O V Y
因为它的每行每列都是递增的，所以它是一个合法的单词。而单词YXWVUTSRQPONMLKJIHGFE
DCBA则显然不合法。 
由于单词太长存储不便，需要给每一个单词编一个码。编码方法如下：写出单词中字母A在
矩阵中的行号和列号，再写出B的行号和列号……依此类推。得到的序列叫做行列序列。如
上面的合法单词的行列序列是：11 21 12 22 13 31 41 23 51 32 42 52 33 43 53 14 24 
34 44 15 25 54 35 45 55。然后把所有合法单词的行列序列排序。一个单词的行列序列排
序后的位置，就是这个单词的编码。比如，单词ABCDEFGHIJKLMNOPQRSTUVWXY的编码为1，而
单词ABCDEFGHIJKLMNOPQRSUTVWXY的编码为2。 
现在，你需要编一个程序，完成单词与编码间的转换。
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
      static const int N=5;
      typedef char string[N*N+2];
      char order;
      string s;
      int n;
      int f[N+2][N+2][N+2][N+2][N+2];
      int put[N*N+2];
      bool used[N*N+2];
      int maxx[N+2];
      int maxy[N+2];
      //x 对应行
      //y 对应列 
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        cin>>order;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      inline
      char to(int c)
      {
           return 'A'+c-1;
      }
      inline
      int from(char c)
      {
          return c-'A'+1;
      }
      int dp(int l1,int l2,int l3,int l4,int l5,int c)
      {
          if (!f[l1][l2][l3][l4][l5])
          {
             if (used[c]) f[l1][l2][l3][l4][l5]=dp(l1,l2,l3,l4,l5,c+1);
             else
             {
                 if (l1<N&&c>maxy[l1+1]&&c>maxx[1]) f[l1][l2][l3][l4][l5]+=dp(l1+1,l2,l3,l4,l5,c+1);
                 if (l1>l2&&c>maxy[l2+1]&&c>maxx[2]) f[l1][l2][l3][l4][l5]+=dp(l1,l2+1,l3,l4,l5,c+1);
                 if (l2>l3&&c>maxy[l3+1]&&c>maxx[3]) f[l1][l2][l3][l4][l5]+=dp(l1,l2,l3+1,l4,l5,c+1);
                 if (l3>l4&&c>maxy[l4+1]&&c>maxx[4]) f[l1][l2][l3][l4][l5]+=dp(l1,l2,l3,l4+1,l5,c+1);
                 if (l4>l5&&c>maxy[l5+1]&&c>maxx[5]) f[l1][l2][l3][l4][l5]+=dp(l1,l2,l3,l4,l5+1,c+1);
             }
          }
          return f[l1][l2][l3][l4][l5];
      }
      int get(int step)
      {
          memset(f,0,sizeof(f));
          f[5][5][5][5][5]=1;
          int l[N+2];
          memset(l,0,sizeof(l));
          for (int i=1;i<=N;i++)
          {
              if (step-N>=0)
              {
                 l[i]=N;
                 step-=N;
              }
              else
              {
                  l[i]=step;
                  break;
              }
          }
          return dp(l[1],l[2],l[3],l[4],l[5],1);
      }
      void dealN()
      {
           memset(maxx,0,sizeof(maxx));
           memset(maxy,0,sizeof(maxy));
           memset(used,false,sizeof(used));
           
           cin>>n;
           //摆放顺序: 
           //  1  2  3  4  5
           //  6  7  8  9 10
           // 11 12 13 14 15
           // 16 17 18 19 20
           // 21 22 23 24 25
           for (int step=1;step<=N*N;step++)
           {
               int px=(step-1)/N+1;
               int py=(step-1)%N+1;
               //cout<<px<<" "<<py<<endl;
               int i;
               for (i=1;i<=N*N;i++)
                   if ((!used[i])&&(maxx[px]<i&&maxy[py]<i))
                   {
                      used[i]=true;
                      maxx[px]=i;
                      maxy[py]=i;
                      int d=get(step);
                      if (n-d<=0) break;
                      else n-=d;
                      used[i]=false;
                   }
               s[step-1]=to(i);
           }
           s[N*N]='\0';
           cout<<s<<endl;
      }
      void dealW()
      {
           memset(maxx,0,sizeof(maxx));
           memset(maxy,0,sizeof(maxy));
           memset(used,false,sizeof(used));
           n=0;
           
           cin>>s;
           //摆放顺序: 
           //  1  2  3  4  5
           //  6  7  8  9 10
           // 11 12 13 14 15
           // 16 17 18 19 20
           // 21 22 23 24 25
           for (int step=1;step<=N*N;step++)
           {
               int px=(step-1)/N+1;
               int py=(step-1)%N+1;
               int i;
               for (i=1;i<from(s[step-1]);i++)
                   if ((!used[i])&&(maxx[px]<i&&maxy[py]<i))
                   {
                      used[i]=true;
                      maxx[px]=i;
                      maxy[py]=i;
                      n+=get(step);
                      used[i]=false;
                   }
               used[i]=true;
               maxx[px]=i;
               maxy[py]=i;
           }
           n++;
           cout<<n<<endl;
      }
      int run()
      {
          switch (order)
          {
                 case 'N':
                      dealN();
                 break; 
                 case 'W':
                      dealW();
                 break; 
          }
          return 0;
      }
};

int main()
{
    Application app("twofive.in","twofive.out");
    return app.run();
}
