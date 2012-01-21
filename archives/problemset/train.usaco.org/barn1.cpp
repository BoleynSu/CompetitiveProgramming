/*
ID: sujiao1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("barn1.in");
std::ofstream cout("barn1.out");

int M,S,C;
int a[1000];
int main()
{
    cin>>M>>S>>C;
    for (int i=1;i<=C;i++)
        cin>>a[i];
    for (int i=1;i<C;i++)
        for (int j=i+1;j<=C;j++)
            if (a[i]>a[j])
            {
               int swap=a[i];
               a[i]=a[j];
               a[j]=swap;
            }
    int total=a[C]-a[1];
    for (int i=1;i<C;i++)
    {
        a[i]=a[i+1]-a[i];
    }
    
    for (int i=1;i<C-1;i++)
        for (int j=i+1;j<C;j++)
            if (a[i]<a[j])
            {
               int swap=a[i];
               a[i]=a[j];
               a[j]=swap;
            }
    //for (int i=1;i<C;i++) cout<<a[i]<<" ";cout<<endl;
    
    for (int i=1;i<M;i++)
        total-=a[i];
    
    total+=M;
    
    if (C<=M) total=C;
    
    cout<<total<<endl;
    
    //while (cin.get());
    return 0;
}
