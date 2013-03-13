/*
AUTHOR: Su Jiao
DATE: 2010-8-26
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
#include <math.h>
using namespace std;

#define lli long long int
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ceil_div(a,b) ceil(double(a)/double(b))
#define floor_div(a,b) floor(double(a)/double(b))

lli gcd(lli a,lli b,lli& x,lli& y)
{
    //ax+by=gcd(a,b)
    if (b==0)
    {
       x=1,y=0;
       return a;
    }
    else
    {
        lli g=gcd(b,a%b,y,x);
        //b*y+a%b*x=gcd(b,a%b)=gcd(a,b)
        // b*y+a%b*x
        //=b*y+(a-a/b*b)*x
        //=b*y-a/b*b*x+a*x
        //=a*x+b*(y-a/b*x)
        y-=a/b*x;
        return g;
    }
}
lli get_answer(lli a,lli b,lli c,lli x1,lli x2,lli y1,lli y2)
{
    //ax+by+c=0
    if (!(x1<=x2&&y1<=y2)) return 0;
    else if (a==0&&b==0)
         return (c==0)*(x2-x1+1)*(y2-y1+1);
    else if (a==0)
    {
         lli y=-c/b;
         return ((b*y+c==0)&&(y1<=y&&y<=y2))*(x2-x1+1);
    }
    else if (b==0)
    {
         lli x=-c/a;
         return ((a*x+c==0)&&(x1<=x&&x<=x2))*(y2-y1+1);
    }
    else
    {
        //a*x = c (mod b)
        lli x,y,g;
        g=gcd(a,b,x,y);//ax+by=g
        if (c%g==0)
        {
           a/=g,b/=g,c/=g;//ax+by=1
           x*=-c,y*=-c;//ax*(-c)+by*(-c)=-c           
           //set of root = {(x+b*k,y-a*k)}           
           lli rxa,rxb;
           if (b>0) rxa=ceil_div(x1-x,b),rxb=floor_div(x2-x,b);
           else rxa=ceil_div(x2-x,b),rxb=floor_div(x1-x,b);
           lli rya,ryb;
           if (a<0) rya=ceil_div(y-y1,a),ryb=floor_div(y-y2,a);
           else rya=ceil_div(y-y2,a),ryb=floor_div(y-y1,a);
           lli ra,rb;
           ra=max(rxa,rya);
           rb=min(rxb,ryb);
           if (ra<=rb) return (rb-ra+1);
           else return 0;
        }
        else return 0;
    }
}

int main()
{
    lli a,b,c,x1,x2,y1,y2;
    cin>>a>>b>>c>>x1>>x2>>y1>>y2;
    cout<<get_answer(a,b,c,x1,x2,y1,y2)<<endl;
}
