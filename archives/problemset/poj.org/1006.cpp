#include <cstdio>
using namespace std;

int gcd(int a,int b,int& x,int& y)
{
    //a*x+b*y=gcd(a,b)
    if (b)
    {
          int get_gcd=gcd(b,a%b,y,x);
          y-=(a/b)*x;          
          return get_gcd;
    }
    else
    {
        x=1;
        y=0;
        return a;
    }
}


int main()
{
    int a,b,c,d;
    for (int t=1;;t++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if (a==-1&&b==-1&&c==-1&&d==-1) break;
        /*
        for (int i=d+1;;i++)
            if (((i-a)%23==0)&&((i-b)%28==0)&&((i-c)%33==0))
            {
               printf("Case %d: the next triple peak occurs in %d days.\n",t,i-d);
               break;
            }
        */
        int M=23*28*33;
        int m23=M/23,x23,y23;
        int m28=M/28,x28,y28;
        int m33=M/33,x33,y33;
        //mx*xx+x*yx=1
        gcd(m23,23,x23,y23);
        gcd(m28,28,x28,y28);
        gcd(m33,33,x33,y33);
        int answer=m23*x23*a+m28*x28*b+m33*x33*c;
        answer=((answer-d)%M+M)%M;
        if (answer==0) answer=M;
        printf("Case %d: the next triple peak occurs in %d days.\n",t,answer);
    }
}
