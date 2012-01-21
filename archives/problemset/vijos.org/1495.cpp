#include <iostream>
#include <string>
using namespace std;

string a;
int c[256*5];

bool is(int n)
{
     if (n<2) return false;
     if (n==2) return true;
     for (int i=2;i<n;i++)
         if ((n%i)==0) return false;
     return true;
}

int main()
{
    cin>>a;
    for (int i=0;i<a.length();i++)
        c[a[i]]++;
    int max=0;
    int min=a.length();
    for (char i='a';i<='z';i++)
    {
        if ((c[i]<min)&&(c[i]!=0)) min=c[i];
        if (c[i]>max) max=c[i];
    }
    //cout<<"m"<<max<<"m"<<min;
    if (is(max-min)) cout<<"Lucky Word"<<endl<<(max-min)<<endl;
    else cout<<"No Answer"<<endl<<0<<endl;
    //while (1);
}
