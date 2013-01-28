#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAXLEN=1024;
struct num
{
       int n[MAXLEN];
       int len;
};

void x(num& a,num& R);
void answer(char* R,int n); 

int main()
{
    char R[7];
    int n;
    while (cin>>R>>n)
    {
          answer(R,n);
    }
}

void x(num& a,num& R)
{
     num b;
     for (int i=0;i<MAXLEN;i++) b.n[i]=0;
     b.len=a.len+R.len;
     for (int i=0;i<a.len;i++)
         for (int j=0;j<R.len;j++)
         {
             b.n[i+j]+=a.n[i]*R.n[j];
         }
     for (int i=0;i<b.len;i++)
         if (b.n[i]>=10)
         {
            b.n[i+1]+=b.n[i]/10;
            b.n[i]%=10;
         }
     
     a.len=b.len;
     for (int i=0;i<a.len;i++) a.n[i]=b.n[i];
}

void answer(char* R,int n)
{
     int e10=0;
     for (int i=5;i>=0;i--)
         if (R[i]=='.')
         {                       
            e10=5-i;
            for (int j=i;j>0;j--) R[j]=R[j-1];
            R[0]='0';
            break;
         }
     e10*=n;
     
     num _R,ans;
     
     for (int i=0;i<MAXLEN;i++) _R.n[i]=0;
     for (int i=0;i<6;i++) _R.n[i]=(R[5-i]-'0');
     _R.len=6;
     
     for (int i=0;i<MAXLEN;i++) ans.n[i]=0;
     ans.n[0]=1;
     ans.len=1;
     
     for (int i=0;i<n;i++)
         x(ans,_R);
     
     ans.len=MAXLEN;
     while (ans.n[--ans.len]==0);
     ans.len++;
     
     for (int i=ans.len-1;i>=e10;i--) cout<<ans.n[i];
     int c=0;
     while (ans.n[c]==0) c++;
     if (e10>c) cout<<'.';
     for (int i=e10-1;i>=c;i--) cout<<ans.n[i];
     cout<<endl;
     /*
     int counter=ans.len-1;
     while ((counter>e10)&&(ans.n[counter]==0)) counter--;
     for (int i=counter;i>=e10;i--)
         cout<<ans.n[i];
     counter=0;
     while ((ans.n[counter]==0)&&(counter<e10)) counter++;
     if ((e10!=0)&&(counter!=e10)) cout<<'.';
     for (int i=e10-1;i>=counter;i--)
         cout<<ans.n[i];
     cout<<endl;
     */
}
