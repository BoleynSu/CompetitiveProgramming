#include <iostream>
using namespace std;

long long n,k;
bool possible(long long x)
{
     long long t=x,p=n;
     while (t)
     {
           p-=t;
           if (p<=0) return true;
           t/=k;
     }
     return false; 
}

int main()
{
    cin>>n>>k;
    long long l=0,r=n;
    while (l+1!=r)
    {
          long long mid=(l+r)>>1;
          if (possible(mid)) r=mid;
          else l=mid;
    }
    cout<<r<<endl;
    return 0;
}
 

