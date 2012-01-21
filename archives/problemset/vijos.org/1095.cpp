#include <iostream>
#include <string>
using namespace std;
/*//OLD VERSION:
#define f(arg) (((arg)%n==0)?(n):(arg)%n)
int next[100+2];

int main()
{
for (int n=1;n<=100;n++)
{
    //int n;
    //cin>>n;
    for (int i=1;i<=n;i++)
        next[i]=f(i+1);
    
    int answer=1;
    for (int i=1;i<n;i++)
    {
        int next2=next[next[answer]];
        next[answer]=next2;
        answer=next2;
    }
    cout<<"f("<<n<<")="<<answer<<endl;
}
    while (1);
    return 0;
}
*/
/*
FUNCTION:
         f(2^n+x)=2*x+1 (x<2^n)
*/
const int MAXL=100+2;
typedef int big[MAXL+2];
const int K=10;
big f[MAXL*4+2];

void print(const big a)
{
     int h=MAXL;
     while ((a[h]==0)&&(h>=0)) h--;
     if (h<0) cout<<0;
     else
         for (int i=h;i>=0;i--)
             cout<<a[i];
     cout<<endl;
}
void set(big var,int value=0)
{
     for (int i=1;i<MAXL+2;i++)
         var[i]=0;
     var[0]=value;
}
void add(const big a,const big b,big c)
{
     set(c);
     for (int i=0;i<MAXL;i++)
     {
         c[i]+=a[i]+b[i];
         if (c[i]>=K)
         {
            c[i]-=K;
            c[i+1]++;
         }
     }
}
void sub(const big a,const big b,big c)
{
     set(c);
     for (int i=0;i<MAXL;i++)
     {
         c[i]+=a[i]-b[i];
         if (c[i]<0)
         {
            c[i]+=K;
            c[i+1]--;
         }
     }
}
void inif()
{
     set(f[0],1);
     for (int i=1;i<MAXL*4;i++)
         add(f[i-1],f[i-1],f[i]);
}
void get(big n)
{
     string s;
     cin>>s;
     set(n,0);
     for (int i=s.length()-1;i>=0;i--)
         n[s.length()-1-i]=s[i]-'0';
}
bool bigger(const big a,const big b)
{
     int c=0;
     for (int i=MAXL;i>=0;i--)
         if (a[i]>b[i]) return true;
         else if(a[i]<b[i]) return false;
     return false;
}
void answer()
{
     big n;
     get(n);
     inif();
     int m;
     for (m=MAXL*4-1;bigger(f[m],n);m--) ;
     big x;
     sub(n,f[m],x);
     big x_2;
     add(x,x,x_2);
     big one;
     set(one,1);
     big answer;
     add(one,x_2,answer);
     print(answer);
     //while (1);
}

int main()
{
    answer();
}
