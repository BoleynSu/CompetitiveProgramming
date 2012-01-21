/*
ID: sujiao1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("pprime.in");
std::ofstream cout("pprime.out");

struct Program
{
       static const int MAX=100000000;//5 to 100000000
       int a,b;
       int pt[5000];
       int ptl;
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
            if ((n<a)||(n>b)) return false;
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
       Program()
       {
                cin>>a>>b;
       }
       inline
       int max(int a,int b)
       {
           return a>b?a:b;
       }
       void getAnswer()
       {
            //cout<<"getAnswer()\n";
            for (int i=1;i<=9;i+=2)
                if (isP(i)) cout<<i<<endl;
            for (int i=1;i<=9;i+=2)
                if (isP(i*11)) cout<<i*11<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    if (isP(i*101+j*10)) cout<<i*101+j*10<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    if (isP(i*1001+j*110)) cout<<i*1001+j*110<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    for (int k=0;k<=9;k++)
                        if (isP(i*10001+j*1010+k*100)) cout<<i*10001+j*1010+k*100<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    for (int k=0;k<=9;k++)
                        if (isP(i*100001+j*10010+k*1100)) cout<<i*100001+j*10010+k*1100<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    for (int k=0;k<=9;k++)
                        for (int l=0;l<=9;l++)
                            if (isP(i*1000001+j*100010+k*10100+l*1000)) cout<<i*1000001+j*100010+k*10100+l*1000<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    for (int k=0;k<=9;k++)
                        for (int l=0;l<=9;l++)
                            if (isP(i*10000001+j*1000010+k*100100+l*11000)) cout<<i*10000001+j*1000010+k*100100+l*11000<<endl;
            for (int i=1;i<=9;i+=2)
                for (int j=0;j<=9;j++)
                    for (int k=0;k<=9;k++)
                        for (int l=0;l<=9;l++)
                            for (int m=0;m<=9;m++)
                                if (isP(i*100000001+j*10000010+k*1000100+l*101000+m*10000)) cout<<i*100000001+j*10000010+k*1000100+l*101000+m*10000<<endl;
       }
       int run()
       {
           initPt();
           getAnswer();
           //cout<<clock()<<endl;
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
