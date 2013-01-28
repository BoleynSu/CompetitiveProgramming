#include <iostream>
using namespace std;

bool f[120000+2];
int n[6+2];

bool can_be_divided()
{
     int sum=0;
     for (int i=1;i<=6;i++)
         sum+=i*n[i];
     if (sum%2!=0) return false;
     int target=sum/2;
     f[0]=true;
     for (int i=1;i<=target;i++) f[i]=false;
     for (int i=1;i<=6;i++)
         for (int k=n[i];k;k=k-(k+1)/2)
             for (int m=target,n=target+i*((k+1)/2);m>=0;m--,n--)
                 if (f[m]) f[n]=true;
     return f[target];
}

int main()
{
    for (int k=1;;k++)
    {
        for (int i=1;i<=6;i++)
            cin>>n[i];
        bool end=true;
        for (int i=1;i<=6;i++)
            if (n[i]) end=false;
        if (end) break;
        cout<<"Collection #"<<k<<":"<<endl
            <<(can_be_divided()?"Can be divided.":"Can't be divided.")<<endl
            <<endl;
    }
    return 0;
}
