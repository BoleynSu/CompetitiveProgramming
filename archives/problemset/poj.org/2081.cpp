#include <iostream>
using namespace std;

int a[1000000];
bool b[100000000];
int main()
{
b[a[0]=0]=1;
for (int i=1;i<=600000;i++) if (((a[i]=a[i-1]-i)>=0)&&(!b[a[i]])) b[a[i]]=1; else b[a[i]=a[i-1]+i]=1;
int k;
while (cin>>k) if (k==-1) break; else cout<<a[k]<<endl;
}
