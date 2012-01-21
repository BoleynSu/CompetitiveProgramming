/*
ID: sujiao1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("hamming.in");
std::ofstream cout("hamming.out");

const int MAXN=64;
const int MAXB=8;
const int MAXD=7;
const int MAXV=1024;
int n,b,d;
int maxv;
int answerl;
int answer[MAXN];
short f[MAXV+2][MAXV+2];

void initF()
{
     maxv=(1<<b)-1;
     //cout<<maxv<<"max"<<endl;
     for (int i=0;i<=maxv;i++)
     {
         //f[i][i]=0;
         for (int j=i+1;j<=maxv;j++)
         {
             int v=0;
             int t=1;
             for (int k=1;k<=b;k++)
             {
                 if ((i/t)%2!=(j/t)%2) v++;
                 t*=2;
             }
             f[i][j]=f[j][i]=v;
         }
     }
     maxv++;
     /*
     for (int i=0;i<=maxv;i++)
         for (int j=0;j<=maxv;j++)
             cout<<"f["<<i<<","<<j<<"]="<<f[i][j]<<endl;
     */
}

void search(int m)
{
     /*
     cout<<"search("<<m<<")"<<endl;
     cout<<answer[1];
     for (int i=2;i<=answerl;i++)
         cout<<" "<<answer[i];
     cout<<endl;
     */
     if (answerl==n)
     {
        int i=0;
        for (;(i+1)*10<answerl;i++)
        {
            cout<<answer[i*10+1];
            for (int j=2;j<=10;j++)
                cout<<" "<<answer[i*10+j];
            cout<<endl;
        }
        cout<<answer[i*10+1];
        for (int j=i*10+2;j<=answerl;j++)
            cout<<" "<<answer[j];
        cout<<endl;
        exit(0);
     }
     if (m>maxv) return;
     for (int i=1;i<=answerl;i++)
         if (f[answer[i]][m]<d) return;
     answerl++;
     answer[answerl]=m;
     for (int i=m+1;i<=maxv;i++) search(i);
     answerl--;
}

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    cin>>n>>b>>d;
    initF();
    answerl=1;
    answer[answerl]=0;
    for (int i=1;i<=maxv;i++)
        search(i);
    
    //cout<<clock()<<endl;
    return 0;
}
