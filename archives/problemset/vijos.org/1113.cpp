#include <iostream>
using namespace std;

int a[100];
int main()
{
    for (int i=1;i<=7;i++)
    {
        int b,c;
        cin>>b>>c;
        if (!a[b+c]) a[b+c]=i;
    }
    bool unhappy=false;
    for (int i=30;i>8;i--)
    {
        if (a[i]){cout<<a[i]<<endl;unhappy=true;break;}
    }
    
    if (!unhappy) cout<<0<<endl;
    //while(cin.get());
    return 0;
}
