#include <iostream>
/*
Description:
利用FFT和逆FFT实现的O(nlogn)的多项式乘法
multiply函数说明:
                 输入vector<int> p1,p2
                 输出return vector<int>
                 return=p1*p2
                 p1,p2,return分别表示多项式 sum{x^k*p1[k]},sum{x^k*p2[k]},sum{x^k*return[k]}
Test:
POJ2389 Accept
JOJ1013 Accept
HDU1402 Accept
*/
#include <complex>
#include <vector>
#include <cmath>
/*
using std::complex; 
using std::vector;
using std::acos;
using std::sin;
using std::cos;
*/
using namespace std;
typedef complex<double> C;
typedef C* VC;
typedef vector<int> VI;
const double PI=acos(-1.0);
void FFT(VC p,int& ps,int flag=+1,bool aFFT=false)
{
     if (ps==1) return;
     C w=1,wn=C(cos(flag*2*PI/ps),sin(flag*2*PI/ps));        
     int p1s=ps/2,p2s=ps/2;
     VC p1=new C[p1s],p2=new C[p2s];
     for (int i=0;i<ps/2;i++)
         p1[i]=p[i*2],p2[i]=p[i*2+1];        
     FFT(p1,p1s,flag,false),FFT(p2,p2s,flag,false);        
     for (int k=0;k<ps/2;k++)
     {
         p[k]=p1[k]+w*p2[k];
         p[k+ps/2]=p1[k]-w*p2[k];
         w*=wn;
     }
     if (aFFT) for (int k=0;k<ps;k++) p[k]/=C(ps);
     delete [] p1;delete [] p2;
}
VI multiply(VI& p1,VI& p2)
{
   VI p(1<<int((log(double(p1.size()+p2.size()))/log(2.0))+1));
   p1.resize(p.size()),p2.resize(p.size());
   int pc1s=p.size(),pc2s=p.size(),pcs=p.size();
   VC pc1=new C[pc1s],pc2=new C[pc2s],pc=new C[pcs];
   for (int i=0;i<p.size();i++)
       pc1[i]=C(p1[i]),pc2[i]=C(p2[i]);   
   FFT(pc1,pc1s),FFT(pc2,pc2s);
   for (int i=0;i<p.size();i++)
       pc[i]=pc1[i]*pc2[i];
   FFT(pc,pcs,-1,true);
   for (int i=0;i<p.size();i++) p[i]=int(pc[i].real()+0.5);
   delete [] pc1;delete [] pc2;delete [] pc;
   while (!p.back()) p.pop_back();
   return p;
}


namespace sj
{
          namespace BigNumber
          {
                    template<unsigned int size>
                    class UnsignedInteger
                    {
                          static const int BASE=100;
                          int length;
                          unsigned int data[size];
                          static int max(int a,int b)
                          {
                                 return a>b?a:b;
                          }
                          static void delete_useless_zero(UnsignedInteger& a)
                          {
                                 while (a.length&&!a.data[a.length]) a.length--;
                                 a.length++;
                          }
                          public:
                          UnsignedInteger(unsigned int value=0):length(0)
                          {
                                              for (int i=0;i<size;data[i++]=0) ;
                                              if (value)
                                                 while (value)
                                                 {
                                                       data[length++]=value%BASE;
                                                       value/=BASE;
                                                 }
                                              else data[length++]=value;
                          }
                          friend UnsignedInteger operator+(const UnsignedInteger& a,const UnsignedInteger& b)
                          {
                                 UnsignedInteger c;
                                 c.length=max(a.length,b.length);
                                 int t=0;
                                 for (int i=0;i<c.length;i++)
                                 {
                                     t+=a.data[i]+b.data[i];
                                     c.data[i]=t;
                                     if (t<BASE) t=0;
                                     else t=1,c.data[i]-=BASE;
                                 }
                                 if (t) c.data[c.length++]=t;
                                 delete_useless_zero(c);
                                 return c;
                          }
                          friend UnsignedInteger operator-(const UnsignedInteger& a,const UnsignedInteger& b)
                          {
                                 UnsignedInteger c;
                                 c.length=max(a.length,b.length);
                                 int t=0;
                                 for (int i=0;i<c.length;i++)
                                 {
                                     t+=a.data[i]-b.data[i];
                                     c.data[i]=t;
                                     if (t<0) t=-1,c.data[i]+=BASE;
                                     else t=0;
                                 }
                                 delete_useless_zero(c);
                                 return c;
                          }
                          friend UnsignedInteger operator*(const UnsignedInteger& a,const UnsignedInteger& b)
                          {
                                 vector<int> av(a.data,a.data+a.length);
                                 vector<int> bv(b.data,b.data+b.length);
                                 vector<int> cv=multiply(av,bv);
                                 UnsignedInteger c;
                                 c.length=cv.size();
                                 c.data[0]=0;
                                 for (int i=0;i<c.length;i++)
                                 {
                                     c.data[i]+=cv[i];
                                     c.data[i+1]=c.data[i]/BASE;
                                     c.data[i]%=BASE;
                                 }
                                 c.length++;
                                 delete_useless_zero(c);
                                 return c;
                          }
                          friend UnsignedInteger operator/(const UnsignedInteger& a,const UnsignedInteger& b)
                          {
                                 UnsignedInteger c;
                                 c.length=a.length;
                                 UnsignedInteger t=0;                                 
                                 for (int i=c.length;i>=0;)
                                 {
                                     int l=0,r=BASE;
                                     while (l+1!=r)
                                     {
                                           int mid=(l+r)>>1;
                                           if (t<mid*b) r=mid;
                                           else l=mid;
                                     }
                                     c.data[i]=l;
                                     t=t-l*b;
                                     t=t*BASE;
                                     if (i>=0) t=t+a.data[--i];
                                     else i--;
                                 }
                                 delete_useless_zero(c);
                                 return c;
                          }
                          friend bool operator<(const UnsignedInteger& a,const UnsignedInteger& b)
                          {
                                 if (a.length<b.length) return true;
                                 else if (a.length>b.length) return false;
                                 else
                                 {
                                     for (int i=a.length;i--;)
                                         if (a.data[i]<b.data[i]) return true;
                                         else if (a.data[i]>b.data[i]) return false;
                                     return false;
                                 }
                          }
                          template<typename ostream>
                          friend ostream& operator<<(ostream& cout,const UnsignedInteger& number)
                          {
                                 if (number.length==0) {cout<<'0';return cout;}
                                 int pos=number.length;
                                 cout<<number.data[--pos];
                                 while (pos--)
                                       for (int i=number.BASE;i/=10;cout<<char((number.data[pos]/i)%10+'0')) ;
                                 return cout;
                          }
                          template<typename istream>
                          friend istream& operator>>(istream& cin,UnsignedInteger& number)
                          {
                                 string ns;
                                 cin>>ns;
                                 number.length=(ns.length()/2)+((ns.length()%2)?1:0);
                                 for (int i=0;i<2*(ns.length()/2);i+=2)
                                     number.data[i/2]=(ns[ns.length()-i-2]-'0')*10+(ns[ns.length()-i-1]-'0')*1;
                                 if (ns.length()%2)
                                 {
                                    number.data[number.length-1]=0;
                                    for (int i=0;i<ns.length()%2;i++)
                                        number.data[number.length-1]=number.data[number.length-1]*10+ns[i]-'0'; 
                                 }
                                 return cin;
                          }
                    };
          }
}
using sj::BigNumber::UnsignedInteger;

UnsignedInteger<100000> a,b;
int main()
{    
    // freopen("in","r",stdin);
    while (cin>>a>>b) cout<<(a*b)<<endl;
}

