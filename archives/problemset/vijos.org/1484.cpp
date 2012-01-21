#include <iostream>
using namespace std;

int main()
{
    int n[10];
    char t;
    cin>>n[1];
    cin.get();
    cin>>n[2];
    n[3]=n[2]%100;
    n[4]=n[3]%10;
    n[3]/=10;
    n[2]/=100;
    cin.get();
    cin>>n[5];
    n[6]=n[5]%10000;
    n[7]=n[6]%1000;
    n[8]=n[7]%100;
    n[9]=n[8]%10;
    n[8]/=10;
    n[7]/=100;
    n[6]/=1000;
    n[5]/=10000;
    cin.get();
    cin>>t;
    int total=0;
    //for (int i=1;i<=9;i++)cout<<n[i];cout<<endl;
    
    for (int i=1;i<=9;i++)
        total+=n[i]*i;
    if ((((total%11)==10)&&t=='X')||((total%11)==(t-'0'))) cout<<"Right"<<endl;
    else
    {
        cout<<n[1]<<'-'<<n[2]<<n[3]<<n[4]<<'-'<<n[5]<<n[6]<<n[7]<<n[8]<<n[9]<<'-';
        if ((total%11)==10) cout<<char('X');
        else cout<<int(total%11);
        cout<<endl;
    }
    //while(cin.get());
    return 0;
}
