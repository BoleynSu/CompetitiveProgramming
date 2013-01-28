/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-09
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

int cut(long long int x)
{
    for (int i=0;;i++)
    {
        if (x<=0) return i;
        x-=1ll<<i;
    }
}

int main()
{
    int TC;
    cin>>TC;
    for (int tc=1;tc<=TC;tc++)
    {
        long long int x,y,z;
        cin>>x>>y>>z;
        cout<<"Case #"<<tc<<": "<<(x*y*z-1)<<" "<<(cut(x-1)+cut(y-1)+cut(z-1))<<endl;
    }
    return 0;
}

