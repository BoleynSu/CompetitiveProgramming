#include <iostream>
using namespace std;

int m[10000];
int l=1;
void f()
{
     int n[10000];
     n[0]=0;
     for (int i=0;i<l;i++)
     {
         n[i]+=2*m[i];
         n[i+1]=n[i]/10;
         n[i]%=10;
     }
     l++;
     for (int i=0;i<l;i++)
     {
         m[i]=n[i];
     }
}
void print()
{
     int start=false; 
     for (int i=l-1;i>=0;i--)
     {
         if ((!start)&&(m[i]!=0)) start=true;
         if (start) cout<<m[i];
     }
     cout<<endl;
}

int main()
{
int _n;
m[0]=1;
cin>>_n;
for (int i=0;i<_n;i++)f();
if (m[0]>0) m[0]--;
else
{
    for (int i=0;i<l;i++)
    {
        m[i]--;
        if (m[i]<0) m[i]+=10;
        else break;
    }
}
f();
print();
return 0;
}
