/*
ID: sujiao1
PROG: frac1
LANG: C++
*/
#include <cstring>
#include <iostream>
#include <fstream>
using std::endl;
using std::strlen;
/*
using std::cin;
using std::cout;
*/
std::ifstream cin("frac1.in");
std::ofstream cout("frac1.out");

int gcd(int a,int b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}
struct da{int a,b;}d[160*160];
int l=0;
int main()
{
    int N;
    cin>>N;
    for (int i=0;i<=N;i++)
        for (int j=i;j<=N;j++)
            if (gcd(j,i)==1)
            {
               l++;
               d[l].a=i;
               d[l].b=j;
               //cout<<i<<"/"<<j<<endl;
            }
    for (int i=1;i<=l;i++)
        for (int j=i+1;j<=l;j++)
            if (d[i].a*d[j].b>d[j].a*d[i].b)
            {
               da s=d[i];
               d[i]=d[j];
               d[j]=s;
            }
    for (int i=1;i<=l;i++)
        cout<<d[i].a<<"/"<<d[i].b<<endl;
}
