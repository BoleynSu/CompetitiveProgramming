/*
ID: sujiao1
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
using std::endl;
//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("inflate.in");
std::ofstream cout("inflate.out");

inline int max(int x,int y){return x>y?x:y;}
void get()
{
     int M,N;
     cin>>M>>N;
     int* p=new int[N];
     int* t=new int[N];
     for (int i=0;i<N;i++) cin>>p[i]>>t[i];
     int* ret=new int[M+1];
     for (int i=0;i<=M;i++) ret[i]=0;
     for (int n=0;n<N;n++)
         for (int m=0;m<=M;m++)
             ret[m]=max(
             ((m-t[n])>=0)?(ret[m-t[n]]+p[n]):0
             ,
             ret[m]
             );
     
     cout<<ret[M]<<endl;
}

int main()
{
    get();
    //while(1);
    return 0;
}
