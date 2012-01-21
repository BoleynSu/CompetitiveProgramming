/*
ID: sujiao1
PROG: crypt1
LANG: C++
*/

//#include <cstring>
//using std::strlen;

#include <iostream>
#include <fstream>
using std::endl;
/*
using std::cin;
using std::cout;
*/
std::ifstream cin("crypt1.in");
std::ofstream cout("crypt1.out");

struct Program
{
       static const int MAXN=9;
       bool can[10];
       int answer;
       Program():answer(0)
       {
                for (int i=0;i<=MAXN;i++) can[i]=false;
                int n;
                cin>>n;
                for (int i=1;i<=n;i++)
                {
                    int m;
                    cin>>m;
                    can[m]=true;
                }
       }
       bool is(int a3,int a2,int a1,int b2,int b1)
       {
            int a=a3*100+a2*10+a1;
            int l1=a*b1;
            int l2=a*b2;
            int l3=l1+l2*10;
            if ((l1>=1000)||(l2>=1000)||(l3>=10000)) return false;
            for (int k=100;k>=1;k/=10)
                if (!can[(l1/k)%10]) return false;
            for (int k=100;k>=1;k/=10)
                if (!can[(l2/k)%10]) return false;
            for (int k=1000;k>=1;k/=10)
                if (!can[(l3/k)%10]) return false;
            //cout<<a3<<a2<<a1<<endl<<b2<<b1<<endl<<l3<<endl<<answer+1<<"th"<<endl;
            return true;
       }
       int run()
       {
           //   * * *
           //X    * *
           //--------
           //   * * *
           // * * *
           //--------
           // * * * *
           
           //   a3 a2 a1
           //X     b2 b1
           for (int a3=1;a3<=MAXN;a3++)
           if (can[a3])
           for (int a2=1;a2<=MAXN;a2++)
           if (can[a2])
           for (int a1=1;a1<=MAXN;a1++)
           if (can[a1])
           for (int b2=1;b2<=MAXN;b2++)
           if (can[b2])
           for (int b1=1;b1<=MAXN;b1++)
           if (can[b1])
           if (is(a3,a2,a1,b2,b1)) answer++;
           cout<<answer<<endl;
           //while (cin.get());
           return 0;
       }
};

int main()
{
    Program app;
    return app.run();
}
