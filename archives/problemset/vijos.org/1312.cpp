#include <iostream>
using namespace std;

const int MAXN=100;
int n;
int A[MAXN+2];
#define K(_k_) (((((_k_)+n)%n)==0)?n:(((_k_)+n)%n)) 
int f[MAXN+2][MAXN+2];
int output; 
/*
k 合并次数
sk  从sk合并到sk+k 
xk sk是由哪一点合并来的 {sk<xk<sk+k}
vk=A[sk]*A[xk]*A[sk+k] 
fk(sk)=max{f(xk-sk)(sk)+f(sk+k-xk)(xk)+vk} 
f1(all)=0 
*/
void get()
{
     cin>>n;     
     for (int i=1;i<=n;i++)
         cin>>A[i];
     for (int k=2;k<=n;k++)
     {
         for (int sk=1;sk<=n;sk++)
         {
             f[K(k)][K(sk)]=0; 
             for (int xk=sk+1;xk<sk+k;xk++) 
             {
                 int vk=A[K(sk)]*A[K(xk)]*A[K(sk+k)];
                 int t=f[K(xk-sk)][K(sk)]+f[K(sk+k-xk)][K(xk)]+vk;
                 if (t>f[K(k)][K(sk)]) f[K(k)][K(sk)]=t;
                 //cout<<"After xk="<<xk<<endl; 
                 //cout<<"f["<<K(k)<<"]["<<K(sk)<<"]["<<K(sk+k)<<"]="<<t<<endl; 
             } 
         } 
     }
     for (int i=1;i<=n;i++)
     {
         output=output>f[K(n)][K(i)]?output:f[K(n)][K(i)];
     }
     cout<<output<<endl;
}

int main()
{
    get();
    return 0;
}
