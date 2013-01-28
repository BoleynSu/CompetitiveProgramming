#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
int a[1000],b[1000],c[1000];

int main()
{
    while (cin>>n>>m)
    {
        int SG=0;
        for (int i=0;i<n;i++)
            cin>>a[i]>>b[i],
            c[i]=abs(a[i]-b[i])-1,
            SG^=c[i];
        cout<<(SG?"I WIN!":"BAD LUCK!")<<endl;
    }
}

