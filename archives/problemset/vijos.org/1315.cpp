#include <iostream>
using namespace std;

/*
f(x,y)=sum{f(x-1,y')} {y'=y+1 to 2^k}
f(x,y+1)=sum{f(x-1,y')} {y'=y+2 to 2^k}
f(x,y+1)-f(x,y)=-f(x-1,y+1)
*/
/*
up(w,k)=w/k+(w%k!=0)
f(1,y)=1; {y=1 to 2^k-1}
f(x,2^k-1)=0 {x=2 to up(w,k)}
f(x,y)=f(x,y+1)+f(x-1,y+1) {x=0 to 2^k-1}
answer=sum{f(up(w,k),i)} {i=1 to 2^(w%k)-1}
      +sum{f(i,0)} {i=3 to up(w,k)} 
*/

class big
{
      static int K;
      static const int MAXLEN=25;
      int len;
      int data[MAXLEN+2];
      public:
      big(int value=0){memset(data,0,sizeof(data));operator =(value);}
      big& operator =(int other){len=1;data[0]=other;return *this;}
      big operator +(big& other)
      {
          big ret;
          ret.len=len>other.len?len:other.len;
          for (int i=0;i<ret.len;i++)
          {
              ret.data[i]+=data[i]+other.data[i];
              if (ret.data[i]>=K)
              {
                 ret.data[i]-=K;
                 ret.data[i+1]++;
              }
          }
          if (ret.data[ret.len]>0) ret.len++;
          return ret;
      }
      big& operator =(const big& other)
      {
           len=other.len;
           for (int i=0;i<len;i++)
               data[i]=other.data[i];
           return *this;
      }
      big& operator +=(big& other)
      {
           this -> operator =(this -> operator + (other));
           return *this;
      }
      friend ostream& operator <<(ostream& out,big& input); 
};
int big::K=1000000000;
ostream& operator <<(ostream& out,big& input)
{
         cout<<input.data[input.len-1];
         for (int i=input.len-2;i>=0;i--)
         {
             int output=input.data[i];
             for (int k=big::K/10;k>=1;k/=10)
             {
                 cout<<output/k;
                 output%=k;
             }
         }
         return out;
} 

const int MAXX=1024;
const int MAXY=512;
int k,w;
big f[MAXX+2][MAXY+2];

//up(w,k)=w/k+(w%k!=0)
inline
int up(int a,int b)
{
    return a/b+(a%b!=0);
}

int main()
{
    
    while (cin>>k>>w)
    {
    big answer=0;
    int k2=1;
    int k3=1;
    for (int i=1;i<= k ;i++) k2*=2;
    if (w%k==0) k3=k2;
    else for (int i=1;i<=w%k;i++) k3*=2;
    k2--;
    k3--;
    //f(1,y)=1; {y=1 to 2^k-1}
    for (int y=1;y<=k2;y++)
        f[1][y]=1;
    //f(x,2^k-1)=0 {x=2 to up(w/k)}
    for (int x=2;x<=up(w,k);x++)
        f[x][k2]=0;
    
    //f(x,y)=f(x,y+1)+f(x-1,y+1) {y=0 to (2^k-1)-1}
    for (int x=2;x<=up(w,k);x++)
    {
        for (int y=k2-1;y>=0;y--)
        {
            if (y==0)
            {
               f[x][y]=0;
               for (int i=1;i<=k2;i++)
                   f[x][y]+=f[x-1][i];
            }
            else f[x][y]=f[x][y+1]+f[x-1][y+1];
            //cout<<"f["<<x<<","<<y<<"]="<<f[x][y]<<endl;
        }
    }
    //answer=sum{f(up(w,k),i)} {i=1 to 2^(w%k)-1}
    //      +sum{f(i,0)} {i=3 to up(w,k)} 
    for (int i=1;i<=k3;i++)
        answer+=f[up(w,k)][i];
    for (int i=3;i<=up(w,k);i++)
        answer+=f[i][0];
    
    cout<<answer<<endl;
    }
    return 0;
}
