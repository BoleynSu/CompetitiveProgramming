#include <iostream>
using namespace std;
/*
__int64 n,k,t;
__int64 a[1024*1024];

__int64 mian()
{
    cin>>n>>k>>t;
    for (__int64 i=1;i<=k;i++)
        cin>>a[i];
    v(a[i] at j)=j-a[i]
}
*/

__int64 n,k,t;
__int64 a;
__int64 answer;

int main()
{
    cin>>n>>k>>t;
    answer=(k+1)*k/2;
    for (__int64 i=1;i<=k;i++)
    {
        cin>>a;
        answer-=a;
    }
    cout<<answer<<endl;
}
