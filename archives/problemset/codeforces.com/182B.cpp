#include <string>
#include <iostream>
using namespace std;

int d;
int n;
int a[2000+2];
int main()
{cin>>d>>n;for (int i=0;i<n;i++)cin>>a[i];
int current=1,answer=0;
for (int i=0;i<n;i++)
{
    if (current!=1) answer+=d-current+1;
    current=a[i]%d+1;
}cout<<answer<<endl;
} 

