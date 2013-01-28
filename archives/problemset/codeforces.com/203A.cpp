#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int gcd(int a,int b,int& x,int& y)
{
    if (a)
    {
        int g=gcd(b%a,a,y,x);
        x-=b/a*y;
        return g;
    }
    else
    {
        x=0,y=1;
        return b;
    }
}
int mydiv(int a,int b)
{
    if (a%b)
    {
        double c=double(a)/double(b);
        if (a*b>0) return int(c);
        else return int(c)-1;
    }
    else return a/b;
}

int main()
{
    int X,t,a,b,da,db,x,y;
    cin>>X>>t>>a>>b>>da>>db;
    int g=gcd(da,db,x,y);
    if (X==0) cout<<"YES"<<endl;
    else if ((a-X)%da==0&&0<=(a-X)/da&&(a-X)/da<t) cout<<"YES"<<endl;
    else if ((b-X)%db==0&&0<=(b-X)/db&&(b-X)/db<t) cout<<"YES"<<endl;
    else if ((a+b-X)%g||a+b-X<0) cout<<"NO"<<endl;
    else
    {
        x*=(a+b-X)/g;
        y*=(a+b-X)/g;
        int ta=db/g;
        int tb=da/g;
        //-x/ta<=i<(t-x)/ta
        //(y-t)/tb<i<=y/tb
    //    cout<<x<<" "<<y<<endl;
      ////  cout<<ta<<" "<<tb<<endl;
        int b=max((mydiv(-x,ta)+(x%ta?1:0)),mydiv(y-t,tb)+1);
        int e=min(mydiv(t-x,ta)-((t-x)%ta?0:1),mydiv(y,tb));
     //  cout<<b<<" "<<e<<endl;
      //  cout<<x+ta*b<<" "<<y-tb*b<<endl;
        if (b<=e) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

