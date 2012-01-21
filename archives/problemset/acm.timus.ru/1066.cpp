/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-8
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>

#include <cstring>
using std::memset;

#define oo 1e10
#define MAXN 1000

int N;
double A;
double B;

void read()
{
     cin>>N>>A;
}
void write()
{
     cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
     cout<<B<<endl;
}
void solve()
{
     /*
     h[i]=(h[i-1]+h[i+1])/2-1
     h[i]*2+2=(h[i-1]+h[i+1])
     h[i+1]=h[i]*2+2-h[i-1]
     h[i]=h[i-1]*2-h[i-2]+2
     h[i]-h[i-1]=h[i-1]-h[i-2]+2
     
     令a[i]=h[i]-h[i-1]
     则a[2]=h[2]-h[1]
       a[i]=a[i-1]+2
     所以a[i]=a[2]+(i-2)*2
     h[i]=h[i]-h[i-1]+h[i-1]-h[i-2]+...+h[2]-h[1]+h[1]
         =a[i]       +a[i-1]       +...+a[2]     +h[1]
         =sum{a[j],2<=j<=i}+h[1]
         =sum{(a[2]+(j-2)*2),2<=j<i}+h[1]
         =(i-2+1)*a[2]+(0+(i-2)*2)*(i-2+1)/2+h[1]
         =(i-1)*(h[2]-h[1])+(i-2)*(i-1)+h[1]
         =(i-1)*h[2]-(i-2)*h[1]+(i-2)*(i-1)
     */
     double h[MAXN+2];
     h[1]=A;
     B=oo;
     for (int i=2;i<=N;i++)//假设其中一个贴地
     {
         h[i]=0;
         h[2]=(h[i]-(i-2)*(i-1)+(i-2)*h[1])/(i-1);
         
         bool can=true;
         for (int j=2;j<=N;j++)
         {
             h[j]=(j-1)*h[2]-(j-2)*h[1]+(j-2)*(j-1);
             if (h[j]<0)
             {
                can=false;
                break;
             }
         }
         if (can)
            if (B>h[N]) B=h[N];
     } 
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
