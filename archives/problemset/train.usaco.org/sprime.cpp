/*
ID: sujiao1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("sprime.in");
std::ofstream cout("sprime.out");

struct Program
{
       static const int MAXN=8;//1 to 8
       int n;
       int pt[5000];
       int ptl;
       Program()
       {
                cin>>n;
       }
       void initPt()
       {
            ptl=1;
            pt[1]=2;
            for (int i=3;i<=10000;i++)
            {
                bool is=true;
                for (int j=1;j<=ptl;j++)
                    if (i%pt[j]==0)
                    {
                       is=false;
                       break;
                    }
                if (is)
                {
                   ptl++;
                   pt[ptl]=i;
                }
            }
            /*
            cout<<ptl<<endl;
            for (int i=1;i<=ptl;i++)
            {
                cout<<pt[i]<<",";
            }
            */
       }
       bool isP(int n)
       {     
            //cout<<"isP("<<n<<")\n";
            for (int j=1;j<=ptl;j++)
            {
                if (n==pt[j]) return true;
                else if (n%pt[j]==0)
                {
                   //cout<<n<<" "<<pt[j]<<endl;
                   return false;
                }
            }
            return true;
       }
       void getAnswer(int depth,int number)
       {
            if (!isP(number)) return;
            if (depth==0)
            {
               cout<<number<<endl; 
               return;
            }
            for (int i=0;i<=9;i++)
                getAnswer(depth-1,number*10+i);
       }
       int run()
       {
           initPt();
           for (int i=2;i<=9;i++)
               getAnswer(n-1,i);
           return 0;    
       }
};
//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
