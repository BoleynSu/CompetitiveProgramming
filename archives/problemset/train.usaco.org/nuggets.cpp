/*
ID: sujiao1
PROG: nuggets
LANG: C++
*/
/*
PROGRAM: nuggets
AUTHOR: Su Jiao
DATE: 2009-12-29
DESCRIPTION:
农夫布朗的奶牛们正在进行斗争，因为它们听说麦当劳正在考虑引进一种新产品：麦香牛
块。奶牛们正在想尽一切办法让这种可怕的设想泡汤。奶牛们进行斗争的策略之一是“劣
质的包装”。“看，”，奶牛们说，“如果你只用一次能装3块、6块或者10块的三种包装
盒包装麦香牛块，你就不可能满足一次只想买1、2、4、5、7、8、11、14或者17块麦香牛
块的顾客了。劣质的包装意味着劣质的产品。” 
你的任务是帮助这些奶牛。给出包装盒的种类数N(1<=N<=10)和N个代表不同种类包装盒容
纳麦香牛块个数的正整数(1<=i<=256)，输出顾客不能用上述包装盒(每种盒子数量无限)买
到麦香牛块的最大块数。如果所有购买方案都能得到满足或者不存在不能买到块数的上限，
则输出0。不能买到的最大块数（倘它存在）不超过2,000,000,000。 
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
      static const int MAX=2000000000;
      static const int MAXN=10;
      static const int MAXA=256;
      int N;
      int a[MAXN+2];
      bool f[MAXA*MAXA+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>N;
                              for (int i=1;i<=N;i++)
                                  cin>>a[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      int gcd(int a,int b)
      {
          return b?gcd(b,a%b):a;
      }
      void sort()
      {
           for (int i=1;i<=N;i++)
               for (int j=i+1;j<=N;j++)
                   if (a[i]>a[j])
                   {
                      int swap=a[i];
                      a[i]=a[j];
                      a[j]=swap;
                   }
      }
      int gcd_all()
      {
          int ret=0;
          for (int i=1;i<=N;i++)
              ret=gcd(a[i],ret);
          return ret;
      }
      int getAnswer()
      {
          memset(f,false,sizeof(f));
          int MAX=a[N]*a[N-1];
          f[0]=true;
          for (int i=0;i<=MAX;i++)
              for (int j=1;j<=N;j++)
                  f[i+a[j]]|=f[i];
          for (;MAX>=1;MAX--)
              if (!f[MAX]) break;
          return MAX;
      }
      int run()
      {
          sort();
          if (gcd_all()!=1)
             cout<<0<<endl;
          else
              cout<<getAnswer()<<endl;
          return 0;
      }
};

int main()
{
    Application app("nuggets.in","nuggets.out");
    return app.run();
}
