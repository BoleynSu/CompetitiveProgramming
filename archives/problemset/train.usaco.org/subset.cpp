/*
ID: sujiao1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("subset.in");
std::ofstream cout("subset.out");

void get()
{
     int N,S;
     cin>>N;
     
     if ((N*(N+1)%4)!=0) cout<<0<<endl;
     else
     {
         S=N*(N+1)/4;
         long long int *num=new long long int[S+1];
         for (int i=0;i<=S;i++) num[i]=0;
         num[0]=1;
         
         for (int n=1;n<=N;n++)
             for (int s=S;s>=n;s--)
                 num[s]=num[s]+num[s-n];
         
         cout<<num[S]/2<<endl;
     }
}

int main()
{
    get();
    return 0;
}
