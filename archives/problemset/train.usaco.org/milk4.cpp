/*
ID: sujiao1
PROG: milk4
LANG: C++
*/
/*
PROGRAM: milk4
AUTHOR: Su Jiao
DATE: 2010-1-15
DESCRIPTION:
农夫约翰要量取 Q（1 <= Q <= 20,000）夸脱（夸脱，quarts，容积单位——译者注） 他
的最好的牛奶，并把它装入一个大瓶子中卖出。消费者要多少，他就给多少，从不有任何误
差。 
农夫约翰总是很节约。他现在在奶牛五金商店购买一些桶，用来从他的巨大的牛奶池中量出
 Q 夸脱的牛奶。每个桶的价格一样。你的任务是计算出一个农夫约翰可以购买的最少的桶
 的集合，使得能够刚好用这些桶量出 Q 夸脱的牛奶。另外，由于农夫约翰必须把这些桶搬
 回家，对于给出的两个极小桶集合，他会选择“更小的”一个，即：把这两个集合按升序
 排序，比较第一个桶，选择第一个桶容积较小的一个。如果第一个桶相同，比较第二个桶，
 也按上面的方法选择。否则继续这样的工作，直到相比较的两个桶不一致为止。例如，集
 合 {3，5，7，100} 比集合 {3，6，7，8} 要好。 
为了量出牛奶，农夫约翰可以从牛奶池把桶装满，然后倒进瓶子。他决不把瓶子里的牛奶倒
出来或者把桶里的牛奶倒到别处。用一个容积为 1 夸脱的桶，农夫约翰可以只用这个桶量
出所有可能的夸脱数。其它的桶的组合没有这么方便。 
计算需要购买的最佳桶集，保证所有的测试数据都至少有一个解。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <algorithm>
using std::sort;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXP=100;
      static const int MAXW=20000;
      int Q,P;
      int w[MAXP+2];
      int p[MAXP+2];
      public:
      Application(char* input,char* output)
                        :cin(input),cout(output)
      {
                        cin>>Q>>P;
                        for (int i=1;i<=P;i++)
                            cin>>w[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      bool dp_can(const int& N)
      {
           bool f[MAXW+2];
           memset(f,false,sizeof(f));
           f[0]=true;
           for (int k=1;k<=N;k++)
               for (int i=p[k];i<=Q;i++)
                   f[i]=f[i]||f[i-p[k]];
           //for (int i=1;i<=N;i++) cout<<p[i]<<endl;
           //cout<<"end"<<f[Q]<<endl;
           return f[Q];
      }
      bool search(int step,int last,const int& MAXDEPTH)
      {
           if (++step>MAXDEPTH)
              return dp_can(MAXDEPTH);
           
           for (int i=last+1;i<=P;i++)
           {
               p[step]=w[i];
               if (search(step,i,MAXDEPTH)) return true;
           }
           return false;
      }
      int run()
      {
          sort(&w[1],&w[P]);
          for (int i=1;i<=P;i++)
              if (search(0,0,i))
              {
                 cout<<i;
                 for (int j=1;j<=i;j++)
                     cout<<" "<<p[j];
                 cout<<endl;
                 break;
              }
          return 0;
      }
};

int main()
{
    Application app("milk4.in","milk4.out");
    return app.run();
}
